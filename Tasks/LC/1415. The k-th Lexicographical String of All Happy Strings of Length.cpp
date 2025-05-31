/*
https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/

A happy string is a string that:

consists only of letters of the set ['a', 'b', 'c'].
s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.

Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.

Return the kth string of this list or return an empty string if there are less than k happy strings of length n.

 

Example 1:

Input: n = 1, k = 3
Output: "c"
Explanation: The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".
Example 2:

Input: n = 1, k = 4
Output: ""
Explanation: There are only 3 happy strings of length 1.
Example 3:

Input: n = 3, k = 9
Output: "cab"
Explanation: There are 12 different happy string of length 3 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. You will find the 9th string = "cab"
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
   void backtrack(int n, int &k, string &curr, vector<string> &results) {
        if (curr.length() == n) { 
            results.push_back(curr);
            k--;
            return;
        }
        
        for (char ch : {'a', 'b', 'c'}) {
            if (curr.empty() || curr.back() != ch) { 
                curr.push_back(ch);
                backtrack(n, k, curr, results);
                if (k == 0) return; 
                curr.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        int totalStrings = 3 * (1 << (n - 1)); 
        if (k > totalStrings) return "";

        vector<string> results;
        string curr;
        backtrack(n, k, curr, results);
        
        return (k == 0) ? results.back() : ""; 
    }
};


//

class Solution {
public:
    string getHappyString(int n, int k) {
        string currentString = "";
        string result = "";
        int indexInSortedList = 0;

        // Generate happy strings and track the k-th string
        generateHappyStrings(n, k, currentString, indexInSortedList, result);
        return result;
    }

private:
    void generateHappyStrings(int n, int k, string &currentString,
                              int &indexInSortedList, string &result) {
        // If the current string has reached the desired length
        if (currentString.size() == n) {
            indexInSortedList++;  // Increment the count of generated strings

            // If this is the k-th string, store it in the result
            if (indexInSortedList == k) result = currentString;
            return;
        }

        // Try adding each character ('a', 'b', 'c') to the current string
        for (char currentChar = 'a'; currentChar <= 'c'; currentChar++) {
            // Skip if the current character is the same as the last one
            if (currentString.size() > 0 && currentString.back() == currentChar)
                continue;

            currentString += currentChar;

            // Recursively generate the next character
            generateHappyStrings(n, k, currentString, indexInSortedList,
                                 result);

            // If the result is found, stop further processing
            if (result != "") return;

            // Backtrack by removing the last character
            currentString.pop_back();
        }
    }
};

//

class Solution {
public:
    string getHappyString(int n, int k) {
        stack<string> stringsStack;
        int indexInSortedList = 0;
        stringsStack.push("");  // Start with an empty string

        while (stringsStack.size() > 0) {
            string currentString = stringsStack.top();
            stringsStack.pop();

            // If we have built a string of length n, count it
            if (currentString.size() == n) {
                indexInSortedList++;
                // If we reach the k-th happy string, return it
                if (indexInSortedList == k) {
                    return currentString;
                }
                continue;
            }

            // Expand the current string by adding 'a', 'b', or 'c'
            // Ensuring lexicographic order by pushing in reverse
            for (char currentChar = 'c'; currentChar >= 'a'; currentChar--) {
                // Avoid consecutive identical characters
                if (currentString.size() > 0 &&
                    currentString.back() == currentChar)
                    continue;
                stringsStack.push(currentString + currentChar);
            }
        }
        return "";
    }
};

//
class Solution {
public:
    string getHappyString(int n, int k) {
        // Calculate the total number of happy strings of length n
        int total = 3 * (1 << (n - 1));

        // If k is greater than the total number of happy strings, return an
        // empty string
        if (k > total) return "";

        string result(n, 'a');

        // Define mappings for the next smallest and greatest valid characters
        unordered_map<char, char> nextSmallest = {
            {'a', 'b'}, {'b', 'a'}, {'c', 'a'}};
        unordered_map<char, char> nextGreatest = {
            {'a', 'c'}, {'b', 'c'}, {'c', 'b'}};

        // Calculate the starting indices for strings beginning with 'a', 'b',
        // and 'c'
        int startA = 1;
        int startB = startA + (1 << (n - 1));
        int startC = startB + (1 << (n - 1));

        // Determine the first character based on the value of k
        if (k < startB) {
            result[0] = 'a';
            k -= startA;
        } else if (k < startC) {
            result[0] = 'b';
            k -= startB;
        } else {
            result[0] = 'c';
            k -= startC;
        }

        // Iterate through the remaining positions in the result string
        for (int charIndex = 1; charIndex < n; charIndex++) {
            // Calculate the midpoint of the group for the current character
            // position
            int midpoint = (1 << (n - charIndex - 1));

            // Determine the next character based on the value of k
            if (k < midpoint) {
                result[charIndex] = nextSmallest[result[charIndex - 1]];
            } else {
                result[charIndex] = nextGreatest[result[charIndex - 1]];
                k -= midpoint;
            }
        }

        return result;
    }
};