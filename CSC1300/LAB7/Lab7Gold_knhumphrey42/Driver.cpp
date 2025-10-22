/*
    Filename: Driver.cpp
    Author: Kayla Humphrey
    Date: 03/07/2023
    Purpose: A program that takes a sloth and a turtle on a vacation
*/

#include "Lab7.h"

int main(){
    //variables
    int again = 0, turtleScore = 0, slothScore = 0, totalScore = 0;
    srand(time(0));

    //title
    cout << endl << setfill('+') << setw(50) << " " << setfill(' '); //LINE
    cout << "\n\tTurtle and Sloth go deep sea fishing!";
    cout << endl << setfill('+') << setw(50) << " " << setfill(' '); //LINE

    do{
        //these variables need to reset if the program is ran again.
        turtleScore = 0, slothScore = 0, totalScore = 0;

        cout << "\n\nTurtle and Sloth have decided to go deep sea fishing on their vacation to Florida."
         << "\nThey each have 5 pieces of bait. You will help by guessing a random number between 1 and 100 to determine their luck."
         << "\nGet the highest score by helping Turtle and Sloth catch a lot of rare fish!\n";

         //turtle
         for(int i = 1; i <= 5; i++){
            cout << "\nBAIT " << i;
            turtleScore += catchFish("Turtle", turtleScore);
         }
         cout << "\n\nTurtle\'s score:  " << turtleScore;
         cout << endl << setfill('-') << setw(50) << " " << setfill(' '); //LINE
         
        //sloth
        for(int i = 1; i <= 5; i++){
            cout << "\nBAIT " << i;
            slothScore += catchFish("Sloth", slothScore);
        }
        cout << "\n\nSloth\'s score:  " << slothScore;
        cout << endl << setfill('-') << setw(50) << " " << setfill(' '); //LINE
        
        //final output
        totalScore = slothScore + turtleScore;
        cout << "\nYour final score was " << totalScore << "!";
        cout << "\nCongrats! Turtle and Sloth had a great vacation!";

        //Decide whether to run again
        again = runAgain();
    }while(again != 0);
}