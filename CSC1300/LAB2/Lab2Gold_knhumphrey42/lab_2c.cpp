/*
    File name: lab_2c.cpp
    Date: 1/31/2023
    Author: Kayla Humphrey
    Purpose: A three month game cost analyzer.
*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    string month = "";
    double gameInput = 0.0;
    double allGameTotal = 0.0;
    double monthlyGameTotal = 0.0;
    double average = 0.0;
    cout << fixed << setprecision(2); //formatting floating point numbers

    /*
      Steps
      1. The month is input.
      2. Each game is input, which is added to the monthly total and the all games total.
      3. After the third game, the monthly total is output.
      4. The monthly total is reset before moving onto the next month. 
    */
    cout << "\nEnter the month:  ";
    getline(cin, month);

    cout << "Price of Game 1:  $";
    cin >> gameInput;
    allGameTotal += gameInput; 
    monthlyGameTotal += gameInput;

    cout << "Price of Game 2:  $";
    cin >> gameInput;
    allGameTotal += gameInput; 
    monthlyGameTotal += gameInput;

    cout << "Price of Game 3:  $";
    cin >> gameInput;
    cin.ignore(); 
    allGameTotal += gameInput; 
    monthlyGameTotal += gameInput;

    cout << "Total cost of all three games for " << month << ":  $" << monthlyGameTotal;
    monthlyGameTotal = 0.0; //reset

    cout << "\n\nEnter the month:  ";
    getline(cin, month);

    cout << "Price of Game 1:  $";
    cin >> gameInput;
    allGameTotal += gameInput; 
    monthlyGameTotal += gameInput;

    cout << "Price of Game 2:  $";
    cin >> gameInput;
    allGameTotal += gameInput; 
    monthlyGameTotal += gameInput;

    cout << "Price of Game 3:  $";
    cin >> gameInput;
    cin.ignore();
    allGameTotal += gameInput; 
    monthlyGameTotal += gameInput;

    cout << "Total cost of all three games for " << month << ":  $" << monthlyGameTotal;
    monthlyGameTotal = 0.0; //reset

    cout << "\n\nEnter the month:  ";
    getline(cin, month);

    cout << "Price of Game 1:  $";
    cin >> gameInput;
    allGameTotal += gameInput; 
    monthlyGameTotal += gameInput;

    cout << "Price of Game 2:  $";
    cin >> gameInput;
    allGameTotal += gameInput; 
    monthlyGameTotal += gameInput;

    cout << "Price of Game 3:  $";
    cin >> gameInput;
    allGameTotal += gameInput; 
    monthlyGameTotal += gameInput;

    cout << "Total cost of all three games for " << month << ":  $" << monthlyGameTotal;
    monthlyGameTotal = 0.0; //reset

    //final output 
    cout << "\n\nTotal amount spent over the three months:  $" << allGameTotal;
    average = allGameTotal / 9;
    cout << "\nAverage price per game:  $" << average;

    return 0;

}