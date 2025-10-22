/*
    Filename: knhumphrey42_prog3driver.cpp
    Author: Kayla Humphrey
    Date: 03/28/2023
    Purpose: The main function for program 3
*/

#include "knhumphrey42_prog3.h"

int main(){
    //variables
    int playernum = 0;
    string names[MAX_PLAYERS];
    int boardSpace[MAX_PLAYERS];
    double money[MAX_PLAYERS];
    int again = 0;
    bool stop = false;
    int dicenum = 0;
    char userchar = 'a';
    srand(time(0));

    do{
        cout << "\nYOU ARE PLAYING THE LIFE GAME!"
        << "\nHow many players?:  ";
        cin >> playernum;
        cin.ignore();
        //validate
        while(playernum < 1 || playernum > 20){
            cout << "\nERROR: please input a number between 1 and " << MAX_PLAYERS << ":  ";
            cin >> playernum;
            cin.ignore();
        }

        //set up empty arrays and reset stop
        stop = false;
        for(int i = 0; i < MAX_PLAYERS; i++){
            names[i] = " ";
            boardSpace[i] = 0;
            money[i] = 0.0;
        }

        //get names :)
        GetPlayersNames(names, playernum);

        while(stop == false){
            for(int i = 0; i < playernum; i++){
                dicenum = RollDice(names[i]);
                boardSpace[i] += dicenum;
                if(boardSpace[i] >= SPACES){
                    PlayerFinishedBoard(names, boardSpace, money, playernum);
                    stop = true;
                    break; //making sure that the other players can't go after this point
                }
                else{
                    ActivateActionOnSpace(names, boardSpace, money, i);
                }
            }
        }

        cout << "\n\nDO YOU WANT TO PLAY AGAIN?"
            << "\nY or N: ";
        cin >> userchar;
        //validate
        while(userchar != 'y' && userchar != 'Y' && userchar != 'n' && userchar != 'N'){
            cout << "ERROR: Please enter Y or N:  ";
            cin >> userchar;
        }

        switch(userchar){
            case 'Y':
            case 'y': again = 1;
                    break;
            case 'N':
            case 'n': again = 0;
                    break;
        }
    }while(again == 1);
    return 0;
}
