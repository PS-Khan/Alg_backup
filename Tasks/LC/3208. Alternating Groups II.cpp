
/*
https://leetcode.com/problems/alternating-groups-ii/description/?envType=daily-question&envId=2025-03-09

There is a circle of red and blue tiles. You are given an array of integers colors and an integer k. The color of tile i is represented by colors[i]:

colors[i] == 0 means that tile i is red.
colors[i] == 1 means that tile i is blue.
An alternating group is every k contiguous tiles in the circle with alternating colors (each tile in the group except the first and last one has a different color from its left and right tiles).

Return the number of alternating groups.

Note that since colors represents a circle, the first and the last tiles are considered to be next to each other.

 
*/

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
// TLE
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int i = 0, res = 0;
        int n = colors.size();
        if (k > n) return 0;
         for (int start = 0; start < n; start++) { 
            bool valid = true;
            for (int i = 0; i < k - 1; i++) { 
                int curr = colors[(start + i) % n];
                int next = colors[(start + i + 1) % n];
                if (curr == next) {
                    valid = false;
                    break;
                }
            }
            if (valid) res++;
        }
        
        return res;
    }
};

//

class Solution {
public:
    bool valid_window(vector<int>& colors, int start, int k) {
        int s = colors.size();
        for (int j = 1; j < k; j++) {
            if (colors[(start + j) % s] == colors[(start + j - 1) % s]) {
                return false; 
            }
        }
        return true;
    }

    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int s = colors.size();
        if (k > s) return 0;

        int res = 0;
        int i = 0;

        while (i < s) {
            if (valid_window(colors, i, k)) {
                res++;
                int j = (i + k - 1) % s;  
                

                while (i < s - 1 && colors[j] != colors[(j + 1) % s]) {
                    res++;
                    j = (j + 1) % s;
                    i++; 
                }
            }
            i++; 
        }
        return res;
    }
};

//

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        // Extend the array to handle circular sequences
        for (int i = 0; i < k - 1; i++) {
            colors.push_back(colors[i]);
        }

        int length = colors.size();
        int result = 0;
        // Initialize the bounds of the sliding window
        int left = 0;
        int right = 1;

        while (right < length) {
            // Check if the current color is the same as the last one
            if (colors[right] == colors[right - 1]) {
                // Pattern breaks, reset window from the current position
                left = right;
                right++;
                continue;
            }

            // Expand the window to the right
            right++;

            // Skip counting sequence if its length is less than k
            if (right - left < k) continue;

            // Record a valid sequence and shrink window from the left to search
            // for more
            result++;
            left++;
        }

        return result;
    }
};


//

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int length = colors.size();
        int result = 0;
        // Tracks the length of the current alternating sequence
        int alternatingElementsCount = 1;
        int lastColor = colors[0];

        for (int index = 1; index < length; index++) {
            // Check if the current color is the same as the last one
            if (colors[index] == lastColor) {
                // Pattern breaks, reset sequence length
                alternatingElementsCount = 1;
                lastColor = colors[index];
                continue;
            }

            // Sequence can be extended
            alternatingElementsCount++;

            // Record a new alternating sequence
            if (alternatingElementsCount >= k) {
                result++;
            }

            lastColor = colors[index];
        }

        // Wrap around to the first k - 1 elements
        for (int index = 0; index < k - 1; index++) {
            // Pattern breaks. Since there are less than k elements remaining,
            // no more sequences can be formed
            if (colors[index] == lastColor) break;

            // Extend the pattern
            alternatingElementsCount++;

            // Record a new alternating sequence
            if (alternatingElementsCount >= k) {
                result++;
            }

            lastColor = colors[index];
        }
        return result;
    }
};


//

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int length = colors.size();
        int result = 0;
        // Tracks the length of the current alternating sequence
        int alternatingElementsCount = 1;
        int lastColor = colors[0];

        // Loop through the array, including the wrap-around (circular check)
        for (int i = 1; i < length + k - 1; i++) {
            // Use modulo to handle circular traversal
            int index = i % length;

            // Check if current color is the same as last color
            if (colors[index] == lastColor) {
                // Pattern breaks, reset sequence length
                alternatingElementsCount = 1;
                lastColor = colors[index];
                continue;
            }

            // Extend alternating sequence
            alternatingElementsCount += 1;

            // If sequence length reaches at least k, count it
            if (alternatingElementsCount >= k) {
                result++;
            }

            lastColor = colors[index];
        }
    }
};