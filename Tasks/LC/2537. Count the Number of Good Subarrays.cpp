/*
https://leetcode.com/problems/count-the-number-of-good-subarrays/description/?envType=daily-question&envId=2025-04-16
Given an integer array nums and an integer k, return the number of good subarrays of nums.

A subarray arr is good if there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].

A subarray is a contiguous non-empty sequence of elements within an array.

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


// first try not right , checking not all sub arrs

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int size = nums.size();
        long long count = 0;
        long long res = 0;
        int j = 0;
        for(int i = 0; i < size ; ++i){
            if(++map[nums[i]] > 1){
                count+= map[nums[i]]-1;
                if(count >= k){
                    res++;
                }
            }
        }
        while(count >= k && j < size){
            count-= map[nums[j]]-1;
            j++;
            if(count >= k){
                res++;
            }
        }
        return res;
    }
};

// for some reason works 

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long count = 0, res = 0;
        int j = 0;

        for (int i = 0; i < nums.size(); ++i) {
            count += freq[nums[i]];
            freq[nums[i]]++;

            while (count >= k) {

                count -= freq[nums[j]] - 1;
                freq[nums[j]]--;
                j++;
            }

            res += j;
        }

        return res;
    }
};


//


class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int same = 0, right = -1;
        unordered_map<int, int> cnt;
        long long ans = 0;
        for (int left = 0; left < n; ++left) {
            while (same < k && right + 1 < n) {
                ++right;
                same += cnt[nums[right]];
                ++cnt[nums[right]];
            }
            if (same >= k) {
                ans += n - right;
            }
            --cnt[nums[left]];
            same -= cnt[nums[left]];
        }
        return ans;
    }
};

// normal code

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int same = 0, right = -1;
        unordered_map<int, int> cnt;
        long long ans = 0;
        for (int left = 0; left < n; ++left) {
            while (same < k && right + 1 < n) {
                ++right;
                same += cnt[nums[right]];
                ++cnt[nums[right]];
            }
            if (same >= k) {
                ans += n - right;
            }
            --cnt[nums[left]];
            same -= cnt[nums[left]];
        }
        return ans;
    }
};