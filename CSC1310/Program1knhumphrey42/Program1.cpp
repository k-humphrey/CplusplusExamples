/*
    Filename: Program1.cpp
    Author: Kayla Humphrey
    Due date: 09/18/2023
    Course and Section: Data Structures 1310-002
    Purpose: Driver for program 1
*/

#include "VideoGameLibrary.h"

int main(){
    //VARIABLES
    int gameNum;
    int choice = 0;
    VideoGameLibrary* library;
    char input[100];
    char* filename = new char(100);

    //CREATE VIDEO GAME LIBRARY
    cout << "\nHow many video games can your library hold?\n";
    cin >> gameNum;
    library = new VideoGameLibrary(gameNum);

    //MENU
    do{
        cout << "\n\nWhat would you like to do?"
             << "\n1. Load video games from file."
             << "\n2. Save video games to a file."
             << "\n3. Add a video game."
             << "\n4. Remove a video game."
             << "\n5. Display all video games."
             << "\n6. Remove ALL video games from this library and end program."
             << "\nCHOOSE 1-6:  ";
        cin >> choice;

        //validate
        if(choice < 1 || choice > 6){
            cout << "\nThat is not a valid choice."
                 << "\nCHOOSE 1-6:  ";
                    cin >> choice;
        }
        
        //switch to call functions
        switch(choice){
            case 1:
                    cout << "\nWhat is the name of the file? (example.txt):  ";
                    cin.ignore();
                    cin.getline(input, 100);
                    strcpy(filename,input);
                    library->loadVideoGamesFromFile(filename);
                    break;

            case 2:
                    cout << "\nWhat do you want to name the file? (example.txt):  ";
                    cin.ignore();
                    cin.getline(input, 100);
                    strcpy(filename, input);
                    library->saveToFile(filename);
                    break;

            case 3:
                    library->addVideoGameToArray();
                    break;

            case 4:
                    library->removeVideoGameFromArray();
                    break;

            case 5:
                    library->displayVideoGames();
                    break;

            case 6:
                    delete library;
                    cout << "\n\nGOODBYE!";
        }
    }while(choice != 6);

    delete filename;
    return 0;
}