#include <iostream>

int interpolation_sort (int *arr, int value, int size){
    int high = size-1;
    int low = 0;

    while(value >=arr[low] &&  value <= arr[high] && low <= high ){
        
        int probe = low + (high - low) * (value - arr[low]) /
        (arr[high] - arr[low] );

        std::cout<<probe<<std::endl;

        if(arr[probe] == value){
            return probe;
        }else if(arr[probe] < value){
            low = probe + 1;
        }else{
            high = probe -1 ;
        }
    }
    return -1;
    


}

int main(){

    int arr[100]={};

    for (int i=0;i<100;i++){
        arr[i]=i;
    }

    std::cout<<interpolation_sort(arr,88,100);

    return 0;
}