/*
https://leetcode.com/problems/2-keys-keyboard/description/?envType=daily-question&envId=2024-08-19


There is only one character 'A' on the screen of a notepad. You can perform one of two operations on this notepad for each step:

Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
Given an integer n, return the minimum number of operations to get the character 'A' exactly n times on the screen.

*/


#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <set>
#include <unordered_set>
using namespace std;


class Solution {
    int n;

public:
    int minSteps(int n) {
        if (n == 1) return 0;
        this->n = n;
        // first step is always a Copy All operation
        return 1 + minStepsHelper(1, 1);
    }

private:
    int minStepsHelper(int currLen, int pasteLen) {
        // base case: reached n A's, don't need more operations
        if (currLen == n) return 0;
        // base case: exceeded n `A`s, not a valid sequence, so
        // return max value
        if (currLen > n) return 1000;

        // copy all + paste
        int opt1 = 2 + minStepsHelper(currLen * 2, currLen);
        // paste
        int opt2 = 1 + minStepsHelper(currLen + pasteLen, pasteLen);

        return min(opt1, opt2);
    }
};


//

class Solution {
public:
    int n;
    vector<vector<int>> memo;

    int minSteps(int n) {
        if (n == 1) return 0;
        this->n = n;

        memo = vector<vector<int>>(n + 1, vector<int>(n / 2 + 1, 0));
        return 1 + minStepsHelper(1, 1);
    }

    int minStepsHelper(int currLen, int pasteLen) {
        if (currLen == n) return 0;
        if (currLen > n) return 1000;

        // return result if it has been calculated already
        if (memo[currLen][pasteLen] != 0) return memo[currLen][pasteLen];

        int opt1 = 1 + minStepsHelper(currLen + pasteLen, pasteLen);
        int opt2 = 2 + minStepsHelper(currLen * 2, currLen);
        memo[currLen][pasteLen] = min(opt1, opt2);
        return memo[currLen][pasteLen];
    }
};


//

class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, 1000);

        // Base case
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i / 2; j++) {
                // Copy All and Paste (i-j) / j times
                // for all valid j's
                if (i % j == 0) {
                    dp[i] = min(dp[i], dp[j] + i / j);
                }
            }
        }

        return dp[n];
    }
};

//

class Solution {
public:
    int minSteps(int n) {
        int ans = 0;
        int d = 2;
        while (n > 1) {
            // If d is prime factor, keep dividing
            // n by d until is no longer divisible
            while (n % d == 0) {
                ans += d;
                n /= d;
            }
            d++;
        }
        return ans;
    }
};