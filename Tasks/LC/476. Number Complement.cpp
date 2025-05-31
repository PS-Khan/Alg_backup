/*

The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
Given an integer num, return its complement.
https://leetcode.com/problems/number-complement/?envType=daily-question&envId=2024-08-22
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

class Solution {
public:
    int findComplement(int num) {
        long tmp = 1;
        long n = num;
        while(n>0){
            tmp <<=1;
            n >>=1;
        }
        tmp--;
        
        return num ^ tmp;
    }
};



//

/*
Here we need a little bit pattern observation.
How we take complement of 5 which is 2
5 -> 1 0 1
2 -> 0 1 0

But if we observe carefully
5 + 2 = 7
which is in binary -> 1 1 1

So we don't need to go to each bit and convert it
we just need to next number filled by 1

like if we need to complement -> 1 1 0 1 0 1 (53)
then we just need to find -> 1 1 1 1 1 1 (63)
and subtract it -> 1 1 1 1 1 1 - 1 1 0 1 0 1 (63 - 53) = 10

so we will find next power of 2 greater thanks the number and subtract 1 to make this all 1

and we will subtact the number from it and will get the complement.

That's it.
*/
int findComplement(int num) {
        if(num == 0)return 1;
        int i = 0;
        while(pow(2,i) <= num){
            i++;
        }
        return pow(2,i) - num - 1;
    }