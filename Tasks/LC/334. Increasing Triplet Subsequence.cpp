#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;
/*

https://leetcode.com/problems/increasing-triplet-subsequence/description/

Given an integer array nums, return true if there exists a triple of indices (i, j, k) 
such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.
*/
std::vector<int> v;

bool increasingTriplet(vector<int>& nums) {
        int i = INT_MAX, k = INT_MAX;
        for(int j = 0 ; j < nums.size(); j++){
            if(nums[j] <= i){
                i = nums[j];
            }else if(nums[j] <= k ){
                k = nums[j];
            }else{
                return true;
            }

        }
        
        return false;
    }