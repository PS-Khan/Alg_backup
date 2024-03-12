#include <iostream>

bool l_search(int *array, int target, size_t steps){
    for(size_t i; i<steps;i++){
        if(array[i]==target){
            return true;
        }
    }
    return false;
}

//need to be sorted
int b_search(int *array, int target, int length){
    int low=0, high=length-1;
    while(low<=high){
        int midle = low + (high-low)/2;
        int value = array[midle];

        if(value < target){
            low = midle+1;
        }else if(value > target){
            high = midle-1;
        }else{
            return midle;
        }
    }
    return -1;
}

int main()
{
    int arr[5]={1,2,3,4,5};
    std::cout<<l_search(arr,5,5)<<std::endl;


    int arr2[100]={};
    for(int i=0;i<100;i++){
        arr2[i]=i;
    }

    std::cout<<b_search(arr2,42,100);

    return 0;
}