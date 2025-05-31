//https://leetcode.com/problems/find-the-punishment-number-of-an-integer/description/?envType=daily-question&envId=2025-02-15


/*
Given a positive integer n, return the punishment number of n.

The punishment number of n is defined as the sum of the squares of all integers i such that:

1 <= i <= n
The decimal representation of i * i can be partitioned into contiguous substrings such that the sum of the integer values of these substrings equals i.
 

Example 1:

Input: n = 10
Output: 182
Explanation: There are exactly 3 integers i in the range [1, 10] that satisfy the conditions in the statement:
- 1 since 1 * 1 = 1
- 9 since 9 * 9 = 81 and 81 can be partitioned into 8 and 1 with a sum equal to 8 + 1 == 9.
- 10 since 10 * 10 = 100 and 100 can be partitioned into 10 and 0 with a sum equal to 10 + 0 == 10.
Hence, the punishment number of 10 is 1 + 81 + 100 = 182
Example 2:

Input: n = 37
Output: 1478
Explanation: There are exactly 4 integers i in the range [1, 37] that satisfy the conditions in the statement:
- 1 since 1 * 1 = 1. 
- 9 since 9 * 9 = 81 and 81 can be partitioned into 8 + 1. 
- 10 since 10 * 10 = 100 and 100 can be partitioned into 10 + 0. 
- 36 since 36 * 36 = 1296 and 1296 can be partitioned into 1 + 29 + 6.
Hence, the punishment number of 37 is 1 + 81 + 100 + 1296 = 1478
 

Constraints:

1 <= n <= 1000

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
    bool canPartition(string& s, int target, int index, int currentSum) {
        if (index == s.size()) {
            return currentSum == target; 
        }
        
        int num = 0;
        for (int j = index; j < s.size(); j++) {
            num = num * 10 + (s[j] - '0');  
            
            if (canPartition(s, target, j + 1, currentSum + num)) {
                return true;
            }
        }
        
        return false;
    }

    bool check(int i, int sqr) {
        string s = to_string(sqr);
        return canPartition(s, i, 0, 0);
    }
    int punishmentNumber(int n) {
        int res = 0;
        int sqr;
        for(int i = 0; i < n+1 ; i++){
            sqr = i*i;
            if(check(i,sqr)){
                res+=sqr;
            }
        }
        return res;
    }
};

//

class Solution {
public:
    bool findPartitions(int startIndex, int sum, string stringNum, int target,
                        vector<vector<int>>& memo) {

        if (startIndex == stringNum.size()) {
            return sum == target;
        }


        if (sum > target) return false;


        if (memo[startIndex][sum] != -1) return memo[startIndex][sum];

        bool partitionFound = false;

   
        for (int currentIndex = startIndex; currentIndex < stringNum.size();
             currentIndex++) {

            string currentString =
                stringNum.substr(startIndex, currentIndex - startIndex + 1);
                /*currentIndex - startIndex gives the zero-based difference (how far currentIndex         is        from   startIndex).substr requires a one-based length (how many characters to extract), so we add 1.*/
            int addend = stoi(currentString);


            partitionFound =
                partitionFound || findPartitions(currentIndex + 1, sum + addend,
                                                 stringNum, target, memo);
            if (partitionFound == true) return true;
        }


        return memo[startIndex][sum] = partitionFound;
    }

    int punishmentNumber(int n) {
        int punishmentNum = 0;

        for (int currentNum = 1; currentNum <= n; currentNum++) {
            int squareNum = currentNum * currentNum;
            string stringNum = to_string(squareNum);

            vector<vector<int>> memoArray(stringNum.size(),
                                          vector<int>(currentNum + 1, -1));

        
            if (findPartitions(0, 0, stringNum, currentNum, memoArray)) {
                punishmentNum += squareNum;
            }
        }
        return punishmentNum;
    }
};

//

class Solution {
public:
    bool canPartition(string stringNum, int target) {
        // Valid Partition Found
        if (stringNum == "" && target == 0) return true;

        // Invalid Partition Found
        if (target < 0) return false;

        // Recursively check all partitions for a valid partition
        for (int index = 0; index < stringNum.size(); index++) {
            string left = stringNum.substr(0, index + 1);
            string right = stringNum.substr(index + 1);
            int leftNum = stoi(left);

            if (canPartition(right, target - leftNum)) return true;
        }
        return false;
    }

    int punishmentNumber(int n) {
        int punishmentNum = 0;

        // Iterate through numbers in range [1, n]
        for (int currentNum = 1; currentNum <= n; currentNum++) {
            int squareNum = currentNum * currentNum;

            // Check if valid partition can be found and add squared number if
            // so
            if (canPartition(to_string(squareNum), currentNum)) {
                punishmentNum += squareNum;
            }
        }
        return punishmentNum;
    }
};

//

class Solution {
public:
    bool CanPartition(int num, int target) {
        // Invalid partition found
        if (target < 0 || num < target) {
            return false;
        }

        // Valid partition found
        if (num == target) {
            return true;
        }

        // Recursively check all partitions for a valid partition
        return CanPartition(num / 10, target - num % 10) ||
               CanPartition(num / 100, target - num % 100) ||
               CanPartition(num / 1000, target - num % 1000);
    }

    int punishmentNumber(int n) {
        int punishmentNum = 0;

        // Iterate through numbers in range [1, n]
        for (int currentNum = 1; currentNum <= n; currentNum++) {
            int squareNum = currentNum * currentNum;

            // Check if valid partition can be found and add squared number if
            // so
            if (CanPartition(squareNum, currentNum)) {
                punishmentNum += squareNum;
            }
        }
        return punishmentNum;
    }
};
