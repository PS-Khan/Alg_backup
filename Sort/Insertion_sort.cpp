#include <iostream>

//O(n^2)
void insertion_sort (int *arr ,int size){
    for (int i=1; i<size; i++){
        int tmp =arr[i];
        int j = i-1;

        while (j >= 0 && arr[j] > tmp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = tmp;
    }
}

int main(){
    int arr[9]= {1,3,4,6,7,9,8};
    insertion_sort(arr, 9);

    for (int i : arr){
        std::cout<<i<<" ";
    }

    return 0;
}