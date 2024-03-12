#include <iostream>
#include <vector>

bool search_in_matrix(int *target, std::vector<std::vector<int>> *matrix){
    int rows = 0;
    int cols = matrix->at(0).size() - 1;
    while(rows < matrix->size() && cols > 0){
        if((*target) == matrix->at(rows ).at(cols)){
            return true;
        } else if((*target) > matrix->at(rows ).at(cols) ) {
            rows++;
        }else{
            cols--;
        }
    }
    return false;
}


int main(){
    std::vector<std::vector<int>>matrix = {
        {1,4,7,11},
        {2,5,8,12},
        {3,6,9,16},
        {10,13,14,17}
    };
    int target = 9;
    std::cout<<search_in_matrix( &target, &matrix);
    return 0;
}