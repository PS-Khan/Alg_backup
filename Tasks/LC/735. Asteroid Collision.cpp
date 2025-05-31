/*
https://leetcode.com/problems/asteroid-collision/description/?envType=study-plan-v2&envId=leetcode-75

We are given an array asteroids of integers representing asteroids in a row. The indices of the asteriod in the array represent their relative position in space.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

*/

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
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int> st;
        for(int &i: a){
            if(i>0){
                st.push_back(i);
            }else if (i<0){
                while(!st.empty() && st.back()>0 && st.back()<abs(i)){
                    st.pop_back();
                }
                if(st.empty() || st.back()<0){
                    st.push_back(i);
                }else if(abs(i) == st.back()){
                    st.pop_back();
                }
            }
        }
        return st;
    }
};
