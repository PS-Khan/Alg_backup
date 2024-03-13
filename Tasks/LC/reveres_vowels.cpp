/*
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 

Example 1:

Input: s = "hello"
Output: "holle"
Example 2:

Input: s = "leetcode"
Output: "leotcede"
 

Constraints:

1 <= s.length <= 3 * 105
s consist of printable ASCII characters.

*/

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <unordered_map>
using namespace std;

string reverseVowels(string s) {
        unordered_map<char,int> arr = {
        {'a',1},
        {'e',('e'-'a'+1)},
        {'i',('i'-'a'+1)},
        {'o',('o'-'a'+1)},
        {'u',('u'-'a'+1)},
        };
        string tmp_s = s;
        std::transform(tmp_s.begin(), tmp_s.end(), tmp_s.begin(),
                [](unsigned char c) { return std::tolower(c); });

        int i = 0, j = s.length() - 1;
        while (i < j) {
            while (i < j && arr.find(tmp_s.at(i)) == arr.end()) {
                i++;
            }
            while (i < j && arr.find(tmp_s.at(j)) == arr.end()) {
                j--;
            }
            if (i < j) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }