#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <stack>
#include <vector>
#include <queue>
#include <list>
#include <thread>
#include <mutex>
#include<string>
using namespace std;

/*

Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

 

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.

*/

string removeKdigits(string num, int k) {
        int i = 0;
        while(k>0 && i+1 < num.length()){
            if(num[i] > num[i+1] ){
                num.erase(i,1);
                k--;
                if(i>0){
                    i--;
                }
            }else{
                i++;
            }  
        }
        while (!num.empty() && num[0] == '0') {
            num.erase(0, 1);
        }
        while (k > 0 && !num.empty()) {
            num.pop_back();
            k--;
        }
        if(num.length() == 0){
            num.push_back('0');
        }
        return num;
        
    }

    string removeKdigits(string num, int k) {
        std::string result;
        for (char digit : num) {
            while (!result.empty() && k > 0 && result.back() > digit) {
                result.pop_back();
                k--;
            }
            result.push_back(digit);
        }
        result.resize(result.length() - k);
        
        size_t nonZeroIndex = result.find_first_not_of('0');
        result = (nonZeroIndex != std::string::npos) ? result.substr(nonZeroIndex) : "0";

        return result;
            
    }

int main(){
    
    return 0;
}