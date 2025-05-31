/*
https://leetcode.com/problems/equal-row-and-column-pairs/description/?envType=study-plan-v2&envId=leetcode-75

Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.

A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).

 

Example 1:


Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
Output: 1
Explanation: There is 1 equal row and column pair:
- (Row 2, Column 1): [2,7,7]
Example 2:


Input: grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
Output: 3
Explanation: There are 3 equal row and column pairs:
- (Row 0, Column 0): [3,1,2,2]
- (Row 2, Column 2): [2,4,2,2]
- (Row 3, Column 2): [2,4,2,2]
*/

// My sol:
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <set>
#include <queue>
#include <set>
#include <utility>

using namespace std;

class Solution {
public:
    struct Compare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
            return (a.second < b.second) || (a.second == b.second && a.first < b.first);
        }
    };

    int equalPairs(vector<vector<int>>& grid) {
        int size = grid.size();
        multiset<pair<int, int>, Compare> cols, rows;  
        int count = 0;

        
        for (int i = 0; i < size; i++) {
            int row_sum = 0, col_sum = 0;
            for (int j = 0; j < size; j++) {
                row_sum += grid[i][j];
                col_sum += grid[j][i];
            }
            rows.emplace(i, row_sum);
            cols.emplace(i, col_sum);
        }

        
        for (auto it_row = rows.begin(); it_row != rows.end(); ++it_row) {
            for (auto it_col = cols.begin(); it_col != cols.end(); ++it_col) {
                if (it_row->second < it_col->second) break; 
                if (it_row->second > it_col->second) continue;  

                
                bool match = true;
                for (int k = 0; k < size; k++) {
                    if (grid[it_row->first][k] != grid[k][it_col->first]) {
                        match = false;
                        break;
                    }
                }
                if (match) count++;
            }
        }

        return count;
    }
};

// Behold The POWER of HASHMAP

#include <unordered_map>
class Solution {
public:

    struct VectorHash {
        size_t operator()(const std::vector<int>& v) const {
            size_t hash = 0;
            for (int num : v) {
                hash ^= std::hash<int>{}(num) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
            }
            return hash;
        }
    };
    int equalPairs(vector<vector<int>>& grid) {
        int size = grid.size();
        unordered_map<vector<int>, int, VectorHash> row_map;
        int count = 0;

     
        for (int i = 0; i < size; i++) {
            row_map[grid[i]]++;  
        }

     
        for (int j = 0; j < size; j++) {
            vector<int> col;
            for (int i = 0; i < size; i++) {
                col.push_back(grid[i][j]);  
            }
            count += row_map[col];
        }

        return count;
    }
};