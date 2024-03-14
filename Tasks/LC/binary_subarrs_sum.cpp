/*
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15

though it was easy , until i faced with time limit exceeded testcase 56/60: 
like this at least is an intuative aproach
*/

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <unordered_map>
using namespace std;
int numSubarraysWithSum(vector<int>& nums, int goal) {
        int start = 0, res= 0;;
        while(start < nums.size()){
            int tmp = 0;
            for(int i = start; i< nums.size(); i++){
                tmp+=nums.at(i);
                if(tmp == goal){
                    res++;
                }else if(tmp>goal){
                    break;
                }
            }
            start++;
        }
        return res;
    }

//2 O(n) ... Like what code does is not hard to understand
//harder to understand why what code does solves the prob)
//1. for each sum from 0 to n stores sums in hashtab and increments same sum
//2. by adding all previous encounters of prefsum  sum - 
//magicaly we get number of possible sub arrays with desired some.:
int numSubarraysWithSum2(vector<int>& nums, int goal) {
        std::unordered_map<int, int> prefixSums;
        prefixSums[0] = 1; 
        int sum = 0, res = 0;
        for (int num : nums) {
            sum += num;
            if (prefixSums.count(sum - goal)) {
                res += prefixSums[sum - goal];
            }
            prefixSums[sum]++;
        }
        return res;
    }
//ok , why i read comments ...
//sanity gone.
int numSubarraysWithSum3(vector<int>& nums, int goal) {
        int i1 = 0; 
        int i2 = 0; 
        int sumi1 = 0;
        int sumi2 = 0; 
        int border = 0;
        int res = 0; 
        int numSize = nums.size(); 
        
        while (border < numSize){
            sumi1 += nums[border];
            sumi2 += nums[border];

            //all that greater
            while( i1 <= border && sumi1 > goal ){
                sumi1 -= nums[i1++];
                
            }
            
            
            //all that smaller or equal
            while( i2 <=border && sumi2 >= goal ){
                sumi2 -= nums[i2++];
                
            }
            
            res += i2 - i1;

            ++border;
        }

        
        return res;
    }
