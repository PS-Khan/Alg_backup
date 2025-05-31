/*
https://leetcode.com/problems/determine-if-two-strings-are-close/description/

Two strings are considered close if you can attain one from the other using the following operations:

Operation 1: Swap any two existing characters.
For example, abcde -> aecdb
Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

*/


#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <memory.h>
#include <sstream>
#include <regex>

using namespace std;


class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int l1 = word1.length()-1;
        unordered_map<char, int> w1, w2;
        if(l1 != word2.length()-1){
            cout<<"not equal length";
            return false;
        }
        for (char ch : word1) {
            w1[ch]++;
        }
        for (char ch : word2) {
            w2[ch]++;
        }

        for (auto it = w1.begin(); it != w1.end(); ++it) {
            if (w2.find(it->first) == w2.end()) {
                cout<<"not same letters";
                return false;
            }
        }

        for (auto it = w1.begin(); it != w1.end(); ++it) {
            for (auto it2 = w2.begin(); it2 != w2.end(); ++it2) {
                if(it->second == it2->second){
                    it->second = -1;
                    it2->second = -1;
                    break;
                }
            }
            if(it->second != -1){
                return false;
            }
           
        }
        return true;



    }
};

//same but in dif style

bool closeStrings(std::string word1, std::string word2) {
        // Check if lengths are different
        if (word1.length() != word2.length()) {
            return false;
        }

        // Count frequency of characters in both words
        std::unordered_map<char, int> freq1, freq2;
        for (char ch : word1) {
            freq1[ch]++;
        }
        for (char ch : word2) {
            freq2[ch]++;
        }

        // Check if both words have the same set of characters
        if (freq1.size() != freq2.size()) {
            return false;
        }
        for (const auto& [key, _] : freq1) {
            if (freq2.find(key) == freq2.end()) {
                return false;
            }
        }

        // Compare frequency distributions
        std::vector<int> count1, count2;
        for (const auto& [_, value] : freq1) {
            count1.push_back(value);
        }
        for (const auto& [_, value] : freq2) {
            count2.push_back(value);
        }
        
        std::sort(count1.begin(), count1.end());
        std::sort(count2.begin(), count2.end());

        return count1 == count2;
    }

// optimized


bool closeStrings(std::string word1, std::string word2) {
        std::vector<int> freq1(26, 0);
        std::vector<int> freq2(26, 0);

        for (char ch : word1) {
            freq1[ch - 'a']++;
        }

        for (char ch : word2) {
            freq2[ch - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if ((freq1[i] == 0 && freq2[i] != 0) || (freq1[i] != 0 && freq2[i] == 0)) {
                return false;
            }
        }

        std::sort(freq1.begin(), freq1.end());
        std::sort(freq2.begin(), freq2.end());

        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) {
                return false;
            }
        }

        return true;
    }