/*
https://leetcode.com/problems/find-the-closest-palindrome/description/

Given a string n representing an integer, return the closest integer (not including itself), which is a palindrome. If there is a tie, return the smaller one.

The closest is defined as the absolute difference minimized between two integers.

 
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
    
    bool check_num(long long num) {
        std::string n = std::to_string(num);
        std::string reversed_n = n;
        std::reverse(reversed_n.begin(), reversed_n.end());
        return n == reversed_n;
    }

    std::string nearestPalindromic(std::string n) {
        long long num;
        try {
            num = std::stoll(n); 
        } catch (const std::out_of_range& e) {
            std::cerr << "Number out of range: " << e.what() << std::endl;
            return "";
        }

        long long i = num - 1, j = num + 1;

        while (true) {
            if (check_num(i)) return std::to_string(i);
            if (check_num(j)) return std::to_string(j);
            i--;
            j++;
        }

        return n;
    }

};
/*

Intuition
The problem asks us to find the closest palindrome to a given integer n represented as a string. The string length is at most 10, meaning n can be as large as 9,999,999,999. The goal is to return the nearest palindrome to n that is not equal to n itself, minimizing the absolute difference.

To solve this, we can think of a palindrome as a number where the first half is mirrored to create the second half. For example, the palindrome for 12321 is formed by reversing the first half (12) and appending it to itself (12 -> 12321). This observation is key to finding the closest palindrome.

If we consider changing the second half of n to match the reverse of the first half, we might obtain a palindrome close to n. However, there are cases where this method might not give us the optimal answer, particularly for odd-length strings or when small adjustments to the first half could yield a closer palindrome.

For instance, consider n = 139. If we mirror the first half (13), we get 131, but a closer palindrome is 141. Therefore, it's important to also check palindromes formed by slightly adjusting the first half of n:

Same Half: Create a palindrome by mirroring the first half.
Decremented Half: Create a palindrome by decrementing the first half by 1 and mirroring it.
Incremented Half: Create a palindrome by incrementing the first half by 1 and mirroring it.
Note: Adding +1 or subtracting -1 to/from the first half ensures that we stay as close as possible to the original number while creating new potential palindromes. If we were to add or subtract a larger value, such as +2 or -2, the resulting palindrome would be farther away from the original number, potentially missing a closer palindrome, and it's given that we need to find the closest palindrome.

In addition to these cases, we must handle edge cases where n is close to numbers like 1000, 10000, etc., or very small numbers like 11 or 9. These can produce palindromes like 99, 999, or 101, 1001, which might be closer to n.

To summarize, we need to check the following five candidates:

Palindrome formed from the first half of n.
Palindrome formed from the first half decremented by 1.
Palindrome formed from the first half incremented by 1.
Nearest palindrome of the form 99, 999, etc.
Nearest palindrome of the form 101, 1001, etc.
After generating these candidates, we compare them to n and choose the one with the smallest absolute difference.

*/
//

class Solution {
public:
    // Convert to palindrome keeping first half constant.
    long long convert(long long& num) {
        string s = to_string(num);
        int n = s.length();
        int l = (n - 1) / 2, r = n / 2;
        while (l >= 0) s[r++] = s[l--];
        return stoll(s);
    }
    // Find the next palindrome, just greater than n.
    long long nextPalindrome(long long num) {
        long long left = 0, right = num;
        long long ans = INT_MIN;
        while (left <= right) {
            long long mid = (right - left) / 2 + left;
            long long palin = convert(mid);
            if (palin < num) {
                ans = palin;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
    // Find the previous palindrome, just smaller than n.
    long long previousPalindrome(long long num) {
        long long left = num, right = 1e18;
        long long ans = INT_MIN;
        while (left <= right) {
            long long mid = (right - left) / 2 + left;
            long long palin = convert(mid);
            if (palin > num) {
                ans = palin;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
    string nearestPalindromic(string n) {
        int len = n.size();
        long long num = stoll(n);
        long long a = nextPalindrome(num);
        long long b = previousPalindrome(num);
        if (abs(a - num) <= abs(b - num)) return to_string(a);
        return to_string(b);
    }
};

class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.size();
        int i = len % 2 == 0 ? len / 2 - 1 : len / 2;
        long firstHalf = stol(n.substr(0, i + 1));
        /*
        Generate possible palindromic candidates:
        1. Create a palindrome by mirroring the first half.
        2. Create a palindrome by mirroring the first half incremented by 1.
        3. Create a palindrome by mirroring the first half decremented by 1.
        4. Handle edge cases by considering palindromes of the form 999...
           and 100...001 (smallest and largest n-digit palindromes).
        */
        vector<long> possibilities;
        possibilities.push_back(halfToPalindrome(firstHalf, len % 2 == 0));
        possibilities.push_back(halfToPalindrome(firstHalf + 1, len % 2 == 0));
        possibilities.push_back(halfToPalindrome(firstHalf - 1, len % 2 == 0));
        possibilities.push_back((long)pow(10, len - 1) - 1);
        possibilities.push_back((long)pow(10, len) + 1);

        long diff = LONG_MAX, res = 0, nl = stol(n);
        for (auto cand : possibilities) {
            if (cand == nl) continue;
            if (abs(cand - nl) < diff) {
                diff = abs(cand - nl);
                res = cand;
            } else if (abs(cand - nl) == diff) {
                res = min(res, cand);
            }
        }

        return to_string(res);
    }

private:
    long halfToPalindrome(long left, bool even) {
        long res = left;
        if (!even) left = left / 10;
        while (left > 0) {
            res = res * 10 + left % 10;
            left /= 10;
        }
        return res;
    }
};