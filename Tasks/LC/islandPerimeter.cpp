

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

You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

*/
int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int perimeter = 0;

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 1) {
                    perimeter += 4; 
                    if (row > 0 && grid[row - 1][col] == 1) perimeter -= 2;
                    if (col > 0 && grid[row][col - 1] == 1) perimeter -= 2;
                }
            }
        }

        return perimeter;
    }


//This may be slower but i like my first approach for it will work even when we have multiple islands on map , 
//it will count perimeter only for 1 island and won`t iterate over each cell :
int islandPerimeter(vector<vector<int>>& grid) {
        std::queue<std::pair<int,int>> q;
        int rows = grid.size(), cols = grid[0].size();
        for( int row = 0; row < rows; row++){
            bool out = false;
            for(int col = 0; col < cols; col++){
                if(grid[row][col] == 1){
                    q.push({row,col});
                    out = true;
                    break;
                }
            }
            if(out){
                break;
            }
        }
        int P = 0;
        
        while(!q.empty()){
            std::pair<int,int> current = q.front();
            q.pop();
            int y = current.first , x = current.second ;
            grid[y][x] = 2;
            
            if(y+1 > rows && x+1 > cols){
                P+=2;
            }else{
                if(y+1 >= rows || grid[y+1][x] == 0){
                    P++;
                }else if(grid[y+1][x] == 1){
                    grid[y+1][x] = 2;
                    q.push({y+1, x});
                }

                if(x+1 >= cols || grid[y][x+1] == 0){
                    P++;
                }else if(grid[y][x+1] == 1){
                    grid[y][x+1] = 2;
                    q.push({y, x+1});
                }
            }
            
            
            if(y-1 < 0 && x-1 < 0 ){
                P+=2;
            }else{
                if(y-1 < 0 || grid[y-1][x] == 0){
                    P++;
                }else if( grid[y-1][x] == 1){
                    grid[y-1][x] = 2;
                    q.push({y-1,x});
                }
                
                if(x-1 < 0 || grid[y][x-1] == 0){
                    P++;
                }else if( grid[y][x-1] == 1){
                    grid[y][x-1] = 2;
                    q.push({y,x-1});
                }
            }

        }
        
        return P;

    }

