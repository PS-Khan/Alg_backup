/*
An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.

Given the grid grid represented as a string array, return the number of regions.

Note that backslash characters are escaped, so a '\' is represented as '\\'.


https://leetcode.com/problems/regions-cut-by-slashes/description/?envType=daily-question&envId=2024-08-10
*/


#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;



//my solution


class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int ans = 0;
        std::vector<std::vector<int>> map(n*3, std::vector<int>(n*3));
        std::vector<std::vector<int>> visited =  map;

        for(int i = 0; i<n; ++i){
            for(int j = 0 ;j<n; ++j){
                fillMap(map, i, j, grid[i][j]);
            }
        }

        for(std::vector<int> row : map){
            for(int i : row ){
                std::cout<<i << " ";
            }
            std::cout<<"\n";
        }

        for(int i = 0; i<n*3; ++i){
            for(int j = 0 ;j< n*3; ++j){
                ans+= Dsearch(visited, i, j, map);
            }
        }

        return ans ;

        
    }
    void fillMap(std::vector<std::vector<int>>& map, int i, int j, char ch){
        std::vector<std::vector<int>> slash = {
            {0,0,1},
            {0,1,0},
            {1,0,0}
        };
        std::vector<std::vector<int>> bslash = {
            {1,0,0},
            {0,1,0},
            {0,0,1}
        };
        int baseRow = i * 3;
        int baseCol = j * 3;

        switch (ch) {
            case '\\':
                for (int row = 0; row < 3; ++row) {
                    for (int col = 0; col < 3; ++col) {
                        map[baseRow + row][baseCol + col] = bslash[row][col];
                    }
                }
                break;
            case '/':
                for (int row = 0; row < 3; ++row) {
                    for (int col = 0; col < 3; ++col) {
                        map[baseRow + row][baseCol + col] = slash[row][col];
                    }
                }
                break;
            case ' ':
                for (int row = 0; row < 3; ++row) {
                    for (int col = 0; col < 3; ++col) {
                        map[baseRow + row][baseCol + col] = 0;
                    }
                }
                break;
        }
    }
        int Dsearch(std::vector<std::vector<int>> &visited, int i, int j,       std::vector<std::vector<int>> &grid) {
        // Base condition: if the cell is already visited, return 0.
        if (visited[i][j] == 1 || grid[i][j] == 1) {
            return 0;
        }

        // Mark the cell as visited.
        visited[i][j] = 1;


        // Recursively visit all connected cells (right, left, down, up).
        if (j + 1 < grid.size()) {
            Dsearch(visited, i, j + 1, grid);
        }
        if (j - 1 >= 0) {
            Dsearch(visited, i, j - 1, grid);
        }
        if (i + 1 < grid.size()) {
            Dsearch(visited, i + 1, j, grid);
        }
        if (i - 1 >= 0) {
            Dsearch(visited, i - 1, j, grid);
        }

        // Return 1 to indicate that a new region has been found.
        return 1;
        }
};



///



class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int gridSize = grid.size();
        // Create a 3x3 matrix for each cell in the original grid
        vector<vector<int>> expandedGrid(gridSize * 3,
                                         vector<int>(gridSize * 3, 0));

        // Populate the expanded grid based on the original grid
        // 1 represents a barrier in the expanded grid
        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                int baseRow = i * 3;
                int baseCol = j * 3;
                // Check the character in the original grid
                if (grid[i][j] == '\\') {
                    // Mark diagonal for backslash
                    expandedGrid[baseRow][baseCol] = 1;
                    expandedGrid[baseRow + 1][baseCol + 1] = 1;
                    expandedGrid[baseRow + 2][baseCol + 2] = 1;
                } else if (grid[i][j] == '/') {
                    // Mark diagonal for forward slash
                    expandedGrid[baseRow][baseCol + 2] = 1;
                    expandedGrid[baseRow + 1][baseCol + 1] = 1;
                    expandedGrid[baseRow + 2][baseCol] = 1;
                }
            }
        }

        int regionCount = 0;
        // Count regions using flood fill
        for (int i = 0; i < gridSize * 3; i++) {
            for (int j = 0; j < gridSize * 3; j++) {
                // If we find an unvisited cell (0), it's a new region
                if (expandedGrid[i][j] == 0) {
                    // Fill that region
                    floodFill(expandedGrid, i, j);
                    regionCount++;
                }
            }
        }
        return regionCount;
    }

private:
    // Directions for traversal: right, left, down, up
    const vector<vector<int>> DIRECTIONS = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // Flood fill algorithm to mark all cells in a region
    void floodFill(vector<vector<int>>& expandedGrid, int row, int col) {
        queue<pair<int, int>> q;
        expandedGrid[row][col] = 1;
        q.push({row, col});

        while (!q.empty()) {
            auto [currentRow, currentCol] = q.front();
            q.pop();
            // Check all four directions from the current cell
            for (const auto& direction : DIRECTIONS) {
                int newRow = direction[0] + currentRow;
                int newCol = direction[1] + currentCol;
                // If the new cell is valid and unvisited, mark it and add to
                // queue
                if (isValidCell(expandedGrid, newRow, newCol)) {
                    expandedGrid[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }

    // Check if a cell is within bounds and unvisited
    bool isValidCell(const vector<vector<int>>& expandedGrid, int row,
                     int col) {
        int n = expandedGrid.size();
        return row >= 0 && col >= 0 && row < n && col < n &&
               expandedGrid[row][col] == 0;
    }
};