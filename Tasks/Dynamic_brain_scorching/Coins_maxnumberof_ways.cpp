#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <cstring>
#include <queue>
#include <limits>
#include <vector>

using namespace std;



long long b_up_max_ways_coins(int *coins, int target, int number_c) {
    std::unordered_map<long long, long long> memo = {};
    memo[0] = 1;  
    for (int i = 1; i <= target; i++) {
        memo[0] = 1;  
        for (int coin = 0; coin < number_c; coin++) {
            int subproblem = i - coins[coin];
            if (subproblem < 0) {
                continue;
            }
            memo[i] = memo[i] + memo[subproblem];
        }
    }
    return memo[target];
}



int main() {
    int coins[4] = {1, 4, 5, 8};
    int target = 87;
    std::cout<<b_up_max_ways_coins(coins, target, 4);
    
    return 0;
}