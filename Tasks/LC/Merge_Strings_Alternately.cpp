/*
You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

 

Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
Example 2:

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s
Example 3:

Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d
 
*/
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int min = std::min( word1.length(),word2.length() );
        std::string res((min*2), ' '); 
        for(int i  = 0; i < min; i++){
            if (i % 2 == 0) {
                res[i * 2] = word1[i];
                res[i * 2 + 1] = word2[i];
            } else {
                res[i * 2] = word1[i];
                res[i * 2 + 1] = word2[i];
            }
        }
        if (word1.length() > word2.length()) {
            res += word1.substr(min);
        } else {
            res += word2.substr(min);
        }
        return res;
    }
};