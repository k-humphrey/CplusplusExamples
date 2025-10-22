/*
    Filename: lab4.cpp
    Author: Kayla Humphrey
    Date: 2/14/2023
    Purpose: A text based game that takes a player through a strange farm
*/
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){
    //VARIABLES
    int again = 0;
    int rtemp = 0; //temporary value to be used for random generation
    int temp = 0; //temporary value to be used for user input
    bool timeManipulator = false; //value that holds if you have a timeManipulator or not
    string season = " ";
    string appearance = " ";
    srand(time(0));

    do{
        //reset
        timeManipulator = false;
        again = 0;
        //Generating random variables
        rtemp = rand() % (4 - 1 + 1) + 1; // 1-4 for seasons
        if(rtemp == 1){
            season = "winter";
        }
        else if(rtemp == 2){
            season = "spring";
        }
        else if(rtemp == 3){
            season = "summer";
        }
        else{
            season = "fall";
        }
        rtemp = rand() % (2 - 1 + 1) + 1; // 1-2 for appearance 
        if(rtemp == 1){
            appearance = "younger";
        }
        else{
            appearance = "older";
        }


        //GAME START
        cout << setfill('=') << setw(50) << "" << setfill(' ') << endl; //LINE
        cout << setw(32) << "A day on the Farm" << endl << endl;

        cout << "[You wake up to the sound of a rooster crowing.]"
             << "\nLight streams through your open window, the " << season << " air feels fresh on your skin."
             << "\nYou get out of bed, now what?"
             << "\n1. Look into the mirror"
             << "\n2. Read the paper"
             << "\n3. Walk outside"
             << "\n(Enter 1, 2, or 3):  ";
        cin >> temp;
        while(temp < 1 || temp > 3){   //Input validation
            cout << "\nERROR: invalid input."
                 << "\nTry again:  ";
            cin >> temp;
        }
        //user picks 1 of 3 options (mirror,paper,go outside)
        if(temp == 1){
            cout << setfill('=') << setw(50) << "" << setfill(' ') << endl; //LINE
            cout << "\n[You look into the mirror.]"
                 << "\nYou look "<< appearance << " today."
                 << "\nNot that it matters...\n\n\n";
            cout << setfill('=') << setw(50) << "" << setfill(' ') << endl; //LINE 
        }
        else if(temp == 2){
            cout << setfill('=') << setw(50) << "" << setfill(' ') << endl; //LINE
            cout << "\n[You read the paper.]"
                 << "\nIt is filled with articles about Hollywood and politics."
                 << "\nNone of that concerns you anyways, living all the way out here.\n\n\n";
            cout << setfill('=') << setw(50) << "" << setfill(' ') << endl; //LINE
        }
        else{
            cout << setfill('=') << setw(50) << "" << setfill(' ') << endl; //LINE
            //nothing happens because this continues outside of this loop
        }


        cout << "\n[After getting ready for the day, you walk outside.]"
             << "\nYou feel energized, as if yesterday\'s hard work never happened."
             << "\nIt\'s time to get to work!"
             << "\nWhat should you do first?"
             << "\n1. Planting vegetables"
             << "\n2. Feeding the animals"
             << "\n(Enter 1 or 2):  ";
        cin >> temp;
        while(temp < 1 || temp > 2){ //Input validation
            cout << "\nERROR: invalid input."
                 << "\nTry again:  ";
            cin >> temp;
        }
        //user picks 1 of 2 options (garden first, or barn first) 10% chance to get a time manipulator IF it hasnt already been found.
        if(temp == 1){
            cout << setfill('=') << setw(50) << "" << setfill(' ') << endl; //LINE
            cout << "\n[You walk to the garden.]";
            for(int i = 1; i <= 5; i++){ //Can plant 5 times
                cout << "\nEnter 1 to dig a hole and plant a vegetable."
                     << "\nEnter 1:  ";
                cin >> temp;
                while(temp != 1){
                    cout << "\nERROR: Invalid Input. You have to do your duties. Enter 1"
                         << "\nEnter 1:  ";
                    cin >> temp;
                }
                rtemp = rand() % (10 - 1 + 1) + 1; // 1-10 to be used for a chance to get timeManipulator
                if(rtemp == 1 && timeManipulator == false){ // this simulates a 1 in 10 chance that you get a timeManipulator
                    timeManipulator = true;
                    cout << "\n[Your shovel hits a mysterious object.]"
                         << "\nIt glows with power. You have come across a time manipulator."
                         << "\nYou put it in your pocket.\n\n\n";
                }
                else{
                    cout << "\nGood job!";
                }
            }
            //After planting, you must go feed the animals
            cout << "\n\n";
            cout << setfill('=') << setw(50) << "" << setfill(' ') << endl; //LINE
            cout << "\nNow, you must go feed the animals."
                 << "\n[You walk to the barn.]";
            for(int i = 1; i <= 5; i++){ //feed animals 5 times
                cout << "\nEnter 1 to feed an animal."
                     << "\nEnter 1:  ";
                cin >> temp;
                while(temp != 1){
                    cout << "\nERROR: Invalid Input. You have to do your duties. Enter 1"
                         << "\nEnter 1:  ";
                    cin >> temp;
                }
                rtemp = rand() % (10 - 1 + 1) + 1; 
                if(rtemp == 1 && timeManipulator == false){ 
                    timeManipulator = true;
                    cout << "\n[Your boot hits a hard object sticking out of the dirt.]"
                         << "\nIt glows with power. You have come across a time manipulator."
                         << "\nYou put it in your pocket.";
                }
                else{
                    cout << "\nGood job!";
                }
            }
        }
        if(temp == 2){ // this is the same as the first option but in reverse order
            cout << setfill('=') << setw(50) << "" << setfill(' ') << endl; //LINE
            cout << "\n[You walk to the barn.]";
            for(int i = 1; i <= 5; i++){ //feed animals 5 times
                cout << "\nEnter 1 to feed an animal."
                     << "\nEnter 1:  ";
                cin >> temp;
                while(temp != 1){
                    cout << "\nERROR: Invalid Input. You have to do your duties. Enter 1"
                         << "\nEnter 1:  ";
                    cin >> temp;
                }
                rtemp = rand() % (10 - 1 + 1) + 1; 
                if(rtemp == 1 && timeManipulator == false){ 
                    timeManipulator = true;
                    cout << "\n[Your boot hits a hard object sticking out of the dirt.]"
                         << "\nIt glows with power. You have come across a time manipulator."
                         << "\nYou put it in your pocket.";
                }
                else{
                    cout << "\nGood job!";
                }
            }
            //After feeding the animals, you need to plant vegetables
            cout << "\n\n";
            cout << setfill('=') << setw(50) << "" << setfill(' ') << endl; //LINE
            cout << "\nNow, you must go plant vegetables."
                 << "\n[You walk to the garden.]";
            for(int i = 1; i <= 5; i++){ //plant vegetables 5 times
                cout << "\nEnter 1 to plant a vegetable."
                     << "\nEnter 1:  ";
                cin >> temp;
                while(temp != 1){
                    cout << "\nERROR: Invalid Input. You have to do your duties. Enter 1"
                         << "\nEnter 1:  ";
                    cin >> temp;
                }
                rtemp = rand() % (10 - 1 + 1) + 1;
                if(rtemp == 1 && timeManipulator == false){ 
                    timeManipulator = true;
                    cout << "\n[Your shovel hits a mysterious object.]"
                         << "\nIt glows with power. You have come across a time manipulator."
                         << "\nYou put it in your pocket.\n\n\n";
                }
                else{
                    cout << "\nGood job!";
                }
            }
        }
        cout << "\n\n";


        cout << setfill('=') << setw(50) << "" << setfill(' ') << endl; //LINE
        cout << "\nGreat job! You have completed your tasks for the day!"
             << "\n[You walk back into your house.]"
             << "\nYou eat dinner, take a bath, and get ready for bed."
             << "\nYou think, \"I could live like this forever.\" A simple life is good.";
        if(timeManipulator == true){ //user only has the choice to use time manipulator if they found it earlier
            cout << "\nOn your way to your bed, you feel a weight in your pocket. The time manipulator."
                 << "\nIt glows, waiting for you, what do you do?"
                 << "\n1. Use it"
                 << "\n2. Throw it out the window"
                 << "\n(Enter 1 or 2):  ";
            cin >> temp;
            while(temp < 1 || temp > 2){
                cout << "\nERROR: incorrect input. Try again"
                     << "\n(Enter 1 or 2):  ";
                cin >> temp;
            }
            if(temp == 1){
                cout << "\nYou put the time Manipulator under your pillow.";
                again = 1; //makes the do while loop again
            }
            else{
                cout << "\nYou throw the time manipulator out the window.";
                again = 0;
            }
        }
    
        cout << "\nYou go to sleep.\n\n";
    }while(again == 1); 
    return 0;
}