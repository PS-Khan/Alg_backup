/*

https://leetcode.com/problems/making-a-large-island/description/?envType=daily-question&envId=2025-01-31


You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.

 

Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
Example 2:

Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
Example 3:

Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.
 
*/

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <set>
#include <unordered_set>
using namespace std;


class Solution {
public:
  int directions[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

// Function to find island size using DFS
int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& islandIndex, int index) {
    int n = grid.size();
    if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] != 1 || islandIndex[i][j] != 0) 
        return 0;

    islandIndex[i][j] = index; // Mark island cell with its unique index
    int size = 1;  // This cell itself counts as part of the island

    // Explore all 4 possible directions
    for (auto &dir : directions) {
        int new_i = i + dir[0], new_j = j + dir[1];
        size += dfs(new_i, new_j, grid, islandIndex, index);
    }
    return size;
}

int largestIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    unordered_map<int, int> islandSizes; // Stores size of each island (index -> size)
    vector<vector<int>> islandIndex(n, vector<int>(n, 0)); // Stores island index for each cell

    int index = 2; // Start indexing islands from 2 (1 is already in grid)
    int maxSize = 0; // Track the largest island

    // Step 1: Find all islands and assign them an index
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 && islandIndex[i][j] == 0) {
                int size = dfs(i, j, grid, islandIndex, index);
                islandSizes[index] = size; // Store island size
                maxSize = max(maxSize, size);
                index++;
            }
        }
    }

    // Step 2: Try changing each '0' to '1' and check the largest possible island
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) {
                unordered_set<int> uniqueIslands; // Track which islands are adjacent

                // Check all 4 possible neighbors
                for (auto &dir : directions) {
                    int new_i = i + dir[0], new_j = j + dir[1];
                    if (new_i >= 0 && new_j >= 0 && new_i < n && new_j < n && islandIndex[new_i][new_j] > 1) {
                        uniqueIslands.insert(islandIndex[new_i][new_j]); // Add island index
                    }
                }

                // Merge the found islands + 1 (for the flipped cell)
                int possibleSize = 1; 
                for (int island : uniqueIslands) {
                    possibleSize += islandSizes[island];
                }
                maxSize = max(maxSize, possibleSize);
            }
        }
    }

    return maxSize;
}     
};
