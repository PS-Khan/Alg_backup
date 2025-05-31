/*

This suggests we can use a binary search-like algorithm, we can take the decision of discarding some part of the search space at each step.

Our search space for the gap values starts with low=1, since there will be at least a gap of 1 between any two adjacent balls, and extends to high=⌈ 
m−1
maxPosition
​
 ⌉, the maximum gap between m balls if all positions from 1 to position[n−1] are available.

To determine if we can place the balls with a given gap x=mid we will use another function canPlaceBalls(x, positions, m), where mid=low+ 
2
(high−low)
​
 .
If placing the balls is possible with this gap, we discard all gaps smaller than mid from our search space. Conversely, if we cannot place the balls, we discard all gaps greater than mid. We repeat this process in the reduced search space until we find the maximum gap value.

In canPlaceBalls(x, positions, m) function, we check if we can place m balls in the given position array with at least x gap between them. We iterate through the position array, checking if each position is suitable for placing a ball by maintaining a gap of at least xfrom the previous ball's position. If the current position meets the requirement, we place the ball there and move to the next position. We stop once we either run out of positions or successfully place all m balls.

*/

/*
In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.

Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

Given the integer array position and the integer m. Return the required force.
*/

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    bool canPlaceBalls(int x, vector<int> &position, int m) {
        // Place the first ball at the first position.
        int prevBallPos = position[0];
        int ballsPlaced = 1;

        // Iterate on each 'position' and place a ball there if we can place it.
        for (int i = 1; i < position.size() && ballsPlaced < m; ++i) {
            int currPos = position[i];
            // Check if we can place the ball at the current position.
            if (currPos - prevBallPos >= x) {
                ballsPlaced += 1;
                prevBallPos = currPos;
            }
        }
        // If all 'm' balls are placed, return 'true'.
        return ballsPlaced == m;
    }

    int maxDistance(vector<int> &position, int m) {
        int answer = 0;
        int n = position.size();
        sort(position.begin(), position.end());

        // Initial search space.
        int low = 1;
        int high = ceil(position[n - 1] / (m - 1.0));
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // If we can place all balls having a gap at least 'mid',
            if (canPlaceBalls(mid, position, m)) {
                // then 'mid' can be our answer,
                answer = mid;
                // and discard the left half search space.
                low = mid + 1;
            } else {
                // Discard the right half search space.
                high = mid - 1;
            }
        }
        return answer;
    }

    

};