/*

https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/?envType=daily-question&envId=2025-02-02

Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.

*/



#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <queue>
#include <algorithm>
using namespace std;


// try with recinstruction, dont work with dublicates (same numbers):

class Solution {
public:
    bool check(vector<int>& nums) {
       vector<int> check;
       int min = *min_element(nums.begin(), nums.end());
       int size = nums.size();
       int start = 0;
       for(int i  = 0; i < size; i++){
            if(nums[i]==min){
                start = i ;
                break;
            }
       }
        for (int i = start; i < size; i++) {
            check.push_back(nums[i]);
        }
        for (int i = 0; i < start; i++) {
            check.push_back(nums[i]);
        }
       sort(nums.begin(), nums.end());
       
       if(check == nums ){
           return true;
       }

       return false;

       
    }
};


// best sol

/*

this works because in rotated arr would be only one occurance of bigger prev element 

*/

bool check(vector<int>& nums) {
    int count = 0, n = nums.size();

    for (int i = 0; i < n; i++) {
        if (nums[i] > nums[(i + 1) % n]) {  
            count++;
        }
    }

    return count <= 1;
}
