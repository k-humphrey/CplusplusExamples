/*
    Filename: Budget.h
    Author: Kayla Humphrey
    Date: 3/29/2023
    Purpose: Header file for lab 8
*/

#ifndef BUDGET_H
#define BUDGET_H
    #include <iostream>
    #include <cstring>
    #include <iomanip>

    using namespace std;
    //global variables
    const int COLUMN = 3;
    const int ROW = 4;
    const int CHARCOLUMN = 50; //has to be big enough to hold word length + 1

    //function prototypes
    void getUserInput(string [], double [], char [][CHARCOLUMN], double [][COLUMN]);
    void calculateBalance(double [], double [], double [][COLUMN]);
    int getHighest(double []);
    int getLowest(double []);
#endif