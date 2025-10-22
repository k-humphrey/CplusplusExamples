
/*
    Filename: knhumphrey42_prog3.h
    Author: Kayla Humphrey
    Date: 03/28/2023
    Purpose: Header file for program 3
*/
#ifndef KNHUMPHREY42_PROG3_H
#define KNHUMPHREY42_PROG3_H

    #include <iostream>
    #include <cstdlib>
    #include <ctime>
    #include <iomanip>
    #include <fstream>
    #include <limits>

    using namespace std;

    //function prototypes
    void GetPlayersNames(string [], int);
    int RollDice(string);
    void PlayerFinishedBoard(string [], int [], double [], int);
    void ActivateActionOnSpace(string [], int [], double [], int);

    //global constants
    const int MAX_PLAYERS = 20;
    const int SPACES = 25;
    
#endif