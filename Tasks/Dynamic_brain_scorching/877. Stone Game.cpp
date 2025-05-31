/*
Alice and Bob play a game with piles of stones. There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

The objective of the game is to end with the most stones. The total number of stones across all the piles is odd, so there are no ties.

Alice and Bob take turns, with Alice starting first. Each turn, a player takes the entire pile of stones either from the beginning or from the end of the row. This continues until there are no more piles left, at which point the person with the most stones wins.

Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.

https://leetcode.com/problems/stone-game/description/
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
#include <algorithm>
#include <numeric>
#include <memory.h>
using namespace std;


// my solution, time limit exceeded, but i think i actually made it work.


class Solution {
public:
    int pick(vector<int> &piles, int score, bool step){
        vector<int> tmp = piles;
        int l_score;
        int r_score;
        if(piles.empty()){
            return score;
        }
        if(step){
            int fr = piles[0];
            int bck = piles.back();
            tmp.erase(tmp.begin());
            l_score = pick(tmp, score+fr,false);
            piles.pop_back();
            r_score = pick(piles, score+bck,false);
        }else{
            tmp.erase(tmp.begin());
            l_score = pick(tmp, score,true);
            piles.pop_back();
            r_score = pick(piles, score,true);
        }
        return max(r_score,l_score);
    }
    bool stoneGame(vector<int>& piles) {
        int score = pick(piles, 0, true);
        int sum = std::accumulate(piles.begin(), piles.end(), 0);
       
        return (sum-score < sum - (sum-score)) ? true : false ;
    }
};


// optimised 


int pick(vector<int>& piles, int left, int right, vector<vector<int>>& memo) {
        if (left > right) {
            return 0;
        }
        if (memo[left][right] != -1) {
            return memo[left][right];
        }
        int pickLeft = piles[left] - pick(piles, left + 1, right, memo);
        int pickRight = piles[right] - pick(piles, left, right - 1, memo);
        memo[left][right] = max(pickLeft, pickRight);
        return memo[left][right];
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return pick(piles, 0, n - 1, memo) > 0;
    }

/*

Problem Recap
Given a vector piles, each player alternates picking a pile of stones from either the front or back. The goal is to determine if the first player can win with optimal play.

Example: piles = {3, 9, 1, 2}
We want to determine if the first player can guarantee a win.

Step 1: Initial Setup
We start by calling pick(piles, 0, n-1, memo), where n = 4 (size of piles).
Initial call: pick(piles, 0, 3, memo).
Step 2: First Layer of Recursion
At this layer, the entire array is considered: piles = {3, 9, 1, 2}.

Option 1: Pick the first element (3).

This leaves the opponent with the subarray {9, 1, 2}.
The score difference for this choice is: 3 - pick(piles, 1, 3, memo).
Option 2: Pick the last element (2).

This leaves the opponent with the subarray {3, 9, 1}.
The score difference for this choice is: 2 - pick(piles, 0, 2, memo).
Now, we need to recursively calculate pick(piles, 1, 3, memo) and pick(piles, 0, 2, memo).

Step 3: Second Layer of Recursion
Let's first consider the left option: pick(piles, 1, 3, memo) where the subarray is {9, 1, 2}.

Option 1: Pick the first element (9).

This leaves the opponent with {1, 2}.
The score difference is: 9 - pick(piles, 2, 3, memo).
Option 2: Pick the last element (2).

This leaves the opponent with {9, 1}.
The score difference is: 2 - pick(piles, 1, 2, memo).
Next, we need to recursively calculate pick(piles, 2, 3, memo) and pick(piles, 1, 2, memo).

Step 4: Third Layer of Recursion
Now, let's consider pick(piles, 2, 3, memo) with the subarray {1, 2}.

Option 1: Pick the first element (1).

This leaves the opponent with {2}.
The score difference is: 1 - pick(piles, 3, 3, memo).
Option 2: Pick the last element (2).

This leaves the opponent with {1}.
The score difference is: 2 - pick(piles, 2, 2, memo).
Now we need to calculate pick(piles, 3, 3, memo) and pick(piles, 2, 2, memo).

Step 5: Base Case (Fourth Layer)
At this layer, we are dealing with single elements.

For pick(piles, 3, 3, memo) where the subarray is {2}:

The only option is to pick 2, so the score difference is 2.
Return 2.
For pick(piles, 2, 2, memo) where the subarray is {1}:

The only option is to pick 1, so the score difference is 1.
Return 1.
Step 6: Resolving Third Layer
Now we can resolve pick(piles, 2, 3, memo).

Option 1: Picking 1 leads to a score difference of 1 - 2 = -1.
Option 2: Picking 2 leads to a score difference of 2 - 1 = 1.
The best choice here is picking 2, so pick(piles, 2, 3, memo) returns 1. Store memo[2][3] = 1.

Step 7: Resolving Second Layer
Let's now resolve pick(piles, 1, 3, memo) where the subarray is {9, 1, 2}.

Option 1: Picking 9 leads to a score difference of 9 - 1 = 8.
Option 2: Picking 2 leads to a score difference of 2 - 1 = 1.
The best choice here is picking 9, so pick(piles, 1, 3, memo) returns 8. Store memo[1][3] = 8.

Step 8: Resolve the Other Branch (Second Layer)
Next, consider pick(piles, 0, 2, memo) where the subarray is {3, 9, 1}.

Option 1: Picking 3 leads to a score difference of 3 - 8 = -5.
Option 2: Picking 1 leads to a score difference of 1 - 9 = -8.
The best choice here is picking 3, so pick(piles, 0, 2, memo) returns -5. Store memo[0][2] = -5.

Step 9: Resolve the First Layer
Finally, let's resolve the initial call pick(piles, 0, 3, memo).

Option 1: Picking 3 leads to a score difference of 3 - 8 = -5.
Option 2: Picking 2 leads to a score difference of 2 - (-5) = 7.
The best choice here is picking 2, so pick(piles, 0, 3, memo) returns 7. Store memo[0][3] = 7.

Final Decision
The result pick(piles, 0, 3, memo) = 7 means the first player can achieve a net positive score difference of 7 by optimal play. Therefore, the first player wins.
Summary:
Initial Call: We start with the entire array and consider all possible choices.
Recursive Calculation: For each choice, we calculate the resulting score difference, considering the opponent's optimal response.
Memoization: Store results of subproblems to avoid redundant calculations.
Final Result: The result from the initial call determines if the first player wins.
This method ensures that all subproblems are solved optimally, and by backtracking from the base cases, we can determine the best possible outcome for the first player.


*/




///

class Solution {
public:
   bool stoneGame(vector<int>& piles) {
        int N = piles.size();

        // dp[i+1][j+1] = the value of the game [piles[i], ..., piles[j]]
        int dp[N+2][N+2];
        memset(dp, 0, sizeof(dp));

        for (int size = 1; size <= N; ++size)
            for (int i = 0, j = size - 1; j < N; ++i, ++j) {
                int parity = (j + i + N) % 2;  // j - i - N; but +x = -x (mod 2)
                if (parity == 1)
                    dp[i+1][j+1] = max(piles[i] + dp[i+2][j+1], piles[j] + dp[i+1][j]);
                else
                    dp[i+1][j+1] = min(-piles[i] + dp[i+2][j+1], -piles[j] + dp[i+1][j]);
            }

        return dp[1][N] > 0;
    }
};



/*
If parity == 1 (First Player's Turn):

The first player aims to maximize their score difference.
They can either:
Pick piles[i] and then let the opponent deal with the subarray piles[i+1] to piles[j].
Pick piles[j] and then let the opponent deal with the subarray piles[i] to piles[j-1].
Hence, we use max to select the optimal move.

If parity == 0 (Opponent's Turn):

The opponent aims to minimize the score difference for the first player.
They can either:
Pick piles[i], leaving the subarray piles[i+1] to piles[j] for the first player.
Pick piles[j], leaving the subarray piles[i] to piles[j-1] for the first player.
Hence, we use min because the opponent will choose the move that minimizes the score difference for the first player.
The calculation for the player's move (parity == 1) adds piles[i] or piles[j] because that pile's value is added to the player's score. Conversely, for the opponent's move (parity == 0), we subtract the pile's value because it is not beneficial to the current player.
*/


//Ahahah
class Solution {
public:
   bool stoneGame(vector<int>& piles) {
        return true;
    }
};
/*

Approach 2: Mathematical
Intuition and Algorithm

Alice clearly always wins the 2 pile game. With some effort, we can see that she always wins the 4 pile game.

If Alice takes the first pile initially, she can always take the third pile. If she takes the fourth pile initially, she can always take the second pile. At least one of first + third, second + fourth is larger, so she can always win.

We can extend this idea to N piles. Say the first, third, fifth, seventh, etc. piles are white, and the second, fourth, sixth, eighth, etc. piles are black. Alice can always take either all white piles or all black piles, and one of the colors must have a sum number of stones larger than the other color.

Hence, Alice always wins the game.

*/



