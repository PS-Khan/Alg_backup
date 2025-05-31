/*
https://leetcode.com/problems/greatest-common-divisor-of-strings/description/

For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

 

Example 1:

Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
Example 2:

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
Example 3:

Input: str1 = "LEET", str2 = "CODE"
Output: ""
 

Constraints:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of English uppercase letters.
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string res;
        if(str1 == str2 ){
            return str1;
        }
        
        if(str1.substr(0, str2.length()) == str2 ){
            str1.erase(0, str2.length());
        }else if(str2.substr(0, str1.length()) == str1 ){
            str2.erase(0, str1.length());
        }else{
            return "";
        }
        res = gcdOfStrings(str1,  str2);
        return res;
       
       
        
        
    }
};