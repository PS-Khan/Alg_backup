/*
https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/description/?envType=daily-question&envId=2025-03-26


You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.

A uni-value grid is a grid where all the elements of it are equal.

Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.

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

using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> nums;
        int modBase = grid[0][0] % x;
        
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] % x != modBase) {
                    return -1; 
                }
                nums.push_back(grid[i][j]);
            }
        }
        
       
        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];
        int res = 0;
        
       
        for (int num : nums) {
            res += abs(median - num) / x;
        }
        
        return res;
    }
};

//

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        // Initialize an empty array to store all numbers
        vector<int> numsArray;
        int result = INT_MAX;

        // Flatten the grid into numsArray and check if all elements have the
        // same remainder when divided by x
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                // If remainder of any element doesn't match the first element,
                // return -1
                if (grid[row][col] % x != grid[0][0] % x) return -1;
                numsArray.push_back(grid[row][col]);
            }
        }

        // Sort numsArray in non-decreasing order to easily calculate operations
        sort(numsArray.begin(), numsArray.end());

        int length = numsArray.size();
        vector<int> prefixSum(length, 0);
        vector<int> suffixSum(length, 0);

        // Calculate the prefix sum up to each index (excluding the current
        // element)
        for (int index = 1; index < length; index++) {
            prefixSum[index] = prefixSum[index - 1] + numsArray[index - 1];
        }

        // Calculate the suffix sum from each index (excluding the current
        // element)
        for (int index = length - 2; index >= 0; index--) {
            suffixSum[index] = suffixSum[index + 1] + numsArray[index + 1];
        }

        // Iterate through numsArray to calculate the number of operations for
        // each potential common value
        for (int index = 0; index < length; index++) {
            int leftOperations =
                (numsArray[index] * index - prefixSum[index]) / x;

            int rightOperations =
                (suffixSum[index] - numsArray[index] * (length - index - 1)) /
                x;

            // Update the result with the minimum operations needed
            result = min(result, leftOperations + rightOperations);
        }

        return result;
    }
};


//

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        // Initialize an empty array to store all numbers from the grid
        vector<int> numsArray;
        int result = 0;

        // Flatten the grid into numsArray
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                // If any element has a different remainder than the first
                // element, it is impossible to make all elements equal, so
                // return -1
                if (grid[row][col] % x != grid[0][0] % x) return -1;
                numsArray.push_back(grid[row][col]);
            }
        }

        // Sort numsArray in non-decreasing order to facilitate efficient
        // operations
        sort(numsArray.begin(), numsArray.end());

        int length = numsArray.size();
        int prefixIndex = 0;
        int suffixIndex = length - 1;

        // Gradually move prefixIndex and suffixIndex towards the middle
        while (prefixIndex < suffixIndex) {
            // If the prefix of equal elements is shorter than the suffix
            if (prefixIndex < length - suffixIndex - 1) {
                // Calculate the number of operations required to extend the
                // prefix
                int prefixOperations =
                    (prefixIndex + 1) *
                    (numsArray[prefixIndex + 1] - numsArray[prefixIndex]) / x;

                result += prefixOperations;
                // Move the prefix index forward
                prefixIndex++;
            } else {
                // Calculate the number of operations required to extend the
                // suffix
                int suffixOperations =
                    (length - suffixIndex) *
                    (numsArray[suffixIndex] - numsArray[suffixIndex - 1]) / x;

                result += suffixOperations;
                // Move the suffix index backward
                suffixIndex--;
            }
        }

        return result;
    }
};