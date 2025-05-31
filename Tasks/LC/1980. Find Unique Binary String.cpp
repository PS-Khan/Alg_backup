
/*
https://leetcode.com/problems/find-unique-binary-string/description/?envType=daily-question&envId=2025-02-20
Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.

 

Example 1:

Input: nums = ["01","10"]
Output: "11"
Explanation: "11" does not appear in nums. "00" would also be correct.
Example 2:

Input: nums = ["00","01"]
Output: "11"
Explanation: "11" does not appear in nums. "10" would also be correct.
Example 3:

Input: nums = ["111","011","001"]
Output: "101"
Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.
 

Constraints:

n == nums.length
1 <= n <= 16
nums[i].length == n
nums[i] is either '0' or '1'.
All the strings of nums are unique.

*/

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <set>
#include <queue>
#include <set>
#include <utility>
#include <stack>

using namespace std;


//my sol

class Solution {
public:
    string backtrack(unordered_map<string,int> &map, int size, string &res){
        int j = 0;
        for(int i = res.length(); i <= size; i++){
            res+= to_string(j);
            j = (j + 1) %2;
            if(res.length() == size && map.find(res) == map.end()){
                return res;
            }
            backtrack(map, size, res);
            res.pop_back();
        }
        return "";
    }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string, int> map;
        int size = nums[0].length();
        for(string &i : nums){
            map[i]++;
        }
        string res = "";
        backtrack(map, size, res);
        return res;
    }
};



/*


Approach 4: Cantor's Diagonal Argument
Intuition

Cantor's diagonal argumentis a proof in set theory.

While we do not need to fully understand the proof and its consequences, this approach uses very similar ideas.

We start by initializing the answeransto an empty string. To buildans, we need to assign either"0"or"1"to each indexifor indices0ton - 1. How do we assign them soansis guaranteed to be different from every string innums? We know that two strings are different, as long as they differ by at least one character. We can intentionally construct ouransbased on this fact.

For each indexi, we will check thei 
th
 character of thei 
th
 string innums. That is, we checkcurr = nums[i][i]. We then assignans[i]to the opposite ofcurr. That is, ifcurr = "0", we assignans[i] = "1". Ifcurr = "1", we assignans[i] = "0".

What is the point of this strategy?answill differ from every string inat leastone position. More specifically:

ansdiffers fromnums[0]innums[0][0].
ansdiffers fromnums[1]innums[1][1].
ansdiffers fromnums[2]innums[2][2].
...
ansdiffers fromnums[n - 1]innums[n - 1][n - 1].
Thus, it is guaranteed thatansdoes not appear innumsand is a valid answer.

This strategy is applicable because both the length ofansand the length of each string innumsare larger than or equal ton, the number of strings innums. Therefore, we can find one unique position for each string innums.

Algorithm

Initialize the answerans. Note that you should build the answer in an efficient manner according to the programming language you're using.
Iterateiover the indices ofnums:
Setcurr = nums[i][i].
Ifcurr = "0", add"1"toans. Otherwise, add"0"toans.
Returnans.
Implementation


Complexity Analysis

Givennas the length ofnums(and the length of each binary string),

Time complexity:O(n)

We iterate over each string innums. Assuming the string building is efficient, each iteration costsO(1), and joining the answer string at the end costsO(n).

Space complexity:O(1)

We don't count the answer as part of the space complexity.


*/

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans;
        for (int i = 0; i < nums.size(); i++) {
            char curr = nums[i][i];
            ans += curr == '0' ? '1' : '0';
        }
        
        return ans;
    }
};