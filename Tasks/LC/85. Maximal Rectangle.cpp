/*
https://leetcode.com/problems/maximal-rectangle/description/

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
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

using namespace std;


//... 54/74:
/*
failed on
[["1","1","1","1","1","1","1","1"],
 ["1","1","1","1","1","1","1","0"],
 ["1","1","1","1","1","1","1","0"],
 ["1","1","1","1","1","0","0","0"],
 ["0","1","1","1","1","0","0","0"]]

problem in that cutting, i think.
 if(hold != 0 && hold > h){
    t_c -= (hold - h); 
}else if(hold != 0 && hold < h){
    t_c -= (h - hold); 
    h = hold;
}
hold = h;
*/
int maximalRectangle(vector<vector<char>>& matrix) {
        int count = 0;
        int rows = matrix.size();
        int cols  = matrix[0].size();
        vector<vector<bool>> visited(rows, std::vector<bool>(cols,false));
        for(int row = 0; row < rows ; row++){//1
            for(int col = 0; col < cols ; col++){//2

                if(matrix[row][col] == '1' && !visited[row][col]){
                    int t_c = 0, hold = 0;
                    for(int t_col = col; t_col < cols ; t_col++){
                        if(matrix[row][t_col] != '1' || visited[row][t_col]){
                          break;
                        }
                        int h = 0;
                        for(int t_row = row; t_row < rows ; t_row++){
                            if(matrix[t_row][t_col] == '1' && !visited[t_row][t_col]){
                                t_c++;
                                h++;
                                if(t_col+1 < cols && matrix[t_row][t_col+1] == '0' ){
                                    visited[t_row][t_col] = true;
                                }
                            }else{
                                break;
                            }
                            
                        }
                        if(hold != 0 && hold > h){
                            t_c -= (t_col - col)*(hold - h); 
                        }else if(hold != 0 && hold < h){
                            t_c -= (t_col - col)*(h - hold); 
                            h = hold;
                        }
                        hold = h;
                        count = max(count, t_c);

                    }

                }

            }
        }
        
        return count;
    }



//2

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> heights(cols, 0);
    int maxArea = 0;

    for (int row = 0; row < rows; row++) {
        
        for (int col = 0; col < cols; col++) {
            if (matrix[row][col] == '1') {
                heights[col]++;
            } else {
                heights[col] = 0;
            }
        }
        
        
        stack<int> stk;
        for (int col = 0; col <= cols; col++) {
            while (!stk.empty() && (col == cols || heights[stk.top()] > heights[col])) {
                int h = stk.top();
                stk.pop();
                int w = stk.empty() ? col : col - stk.top() - 1;
                maxArea = max(maxArea, heights[h] * w);
            }
            stk.push(col);
        }
    }

    return maxArea;
}