#include <iostream>
using namespace std;

/*
    Name: Linear Search
    Precondition: None
    Process: unsorted data, one by one until found. returns index of element or -1 if 
             not found.
*/
int linearSearch(int arr[], int size, int key){
    for(int i = 0; i < size; i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}

/*
    Name: Binary Search
    Precondition: Data must be sorted from least to greatest.
    Process:check the halfwaypoint and then discard the half of the data that will not match
*/
int binarySearch(int arr[], int key, int low, int high){
    int mid = (high + low) / 2;

    if(arr[mid] == key){ // base found
        return mid;
    }
    if(low > high) // base unfound
        return -1;
    else if(key < arr[mid]){ //recursive leftside
        return binarySearch(arr, key, low, (mid-1));
    }
    else{
        return binarySearch(arr, key, (mid+1), high);
    }
    
}
/*
    NON Recursive Binary Search 
    int l = 0, r = size - 1;
    int mid = (l + r) / 2; //check middle

    while(l <= r){
        mid = (l + r) / 2;
        if(arr[mid] == key){ //base case
            return mid;
        }
        else if(key < arr[mid]){ //check left
            r = mid - 1;
        }
        else{ //check right 
            l = mid + 1;
        }
    }
    return -1;
*/

/*
    Name: bubbleSort
    Precondition: Need an array of values and size
    Process: Go through neighbors and swap if necessary, if a full pass makes no swaps, it is done.
*/
void bubbleSort(int arr[], int size){
    //rewrite to stop if done
    for(int j = 0; j < size; j++){
        for(int i = 0; i < size - 1; i++){
            if(arr[i] > arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
}

/*
    Name selectionSort
    Precondition: Need an array of values and size
    Process: Linear searches through data that hasnt been sorted, selects smallest number and puts at the front of the remaining.
             Stops when the smallest is in the correct spot. 
*/
int* selectionSort(int arr[], int size){
    //write
    
}

/*
    name insertionSort
    Precondition: need an array of values and size
    Process: takes the first value of the array, inserts it where it goes in a new sorted array, then it will take the next value
    Stops when the last value has been sorted
*/
void insertionSort(int arr[], int size){
    //write
}

/* recursive
*/
void quickSort(){
   
}

/* recursive
*/
void mergeSort(){

}