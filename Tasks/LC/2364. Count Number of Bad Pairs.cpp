/*
https://leetcode.com/problems/count-number-of-bad-pairs/description/?envType=daily-question&envId=2025-02-09

You are given a 0-indexed integer array nums. A pair of indices (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i].

Return the total number of bad pairs in nums.

 

Example 1:

Input: nums = [4,1,3,3]
Output: 5
Explanation: The pair (0, 1) is a bad pair since 1 - 0 != 1 - 4.
The pair (0, 2) is a bad pair since 2 - 0 != 3 - 4, 2 != -1.
The pair (0, 3) is a bad pair since 3 - 0 != 3 - 4, 3 != -1.
The pair (1, 2) is a bad pair since 2 - 1 != 3 - 1, 1 != 2.
The pair (2, 3) is a bad pair since 3 - 2 != 3 - 3, 1 != 0.
There are a total of 5 bad pairs, so we return 5.
Example 2:

Input: nums = [1,2,3,4,5]
Output: 0
Explanation: There are no bad pairs.
 

*/

//brute force

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <set>
#include <queue>
#include <set>
#include <utility>

using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int size = nums.size();
        long long count = 0;
        for(int i  = 0; i < size ; i++){
            for(int j = i+1; j < size ; j++){
                if(nums[j]- nums[i] != j - i){
                    count++;
                }
            }
        }
        return count;
    }
};

//here trick, look at the condition and try symplify. i < j and j - i != nums[j] - nums[i].
//nums[j] - j != nums[i] - i
//dif[j] != dif[i] 

 long long countBadPairs(vector<int>& nums) {
        unordered_map<int, long long> freq;
        long long goodPairs = 0;
        int size = nums.size();

        
        for (int j = 0; j < size; j++) {
            int diff = nums[j] - j;
            if (freq.count(diff)) {
                goodPairs += freq[diff];  
            }
            freq[diff]++; 
        }

        
        long long totalPairs = (long long)size * (size - 1) / 2;
        return totalPairs - goodPairs;
    
    }
/*
This transformation highlights a key insight: for two positions to form a good pair, the difference between their position and their value (position - value) must be the same. In other words, the value of j - nums[j] must match the value of i - nums[i]. This "position - value" difference is the key to identifying good pairs.

For example, if the array is nums = [1, 1, 2, 1] at positions 0, 1, 2, 3, then calculating position - number gives us [-1, 0, 0, 2]. Here, positions 1 and 2 both have the same tag 0, forming a good pair.

As the number of bad pairs would be the total number of pairs minus the number of good pairs, let's focus on finding the number of good pairs each element can make. Since an element can form a good pair only with elements occurring before it, we can iterate over the nums array and keep a running count of all the good pairs we find.

We can use a hash map to keep track of the counts of each position - number value as we iterate through the array. For each index j, the value j - nums[j] tells us how many indices before j could form good pairs with it. These counts are stored in the hash map.

For an index j, all previous indices 0 to j - 1 can potentially form pairs with it. This means j total pairs are possible.
Out of these, the number of good pairs is determined by the count of j - nums[j] stored in the hash map.
The difference between the total pairs (j) and the good pairs gives the number of bad pairs contributed by nums[j].
As we iterate, we keep updating the hash map with the current position - number values and accumulate the count of bad pairs. After processing the entire array, we return the total count of bad pairs.
*/

