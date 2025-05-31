/*
https://leetcode.com/problems/find-the-highest-altitude/description/

There is a biker going on a road trip. The road trip consists of n + 1 points 
at different altitudes. The biker starts his trip on point 0 with altitude equal 0.

You are given an integer array gain of length n where gain[i] is
 the net gain in altitude between points i​​​​​​ and i + 1 for all (0 <= i < n). Return the highest altitude of a point.

ample 1:

Input: gain = [-5,1,5,0,-7]
Output: 1
Explanation: The altitudes are [0,-5,-4,1,1,-6]. The highest is 1.
Example 2:

Input: gain = [-4,-3,-2,-1,4,3,2]
Output: 0
Explanation: The altitudes are [0,-4,-7,-9,-10,-6,-3,-1]. The highest is 0.
 

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
#include<string>
using namespace std;


int largestAltitude(vector<int>& gain) {
        int step = 0, res  = 0;
        for(int &i : gain){
            step+=i;
            res = std::max(res, step);
        }
        return res;
    }

#include <numeric>
int largestAltitude(vector<int>& gain) {
    int step = 0, res  = 0;
    std::accumulate(gain.begin(), gain.end(), 0 , [&](int a, int b){
        step += b;
        res = max(res,step);
        return b;
    });
    return res;
}