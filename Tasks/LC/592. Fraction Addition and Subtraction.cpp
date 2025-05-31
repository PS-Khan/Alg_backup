/*
Given a string expression representing an expression of fraction addition and subtraction, return the calculation result in string format.

The final result should be an irreducible fraction. If your final result is an integer, change it to the format of a fraction that has a denominator 1. So in this case, 2 should be converted to 2/1.

https://leetcode.com/problems/fraction-addition-and-subtraction/description/?envType=daily-question&envId=2024-08-23
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
#include <sstream>
#include <regex>

using namespace std;

class Solution {
public:
    struct num {
        bool sign;
        int d;
        int n;
    };

    std::vector<std::string> splitString(const std::string &str) {
        std::vector<std::string> result;
        std::regex re("([+-]?\\d+/\\d+)");
        std::sregex_iterator it(str.begin(), str.end(), re);
        std::sregex_iterator reg_end;

        while (it != reg_end) {
            result.push_back(it->str());
            ++it;
        }

        return result;
    }

    std::string calculate(std::vector<num> nums) {
        int numerator = nums[0].sign ? nums[0].d : -nums[0].d;
        int denominator = nums[0].n;

        for (size_t i = 1; i < nums.size(); ++i) {
            int num_i = nums[i].sign ? nums[i].d : -nums[i].d;
            int denom_i = nums[i].n;

            
            numerator = numerator * denom_i + num_i * denominator;
            denominator *= denom_i;
            
           
            int divisor = FindGCD(abs(numerator), denominator);
            numerator /= divisor;
            denominator /= divisor;
        }

      
        std::ostringstream result;
        if (numerator < 0) {
            result << "-";
            numerator = -numerator;
        }
        result << numerator << "/" << denominator;

        return result.str();
    }

    std::string fractionAddition(std::string expression) {
        std::vector<num> nums;
        std::vector<std::string> parts = splitString(expression);

        for (size_t i = 0; i < parts.size(); ++i) {
            std::string prt = parts[i];
            num currentNum;

            if (prt[0] == '-') {
                currentNum.sign = false;
                prt = prt.substr(1);  
            } else {
                currentNum.sign = true;
                if (prt[0] == '+') {
                    prt = prt.substr(1); 
                }
            }

            size_t slashPos = prt.find('/');
            if (slashPos != std::string::npos) {
                currentNum.d = std::stoi(prt.substr(0, slashPos));   
                currentNum.n = std::stoi(prt.substr(slashPos + 1)); 
            }

            nums.push_back(currentNum);
        }

        return calculate(nums);
    }

    int FindGCD(int a, int b) {
        if (a == 0) return b;
        return FindGCD(b % a, a);
    }
};


//


class Solution {
public:
    string fractionAddition(string expression) {
        int num = 0;
        int denom = 1;

        int i = 0;
        while (i < expression.size()) {
            int currNum = 0;
            int currDenom = 0;

            bool isNegative = false;

            // check for sign
            if (expression[i] == '-' || expression[i] == '+') {
                if (expression[i] == '-') {
                    isNegative = true;
                }
                // move to next character
                i++;
            }

            // build numerator
            while (isdigit(expression[i])) {
                int val = expression[i] - '0';
                currNum = currNum * 10 + val;
                i++;
            }

            if (isNegative) currNum *= -1;

            // skip divisor
            i++;

            // build denominator
            while (i < expression.size() && isdigit(expression[i])) {
                int val = expression[i] - '0';
                currDenom = currDenom * 10 + val;
                i++;
            }

            // add fractions together using common denominator
            num = num * currDenom + currNum * denom;
            denom = denom * currDenom;
        }

        int gcd = abs(FindGCD(num, denom));

        // reduce fractions
        num /= gcd;
        denom /= gcd;

        return to_string(num) + "/" + to_string(denom);
    }

private:
    int FindGCD(int a, int b) {
        if (a == 0) return b;
        return FindGCD(b % a, a);
    }
};


//

class Solution {
public:
    string fractionAddition(string expression) {
        int num = 0;
        int denom = 1;

        // separate expression into signed numbers
        vector<string> nums;
        int i = 0;
        if (expression[0] != '-') expression = '+' + expression;
        while (i < expression.size()) {
            int j = i + 1;
            while (j < expression.size() && expression[j] != '+' &&
                   expression[j] != '-') {
                j++;
            }
            nums.push_back(expression.substr(i, j - i));
            i = j;
        }

        for (int i = 0; i < nums.size(); ++i) {
            size_t pos = nums[i].find('/');
            int currNum = stoi(nums[i].substr(1, pos - 1));
            if (nums[i][0] == '-') currNum = -currNum;
            int currDenom = stoi(nums[i].substr(pos + 1));

            num = num * currDenom + currNum * denom;
            denom = denom * currDenom;

            int gcd = abs(FindGCD(num, denom));

            num /= gcd;
            denom /= gcd;
        }

        return to_string(num) + "/" + to_string(denom);
    }

private:
    int FindGCD(int a, int b) {
        if (a == 0) return b;
        return FindGCD(b % a, a);
    }
};