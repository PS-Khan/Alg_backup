/*

Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

 

Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
Example 3:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.
*/

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <unordered_map>
#include <numeric>
using namespace std;


//first attempt as usual too slow.

int maxVowels(std::string s, int k) {
        int res = 0;
        for (int i = 0; i + k - 1 < s.length(); i++) {
            int tmp = 0;
            for (int j = i; j < i + k; j++) {
                if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') {
                    tmp++;
                    if(tmp == k){
                        return k;
                    }
                }
            }
            res = std::max(res, tmp);
        }
        return res;}

//ok , not much harder than firts try

 
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(std::string s, int k) {
        int maxc = 0;
        int cc = 0;
        for (int i = 0; i < k; ++i) {
            if (isVowel(s[i]))
                cc++;
        }
        maxc = cc;
        for (int i = k; i < s.length(); ++i) {
            if (isVowel(s[i]))
                cc++;
            if (isVowel(s[i - k]))
                cc--;

            maxc = std::max(maxc, cc);
        }

        return maxc;
    }