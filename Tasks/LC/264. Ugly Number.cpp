/*
https://leetcode.com/problems/ugly-number-ii/description/?envType=daily-question&envId=2024-08-18
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.

 

Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
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
using namespace std;

class Solution {
public:
    unordered_map<int,bool> results;

    bool check_num(int n){
        queue<int> q;
        bool res = true;
        while(n != 1){
            if(results.find(n) != results.end()){
                return results[n];
            }else{
                if(n % 2 == 0){
                    q.push(n);
                    n /=2; 
                }else if(n % 3 == 0){
                    q.push(n);
                    n /=3; 
                }else if(n % 5 == 0){
                    q.push(n);
                    n /=5; 
                }else{
                    res = false;
                    break;
                }
            }
        }
        while(!q.empty()){
            int r = q.front();
            q.pop();
            results[r] = res;
        }
        return res;
    } 
    int nthUglyNumber(int n) {
        int nums = 0;
        int ans = 0;
        int i = 1;
        while(nums != n){
            if(check_num(i)){
                cout<< i<< " ";
                ans=i;
                nums++;
            }
            i++;
        }
            
        return ans;
    }
};


//

    int nthUglyNumber(int n) {
        set<long> uglyNumbersSet;  // Set to store potential ugly numbers
        uglyNumbersSet.insert(1);  // Start with 1, the first ugly number

        long currentUgly = 1;
        for (int i = 0; i < n; i++) {
            currentUgly =
                *uglyNumbersSet
                     .begin();  // Get the smallest number from the set
            uglyNumbersSet.erase(
                uglyNumbersSet.begin());  // Remove it from the set

            // Insert the next potential ugly numbers
            uglyNumbersSet.insert(currentUgly * 2);
            uglyNumbersSet.insert(currentUgly * 3);
            uglyNumbersSet.insert(currentUgly * 5);
        }

        return static_cast<int>(currentUgly);  // Return the nth ugly number
    }

//

class Solution {
public:
    int nthUglyNumber(int n) {
        // Min-heap to store and retrieve the smallest ugly number
        priority_queue<long, vector<long>, greater<long>> minHeap;
        unordered_set<long> seenNumbers;  // Set to avoid duplicates
        vector<int> primeFactors = {
            2, 3, 5};  // Factors for generating new ugly numbers

        minHeap.push(1);
        seenNumbers.insert(1);

        long currentUgly = 1;
        for (int i = 0; i < n; ++i) {
            currentUgly = minHeap.top();  // Get the smallest number
            minHeap.pop();                // Remove it from the heap

            // Generate and push the next ugly numbers
            for (int prime : primeFactors) {
                long nextUgly = currentUgly * prime;
                if (seenNumbers.find(nextUgly) ==
                    seenNumbers.end()) {  // Avoid duplicates
                    minHeap.push(nextUgly);
                    seenNumbers.insert(nextUgly);
                }
            }
        }

        return static_cast<int>(currentUgly);  // Return the nth ugly number
    }
};


// DP
