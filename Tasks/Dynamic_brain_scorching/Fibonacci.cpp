#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <cstring>
#include <queue>
#include <limits>

using namespace std;

//Tn-1 + Tn-2 + O(1) = F^n  = (1+sqrt(5)/2)^n
long long t_down_fib(int n, std::vector<long long> &memo);

void fib_caller(int n){
    std::vector<long long> memo(n + 1, 0);
    std::cout << t_down_fib(n, memo) << std::endl;
}

long long t_down_fib(int n, std::vector<long long> &memo){
    long long result;
    if (memo[n] != 0){
        return memo[n];
    }
    if (n <= 2){
        result = 1;
    } else {
        result = t_down_fib(n-1, memo) + t_down_fib(n-2, memo);
    }
    memo[n] = result;
    return result;
}

long long b_up_fib(int n) {
    std::vector<long long> memo = {1, 1, 2, 3, 5};
    long long result;

    for (int i = 5; i < n + 1; i++) {
        result = memo[i - 1] + memo[i - 2];  
        memo.push_back(result);
    }

    return result;
}

int main() {
    std::cout << b_up_fib(10) << std::endl;
    return 0;
}