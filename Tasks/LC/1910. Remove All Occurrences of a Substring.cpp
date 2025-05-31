
/*
https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/?envType=daily-question&envId=2025-02-11

Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

Find the leftmost occurrence of the substring part and remove it from s.
Return s after removing all occurrences of part.

A substring is a contiguous sequence of characters in a string.

 

Example 1:

Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"
Explanation: The following operations are done:
- s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
- s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
- s = "dababc", remove "abc" starting at index 3, so s = "dab".
Now s has no occurrences of "abc".
Example 2:

Input: s = "axxxxyyyyb", part = "xy"
Output: "ab"
Explanation: The following operations are done:
- s = "axxxxyyyyb", remove "xy" starting at index 4 so s = "axxxyyyb".
- s = "axxxyyyb", remove "xy" starting at index 3 so s = "axxyyb".
- s = "axxyyb", remove "xy" starting at index 2 so s = "axyb".
- s = "axyb", remove "xy" starting at index 1 so s = "ab".
Now s has no occurrences of "xy".
 

Constraints:

1 <= s.length <= 1000
1 <= part.length <= 1000
s​​​​​​ and part consists of lowercase English letters.

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

//my sol

class Solution {
public:
    string removeOccurrences(string s, string part) {
        int size = s.length(), p_size = part.length();
        if(p_size>size){
            return s;
        }
        int i = 0;
        
        while(i < s.length()){
            bool er = true;
            int tmp = 0;
            for(int j = i; j < size && j < (p_size + i); j++){
                if(s[j] != part[tmp]){
                    er = false;
                    break;
                }
                tmp++;
            } 
            if(er){
                s.erase(i,p_size);
                
                i = max(0, i - p_size);// +1?
                
            }else{
                i++;
            }          
            
        }
        return s;
    }
};

//

class Solution {
public:
    string removeOccurrences(string s, string part) {
        int p_size = part.length();
        
        while (s.find(part) != string::npos) {
            s.erase(s.find(part), p_size);
        }
        
        return s;
    }
};

//
string removeOccurrences(string s, string part) {
    string res; 
    int part_size = part.size();

    for (char c : s) {
        res.push_back(c);

    
        if (res.size() >= part_size && res.substr(res.size() - part_size) == part) {
            res.erase(res.size() - part_size);
        }
    }

    return res;
}

//Approach 3: Knuth-Morris-Pratt (KMP) Algorithm

class Solution {
public:
    string removeOccurrences(string s, string part) {
        // Precompute KMP longest prefix-suffix array for the pattern
        vector<int> kmpLPS = computeLongestPrefixSuffix(part);

        // Using stack to track characters and support pattern matching
        stack<char> charStack;

        // Array to store pattern matching indices during traversal
        vector<int> patternIndexes(s.length() + 1, 0);

        for (int strIndex = 0, patternIndex = 0; strIndex < s.length();
             strIndex++) {
            char currentChar = s[strIndex];
            charStack.push(currentChar);

            if (currentChar == part[patternIndex]) {
                // Track the next pattern index when characters match
                patternIndexes[charStack.size()] = ++patternIndex;

                if (patternIndex == part.length()) {
                    // Remove entire matched pattern from stack
                    int remainingLength = part.length();
                    while (remainingLength != 0) {
                        charStack.pop();
                        remainingLength--;
                    }

                    // Restore pattern index for next potential match
                    patternIndex = charStack.empty()
                                       ? 0
                                       : patternIndexes[charStack.size()];
                }
            } else {
                if (patternIndex != 0) {
                    // Backtrack pattern matching using KMP LPS
                    strIndex--;
                    patternIndex = kmpLPS[patternIndex - 1];
                    charStack.pop();
                } else {
                    // Reset pattern index tracking when no match is possible
                    patternIndexes[charStack.size()] = 0;
                }
            }
        }

        // Convert remaining stack characters to result string
        string result = "";
        while (!charStack.empty()) {
            result = charStack.top() + result;
            charStack.pop();
        }

        return result;
    }

private:
    vector<int> computeLongestPrefixSuffix(string pattern) {
        // Array to store the longest proper prefix which is also a suffix
        vector<int> lps(pattern.length(), 0);

        // Initialize tracking variables for prefix and current position
        for (int current = 1, prefixLength = 0; current < pattern.length();) {
            // If characters match, extend the prefix length
            if (pattern[current] == pattern[prefixLength]) {
                // Store the length of matching prefix
                lps[current] = ++prefixLength;
                current++;
            }
            // If characters don't match and we're not at the start of the
            // pattern
            else if (prefixLength != 0) {
                // Backtrack to the previous longest prefix-suffix
                prefixLength = lps[prefixLength - 1];
            }
            // If no match and no prefix to backtrack
            else {
                // No prefix-suffix match found
                lps[current] = 0;
                current++;
            }
        }

        // Return the computed longest prefix-suffix array
        return lps;
    }
};