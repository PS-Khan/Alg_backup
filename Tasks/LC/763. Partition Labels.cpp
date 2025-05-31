
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
#include <numeric>

using namespace std;

/*
You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part. For example, the string "ababcc" can be partitioned into ["abab", "cc"], but partitions such as ["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.

 

Example 1:

Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
Example 2:

Input: s = "eccbbbbdec"
Output: [10]
 

*/


class Solution {
public:
    vector<int> partitionLabels(string s) {
        int size = s.length();
        vector<int> res;
        unordered_map<char,int> freq;
        for(int i = 0 ; i < size; i++){
            freq[s[i]]++;
        }
        unordered_set<char> q;
        int tmp = 0;
        for(int i = 0 ; i < size; i++){
            q.insert(s[i]);
            freq[s[i]]--;
            tmp++;

            if(freq[s[i]] == 0){
                q.erase(s[i]);
            }
            if(q.empty()){
                res.push_back(tmp);
                tmp = 0;
            }

        }
        return res;
    }
};


//

class Solution {
public:
    vector<int> partitionLabels(string s) {
        // Stores the last index of each character in 's'
        vector<int> lastOccurrence(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            lastOccurrence[s[i] - 'a'] = i;
        }

        int partitionEnd = 0, partitionStart = 0;
        vector<int> partitionSizes;
        for (int i = 0; i < s.size(); ++i) {
            partitionEnd = max(partitionEnd, lastOccurrence[s[i] - 'a']);
            // End of the current partition
            if (i == partitionEnd) {
                partitionSizes.push_back(i - partitionStart + 1);
                partitionStart = i + 1;
            }
        }
        return partitionSizes;
    }
};

//

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> partitionSizes;
        int lastOccurrence[26] = {0}, firstOccurrence[26] = {0};
        int partitionStart = 0, partitionEnd = 0;

        // Store the last occurrence index of each character
        for (int i = 0; i < s.length(); i++) {
            lastOccurrence[s[i] - 'a'] = i;
        }

        for (int i = 0; i < s.length(); i++) {
            // Store the first occurrence index of each character (if not set)
            if (!firstOccurrence[s[i] - 'a']) {
                firstOccurrence[s[i] - 'a'] = i;
            }

            // If we find a new partition start
            if (partitionEnd < firstOccurrence[s[i] - 'a']) {
                partitionSizes.push_back(partitionEnd - partitionStart + 1);
                partitionStart = i;
                partitionEnd = i;
            }

            // Update partition end boundary
            partitionEnd = max(partitionEnd, lastOccurrence[s[i] - 'a']);
        }

        // Add the last partition if it exists
        if (partitionEnd - partitionStart + 1 > 0) {
            partitionSizes.push_back(partitionEnd - partitionStart + 1);
        }

        return partitionSizes;
    }
};