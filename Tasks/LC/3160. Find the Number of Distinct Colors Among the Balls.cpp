
/*
https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/description/?envType=daily-question&envId=2025-02-07

You are given an integer limit and a 2D array queries of size n x 2.

There are limit + 1 balls with distinct labels in the range [0, limit]. Initially, all balls are uncolored. For every query in queries that is of the form [x, y], you mark ball x with the color y. After each query, you need to find the number of distinct colors among the balls.

Return an array result of length n, where result[i] denotes the number of distinct colors after ith query.

Note that when answering a query, lack of a color will not be considered as a color.

 

Example 1:

Input: limit = 4, queries = [[1,4],[2,5],[1,3],[3,4]]

Output: [1,2,2,3]
*/


#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <set>
using namespace std;


//my sol // Time Limit Exceeded

class Solution {
public:
    int check (const unordered_map<int,int> b){
        std::set<int> s;
        for (const auto& [key, value] : b) { 
            s.emplace(value);
        }
        return s.size();
    }
    vector<int> queryResults(int limit, vector<vector<int>>& q) {
        unordered_map<int,int> b;
        vector<int> res;
        int size = q.size();
        for(int i = 0 ; i < size; i++ ){
            int x = q[i][0];
            int y = q[i][1];

            b[x] = y;
            res.emplace_back(check(b));
        }
        return res;
    }
   
};


// best sol
   vector<int> queryResults(int limit, vector<vector<int>>& q) {
        unordered_map<int, int> b; 
        unordered_map<int, int> value_count; 
        vector<int> res;
        
        for (const auto& query : q) {
            int x = query[0];
            int y = query[1];

            if (b.find(x) != b.end()) { 
                int old_value = b[x]; 

             
                if (--value_count[old_value] == 0) {
                    value_count.erase(old_value);
                }
            }

          
            b[x] = y;
            value_count[y]++; 
            
            res.emplace_back(value_count.size()); 
        }

        return res;

    }

//Editorial
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> result(n);
        unordered_map<int, int> colorMap;
        vector<int> ballArray(limit + 1);

        // Iterate through queries
        for (int i = 0; i < n; i++) {
            // Extract ball label and color from query
            int ball = queries[i][0], color = queries[i][1];

            // Check if ball is already colored
            if (ballArray[ball] != 0) {
                // Decrement count of the previous color on the ball
                int prevColor = ballArray[ball];
                colorMap[prevColor]--;

                // If there are no balls with previous color left, remove color
                // from color map
                if (colorMap[prevColor] == 0) colorMap.erase(prevColor);
            }
            // Set color of ball to the new color
            ballArray[ball] = color;

            // Increment the count of the new color
            colorMap[color]++;

            result[i] = colorMap.size();
        }
        return result;
    }
};

//2
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> result(n);
        unordered_map<int, int> colorMap, ballMap;

        // Iterate through queries
        for (int i = 0; i < n; i++) {
            // Extract ball label and color from query
            int ball = queries[i][0], color = queries[i][1];

            // Check if ball is already covered
            if (ballMap.find(ball) != ballMap.end()) {
                // Decrement count of the previous color on the ball
                int prevColor = ballMap[ball];
                colorMap[prevColor]--;

                // If there are no balls with previous color left, remove color
                // from color map
                if (colorMap[prevColor] == 0) colorMap.erase(prevColor);
            }
            // Set color of ball to the new color
            ballMap[ball] = color;

            // Increment the count of the new color
            colorMap[color]++;

            result[i] = colorMap.size();
        }

        return result;
    }
};