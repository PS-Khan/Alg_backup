#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

/*

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.
*/



int maxArea(std::vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int res = 0;

        while (l < r) {
            int h = std::min(height[l], height[r]); 
            int w = r - l; 
            int area = h * w;

            res = std::max(res, area); 

            if (height[l] < height[r]) {
                l++; 
            } else {
                r--; 
            }
        }

        return res;
    }