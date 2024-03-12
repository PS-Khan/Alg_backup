/*
Given two strings ransomNote and magazine, return true if ransomNote can be constructed
by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
*/
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int mNote[26] = {0};
        for (auto &ch : magazine ){
            mNote[ch - 'a']++;
        }
        for (auto &ch : ransomNote ){
            if(isalpha(ch) && mNote[ch - 'a'] > 0){
                mNote[ch - 'a']--;
            }else{
                return false;
            }
        }
        return true;
        
    }
};