/*
https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/description/?envType=daily-question&envId=2025-02-25
Given an array of integers arr, return the number of subarrays with an odd sum.

Since the answer can be very large, return it modulo 109 + 7.

 

Example 1:

Input: arr = [1,3,5]
Output: 4
Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
All sub-arrays sum are [1,4,9,3,8,5].
Odd sums are [1,9,3,5] so the answer is 4.
Example 2:

Input: arr = [2,4,6]
Output: 0
Explanation: All subarrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
All sub-arrays sum are [2,6,12,4,10,6].
All sub-arrays have even sum and the answer is 0.
Example 3:

Input: arr = [1,2,3,4,5,6,7]
Output: 16
 

Constraints:

1 <= arr.length <= 105
1 <= arr[i] <= 100
*/


#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <set>
#include <utility>
#include <stack>

using namespace std;


// time limit exceeded
class Solution {
public:
    void backtrack(vector<int>& arr, int index, int curr_sum, int &count) {
        if (index >= arr.size()) return;  


        curr_sum += arr[index];

      
        if (curr_sum % 2 != 0) count++;

        
        backtrack(arr, index + 1, curr_sum, count);

       
    }

    int numOfSubarrays(vector<int>& arr) {
        int count = 0;
        for (int i = 0; i < arr.size(); i++) {
            backtrack(arr, i, 0, count);
        }
        return count % 1000000007;
    }
};


//

/*
Instead of recomputing sum for every subarray:

Maintain odd (count of prefix sums that are odd).
Maintain even (count of prefix sums that are even).
If sum % 2 == 0, add all previous odd prefix sums to result.
If sum % 2 == 1, add all previous even prefix sums to result.
*/

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long odd = 0, even = 1, sum = 0, res = 0;
        int MOD = 1e9 + 7;

        for (int num : arr) {
            sum += num;
            if (sum % 2 == 0) {
                res = (res + odd) % MOD;
                even++;
            } else {
                res = (res + even) % MOD;
                odd++;
            }
        }

        return res;
    }
};

//
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();

        // Convert elements to 0 (even) or 1 (odd)
        for (auto& num : arr) {
            num %= 2;
        }

        // dpEven[i] represents the number of subarrays with an even sum ending
        // at index i dpOdd[i] represents the number of subarrays with an odd
        // sum ending at index i
        vector<int> dpEven(n), dpOdd(n);

        // Initialization based on the last element
        // The last element is even
        if (arr[n - 1] == 0) {
            dpEven[n - 1] = 1;
        } else {
            // The last element is odd
            dpOdd[n - 1] = 1;
        }

        // Traverse the array in reverse
        for (int num = n - 2; num >= 0; num--) {
            if (arr[num] == 1) {
                // Odd element contributes to odd subarrays
                dpOdd[num] = (1 + dpEven[num + 1]) % MOD;
                // Even element continues the pattern
                dpEven[num] = dpOdd[num + 1];
            } else {
                // Even element contributes to even subarrays
                dpEven[num] = (1 + dpEven[num + 1]) % MOD;
                // Odd element continues the pattern
                dpOdd[num] = dpOdd[num + 1];
            }
        }

        // Sum all the odd subarrays
        int count = 0;
        for (auto oddCount : dpOdd) {
            count += oddCount;
            count %= MOD;
        }

        return count;
    }
};