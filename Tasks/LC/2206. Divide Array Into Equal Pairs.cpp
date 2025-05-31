/*
https://leetcode.com/problems/divide-array-into-equal-pairs/description/?envType=daily-question&envId=2025-03-17

You are given an integer array nums consisting of 2 * n integers.

You need to divide nums into n pairs such that:

Each element belongs to exactly one pair.
The elements present in a pair are equal.
Return true if nums can be divided into n pairs, otherwise return false.

 

Example 1:

Input: nums = [3,2,3,2,2,2]
Output: true
Explanation: 
There are 6 elements in nums, so they should be divided into 6 / 2 = 3 pairs.
If nums is divided into the pairs (2, 2), (3, 3), and (2, 2), it will satisfy all the conditions.
Example 2:

Input: nums = [1,2,3,4]
Output: false
Explanation: 
There is no way to divide nums into 4 / 2 = 2 pairs such that the pairs satisfy every condition.
 
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
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int i = 0 ;i < nums.size(); i++){
            map[nums[i]]++;
        }
        for(auto &item : map){
            if(item.second %2 != 0){
                return false;
            }
        }
        return true;
    }
};

//

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int tmp = nums[0];
        int dev = 1;
        for(int i  = 1; i < nums.size();i++){
            if(tmp == nums[i]){
                dev++;
            }else{
                tmp = nums[i];
                if(dev % 2 != 0){
                    return false;
                }
                dev = 1;
            }
        }
        return true;
    }
};

//

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        // Find maximum value in array
        int maxNum = 0;
        for (int num : nums) {
            maxNum = max(num, maxNum);
        }

        // Toggle pair status for each number
        vector<bool> needsPair(maxNum + 1, false);
        for (int num : nums) {
            needsPair[num] = !needsPair[num];
        }

        // Check if any number remains unpaired
        for (int num : nums) {
            if (needsPair[num]) {
                return false;
            }
        }

        return true;
    }
};

//
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        // Track unpaired numbers
        unordered_set<int> unpaired;

        // Add numbers to set if unseen, remove if seen
        for (int num : nums) {
            if (unpaired.count(num)) {
                unpaired.erase(num);
            } else {
                unpaired.insert(num);
            }
        }

        // Return true if all numbers were paired
        return unpaired.empty();
    }
};