/*
https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/?envType=daily-question&envId=2025-02-12

You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].

Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.

 

Example 1:

Input: nums = [18,43,36,13,7]
Output: 54
Explanation: The pairs (i, j) that satisfy the conditions are:
- (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
- (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
So the maximum sum that we can obtain is 54.
Example 2:

Input: nums = [10,12,19,14]
Output: -1
Explanation: There are no two numbers that satisfy the conditions, so we return -1.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109

*/


#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <set>
#include <queue>
#include <set>
#include <utility>
#include <stack>

using namespace std;


class Solution {
public:
  int sumofdigit(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, pair<int, int>> map; 
        int res = -1;

        for (int num : nums) {
            int key = sumofdigit(num);
            auto& p = map[key];

            if (num > p.first) { 
                p.second = p.first;
                p.first = num;
            } else if (num > p.second) {
                p.second = num;
            }
        }

     
        for (const auto& pair : map) {
            if (pair.second.second > 0) {  
                res = max(res, pair.second.first + pair.second.second);
            }
        }

        return res;
    }
};


/*
Approach 3: Store Maximum Value
Intuition
In the previous approach, we optimized our initial approach further by storing the two greatest elements in the priority queue for each digit sum. Can we optimize this further? Instead of storing two elements for each digit sum, we can store only the greatest element we've encountered so far for each digit sum in an array digitMapping of size 82, corresponding to the 82 possible digit sums. Then, for each new element, we create a pair with the current element and the greatest element found so far for the same digit sum.

Using this approach, it is guaranteed that we will always encounter a pair with two greatest integers for a digit-sum. The proof is given below:

Let's say the array nums is given by: {nums[0], nums[1], ...., largest value with digit-sum n, ...., second largest value with digit-sum n, ..., nums[nums.size - 1]}. In other words, the largest value occurs before the second-largest value with the same digit-sum. In this case, as soon as we reach the largest value, it would replace the value in digitMapping[n]. Now, when we reach the second largest value, the pair sum would be given as second largest value + digitMapping[n], which would give us the largest pair-sum for the given digit-sum.

Similarly, let's say the array nums is given by: {nums[0], nums[1], ...., second largest value with digit-sum n, ...., largest value with digit-sum n..., nums[nums.size - 1]}. In this case, as soon as we reach the second largest value, it would replace the value in digitMapping[n]. Now, when we reach the largest value, the pair sum would be given as largest value + digitMapping[n], which would give us the largest pair-sum for the given digit-sum. After this, the largest value would replace the value in digitMapping[n].

Algorithm
Initialize an array digitMapping of size 82 to store the maximum number for each digit sum (0 to 81). Initialize result as -1.
Iterate through the elements of nums:
Compute the digit sum for each element:
Initialize digitSum as 0.
For each element, repeatedly extract the last digit (using element % 10) and add it to digitSum.
Update element by dividing it by 10.
If digitMapping[digitSum] is greater than 0 (indicating that a number with the same digit sum has been seen before), calculate the sum of the current number and the stored number with the same digit sum.
Update result with the maximum of result and the calculated sum.
Update digitMapping[digitSum] with the maximum value between digitMapping[digitSum] and the current element.
Return result.

*/

//good one

 int maximumSum(vector<int>& nums) {
        int result = -1;
        // Array to map digit sums to the largest element with that sum
        // (82 to cover all possible sums from 0 to 81)
        int digitMapping[82] = {};

        for (int element : nums) {
            int digitSum = 0;

            // Calculate the digit sum of the current element
            for (int currValue = element; currValue; currValue /= 10) {
                int currDigit = currValue % 10;
                digitSum += currDigit;
            }

            // Check if there is already an element with the same digit sum
            if (digitMapping[digitSum] > 0) {
                // Update the result if the sum of the current and mapped
                // element is greater
                result = max(result, digitMapping[digitSum] + element);
            }

            // Update the mapping to store the larger of the current or previous
            // element for this digit sum
            digitMapping[digitSum] = max(digitMapping[digitSum], element);
        }

        return result;
    }