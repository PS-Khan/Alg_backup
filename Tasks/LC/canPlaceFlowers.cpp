/*
You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

 

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
*/


#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;
bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0){
            return true;
        }
        size_t size = flowerbed.size();
        for (int i = 0; i < size; i++){
            if(flowerbed[i] != 0){
                continue;
            }
            bool r,l = false;
            if(i - 1 < 0 || flowerbed[i-1] == 0 ){
                l = true;
            }else{
                continue;
            }
            if(i + 1 == size  || flowerbed[i+1] == 0 ){
                r = true;
            }else{
                continue;
            }
            n--;
            i++;

            if(n == 0){
                return true;
            }
        }
        return false;
    }