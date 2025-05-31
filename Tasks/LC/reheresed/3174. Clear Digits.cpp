/*
https://leetcode.com/problems/clear-digits/description/?envType=daily-question&envId=2025-02-10
You are given a string s.

Your task is to remove all digits by doing this operation repeatedly:

Delete the first digit and the closest non-digit character to its left.
Return the resulting string after removing all digits.

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
    string clearDigits(string s) {
        stack<char> q;
        for(char &c: s){
            if(!q.empty() && isdigit(c)){
                q.pop();
            }
            else{
                q.push(c);
            }
        }
        string c;
        while (!q.empty()) {
            c.push_back(q.top()); 
            q.pop();              
        }

    
        reverse(c.begin(), c.end());
        return c;
    }
};
//

class Solution {
public:
    string clearDigits(string s) {
        string answer;

        // Iterate over each character in the input string
        for (int charIndex = 0; charIndex < s.size(); charIndex++) {
            // If the current character is a digit
            if (isdigit(s[charIndex]) && !answer.empty()) {
                // If the answer string is not empty, remove the last character
                answer.pop_back();
            } else {
                // If the character is not a digit, add it to the answer string
                answer += s[charIndex];
            }
        }

        return answer;
    }
};