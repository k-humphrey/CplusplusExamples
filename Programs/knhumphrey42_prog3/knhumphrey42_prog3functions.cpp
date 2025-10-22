/*
    Filename: knhumphrey42_prog3functions.cpp
    Author: Kayla Humphrey
    Date: 3/28/2023
    Purpose: Functions for program 3
*/

#include "knhumphrey42_prog3.h"

/*
    Name: GetPlayersNames
    Purpose: To assign a name to each players index in the names array
*/
void GetPlayersNames(string names[], int playernum){
    for(int i = 0; i < playernum; i++){
        cout << "\n\nPLAYER " << i + 1 << ", WHAT IS YOUR NAME?"
             << "\nNAME:  ";
        getline(cin, names[i]);
    }
}

/*
    Name: RollDice
    Purpose: Prompts the user to hit enter and rolls a die for them. returns die number
*/
int RollDice(string name){
    int num = 0;
    cout << "\n----------------"
         << "\n" << name << ", PRESS ENTER TO ROLL DIE.";
    //allows user to hit enter to continue
    cin.get();
    num = rand() % (6 - 1 + 1) + 1; //1-6
    cout << "\nYOU ROLLED A " << num << ".";

    switch(num){ //print dice
        case 1:
            cout << "\n _________\n";
            cout << "|         |\n";
            cout << "|    o    |\n";
            cout << "|         |\n";
            cout << "|_________|\n\n";
            break;
        case 2:
            cout << "\n _________\n";
            cout << "|         |\n";
            cout << "|  o      |\n";
            cout << "|      o  |\n";
            cout << "|_________|\n\n";
            break;
        case 3:
            cout << "\n _________\n";
            cout << "| o       |\n";
            cout << "|    o    |\n";
            cout << "|       o |\n";
            cout << "|_________|\n\n";
            break;
        case 4:
            cout << "\n _________\n";
            cout << "| o     o |\n";
            cout << "|         |\n";
            cout << "| o     o |\n";
            cout << "|_________|\n\n";
            break;
        case 5:
            cout << "\n _________\n";
            cout << "| o     o |\n";
            cout << "|    o    |\n";
            cout << "| o     o |\n";
            cout << "|_________|\n\n";
            break;
        case 6:
            cout << "\n _________\n";
            cout << "| o     o |\n";
            cout << "| o     o |\n";
            cout << "| o     o |\n";
            cout << "|_________|\n\n";
            break;
    } 
    return num;      
}

/*
    Name: PlayerFinishedBoard
    Purpose: Displays the results of the game
*/
void PlayerFinishedBoard(string names[], int boardSpace[], double money[], int playernum){
    //Finds the survivor
    int highest = boardSpace[0];
    int survivor = 0;
    for(int i = 0; i < playernum; i++){
        if(boardSpace[i] > highest){
            highest = boardSpace[i];
            survivor = i;
        }
    }

    //Finds the richest
    int greatest = money[0];
    int richest = 0;
    for(int i = 0; i < playernum; i++){
        if(money[i] > greatest){
            greatest = money[i];
            richest = i;
        }
    }

    //print results
    cout << "\nYOU FINISHED THE LIFE GAME BOARD!!"
         << "\n-----------------------"
         << "\n\n\nPLAYER WHO SURVIVED THE ENTIRE LIFE GAME BOARD:  " << names[survivor]
         << "\nPLAYER WHO HAS THE MOST LIFE GAME MONEY:  " << names[richest] << " has $" << money[richest];
}

/*
    Name: ActivateActionOnSpace
    Purpose: to generate what happens on the space that a person lands on
*/
void ActivateActionOnSpace(string names[], int boardSpace[], double money[], int i){
    int gb = rand() % (2 - 1 + 1) + 1; //1-2 for good or bad
    int num = rand() % (20 - 1 + 1) + 1; // num for the action line
    double m = rand() % (100000 - 1 + 1) + 1; // 1-100,000 for money
    string line = " "; 
    ifstream input; 

    cout << endl << names[i] << " IS NOW ON SPACE " << boardSpace[i];

    if(gb == 1){
        //GOOD PRINT
        input.open("goodactions.txt");
        for(int i = 0; i < num; i++){
            getline(input, line);
        }

        cout << "\n\n0\t\t0"
             << "\n \to"
             << "\n  |            |"
             << "\n   ------------";
        cout << "\nYAY! " << line
             << "\nADDED $" << m << " TO YOUR ACCOUNT.";
        money[i] += m;
        cout << "\nYOU NOW HAVE $ " << money[i] << " IN YOUR ACCOUNT."
             << "\n-----------------";
        input.close();
    }
    else{
        //BAD PRINT
        input.open("badactions.txt");
        for(int i = 0; i < num; i++){
            getline(input, line);
        }

        cout << "\n\n_\t\t_"
             << "\n'\to"
             << "\n   ____________"
             << "\n  |            |";
        cout << "\nAW SHUCKS! " << line
             << "\nSUBTRACTED $" << m << " FROM YOUR ACCOUNT.";
        money[i] -= m;
        cout << "\nYOU NOW HAVE $ " << money[i] << " IN YOUR ACCOUNT."
             << "\n----------------";
        input.close();
    }
}
