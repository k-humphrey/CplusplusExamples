/*
    Filename: Driver.cpp
    Author: Kayla Humphrey
    Date: 3/28/2023
    Purpose: Driver for Lab 8. Student budget program
*/

#include "Budget.h"

int main(){
    //VARIABLES
    string name[COLUMN] = {" ", " ", " "};
    double income[COLUMN] = {0.0, 0.0, 0.0};
    double remaining[COLUMN] = {0.0, 0.0, 0.0};
    double expenditures[ROW][COLUMN] = {{0.0, 0.0, 0.0},
                                        {0.0, 0.0, 0.0},
                                        {0.0, 0.0, 0.0},
                                        {0.0, 0.0, 0.0}};
    char category[ROW][CHARCOLUMN];
    int highRemain = 0, lowRemain = 0;

    //format
    cout << fixed << setprecision(2);

    cout << "Welcome to the Student Budget Calculator for the Month of April"
         << "\n\n";
    getUserInput(name, income, category, expenditures);
    calculateBalance(remaining, income, expenditures);
    highRemain = getHighest(remaining);
    lowRemain = getLowest(remaining);



    //Print highest
    cout << "\n\nThe student that has the highest remaining balance of $" << remaining[highRemain] << " is " 
         << name[highRemain] << ", who started out with an income of $" << income[highRemain]
         << " and expenditures of";
    for(int i = 0; i < ROW; i++){
       cout << " " << category[i] << " $" << expenditures[i][highRemain];
    }
    cout << ".";

    //Print lowest
    cout << "\n\nThe student that has the lowest remaining balance of $" << remaining[lowRemain] << " is " 
         << name[lowRemain] << ", who started out with an income of $" << income[lowRemain]
         << " and expenditures of";
    for(int i = 0; i < ROW; i++){
       cout << " " << category[i] << " $" << expenditures[i][lowRemain];
    }
    cout << ".";
    return 0;
}
