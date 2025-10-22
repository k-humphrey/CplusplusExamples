/*
    Filename: Functions.cpp
    Author: Kayla Humphrey
    Date: 03/09/2023
    Purpose: Contains three functions for Driver.cpp
*/
#include "Lab7.h"

/*
    Name: catchFish()
    Purpose: Given the character's name, catches one fish.
*/
int catchFish(string name, int totalScore){
    int num = 0, score = 0, randnum = rand() % (100 - 1 + 1) + 1;
    string fish = " ";
    
    cout << "\n\n" <<  name << " casts their fishing rod!"
         << "\nEnter a number between 1 and 100:  ";
    cin >> num;
    //input validation
    while(num > 100 || num < 1){
        cout << "\nERROR, input invalid. Enter a number between 1 and 100:  ";
        cin >> num;
    }

    fish = whatFish(num, randnum, score);
    cout << "\nYou caught a " << fish << "!";
    cout << "\n" << score << " points have been added to your score.";
    cout << "\n\tSCORE:  " << totalScore + score;
    return score;
}

/*
    Name: whatFish()
    Purpose: Decides what fish you got and returns the name of it. ALSO calculates score.
*/
string whatFish(int num, int random, int& score){
    int distance = fabs(random - num);

    if(distance == 0){
        cout << "\nYou've just caught the rarest fish in the world!";
        score = 100;
        return "[Devil's Hole Pupfish]";
    }
    else if(distance >= 1 && distance <= 10){
        score = 90;
        return "[Peppermint Angelfish]";
    }
    else if(distance >= 11 && distance <= 20){
        score = 80;
        return "[Axolotl]";
    }
    else if(distance >= 21 && distance <= 30){
        score = 70;
        return "[Octopus]";
    }
    else if(distance >= 31 && distance <= 40){
        score = 60;
        return "[American Paddlefish]";
    }
    else if(distance >= 41 && distance <= 50){
        score = 50;
        return "[Neptune Grouper]";
    }
    else if(distance >= 51 && distance <= 60){
        score = 40;
        return "[Bluefin Tuna]";
    }
    else if(distance >= 61 && distance <= 70){
        score = 30;
        return "[Pufferfish]";
    }
    else if(distance >= 71 && distance <= 80){
        score = 20;
        return "[Goldfish]";
    }
    else if(distance >= 81 && distance <= 90){
        score = 10;
        return "[Anchovie]";
    }
    else{
        score = 1;
        return "[A piece of trash]";
    }

}

/*
    Name: runAgain()
    Purpose: Decides whether the user wants to return again, this decision is returned as an integer (1 or 0)
*/
int runAgain(){
    char userChoice = 'y';

    cout << "\n\nDo you wish to play again?"
         << "\nEnter in Y or N:  ";
    cin >> userChoice;
    while(!(userChoice == 'y'|| userChoice == 'Y' || userChoice == 'n' || userChoice == 'N')){
        cout << "\nINVALID INPUT. enter Y or N";
        cin >> userChoice;
    }
    switch(userChoice){
        case 'y':
        case 'Y': return 1;
        case 'n':
        case 'N': cout << "\n\nYou chose to end the program. Goodbye!";
                  return 0;     
    }
    return 0;
}