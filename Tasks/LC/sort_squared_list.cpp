#include <vector>
#include <iostream>
using namespace std;
/**
 Given an integer array nums sorted in non-decreasing order,
  return an array of the squares of each number sorted in non-decreasing order.
*/
    vector<int> sortedSquares(vector<int>& nums) {
        int end = nums.size()-1, start = 0;
        vector<int> result(nums.size(),0);
        for(int i = end;  i > -1; i--){
            if(std::abs(nums[end]) > std::abs(nums[start]) ){
                result[i] = nums[end]*nums[end];
                end--;
            }else{
                result[i] = nums[start]*nums[start];
                start++;
            }
        }
        return result;
    }
