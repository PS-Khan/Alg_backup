/*
http://leetcode.com/problems/zero-array-transformation-i/description/

You are given an integer array nums of length n and a 2D array queries, where queries[i] = [li, ri].

For each queries[i]:

Select a subset of indices within the range [li, ri] in nums.
Decrement the values at the selected indices by 1.
A Zero Array is an array where all elements are equal to 0.

Return true if it is possible to transform nums into a Zero Array after processing all the queries sequentially, otherwise return false.

 

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



class Solution {
public:
    vector<int> init_D(vector<int>& nums){
        vector<int> D(nums.size()+1,0);
        D[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            D[i] = nums[i] - nums[i-1];
        }
        return D;
    }
    void update(vector<int>& D, int l , int r, int i){
        D[l]+=i;
        D[r+1]-=i;
    }
    bool modify(vector<int>& nums, vector<int>& D){
        nums[0]=D[0];
        for(int i = 1; i < nums.size(); i++ ){
            nums[i] = nums[i-1]+D[i];
            if(nums[i]>0){
                return false;
            }
        }
        if(nums[0]>0){
            return false;
        }
        return true;
    }
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int size_n = nums.size();
        vector<int> D = init_D(nums);
        for(vector<int>& part : queries){
            update(D, part[0], part[1],-1);
        }
        return modify(nums,D);
    }
};