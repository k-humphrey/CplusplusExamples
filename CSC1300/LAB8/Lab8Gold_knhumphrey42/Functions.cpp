/*
    Filename: Functions.cpp
    Author: Kayla Humphrey
    Date: 3/29/2023
    Purpose: Functions for lab 8
*/

#include "Budget.h"

/*
    Name: getUserInput()
    Purpose:Takes user name, income, expenditures, and categories
*/
void getUserInput(string name[], double income[], char category[][CHARCOLUMN], double expenditures[][COLUMN]){
    //category
    cout << "Please enter the expenditure category names.\n";
    for(int i = 0; i < ROW; i++){
        cout << "NAME OF CATEGORY " << i + 1 << " - ";
        cin.getline(category[i], CHARCOLUMN);
    }
    //the rest
    cout << "\n\nPlease enter each student's data.";
    for(int i = 0; i < COLUMN; i++){ //runs 3 times 
        cout << "\nSTUDENT " << i + 1 << ":";
        cout << "\n\tNAME - ";
        getline(cin, name[i]);
        cout << "\tINCOME - $";
        cin >> income[i];
        cin.ignore();
        cout << "\tEXPENDITURES\n";
        for(int j = 0; j < ROW; j++){ // runs 4 times
            cout << "\t" << category[j] << " - $";
            cin >> expenditures[j][i];
            cin.ignore();
        }
    }
}

/*
    Name: calculateBalance()
    Purpose: adds up expenditures, subtracts from income, places in remaining
*/
void calculateBalance(double remaining[], double income[], double expenditures[][COLUMN]){
    double total = 0.0;
    for(int i = 0; i < COLUMN; i++){ //runs 3 times
        total = 0.0; //start each out with balance of 0
        for(int j = 0; j < ROW; j++){ // runs 4 times
            total += expenditures[j][i]; // add up the row
        }
        remaining[i] = income[i] - total; // subtract total from income
    }
}

/*
    Name: getHighest()
    Purpose: returns the index of the student with the highest remaining balance
*/
int getHighest(double remaining[]){
    double max = remaining[0];
    int index = 0;
    for(int i = 0; i < COLUMN; i++){
        if(remaining[i] > max){
            max = remaining[i];
            index = i;
        }
    }
    return index;
}

/*
    Name: getLowest()
    Purpose: returns the index of the student with the lowest remaining balance
*/
int getLowest(double remaining[]){
    double min = remaining[0];
    int index = 0;
    for(int i = 0; i < COLUMN; i++){
        if(remaining[i] < min){
            min = remaining[i];
            index = i;
        }
    }
    return index;
}