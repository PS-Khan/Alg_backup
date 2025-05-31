/*
https://leetcode.com/problems/longest-nice-subarray/description/?envType=daily-question&envId=2025-03-18

You are given an array nums consisting of positive integers.

We call a subarray of nums nice if the bitwise AND of every pair of elements that are in different positions in the subarray is equal to 0.

Return the length of the longest nice subarray.

A subarray is a contiguous part of an array.

Note that subarrays of length 1 are always considered nice.

 

Example 1:

Input: nums = [1,3,8,48,10]
Output: 3
Explanation: The longest nice subarray is [3,8,48]. This subarray satisfies the conditions:
- 3 AND 8 = 0.
- 3 AND 48 = 0.
- 8 AND 48 = 0.
It can be proven that no longer nice subarray can be obtained, so we return 3.
Example 2:

Input: nums = [3,1,5,11,13]
Output: 1
Explanation: The length of the longest nice subarray is 1. Any subarray of length 1 can be chosen.
 

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


//

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l = 0, or_sum = 0, max_len = 0;

        for (int r = 0; r < nums.size(); r++) {
            while ((or_sum & nums[r]) != 0) {
                or_sum ^= nums[l];  
                l++;
            }

            or_sum |= nums[r];  
            max_len = max(max_len, r - l + 1);
        }
        
        return max_len;
    }
};