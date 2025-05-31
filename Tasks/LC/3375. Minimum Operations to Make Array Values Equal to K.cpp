/*
https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/description/?envType=daily-question&envId=2025-04-09

You are given an integer array nums and an integer k.

An integer h is called valid if all values in the array that are strictly greater than h are identical.

For example, if nums = [10, 8, 10, 8], a valid integer is h = 9 because all nums[i] > 9 are equal to 10, but 5 is not a valid integer.

You are allowed to perform the following operation on nums:

Select an integer h that is valid for the current values in nums.
For each index i where nums[i] > h, set nums[i] to h.
Return the minimum number of operations required to make every element in nums equal to k. If it is impossible to make all elements equal to k, return -1.

 

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
#include <numeric>
#include <functional>

using namespace std;


class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > k && map.find(nums[i]) == map.end()){
                res++;
            }
            if(nums[i] < k){
                return -1;
            }
            map[nums[i]]++;
        }
        return res;
    }
};