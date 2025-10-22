/*
    Driver file for search algorithms
*/
#include <iostream>

using namespace std;

int linearSearch(int [], int, int);
int binarySearch(int [], int, int, int);
void selectionSort(int [], int);
void insertionSort(int [], int);

int main(){

    int array[] = {52, 30, 22, 88, 90, 100};
    int size = sizeof(array);
    int key = 22;
    int index = -1;

    //linear search. should return 2, index for 22
    cout << "\nLINEAR SEARCH:"
         << "\nSearching for 22..."
         << "\nResults: ";
    index = linearSearch(array, size, key);
    if(index != -1){
        cout << "\nFound 22 at index " << index;
    }
    else{
        cout << "\nDid not find 22";
    }

    //binary search.
    int array2[] = {10, 22, 25, 27, 46, 88};
    int size2 = sizeof(array2);
    int key2 = 46;
    int index2 = 0, high = size2, low = 0;

    cout << "\n\nBINARY SEARCH:"
         << "\nSearching for 46..."
         << "\nResults:  ";
    index2 = binarySearch(array2, key2, low, high);
     if(index2 != -1){
        cout << "\nFound 46 at index " << index2;
    }
    else{
        cout << "\nDid not find 46";
    }
    
    //selectionSort
    int array3[] = {5, 4, 3, 2, 1};
    int size3 = sizeof(array3);

    cout << "\n\nSELECTION SORT:"
         << "\nstarting array = [5, 4, 3, 2, 1]";
    selectionSort(array3, size3);
}