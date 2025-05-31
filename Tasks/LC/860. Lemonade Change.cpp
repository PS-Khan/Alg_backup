/*
https://leetcode.com/problems/lemonade-change/?envType=daily-question&envId=2024-08-15

At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.

Note that you do not have any change in hand at first.

Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise.*/

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool lemonadeChange(std::vector<int>& bills) {
    std::unordered_map<int, int> cash{{5, 0}, {10, 0}, {20, 0}};
    
    for (int &bill : bills) {
        int change = bill - 5;
        cash[bill]++;  
        
        
        while (change > 0) {
            if (change >= 20 && cash[20] > 0) {
                change -= 20;
                cash[20]--;
            } else if (change >= 10 && cash[10] > 0) {
                change -= 10;
                cash[10]--;
            } else if (change >= 5 && cash[5] > 0) {
                change -= 5;
                cash[5]--;
            } else {
                break;  
            }
        }
        
        
        if (change != 0) {
            return false;
        }
    }
    
    return true;  
}
};