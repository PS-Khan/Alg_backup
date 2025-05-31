

/*
https://leetcode.com/problems/decode-string/?envType=study-plan-v2&envId=leetcode-75

Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.
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

// my sol
class Solution {
public:
    string decodeString(string s) {
        string ans;
        if(s.find("[") == string::npos){
            return s;
        }
        
        for(int i = 0; i < s.length(); i++){
          string times, tmp;
          int ttimes = 0;
          if(!isdigit(s[i]) && s[i] !=']' && s[i] != '['){
            ans+=s[i];
          }else if(isdigit(s[i])){
            while(isdigit(s[i])){
                times+=s[i];
                i++;
            }
            i++;
            ttimes = stoi(times);
            int c = 1;
            while(c>0){
                if(s[i]==']'){
                    c--;
                    if(c == 0){
                        break;
                    }
                }else if(s[i]=='['){
                    c++;
                }
                tmp+=s[i];
                i++;
            }
            for(int j = 0; j < ttimes; j++){
                ans+=tmp;
            }
          }
        }
        return decodeString(ans);
        

    }
};