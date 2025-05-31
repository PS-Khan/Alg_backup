/*
https://leetcode.com/problems/closest-prime-numbers-in-range/description/?envType=daily-question&envId=2025-03-07

Given two positive integers left and right, find the two integers num1 and num2 such that:

left <= num1 < num2 <= right .
Both num1 and num2 are prime numbers.
num2 - num1 is the minimum amongst all other pairs satisfying the above conditions.
Return the positive integer array ans = [num1, num2]. If there are multiple pairs satisfying these conditions, return the one with the smallest num1 value. If no such numbers exist, return [-1, -1].
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

// how it accepted this) no TLE
class Solution {
public:
    bool  prime (int i){
        if (i < 2) return false;
        int tmp = sqrt(i);
        for(int j = 2; j <= tmp; j++){
            if(i%j == 0){
                return false;
            }
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> res(2,-1);
        int a = -1, b = -1;
        int m =INT_MAX;
        for(int i = left; i<=right; i++){
            if (prime(i)){
                if(a == -1){
                    a = i;
                }else if(b == -1){
                    b = i;
                    if(abs(a-b) < m){
                        res[0] = a;
                        res[1] = b;
                        m = abs(a-b);
                    }else if( abs(a-b) == m ){
                        if(res[0]>a){
                            res[0] = a;
                            res[1] = b;
                        }
                    }
                }else{
                    a = b;
                    b = i;
                    if(abs(a-b) < m){
                        res[0] = a;
                        res[1] = b;
                        m = abs(a-b);
                    }else if( abs(a-b) == m ){
                        if(res[0]>a){
                            res[0] = a;
                            res[1] = b;
                        }
                    }
                }
            }
        }
        return res;
    }
};

//