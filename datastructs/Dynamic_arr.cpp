#include <iostream>



void shifted(int *arr, int pos, int size){
    
    int new_arr[size]={0};

    for(int i=0; i<size; i++){
        new_arr[(pos+i)%size]=arr[i];
    }

    for(int i=0; i<size; i++){
        arr[i]= new_arr[i];
        std::cout<<arr[i];
    }

}


void shift_and_place(int *arr, int pos, int size, int place, int number){
    int new_arr[size]={0};
    place%=size;
    
    for(int i=place; i<size; i++){
        new_arr[(pos+i)%size]=arr[i];
    }

    new_arr[place]=number;

    for(int i=0; i<place; i++){
        new_arr[i] = arr[i];
    }

    for(int i=0; i<size; i++){
        arr[i] = new_arr[i];
        std::cout<<arr[i];
    }

}

void resizeArray(int* &arr, int oldSize, int newSize) {
    // Allocate a new array with the desired size
    int *newArr = new int[newSize];

    // Copy elements from the old array to the new array
    int elementsToCopy = std::min(oldSize, newSize);
    for (int i = 0; i < elementsToCopy; ++i) {
        newArr[i] = arr[i];
    }

    // Release the memory of the old array
    delete[] arr;

    // Update the pointer to point to the new array
    arr = newArr;
}



int main(){
    int arr[6]={1,2,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    shift_and_place(arr,2,size,2,3);

    
	int x, n;
	std::cout << "Enter the number of items:" << "\n";
	std::cin >>n;
	int *arr = new int(n);
	std::cout << "Enter " << n << " items" << std::endl;
	for (x = 0; x < n; x++) {
		std::cin >> arr[x];
	}
	std::cout << "You entered: ";
	for (x = 0; x < n; x++) {
		std::cout << arr[x] << " ";
	}


    int *arr2 = new int[5]{1, 2, 3, 4, 5};
    int oldSize = 5;
    int newSize = 8;

    // Resize the array
    resizeArray(arr2, oldSize, newSize);

    // Print the resized array
    for (int i = 0; i < newSize; ++i) {
        std::cout << arr2[i] << " ";
    }

    // Don't forget to deallocate the memory when done
    delete[] arr2;

	return 0;
}

