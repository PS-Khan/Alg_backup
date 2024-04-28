/*
You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

 

Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
Example 2:

Input: nums = [5], k = 1
Output: 5.00000
*/
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <unordered_map>
#include <numeric>
using namespace std;

//this was my first try, and i didnt get why it dosent pass ... Like, take the bigest numbers , get max avarage no?
//why they want here 1.75000 if 4+1+2+1 (k = 4) => 8/4 =2 and its bigger than 1.75... oh they wanted sub arrays, no sorting, i got it.
//Input
//nums =
//[1,0,1,4,2]
//k =
//4

//Use Testcase
//Stdout
//4 2 1 1 0 
//Output
//2.00000
//Expected
//1.75000
double findMaxAverage(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end(),[](int a, int b){return abs(a) > abs(b) ;});
        for(int i = 0; i < nums.size(); i++){
            std::cout<<nums[i]<<" ";
        }
        double res = std::accumulate(nums.begin(), nums.begin()+k,0);
        return res/(k);
    }

//this what works..
 double findMaxAverage(std::vector<int>& nums, int k) {
    int n = nums.size();
    double maxAverage = 0;

    // Calculate the sum of the first k elements
    double sum = std::accumulate(nums.begin(), nums.begin() + k, 0);

    // Initialize maxAverage with the average of the first k elements
    maxAverage = sum / k;

    // Iterate through the remaining subarrays
    for (int i = k; i < n; ++i) {
        sum += nums[i] - nums[i - k]; // Update the sum by adding the next element and removing the first element of the window
        maxAverage = std::max(maxAverage, sum / k); // Update maxAverage if a higher average is found
    }

    return maxAverage;
}