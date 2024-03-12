#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <cstring>
#include <queue>
#include <limits>
#include <vector>

using namespace std;

//1
int greadyMincoins(int target, int *coins, int number_c){
    int count = 0;

    while(target > 0){
        int max = 0;
        bool validCoinFound = false;
        for (int i=0; i < number_c; i++){
            if(coins[i] <= target && max < coins[i] ){
                max = coins[i];
                validCoinFound = true;
            }
        }
        if (!validCoinFound) { 
            return -1;
        }
        target-=max;
        count ++;
    }
    
    return count;
   


}

//2
std::unordered_map<int, int> memo;
int min_coins(int *coins, int target, int number_c) {

    if(memo.find(target) != memo.end()){
        return memo[target];
    }

    int answear = std::numeric_limits<int>::max(); 
    if (target == 0) {
        answear = 0;
    } else {
        for (int i = 0; i < number_c; i++) {
            int subproblem = target - coins[i];
            if (subproblem < 0) {
                continue;
            } else {
                answear = std::min(answear, min_coins(coins, subproblem, number_c) + 1);
            }
        }
    }
    memo[target] = answear;
    return answear;
}

int b_up_min_coins(int *coins, int target, int number_c) {
    std::unordered_map<int, int> memo;
    for (int i = 0; i <= target; i++) {
        memo[i] = INT_MAX;  
    }
    memo[0] = 0;  
    for (int i = 1; i <= target; i++) {
        for (int coin = 0; coin < number_c; coin++) {
            int subproblem = i - coins[coin];
            if (subproblem < 0) {
                continue;
            }
            memo[i] = std::min(memo[i], memo[subproblem] + 1);
        }
    }
    return memo[target] == INT_MAX ? -1 : memo[target];
}



int main() {
    int coins[3] = {1, 4, 5};
    int target = 100;
    std::cout<<greadyMincoins(target, coins, 3)<<std::endl;
    std::cout<<min_coins(coins, target, 3)<<std::endl;
    std::cout<<b_up_min_coins(coins, target, 3);
    
    return 0;
}