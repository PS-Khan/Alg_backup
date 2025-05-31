/*
There is a forest with an unknown number of rabbits. We asked n rabbits "How many rabbits have the same color as you?" and collected the answers in an integer array answers where answers[i] is the answer of the ith rabbit.

Given the array answers, return the minimum number of rabbits that could be in the forest.
*/


// my sol 1 try.



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
#include <functional>

using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& ans) {
        unordered_map<int,int> freq;
        int size = ans.size();
        int res = 0;
        for(int i = 0; i < size; ++i){
            freq[ans[i]]++;
        }
        for (const auto& pair : freq){
            if(pair.first == 0){
                res += pair.second;
                continue;
            }
            if(pair.first == pair.second-1){
                res += pair.second;
                continue;
            }
            if(pair.second > pair.first+1){
                int x = pair.first+1;
                int dx = x;
                while(pair.second > x ){
                    x += dx;
                }
                res+=x;
            }
            if(pair.second < pair.first+1){
                res+= pair.first+1;
            }
        }

        return res;
    }
};