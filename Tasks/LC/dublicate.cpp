/*

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

*/
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

int findDuplicate(vector<int>& nums) {
        std::vector<int> arr(nums.size(), 0);
        for (int i = 0; i < nums.size();i++){
            if (arr[nums[i]] > 0){
                return nums[i];
            }else{
                arr[nums[i]]++;
            }
        }
        return -1;
        
    }