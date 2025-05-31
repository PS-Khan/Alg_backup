/*
https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/description/?envType=daily-question&envId=2025-03-08
You are given a 0-indexed string blocks of length n, where blocks[i] is either 'W' or 'B', representing the color of the ith block. The characters 'W' and 'B' denote the colors white and black, respectively.

You are also given an integer k, which is the desired number of consecutive black blocks.

In one operation, you can recolor a white block such that it becomes a black block.

Return the minimum number of operations needed such that there is at least one occurrence of k consecutive black blocks.

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

using namespace std;


class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int j = 0, w = 0, res =INT_MAX;
        int s = blocks.length();
        for(int i = 0; i < s; i++){
            if(blocks[i] == 'B'){
                k--;
            }else{
                w++;
                k--;
            }
            if(k == 0){
                res = min(res,w);
            }else if(k < 0){
                if(blocks[j] == 'W'){
                    w--;
                    res = min(res,w);
                }
                k++;
                j++;
            }
        }
        
        return res;
    }
};