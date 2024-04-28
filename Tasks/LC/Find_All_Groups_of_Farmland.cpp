/*

You are given a 0-indexed m x n binary matrix land where a 0 represents a hectare of forested land and a 1 represents a hectare of farmland.

To keep the land organized, there are designated rectangular areas of hectares that consist entirely of farmland. These rectangular areas are called groups. No two groups are adjacent, meaning farmland in one group is not four-directionally adjacent to another farmland in a different group.

land can be represented by a coordinate system where the top left corner of land is (0, 0) and the bottom right corner of land is (m-1, n-1). Find the coordinates of the top left and bottom right corner of each group of farmland. A group of farmland with a top left corner at (r1, c1) and a bottom right corner at (r2, c2) is represented by the 4-length array [r1, c1, r2, c2].

Return a 2D array containing the 4-length arrays described above for each group of farmland in land. If there are no groups of farmland, return an empty array. You may return the answer in any order.

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
#include <string>
#include <numeric>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> res;
        vector<vector<bool>> visited(land.size(), vector<bool>(land[0].size(), false));
        int rows = land.size(), cols = land[0].size() ;

        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if (land[row][col] && !visited[row][col]) {
                    int row2 = 0 , col2 = 0;
                    dfs(land, visited, row, col, row2, col2);
                    res.push_back({row, col, row2, col2});
                }
            }
        }
        
        return res;
    }
private:
    int dirs[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    bool isWithinFarm(int x, int y, int N, int M) {
        return x >= 0 && x < N && y >= 0 && y < M;
    }
    void dfs(vector<vector<int>> &land, vector<vector<bool>> &visited, int row1, int col1, int& row2, int& col2){
        visited[row1][col1] = true;
        row2 = max(row2, row1); col2 = max(col2, col1);
        for (auto dir : dirs) {
            
            int newX = row1 + dir[0], newY = col1 + dir[1];
            if (isWithinFarm(newX, newY, land.size(), land[0].size()) && !visited[newX][newY]
                    && land[newX][newY]) {
                dfs(land, visited, newX, newY, row2, col2);
            }
        }

    }
};

//

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<bool>> visited(land.size(), vector<bool>(land[0].size(), false));
        vector<vector<int>> ans;
        
        for (int row1 = 0; row1 < land.size(); row1++) {
            for (int col1 = 0; col1 < land[0].size(); col1++) {
                if (land[row1][col1] && !visited[row1][col1]) {
                    queue<pair<int, int>> q;
                    q.push({row1, col1});
                    visited[row1][col1] = true;
                    
                    pair<int, int> last = BFS(q, land, visited, row1, col1);
                    ans.push_back({row1, col1, last.first, last.second});
                }
            }
        }
        
        return ans;
    }
private:    
   
    int dirs[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

   
    bool isWithinFarm(int x, int y, int N, int M) {
        return x >= 0 && x < N && y >= 0 && y < M;
    }
    
    pair<int, int> BFS(queue<pair<int, int>> q, vector<vector<int>>& land,
        vector<vector<bool>>& visited, int x, int y) {
        pair<int, int> curr;
        
        while (!q.empty()) {
            curr = q.front();
            q.pop();

            int x = curr.first;
            int y = curr.second;
            
            for (auto dir : dirs) {
            
                int newX = x + dir[0], newY = y + dir[1];

                
                if (isWithinFarm(newX, newY, land.size(), land[0].size()) && !visited[newX][newY]
                        && land[newX][newY]) {
                    visited[newX][newY] = true;
                    q.push({newX, newY});
                }
            }
        }
        
        return curr;
    }
};


class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int M = land.size(), N = land[0].size();
        vector<vector<int>> res;
        
        for (int row1 = 0; row1 < M; row1++) {
            for (int col1 = 0; col1 < N; col1++) {
                if (land[row1][col1]) {
                    int x = row1, y = col1;
                    
                    for (x = row1; x < M && land[x][col1]; x++) {
                        for (y = col1; y < N && land[x][y]; y++) {
                            land[x][y] = 0;
                        }
                    }

                    res.push_back({row1, col1, x - 1, y - 1});
                }
            }
        }
        return res;
    }
};