/*
    Filename: knhumphrey42_prog4.h
    Author: Kayla Humphrey
    Date: 4/16/2023
    Purpose: Header file for monster zoo program. (Program 4)
*/
#ifndef KNHUMPHREY42_PROG4_H
#define KNHUMPHREY42_PROG4_H

    #include <iostream>
    #include <fstream>
    #include <string>
    #include <iomanip>

    using namespace std;

    //global variables
    const int SIZE = 75;

    //structures
    struct Cost{
        double careHours,
               careCost,
               foodCost,
               materialCost;
    };

    struct Monsters{
        string name,
               description,
               location;
        double weight,
               height;
        int danger;
        Cost Costs;
    };

    //function prototypes
    int loadMonstersFromFile(int, Monsters []);
    int registerMonster(int, Monsters []);
    int removeMonster(int, Monsters []);
    void printMonsters(int, Monsters []);
    void printCostInfo(int, Monsters []);
    void saveMonstersToFile(int, Monsters[]);

#endif