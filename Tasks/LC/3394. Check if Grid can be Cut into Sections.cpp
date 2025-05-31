/*

You are given an integer n representing the dimensions of an n x n grid, with the origin at the bottom-left corner of the grid. You are also given a 2D array of coordinates rectangles, where rectangles[i] is in the form [startx, starty, endx, endy], representing a rectangle on the grid. Each rectangle is defined as follows:

(startx, starty): The bottom-left corner of the rectangle.
(endx, endy): The top-right corner of the rectangle.
Note that the rectangles do not overlap. Your task is to determine if it is possible to make either two horizontal or two vertical cuts on the grid such that:

Each of the three resulting sections formed by the cuts contains at least one rectangle.
Every rectangle belongs to exactly one section.
Return true if such cuts can be made; otherwise, return false.

https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/?envType=daily-question&envId=2025-03-25

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


//TLE :(
class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int a = 0, b = 0;  
        int borderx = 0, bordery = 0;
        for (int i = 1; i < n; i++) { 
            bool x = true, y = true;
            bool hasrecx = false, hasrecy = false;
            bool hasrecxafter = false, hasrecyafter = false;
            for (const auto& rect : rectangles) {  
                int x1 = rect[0], y1 = rect[1], x2 = rect[2], y2 = rect[3];
                //Y cut
                if (y1 < i && i < y2) {  
                    y = false;
                }
                if(i >= y2 && y1 >= bordery){
                    hasrecy = true;
                }
                if(i < y2 && i <= y1){
                    hasrecyafter = true;
                }

                // X cut
                if (x1 < i && i < x2) { 
                    x = false;
                }
                if(i >= x2 && x1 >= borderx){
                    hasrecx = true;
                }
                if(i < x2 && i <= x1){
                    hasrecxafter = true;
                }
                if (!x && !y) break;
            }

            if (x && hasrecxafter && hasrecx ){
                a++;
                borderx = i;
            }  
            if (y && hasrecyafter && hasrecy){
                b++;
                bordery =i;
            } 
            if (a == 2 || b == 2) return true;  
        }

        return false;
    }
};


//

class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return checkCuts(rectangles, 0) || checkCuts(rectangles, 1);
    }

private:
    bool checkCuts(vector<vector<int>>& rectangles, int dim) {
        int gapCount = 0;
        sort(rectangles.begin(), rectangles.end(),
             [dim](const vector<int>& a, const vector<int>& b) {
                 return a[dim] < b[dim];
             });

        int furthestEnd = rectangles[0][dim + 2];

        for (size_t i = 1; i < rectangles.size(); i++) {
            vector<int>& rect = rectangles[i];

            if (furthestEnd <= rect[dim]) {
                gapCount++;
            }

            furthestEnd = max(furthestEnd, rect[dim + 2]);
        }

        return gapCount >= 2;
    }
};