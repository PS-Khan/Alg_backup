/*
https://leetcode.com/problems/custom-sort-string/description/


You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.

Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.

Return any permutation of s that satisfies this property.

 

Example 1:

Input:  order = "cba", s = "abcd" 

Output:  "cbad" 

Explanation: "a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a".

Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.

Example 2:

Input:  order = "bcafg", s = "abcd" 

Output:  "bcad" 

Explanation: The characters "b", "c", and "a" from order dictate the order for the characters in s. The character "d" in s does not appear in order, so its position is flexible.

Following the order of appearance in order, "b", "c", and "a" from s should be arranged as "b", "c", "a". "d" can be placed at any position since it's not in order. The output "bcad" correctly follows this rule. Other arrangements like "bacd" or "bcda" would also be valid, as long as "b", "c", "a" maintain their order.

 

Constraints:

1 <= order.length <= 26
1 <= s.length <= 200
order and s consist of lowercase English letters.
All the characters of order are unique.

*/


#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;
//1
class Solution {
public:
    string customSortString(string order, string s) {
        std::vector<std::pair<char, int>> arr(30, {'A', 0}); // Initialize with 30 elements

        for (char ch : s) {
            arr[ch - 'a' + 1] = {ch, arr[ch - 'a' + 1].second + 1};
        }

        std::string res, rest;

        for (char ch : order) {
            if (arr[ch - 'a' + 1].first == ch) {
                for (int i = 0; i < arr[ch - 'a' + 1].second; i++) {
                    res += ch;
                }
            }else{
                rest+=ch;
            }
        }

        res+=rest;

        return res;

    }
};

//1.2

string customSortString1_2(string order, string s) {
        std::vector<std::pair<char, int>> arr(30, {'A', 0}); // Initialize with 30 elements

        for (char ch : s) {
            arr[ch - 'a' + 1] = {ch, arr[ch - 'a' + 1].second + 1};
        }

        std::string res, rest;

        for (char ch : order) {
            if (arr[ch - 'a' + 1].first == ch) {
                for (int i = 0; i < arr[ch - 'a' + 1].second; i++) {
                    res += ch;
                }
                arr[ch - 'a' + 1] = {'A',0};
            }
        }
        for(auto &ch : arr){
            for (int i = 0; i < ch.second; i++) {
                res += ch.first;
            }
        }

        return res;

    }

//2
string customSortString2(string order, string s) {
        string res;

        for (char &ch : order) {
            while(s.find(ch) != std::string::npos){
                res += ch;
                s.erase(s.find(ch),1);
            }
        }
        for (char &ch : s){
            res+=ch;
        }
       

        return res;

    }