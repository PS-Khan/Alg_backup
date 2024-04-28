

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
/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 
*/
//didnt pass timelimit 39/49
int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        std::queue<std::pair<int,int>> q;
        for(int i = 0; i<rows;  i++){
            for(int j =0; j < cols ;j++){
                if(grid[i][j] == '1'){
                    grid[i][j] = '2';
                    count++;
                    q.push({i,j});
                    while(!q.empty()){
                        std::pair<int,int> current = q.front();
                        q.pop();
                        int row = current.first, col = current.second;
                        grid[row][col] = '2';
                        if(row+1 < rows && grid[row+1][col] == '1'){
                            q.push({row+1,col});
                           
                        }
                        if(row-1 >= 0 && grid[row-1][col] == '1'){
                            q.push({row-1,col});
                           
                        }
                        if(col-1 >= 0 && grid[row][col-1] == '1'){
                            q.push({row,col-1});
                           
                        }
                        if(col+1 < cols && grid[row][col+1] == '1'){
                            q.push({row,col+1});
                        }
                    }



                }
            }
        }
        return count;
    }

//Ok , why dfs faster than bfs?maybe because no queue
int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j, rows, cols);
                }
            }
        }

        return count;
    }

    void dfs(vector<vector<char>>& grid, int row, int col, int rows, int cols) {
        if (row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] != '1') {
            return;
        }

        grid[row][col] = '2'; 

        
        dfs(grid, row + 1, col, rows, cols); 
        dfs(grid, row - 1, col, rows, cols); 
        dfs(grid, row, col + 1, rows, cols); 
        dfs(grid, row, col - 1, rows, cols); 
    }