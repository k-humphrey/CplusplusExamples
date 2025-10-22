/*
    Filename: knhumphrey42_prog4.cpp
    Author: Kayla Humphrey
    Date: 4/13/2023
    Purpose: Driver for program 4. Monster zoo program.
*/
#include "knhumphrey42_prog4.h"

int main(){
    //variables
    Monsters monsterArray[SIZE];
    int current = 0;
    int choice = 0;
    char yn = 'y';
    cout << fixed << setprecision(2);

    //start load existing
    cout << "\nWELCOME TO THE MONSTER ZOO PROGRAM!!";
    current = loadMonstersFromFile(current, monsterArray);

    //menu loop
    do{
        cout << "\n\nWhat would you like to do?"
             << "\n\t1. Register a New Monster"
             << "\n\t2. Remove a Monster From Zoo"
             << "\n\t3. Print Monsters to Screen"
             << "\n\t4. Print Monster Care Cost Data"
             << "\n\t5. End Program"
             << "\n\tEnter 1, 2, 3, 4, or 5."
             << "\nCHOICE:  ";
        cin >> choice;
        while(choice < 1 || choice > 5){
            cout << "\nERROR: Please enter 1, 2, 3, 4, or 5"
                 << "\nCHOICE:  ";
            cin >> choice;
        }
        cin.ignore();

        //switch for menu
        switch(choice){
            case 1: 
                    current = registerMonster(current, monsterArray);
                    break;
            case 2: 
                    current = removeMonster(current, monsterArray);
                    break;
            case 3:
                    printMonsters(current, monsterArray);
                    break;
            case 4: 
                    printCostInfo(current, monsterArray);
                    break;
            case 5:
                    cout << "\n\nWould you like to save your monster list to a file? (y or n):  ";
                    cin >> yn;
                    while(yn != 'y' && yn != 'Y' && yn != 'n' && yn != 'N'){
                        cout << "\nERROR: Please enter y or n:  ";
                        cin >> yn;
                    }
                    cin.ignore();

                    switch(yn){
                        case 'y':
                        case 'Y':
                                 saveMonstersToFile(current, monsterArray);
                                 break;
                        case 'n':
                        case 'N': 
                                 cout << "\nGOODBYE";
                                 break;
                    }
        }

    }while(choice != 5);
    return 0;
}