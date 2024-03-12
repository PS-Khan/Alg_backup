#include <iostream>

//O(n^2)
void buble_sort (int *arr ,int size){
    for (int i=0; i<size; i++){
        for(int j=0; j<size-i-1; j++){

            if(arr[j] < arr[j+1]){ // >
                int tmp =arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }

        }
    }
}

int main(){
    int arr[9]= {1,3,4,6,7,9,8};
    buble_sort (arr, 9);

    for (int i : arr){
        std::cout<<i<<" ";
    }

    return 0;
}