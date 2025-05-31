/*
https://leetcode.com/problems/best-sightseeing-pair/description/

You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.

The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.

Return the maximum score of a pair of sightseeing spots.
*/

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int res = 0;
        int size = values.size();

        for(int i = 0; i < size; ++i){
            for(int j = i+1; j < size ; ++j){
                res = max(res,values[i] + values[j] + i - j);
            }
        }

        return res;
       
    }
};

///2

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
    int max_i = values[0] + 0; 
    int max_score = 0;

    for (int j = 1; j < values.size(); ++j) {
       
        max_score = max(max_score, max_i + values[j] - j);

        
        max_i = max(max_i, values[j] + j);
    }
    return max_score;
}
};