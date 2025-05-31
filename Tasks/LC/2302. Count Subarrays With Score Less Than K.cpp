/*

The score of an array is defined as the product of its sum and its length.

For example, the score of [1, 2, 3, 4, 5] is (1 + 2 + 3 + 4 + 5) * 5 = 75.
Given a positive integer array nums and an integer k, return the number of non-empty subarrays of nums whose score is strictly less than k.

A subarray is a contiguous sequence of elements within an array.

 

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
#include <numeric>
#include <functional>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long res = 0;
        long long sum = 0;
        int j = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            while (sum * (i - j + 1) >= k) {
                sum -= nums[j];
                j++;
            }
            res += (i - j + 1); 
        }

        return res;
    }
};