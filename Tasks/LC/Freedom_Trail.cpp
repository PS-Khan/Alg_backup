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
#include <algorithm>

using namespace std;

/*
In the video game Fallout 4, the quest "Road to Freedom" requires players to reach a metal dial called the "Freedom Trail Ring" and use the dial to spell a specific keyword to open the door.

Given a string ring that represents the code engraved on the outer ring and another string key that represents the keyword that needs to be spelled, return the minimum number of steps to spell all the characters in the keyword.

Initially, the first character of the ring is aligned at the "12:00" direction. You should spell all the characters in key one by one by rotating ring clockwise or anticlockwise to make each character of the string key aligned at the "12:00" direction and then by pressing the center button.

At the stage of rotating the ring to spell the key character key[i]:

You can rotate the ring clockwise or anticlockwise by one place, which counts as one step. The final purpose of the rotation is to align one of ring's characters at the "12:00" direction, where this character must equal key[i].
If the character key[i] has been aligned at the "12:00" direction, press the center button to spell, which also counts as one step. After the pressing, you could begin to spell the next character in the key (next stage). Otherwise, you have finished all the spelling.
*/


/*
Input
ring = "nyngl"
key = "yyynnnnnnlllggg"

Use Testcase
Output
20
Expected
19

I counted actualy 18
*/
int findRotateSteps(string ring, string key) {
        int sizer = ring.size();
        int i = 0 , j = 0;
        int letter = 0;
        int count  = 0;
        while(letter < key.size()){
            while(ring[i] != key[letter] && ring[j] != key[letter] ){
                
                i = (i + 1)%sizer;
                j = (j - 1 + sizer) % sizer;
                
                
                count++;
            }
            if(ring[i] == key[letter]){
                j = i;
            }else if(ring[j] == key[letter]){
                i = j;
            }
            letter++;
            count++;
        }
        return count;
    }


    //

int findRotateSteps(string ring, string key) {
        int n = ring.size();
        int m = key.size();
        
        
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        
       
        for (int i = 0; i < n; ++i) {
            if (ring[i] == key[0]) {
                dp[0][i] = min(i, n - i) + 1;
            }
        }
        
        
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (ring[j] == key[i]) {
                    for (int k = 0; k < n; ++k) {
                        if (dp[i - 1][k] != INT_MAX) {
                            int diff = abs(j - k);
                            dp[i][j] = min(dp[i][j], dp[i - 1][k] + min(diff, n - diff) + 1);
                        }
                    }
                }
            }
        }
        
        
        return *min_element(dp[m - 1].begin(), dp[m - 1].end());
    }