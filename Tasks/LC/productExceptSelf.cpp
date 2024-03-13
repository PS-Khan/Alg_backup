/*

my initial O(n^2) solution:
vector<int> productExceptSelf(vector<int>& nums) {
        int r = 0, l = 0;
        vector<int> res (nums.size(), 0);
        for (int i = 0; i < nums.size(); i++){
            int left = 1, right = 1;
            r = i+1;
            l=  i-1;
            while(l >= 0){
                left*= nums.at(l);
                std::cout<<nums.at(l);
                l--;
                
            }

            while(r < nums.size()){
                right*= nums.at(r);
                std::cout<<nums.at(r);
                r++;
            }
            res[i] = left*right;
        }
        return res;
    }


Given an integer array nums, return an array answer such that answer[i] is equal
 to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

*/

//O(n)
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] * nums[i - 1]; //computed left product for each i
        }
        
        int right_product = 1; 
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= right_product; 
            right_product *= nums[i]; 
        }
        return res;
    }