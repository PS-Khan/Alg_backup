/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
*/
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int size = prices.size();
        int j = 0;
        for(int i = 1; i < size; ++i){
            if(prices[j] > prices[i]){
                j = i;
            }else if(prices[j] < prices[i]){
                res = max(res, prices[i]-prices[j] );
            }
        }
        return res;
    }
};