/*
https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/description/?envType=daily-question&envId=2025-03-10


You are given a string word and a non-negative integer k.

Return the total number of substrings of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once and exactly k consonants.

 

Example 1:

Input: word = "aeioqq", k = 1

Output: 0

Explanation:

There is no substring with every vowel.

Example 2:

Input: word = "aeiou", k = 0

Output: 1

Explanation:

The only substring with every vowel and zero consonants is word[0..4], which is "aeiou".

Example 3:

Input: word = "ieaouqqieaouqq", k = 1

Output: 3

Explanation:

The substrings with every vowel and one consonant are:

word[0..5], which is "ieaouq".
word[6..11], which is "qieaou".
word[7..12], which is "ieaouq".
 

Constraints:

5 <= word.length <= 2 * 105
word consists only of lowercase English letters.
0 <= k <= word.length - 5

*/


// TLE but i ended it in my way

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <set>
#include <utility>
#include <stack>

using namespace std;

class Solution {
public:
    bool check_all_vowels(const std::unordered_map<char, int>& map) {

        return map.at('a') > 0 && map.at('e') > 0 && map.at('i') > 0 &&
               map.at('o') > 0 && map.at('u') > 0;
    }

    long long countOfSubstrings(std::string word, int k) {
        int s = word.length();
        long long res = 0;

        std::unordered_map<char, int> vowel_count{{'a', 0}, {'e', 0}, {'i', 0}, {'o', 0}, {'u', 0}};
        int consonant_count = 0; 
        int start = 0, start2 = 0;

        for (int end = 0; end < s; end++) {
            char c = word[end];

            if (vowel_count.find(c) != vowel_count.end()) {
                vowel_count[c]++;
            } else {
                consonant_count++;
            }

            
            while (consonant_count > k) {
                char start_char = word[start];
                if (vowel_count.find(start_char) != vowel_count.end()) {
                    vowel_count[start_char]--;
                } else {
                    consonant_count--;
                }
                start++;
            }
            int j = end+1;
            int temp = consonant_count ;
            while(j < s && temp == k && check_all_vowels(vowel_count)){
                char start_char = word[j];
                if (vowel_count.find(start_char) == vowel_count.end()) {
                    temp++;
                }
                if(temp == k){
                    res++;
                }
                j++;
            }
            while(consonant_count == k && check_all_vowels(vowel_count)){
                res++;
                char start_char = word[start];
                if (vowel_count.find(start_char) != vowel_count.end()) {
                    vowel_count[start_char]--;
                    int j = end+1;
                    int temp = consonant_count ;
                    while(j < s && temp == k && check_all_vowels(vowel_count)){
                        char start_char = word[j];
                        if (vowel_count.find(start_char) == vowel_count.end()) {
                            temp++;
                        }
                        if(temp == k){
                            res++;
                        }
                        j++;
                    }
                } else {
                    consonant_count--;
                }
                start++;
            }
           
        }
        

        return res;
    }
};


//

class Solution {
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    long countOfSubstrings(string word, int k) {
        long numValidSubstrings = 0;
        int start = 0;
        int end = 0;
        unordered_map<char, int> vowelCount;
        int consonantCount = 0;

        vector<int> nextConsonant(word.size());
        int nextConsonantIndex = word.size();
        for (int i = word.size() - 1; i >= 0; i--) {
            nextConsonant[i] = nextConsonantIndex;
            if (!isVowel(word[i])) {
                nextConsonantIndex = i;
            }
        }

        while (end < word.size()) {
            char newLetter = word[end];

            if (isVowel(newLetter)) {
                vowelCount[newLetter]++;
            } else {
                consonantCount++;
            }

            while (consonantCount > k) {
                char startLetter = word[start];
                if (isVowel(startLetter)) {
                    vowelCount[startLetter]--;
                    if (vowelCount[startLetter] == 0) {
                        vowelCount.erase(startLetter);
                    }
                } else {
                    consonantCount--;
                }
                start++;
            }

            while (start < word.size() && vowelCount.size() == 5 &&
                   consonantCount == k) {
                numValidSubstrings += nextConsonant[end] - end;
                char startLetter = word[start];
                if (isVowel(startLetter)) {
                    vowelCount[startLetter]--;
                    if (vowelCount[startLetter] == 0) {
                        vowelCount.erase(startLetter);
                    }
                } else {
                    consonantCount--;
                }

                start++;
            }
            end++;
        }

        return numValidSubstrings;
    }
};

//
class Solution {
public:
    long countOfSubstrings(string word, int k) {
        return atLeastK(word, k) - atLeastK(word, k + 1);
    }

private:
    long atLeastK(string word, int k) {
        long numValidSubstrings = 0;
        int start = 0;
        int end = 0;
        // Keep track of counts of vowels and consonants.
        unordered_map<char, int> vowelCount;
        int consonantCount = 0;

        // Start sliding window.
        while (end < word.length()) {
            // Insert new letter.
            char newLetter = word[end];

            // Update counts.
            if (isVowel(newLetter)) {
                vowelCount[newLetter]++;
            } else {
                consonantCount++;
            }

            // Shrink window while we have a valid substring.
            while (vowelCount.size() == 5 and consonantCount >= k) {
                numValidSubstrings += word.length() - end;
                char startLetter = word[start];
                if (isVowel(startLetter)) {
                    if (--vowelCount[startLetter] == 0) {
                        vowelCount.erase(startLetter);
                    }
                } else {
                    consonantCount--;
                }
                start++;
            }

            end++;
        }

        return numValidSubstrings;
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};