/*
https://leetcode.com/problems/zero-array-transformation-ii/description/?envType=daily-question&envId=2025-03-13


You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri, vali].

Each queries[i] represents the following action on nums:

Decrement the value at each index in the range [li, ri] in nums by at most vali.
The amount by which each value is decremented can be chosen independently for each index.
A Zero Array is an array with all its elements equal to 0.

Return the minimum possible non-negative value of k, such that after processing the first k queries in sequence, nums becomes a Zero Array. If no such k exists, return -1.

 

Example 1:

Input: nums = [2,0,2], queries = [[0,2,1],[0,2,1],[1,1,3]]

Output: 2

Explanation:

For i = 0 (l = 0, r = 2, val = 1):
Decrement values at indices [0, 1, 2] by [1, 0, 1] respectively.
The array will become [1, 0, 1].
For i = 1 (l = 0, r = 2, val = 1):
Decrement values at indices [0, 1, 2] by [1, 0, 1] respectively.
The array will become [0, 0, 0], which is a Zero Array. Therefore, the minimum value of k is 2.
Example 2:

Input: nums = [4,3,2,1], queries = [[1,3,2],[0,2,1]]

Output: -1

Explanation:

For i = 0 (l = 1, r = 3, val = 2):
Decrement values at indices [1, 2, 3] by [2, 2, 1] respectively.
The array will become [4, 1, 0, 0].
For i = 1 (l = 0, r = 2, val = 1):
Decrement values at indices [0, 1, 2] by [1, 1, 0] respectively.
The array will become [3, 0, 0, 0], which is not a Zero Array.
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 5 * 105
1 <= queries.length <= 105
queries[i].length == 3
0 <= li <= ri < nums.length
1 <= vali <= 5


*/


//TLE

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
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int size_n = nums.size();
        int size_q = queries.size();
        int k = 0;
        for(int i = 0; i < size_n; i++){
            if(nums[i]>0){
                break;
            }
            if (i== size_n-1){
                return 0;
            }
        }
        for( vector<int>& part : queries){
            bool j = true;
            k++;
            for(int i = part[0]; i <= part[1]; i++){
                nums[i] -= part[2];
                if(nums[i]>0){
                    j = false;
                }
            }
            if(j){
                for(int c = 0; c < size_n; c++){
                        if(nums[c]>0){
                            j = false;
                        }
                }
            }
            if(j){
                return k;
            }
        }
        return -1;

    }
};

//TLE

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int size_n = nums.size();
        int size_q = queries.size();
        int k = 0;
        for(int i = 0; i < size_n; i++){
            if(nums[i]>0){
                break;
            }
            if (i== size_n-1){
                return 0;
            }
        }
        vector<int> acum(size_n,0);
        for( vector<int>& part : queries){
            bool j = false;
            for(int i = part[0]; i <= part[1]; i++){
                for(int c = 0; c < size_n; c++){
                    if(acum[c]<nums[c]){
                        j = true;
                    }
                }
                if(acum[i]<nums[i]){
                    acum[i]+=part[2];
                    j = true;
                }
            }
            if(j){
                k++;
            }
        }
        for(int i = 0; i < size_n; i++){
            nums[i]-=acum[i];
            if(nums[i]>0){
                return -1;
            }
        }
        return k;

    }
};

// still TLE

class Solution {
public:
    vector<int> init_D(vector<int>& nums) {
        int n = nums.size();
        vector<int> D(n + 1, 0);
        
     
        D[0] = nums[0];
        for (int i = 1; i < n; i++) {
            D[i] = nums[i] - nums[i - 1];
        }
        return D;
    }

    void update(vector<int>& D, int l, int r, int x) {
        D[l] -= x;
        if (r + 1 < D.size()) {
            D[r + 1] += x; 
        }
    }

    bool isNonPositive(vector<int>& D) {
        int n = D.size() - 1;
        int curr = D[0];

        if (curr > 0) return false;
        
        for (int i = 1; i < n; i++) {
            curr += D[i];
            if (curr > 0) return false;
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), q = queries.size();
        vector<int> D = init_D(nums);

   
        if (isNonPositive(D)) return 0;

       
        for (int k = 0; k < q; k++) {
            update(D, queries[k][0], queries[k][1], queries[k][2]);

            if (isNonPositive(D)) {
                return k + 1; 
            }
        }

        return -1; 
    }
};


//


class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), left = 0, right = queries.size();

        // Zero array isn't formed after all queries are processed
        if (!canFormZeroArray(nums, queries, right)) return -1;

        // Binary Search
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (canFormZeroArray(nums, queries, middle)) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }

        // Return earliest query that zero array can be formed
        return left;
    }

private:
    bool canFormZeroArray(vector<int>& nums, vector<vector<int>>& queries,
                          int k) {
        int n = nums.size(), sum = 0;
        vector<int> differenceArray(n + 1);

        // Process query
        for (int queryIndex = 0; queryIndex < k; queryIndex++) {
            int start = queries[queryIndex][0], end = queries[queryIndex][1],
                val = queries[queryIndex][2];

            // Process start and end of range
            differenceArray[start] += val;
            differenceArray[end + 1] -= val;
        }

        // Check if zero array can be formed
        for (int numIndex = 0; numIndex < n; numIndex++) {
            sum += differenceArray[numIndex];
            if (sum < nums[numIndex]) return false;
        }
        return true;
    }
};

//

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), sum = 0, k = 0;
        vector<int> differenceArray(n + 1);

        // Iterate through nums
        for (int index = 0; index < n; index++) {
            // Iterate through queries while current index of nums cannot equal
            // zero
            while (sum + differenceArray[index] < nums[index]) {
                k++;

                // Zero array isn't formed after all queries are processed
                if (k > queries.size()) {
                    return -1;
                }
                int left = queries[k - 1][0], right = queries[k - 1][1],
                    val = queries[k - 1][2];

                // Process start and end of range
                if (right >= index) {
                    differenceArray[max(left, index)] += val;
                    differenceArray[right + 1] -= val;
                }
            }
            // Update prefix sum at current index
            sum += differenceArray[index];
        }
        return k;
    }
};