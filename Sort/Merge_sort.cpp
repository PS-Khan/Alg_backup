#include <iostream>

//O(nlog(n)) //more space O(n)

void merge(int *lef_arr, int *righ_arr, int *arr, int l_size , int r_size ){
    int i = 0, l = 0, r = 0; //indices

    while(l < l_size && r < r_size){
        if(lef_arr[l]<righ_arr[r]){
            arr[i]=lef_arr[l];
            i++;
            l++;
        }else{
            arr[i]=righ_arr[r];
            i++;
            r++;
        }
    }
    while (l<l_size){
        arr[i] = lef_arr[l];
        i++;
        l++;
    }
    while (r<r_size){
        arr[i] = righ_arr[r];
        i++;
        r++;
    }

}

void merge_sort (int *arr ,int size){
    if(size<=1)return;

    int middle = size/2;
    int left_arr[middle];
    int right_arr[size-middle];

    int i = 0;//left
    int j = 0;//right

    for(;i<size;i++){
        if(i<middle){
            left_arr[i] = arr[i];
        }else{
            right_arr[j] = arr[i];
            j++;
        }
    }

    merge_sort(left_arr,middle);
    merge_sort(right_arr,size-middle);

    merge(left_arr,right_arr,arr,middle,size-middle);
    
}

int main(){
    int arr[9]= {1,5,3,6,2,9,8};
    merge_sort(arr, 9);

    for (int i : arr){
        std::cout<<i<<" ";
    }

    return 0;
}