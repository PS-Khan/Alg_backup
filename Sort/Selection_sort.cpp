#include <iostream>

//O(n^2)
void selection_sort (int *arr ,int size){
    for (int i=0; i<size; i++){
        int min = i;
        for (int j = i+1; j < size; j++ ){ 
            if (arr[min] > arr[j]){ // <
                min = j;
            }
        }
        int tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = tmp;
    }
}

int main(){
    int arr[9]= {1,3,4,6,7,9,8};
    selection_sort(arr, 9);

    for (int i : arr){
        std::cout<<i<<" ";
    }

    return 0;
}