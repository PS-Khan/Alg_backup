#include <iostream>


int partition (int *arr ,int start ,int end ){
    int pivot=arr[end];
    int i = start-1;

    for (int j = start; j<end; j++){
        if (arr[j] < pivot) {
            i++;
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    i++;
    int tmp = arr[i];
    arr[i] = arr[end];
    arr[end] = tmp;

    return i;

    
}

void quick_sort (int *arr ,int start ,int end ){
    if(end<=start){
        return; //base case
    }

    int pivot = partition(arr, start, end);

    quick_sort(arr,start, pivot-1);
    quick_sort(arr,pivot+1, end);
}

int main(){
    int arr[9]= {1,5,3,6,2,9,8};
    quick_sort(arr, 0,9);

    for (int i : arr){
        std::cout<<i<<" ";
    }

    return 0;
}