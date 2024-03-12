#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <cstring>
#include <queue>
#include <limits>
#include <vector>

using namespace std;

long long maze_all_ways(int rows, int cols){
    std::vector<std::vector<long>> memo;
    memo.resize(rows);
    for (auto &row : memo){
        row.resize(cols);
    }
    //std::cout<< memo.capacity()<< " " << memo[0].capacity()<<std::endl;
    for(int i = 0; i < rows ; i++){
        memo[i][0] = 1;
    }
    for(int i = 0; i < cols ; i++){
        memo[0][i] = 1;
    }

    for(int i = 1; i < rows; i++){
        for(int j = 1; j < cols; j++){
            memo[i][j] = memo[(i - 1)][j] + memo[i][j-1];
        }
    }
    std::cout<<memo[rows-1][cols-1];
    return memo[rows-1][cols-1];

}

int main() {
    maze_all_ways(18,6);
    return 0;
}