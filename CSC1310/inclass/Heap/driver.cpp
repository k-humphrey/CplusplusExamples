/*
    name: driver.cpp
    author: Kayla Humphrey
    date: 11/3/2023
    purpose: driver for a heap class
*/
#include "Heap.h"

int main(){
    Heap myheap(5);
    int temp;

    cout << "\nTry to remove a value from empty";
    temp = myheap.remove();
    cout << "\nFalse removal of temp: " << temp;

    cout << "\ninserting 1,2,3,4,5";
    myheap.insert(1);
    myheap.insert(2);
    myheap.insert(3);
    myheap.insert(4);
    myheap.insert(5);
    cout << "\ninsertion complete, height is " << myheap.getHeight();
    cout << "\nThe top node is " << myheap.peek();

    cout << "\nTrying to add more than capacity...";
    myheap.insert(6);
    cout << "\nIt's okay still.";

    

    
}