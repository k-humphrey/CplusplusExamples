/*
    filename: driver.cpp
    Author: Kayla Humphrey
    Date: 10/23/2023
    Purpose: driver file for a binary search tree
*/
#include "bst.h"

int main(){
    //make a tree
    bst tree;

    cout << "\nCreating a new tree {1,3,4,5,7,8}";
    tree.insert(5);
    tree.insert(8);
    tree.insert(7);
    tree.insert(3);
    tree.insert(4);
    tree.insert(1);

    cout << "\n\nPrint functions:\n";
    tree.print();

    cout << "\nSearch for 6 using regular (will not exist)";
    tree.search(6);
    cout << "\nSearch for 6 using recursive search (should return -1)";
    tree.rsearch(6);

    cout << "\nSearch for 3 using regular (will exist)";
    tree.search(3);
    cout << "\nSearch for 3 using recursive search (should return 3)";
    tree.rsearch(3);

    cout << "\n\nPrint functions:\n";
    tree.print();

}