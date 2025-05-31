
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
#include <numeric>
#include <functional>

using namespace std;


/*
https://leetcode.com/problems/partition-equal-subset-sum/description/?envType=daily-question&envId=2025-04-07

Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 
*/


class Solution {
public:
    int sum_of (vector<int> nums){
        int res = 0;
        for(int i  = 0; i < nums.size(); i++){
            res += nums[i];
        }
        return res;
    }
    bool backtrack(vector<int> nums, vector<int> part){
        for(int i  = 0; i < nums.size(); i++){
            int tmp = nums[i];
            part.push_back(tmp);
            nums.erase(nums.begin()+i);
            if(sum_of(part) == sum_of(nums)){
                return true;
            }
            if(backtrack(nums, part)){
                return true;
            }
            part.pop_back();
            nums.insert(nums.begin()+i, tmp);
        }
        return false;
    }
    bool canPartition(vector<int>& nums) {
        vector<int> part;
        return backtrack(nums, part); 
    }
};

//

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) return false;

        int target = total / 2;
        unordered_map<string, bool> memo;

        function<bool(int, int)> dfs = [&](int i, int sum) {
            if (sum == target) return true;
            if (i >= nums.size() || sum > target) return false;

            string key = to_string(i) + "," + to_string(sum);
            if (memo.count(key)) return memo[key];

            bool take = dfs(i + 1, sum + nums[i]);
            bool skip = dfs(i + 1, sum);

            memo[key] = take || skip;
            return memo[key];
        };

        return dfs(0, 0);
    }
};

//

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) return false;

        int target = total / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : nums) {
            for (int i = target; i >= num; --i) {
                dp[i] = dp[i] || dp[i - num];
            }
        }

        return dp[target];
    }
};