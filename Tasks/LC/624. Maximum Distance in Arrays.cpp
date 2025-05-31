/*
You are given m arrays, where each array is sorted in ascending order.

You can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a - b|.

Return the maximum distance.

https://leetcode.com/problems/maximum-distance-in-arrays/description/?envType=daily-question&envId=2024-08-16
*/


#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int min = std::numeric_limits<int>::max();
        int max = std::numeric_limits<int>::min();
        
        bool same = false;
        int same_index = 0;
        for(int i = 0; i < arrays.size(); ++i){
            int size = arrays[i].size();

            if(arrays[i][0] < min && arrays[i][size-1] > max){
                same = true;
                same_index = i;
            }else if(same && arrays[i][0] > min && arrays[i][size-1] < max ){
                same = true;
            }else{
                same = false;
            }

            min = std::min(arrays[i][0],min);
            max = std::max(arrays[i][size-1],max);

            
        }
        if(!same){
            return std::abs(max-min);
        }
        int res = std::numeric_limits<int>::min();
        for(int i = 0; i < arrays.size(); ++i){
            int size = arrays[i].size();
            if(i != same_index){
                res = std::max(res, std::abs(max-arrays[i][0]) );
                res = std::max(res, std::abs(min-arrays[i][size-1]) );
            }
        }
        std::cout<<"same";
        return res;


    }
};