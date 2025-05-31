
/*
https://leetcode.com/problems/construct-smallest-number-from-di-string/description/?envType=daily-question&envId=2025-02-18
You are given a 0-indexed string pattern of length n consisting of the characters 'I' meaning increasing and 'D' meaning decreasing.

A 0-indexed string num of length n + 1 is created using the following conditions:

num consists of the digits '1' to '9', where each digit is used at most once.
If pattern[i] == 'I', then num[i] < num[i + 1].
If pattern[i] == 'D', then num[i] > num[i + 1].
Return the lexicographically smallest possible string num that meets the conditions.

 

Example 1:

Input: pattern = "IIIDIDDD"
Output: "123549876"
Explanation:
At indices 0, 1, 2, and 4 we must have that num[i] < num[i+1].
At indices 3, 5, 6, and 7 we must have that num[i] > num[i+1].
Some possible values of num are "245639871", "135749862", and "123849765".
It can be proven that "123549876" is the smallest possible num that meets the conditions.
Note that "123414321" is not possible because the digit '1' is used more than once.
Example 2:

Input: pattern = "DDD"
Output: "4321"
Explanation:
Some possible values of num are "9876", "7321", and "8742".
It can be proven that "4321" is the smallest possible num that meets the conditions.
 

Constraints:

1 <= pattern.length <= 8
pattern consists of only the letters 'I' and 'D'.
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
    bool s(string &p, string &num, vector<bool> &used){
        if(num.length() ==  p.length()+1){
            return true;
        }

        for(int i = 1; i <= 9; i++){
            if(used[i]){
                continue;
            }

            if(!num.empty()){
                char l = num.back();
                if(p[num.length()-1] == 'D' && l <= ('0'+ i)){
                    continue;
                }
                else if( p[num.length()-1] == 'I' && l >= ('0' + i)){
                    continue;
                }
            }
            num.push_back('0'+ i);
            used[i] = true;

            if (s(p, num, used)) return true; 
            num.pop_back();
            used[i] = false;

        }
        return false;
    }
    string smallestNumber(string pattern) {
        string num;
        vector<bool> used(10, false);
        s(pattern,  num, used);
        return num;
    }
};


//
class Solution {
public:
    // Check if the current sequence matches the pattern of 'I' and 'D'
    bool check(string &sequence, string &pattern) {
        for (int patternIndex = 0; patternIndex < pattern.size();
             patternIndex++) {
            if (pattern[patternIndex] == 'I') {
                // Ensure the sequence is in increasing order at 'I' positions
                if (sequence[patternIndex] > sequence[patternIndex + 1])
                    return false;
            } else {
                // Ensure the sequence is in decreasing order at 'D' positions
                if (sequence[patternIndex] < sequence[patternIndex + 1])
                    return false;
            }
        }
        return true;
    }

    string smallestNumber(string pattern) {
        int patternLength = pattern.size();
        string sequence = "";

        // Create a sequence of numbers from 1 to n+1
        for (int number = 1; number <= 1 + patternLength; number++) {
            sequence.push_back(number + '0');
        }

        string permutation = sequence;

        // Keep finding the next permutation until it matches the pattern
        while (!check(permutation, pattern)) {
            next_permutation(permutation.begin(), permutation.end());
        }

        return permutation;
    }
};

//

class Solution {
public:
    string smallestNumber(string pattern) {
        return to_string(findSmallestNumber(pattern, 0, 0, 0));
    }

private:
    // Recursively find the smallest number that satisfies the pattern
    int findSmallestNumber(string pattern, int currentPosition,
                           int usedDigitsMask, int currentNum) {
        // Base case: return the current number when the whole pattern is
        // processed
        if (currentPosition > pattern.size()) return currentNum;

        int result = INT_MAX;
        int lastDigit = currentNum % 10;
        bool shouldIncrement =
            currentPosition == 0 || pattern[currentPosition - 1] == 'I';

        // Try all possible digits (1 to 9) that are not yet used and follow the
        // pattern
        for (int currentDigit = 1; currentDigit <= 9; ++currentDigit) {
            if ((usedDigitsMask & 1 << currentDigit) == 0 &&
                currentDigit > lastDigit == shouldIncrement)
                result = min(result, findSmallestNumber(
                                         pattern, currentPosition + 1,
                                         usedDigitsMask | 1 << currentDigit,
                                         currentNum * 10 + currentDigit));
        }

        return result;
    }
};

//

class Solution {
public:
    string smallestNumber(string pattern) {
        string result = "";

        // Start building the sequence by calling the helper function
        buildSequence(0, 0, pattern, result);
        // Reverse the final result
        reverse(result.begin(), result.end());
        return result;
    }

    // Recursively build the sequence
    int buildSequence(int currentIndex, int currentCount, string pattern,
                      string& result) {
        if (currentIndex != pattern.size()) {
            if (pattern[currentIndex] == 'I')
                // If 'I', increment the count and move to the next index
                buildSequence(currentIndex + 1, currentIndex + 1, pattern,
                              result);
            else
                // If 'D', keep the count and move to the next index
                currentCount = buildSequence(currentIndex + 1, currentCount,
                                             pattern, result);
        }

        result += to_string(currentCount + 1);
        // Return the next count for the sequence
        return currentCount + 1;
    }
};
//

class Solution {
public:
    string smallestNumber(string pattern) {
        string result;
        stack<int> numStack;

        // Iterate through the pattern
        for (int index = 0; index <= pattern.size(); index++) {
            // Push the next number onto the stack
            numStack.push(index + 1);

            // If 'I' is encountered or we reach the end, pop all stack elements
            if (index == pattern.size() || pattern[index] == 'I') {
                while (!numStack.empty()) {
                    result += to_string(numStack.top());
                    numStack.pop();
                }
            }
        }

        return result;
    }
};

//

class Solution {
public:
    string smallestNumber(string pattern) {
        string result;

        // Iterate through the pattern and build the result
        for (int currentIndex = 0, previousIndex = 0;
             currentIndex <= pattern.length(); ++currentIndex) {
            result += to_string(1 + currentIndex);

            // Reverse the substring starting from previousIndex when necessary
            if (currentIndex == pattern.length() ||
                pattern[currentIndex] == 'I') {
                reverse(result.begin() + previousIndex, result.end());
                previousIndex = currentIndex + 1;
            }
        }

        return result;
    }
};
//

class Solution {
public:
    string smallestNumber(string pattern) {
        int patternLength = pattern.length();
        int maxSoFar = 0, currMax = 0, temp;

        // Array to store lengths of decreasing subsequences in the pattern
        vector<int> arrD(patternLength + 1, 0);

        // Compute the lengths of decreasing subsequences in the pattern
        for (int patternIndex = patternLength - 1; patternIndex >= 0;
             patternIndex--) {
            if (pattern[patternIndex] == 'D')
                // If 'D', increment the length of the decreasing sequence
                arrD[patternIndex] = arrD[patternIndex + 1] + 1;
        }

        string result = "";

        // Build the result string based on the pattern
        for (int position = 0; position <= patternLength; position++) {
            if (pattern[position] == 'I') {
                // If 'I', assign the next maximum digit and append it to the
                // result
                maxSoFar++;
                result += '0' + maxSoFar;

                // Update the max digit encountered so far
                maxSoFar = max(maxSoFar, currMax);

                // Reset current max for the next iteration
                currMax = 0;
            } else {
                // If 'D', calculate the appropriate digit and append it to the
                // result
                temp = 1 + maxSoFar + arrD[position];
                result += '0' + temp;

                // Update the current max value
                currMax = max(currMax, temp);
            }
        }

        return result;
    }
};