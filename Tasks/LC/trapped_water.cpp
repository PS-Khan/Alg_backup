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

using namespace std;

/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining.

 
*/

 int trap(std::vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;

        int leftMax = 0, rightMax = 0;
        int left = 0, right = n - 1;
        int trappedWater = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    trappedWater += leftMax - height[left];
                }
                left++;
            } else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    trappedWater += rightMax - height[right];
                }
                right--;
            }
        }
        return trappedWater;
    }