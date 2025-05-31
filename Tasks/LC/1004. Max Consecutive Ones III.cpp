#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <stack>
#include <vector>
#include <queue>
#include <list>
#include <thread>
#include <mutex>
#include<string>
using namespace std;

/*
https://leetcode.com/problems/max-consecutive-ones-iii/description/

Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 
*/

int longestOnes(vector<int>& nums, int k) {
        int max = 0;
        int tmp = 0;
        int j = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == 1){
                tmp++;
            }else if(nums[i] == 0 && k > 0){
                tmp++;
                k--;
            }else{
                while(nums[j] == 1){
                    j++;
                    tmp--;
                }
                if(nums[j] == 0){
                    k++;
                    j++;
                    i--;
                    tmp--;
                    
                }
                
            }
            max = std::max(max,tmp);
        }
        return max;
    }
//solve the problem is easier then understand why this works, why it works without incrementing of k?:
 int longestOnes(std::vector<int>& nums, int k) {
        int maxLen = 0;
        int tmp = 0;
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                tmp++;
            } else {
                if (k > 0) {
                    tmp++;
                    k--;
                } else {
                    while (nums[j] == 1) {
                        j++;
                        tmp--;
                    }
                    j++;
                }
            }
            maxLen = std::max(maxLen, tmp);
        }
        return maxLen;
}

/*
Longest Subarray of 1's After Deleting One Element
Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

 

Example 1:

Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
Example 2:

Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
Example 3:

Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.
 
*/
//just fixed k;
int longestSubarray(vector<int>& nums) {
        int max = 0;
        int tmp = 0;
        int j = 0;
        int k  = 1;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == 1){
                tmp++;
            }else if(nums[i] == 0 && k > 0){
                tmp++;
                k--;
            }else{
                while(nums[j] == 1){
                    j++;
                    tmp--;
                }
                if(nums[j] == 0){
                    k++;
                    j++;
                    i--;
                    tmp--;
                    
                }
                
            }
            max = std::max(max,tmp);
        }
        return max-1;
    }

//
int longestSubarray(vector<int>& nums) {
        int max = 0;
        int tmp = 0;
        int j = 0;
        int k  = 1;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == 1){
                tmp++;
            }else if(nums[i] == 0 && k == 1){
               k--;
            }else{
                while(nums[j] != 0){
                    j++;
                    tmp--;
                }
                j++;
               
            }
            max = std::max(max,tmp);
        }
        if(max == nums.size())
            max--;
        return max;
    }