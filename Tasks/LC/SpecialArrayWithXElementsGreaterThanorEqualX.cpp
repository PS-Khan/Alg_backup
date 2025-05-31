/*
You are given an array nums of non-negative integers. nums is considered special if there exists a number x such that there are exactly x numbers in nums that are greater than or equal to x.

Notice that x does not have to be an element in nums.

Return x if the array is special, otherwise, return -1. It can be proven that if nums is special, the value for x is unique.
*/

#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <stack>
#include <vector>
#include <queue>
#include <list>
#include <thread>
#include <mutex>
#include <algorithm>

using namespace std;

//naive aproach

int specialArray(vector<int>& nums) {
    int size = nums.size();
    int x = 0;
    while(x < size+1){
        int count = 0;
        for(int i = 0; i< size; ++i){
            if(x <= nums[i]){
                count++;
            } 
        }
        if(count == x){
            return x;
        }
        x++;
    }

    return -1;
}

//binary search


class Solution {
    
    int getFirstGreaterOrEqual(vector<int>& nums, int val) {
        int start = 0;
        int end = nums.size() - 1;

        int index = nums.size();
        while (start <= end) {
            int mid = (start + end) / 2;

            if (nums[mid] >= val) {
                index = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return index;
    }
    
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int N = nums.size();
        for (int i = 1; i <= N; i++) {
            int k = getFirstGreaterOrEqual(nums, i);
            
            if (N - k == i) {
                return i;
            }
        }
        
        return -1;
    }
};


class Solution {
public:
    int specialArray(vector<int>& nums) {
        int N = nums.size();
        
        vector<int> freq(N + 1, 0);
        for (int i = 0; i < N; i++) {
            freq[min(N, nums[i])]++;
        }
        
        int numGreaterThanOrEqual = 0;
        for (int i = N; i >= 1; i--) {
            numGreaterThanOrEqual += freq[i];
            if (i == numGreaterThanOrEqual) {
                return i;
            }
        }
        
        return -1;
    }
};