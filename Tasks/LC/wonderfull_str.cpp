/*


A wonderful string is a string where at most one letter appears an odd number of times.

For example, "ccjjc" and "abab" are wonderful, but "ab" is not.
Given a string word that consists of the first ten lowercase English letters ('a' through 'j'), return the number of wonderful non-empty substrings in word. If the same substring appears multiple times in word, then count each occurrence separately.

A substring is a contiguous sequence of characters in a string.

 

Example 1:

Input: word = "aba"
Output: 4
Explanation: The four wonderful substrings are underlined below:
- "aba" -> "a"
- "aba" -> "b"
- "aba" -> "a"
- "aba" -> "aba"
Example 2:

Input: word = "aabb"
Output: 9
Explanation: The nine wonderful substrings are underlined below:
- "aabb" -> "a"
- "aabb" -> "aa"
- "aabb" -> "aab"
- "aabb" -> "aabb"
- "aabb" -> "a"
- "aabb" -> "abb"
- "aabb" -> "b"
- "aabb" -> "bb"
- "aabb" -> "b"
Example 3:

Input: word = "he"
Output: 2
Explanation: The two wonderful substrings are underlined below:
- "he" -> "h"
- "he" -> "e"

*/



#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <stack>
#include <vector>
#include <queue>
#include <list>
#include <thread>
#include <mutex>
#include <string>
#include <numeric>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<int> count(1024, 0); 
        count[0] = 1; 
        long long result = 0;
        int bitmask = 0;
        for (char &c : word) {
            bitmask ^= 1 << (c - 'a'); //ok i understand what it does , but why
            result += count[bitmask];  // why
            //the hell is that?
            for (int i = 0; i < 10; ++i) {
                result += count[bitmask ^ (1 << i)]; 
            }
            count[bitmask]++; 
        }
        return result;
    }
};

/*
case : aaabbb

count = 0;
result = 0;
bitmask = 0;

1.  'a'

bitmask = ..0 ^ 001 = 001;
result += count[1]; == 0;

{1,...,9}
result += count[bitmask(001) ^ (1 << i(0))] == count[001 ^ 001] == count[0] == 1
...
result += 0;
...
result =1;

count[001(1)]++;

2. 'a'

bitmask = 001 ^ 001 = 0;
result+= count[o] == 1;
result = 2;

{1,...,9}
result += count[bitmask(000) ^ (1 << i(0))] == count[000 ^ 001] == count[1] == 1;
...
result += 0;
...
result =3;
count[000(0)]++; (2)

3. 'a'
bitmask = 000 ^ 001 = 1;
result+= count[1] == 1;
result = 4;

{1,...,9}
result += count[bitmask(001) ^ (1 << i(0))] == count[001 ^ 001] == count[0] == 2;
result = 6;
...


Ok it works , buts still why...




*/