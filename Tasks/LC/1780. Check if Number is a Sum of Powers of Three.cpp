/*
https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/description/?envType=daily-question&envId=2025-03-04

Given an integer n, return true if it is possible to represent n as the sum of distinct powers of three. Otherwise, return false.

An integer y is a power of three if there exists an integer x such that y == 3x.

 
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
    bool checkPowersOfThree(int n) { return checkPowersOfThreeHelper(0, n); }

private:
    bool checkPowersOfThreeHelper(int power, int n) {
        if (n == 0) return true;

        if (pow(3, power) > n) return false;

        
        bool addPower = checkPowersOfThreeHelper(power + 1, n - pow(3, power));

        
        bool skipPower = checkPowersOfThreeHelper(power + 1, n);

        
        return addPower || skipPower;
    }
};
//

class Solution {
public:
    bool checkPowersOfThree(int n) {
        int power = 0;

        // Find the largest power that is smaller or equal to n
        while (pow(3, power) <= n) {
            power++;
        }

        while (n > 0) {
            // Add current power to the sum
            if (n >= pow(3, power)) n -= pow(3, power);
            // We cannot use the same power twice
            if (n >= pow(3, power)) return false;
            // Move to the next power
            power--;
        }

        // n has reached 0
        return true;
    }
};

//

class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n > 0) {
            // Check if this power should be used twice
            if (n % 3 == 2) return false;

            // Divide n by 3 to move to the next greater power
            n /= 3;
        }

        // The ternary representation of n consists only of 0s and 1s
        return true;
    }
};