/*
https://leetcode.com/problems/unique-number-of-occurrences/description/?envType=study-plan-v2&envId=leetcode-75

Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

*/


#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        std::unordered_map<int,int> nums;
        for(int i : arr){
            nums[i]++;
        }
        std::unordered_set<int> set;
        for (const auto& [key, value] : nums) {
            if (!set.insert(value).second) {
                return false;
            }
        }
        return true;

    }
};