
//https://leetcode.com/problems/maximum-ascending-subarray-sum/description/?envType=daily-question&envId=2025-02-04

/*

Given an array of positive integers nums, return the maximum possible sum of an ascending subarray in nums.

A subarray is defined as a contiguous sequence of numbers in an array.

A subarray [numsl, numsl+1, ..., numsr-1, numsr] is ascending if for all i where l <= i < r, numsi  < numsi+1. Note that a subarray of size 1 is ascending.

 

Example 1:

Input: nums = [10,20,30,5,10,50]
Output: 65
Explanation: [5,10,50] is the ascending subarray with the maximum sum of 65.
Example 2:

Input: nums = [10,20,30,40,50]
Output: 150
Explanation: [10,20,30,40,50] is the ascending subarray with the maximum sum of 150.
Example 3:

Input: nums = [12,17,15,13,10,11,12]
Output: 33
Explanation: [10,11,12] is the ascending subarray with the maximum sum of 33.
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100

*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
    int size = nums.size();
    int res = nums[0];
    int max_sum = res;

    for (int i = 1; i < size; i++) {
        if (nums[i] > nums[i - 1]) {  
            res += nums[i];  
        } else {  
            max_sum = std::max(max_sum, res);
            res = nums[i];  
        }
    }
    
    max_sum = std::max(max_sum, res); 
    return max_sum;
}
};