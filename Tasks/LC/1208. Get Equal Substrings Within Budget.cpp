#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

/*
https://leetcode.com/problems/get-equal-substrings-within-budget/description/


You are given two strings s and t of the same length and an integer maxCost.

You want to change s to t. Changing the ith character of s to ith character of t costs |s[i] - t[i]| (i.e., the absolute difference between the ASCII values of the characters).

Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of t with a cost less than or equal to maxCost. If there is no substring from s that can be changed to its corresponding substring from t, return 0.

*/

// i solved it like this but this solution didnt pass all tests for some reason 25/37


class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int N = s.size();
        
        int maxLen = 0;
        int start = 0;
        int currCost = 0;
        int c = 0 ;
        for (int i = 0; i < N; i++) {
            currCost += abs(s[i] - t[i]);
            if(currCost > maxCost){
                if(abs(s[i] - t[i]) <= maxCost){
                    c = 1;
                    currCost = abs(s[i] - t[i]);
                }else{
                    c = 0;
                    currCost = 0;
                }
                
                
            }else{
                c++;
                maxLen = max(maxLen, c); 
            }
           
        }
        
        return maxLen;
    }
};


// right solution

int equalSubstring(string s, string t, int maxCost) {
        int N = s.size();
        
        int maxLen = 0;
        // Starting index of the current substring
        int start = 0;
        // Cost of converting the current substring in s to t
        int currCost = 0;
        
        for (int i = 0; i < N; i++) {
            // Add the current index to the substring
            currCost += abs(s[i] - t[i]);
            
            // Remove the indices from the left end till the cost becomes less than allowed
            while (currCost > maxCost) {
                currCost -= abs(s[start] - t[start]);
                start++;
            }
            
            maxLen = max(maxLen, i - start + 1);
        }
        
        return maxLen;
    }