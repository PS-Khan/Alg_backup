/*

Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "(*)"
Output: true
Example 3:

Input: s = "(*))"
Output: true
 

Constraints:

1 <= s.length <= 100
s[i] is '(', ')' or '*'.

*/
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

/*
my expl to this woodo magic:
Consider cases (*) and (*)) .

1) char ( :   l++; -> l = 1;   r++; -> r = 1;

2) * :  in minimum case, we can take * as ) so l--; l = 0; in max case * will be another ( so r++; r = 2;

3) ) : l--; l = -1; r--; r = 1; This result means that we closed all opened (pure, not * ) parentheses and still can handle one more ) . two abstract results : 1. ()) ->  ) => l = -1  ; 2.  (() -> ( => r = 1;

so in case (*)) ->  l would be -2; r = 0;

if l > 0 we have some opened ( . exmp: ((* -> l =1 ; r = 3;
*/

bool checkValidString(std::string s) {
        int lo = 0, hi = 0;
        for (char &c : s) {
            if (c == '(') {
                lo++;
                hi++;
            } else if (c == '*') {
                lo--;
                hi++;
            } else {  // c == ')'
                lo--;
                hi--;
            }
            if (hi < 0) return false; 
            lo = std::max(lo, 0); 
        }
        return lo == 0;