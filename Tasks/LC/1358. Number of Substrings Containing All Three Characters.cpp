/*
https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/?envType=daily-question&envId=2025-03-11

*/


#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <set>
#include <utility>
#include <stack>

using namespace std;


class Solution {
public:
    int numberOfSubstrings(string s) {
        int a = 0 ,  b = 0, c = 0;
        int res = 0;
        int size  = s.length(); 
        int j = 0;
        for(int i  = 0; i < size; i++){
            if(s[i] == 'a'){
                a++;
            }else if(s[i] == 'b'){
                b++;
            }else if(s[i] == 'c'){
                c++;
            }
            if (a>0 && b>0 && c>0){
                while(a && b && c && j != i){
                    res+= size - i;
                    if(s[j] == 'a'){
                        a--;
                    }else if(s[j] == 'b'){
                        b--;
                    }else if(s[j] == 'c'){
                        c--;
                    }
                    j++;
                    
                }
                
            }
        }
        return res;
    }
};