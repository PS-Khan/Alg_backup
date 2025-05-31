/*

A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

 https://leetcode.com/problems/count-good-numbers/description/?envType=daily-question&envId=2025-04-13
*/

// TLE 

class Solution {
public:
    int countGoodNumbers(long long n) {
        if(n == 1){
            return 5;
        }
        long long res = 1;
        for(long long i = 0; i < n - 1; i++){
            if (i % 2 == 0){
                res = (res*5) % (int(1e9) + 7);
            }else{
                res = (res* 4) % (int(1e9) + 7);
            }
        }
        if((n-1) % 2 == 0){
            res *= 5;
        }else{
            res *= 4;
        }

        return res % (int(1e9) + 7);
    }
};


//



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
    static constexpr int MOD = 1e9 + 7;

    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2; 
        long long oddCount = n / 2;     

        long long evenWays = modPow(5, evenCount, MOD);
        long long oddWays = modPow(4, oddCount, MOD);

        return (evenWays * oddWays) % MOD;
    }
};
