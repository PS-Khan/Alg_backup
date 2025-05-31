/*
https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/description/?envType=daily-question&envId=2025-02-26


You are given an integer array nums. The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).

Return the maximum absolute sum of any (possibly empty) subarray of nums.

Note that abs(x) is defined as follows:

If x is a negative integer, then abs(x) = -x.
If x is a non-negative integer, then abs(x) = x.
 

Example 1:

Input: nums = [1,-3,2,3,-4]
Output: 5
Explanation: The subarray [2,3] has absolute sum = abs(2+3) = abs(5) = 5.
Example 2:

Input: nums = [2,-5,1,-4,3,-2]
Output: 8
Explanation: The subarray [-5,1,-4] has absolute sum = abs(-5+1-4) = abs(-8) = 8.
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104

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
    int ab_sum(vector<int> &s){
        int tmp = 0;
        for(int i = 0; i < s.size(); i++){
            tmp+=s[i];
        }
        return abs(tmp);
    }
    void backtrack(vector<int>& nums, int i, int  &res, vector<int> &sum){
        if(i >= nums.size()){
            return;
        }
        sum.push_back(nums[i]);
        res = max(res, ab_sum(sum) );
        backtrack(nums, i+1, res, sum);
        
    }
    int maxAbsoluteSum(vector<int>& nums) {
        int s = nums.size();
        int res = INT_MIN;
        
        for(int i = 0; i < s; i++ ){
            vector<int> sum;
            backtrack(nums, i, res, sum);
        }
        return res;
    }
};

//Kadanes approach

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int s = nums.size();
        if(s == 1){
            return abs(nums[0]);
        }
        int res = nums[0];
        int mins = nums[0], maxs = nums[0];
        for(int i = 1; i < s; i++){
            maxs = max((nums[i]+maxs), nums[i]);
            mins = min((nums[i]+mins), nums[i]);
            res = max(res, maxs);
            res = max(res, abs(mins));
        } 
        return res;
    }
};