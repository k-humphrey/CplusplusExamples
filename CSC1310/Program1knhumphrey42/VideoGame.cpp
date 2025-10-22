/*
    Filename: VideoGame.cpp
    Author: Kayla Humphrey
    Due date: 09/18/2023
    Course and Section: Data Structures 1310-002
    Purpose: VideoGame class. manipulations for an object with information about a videogame.
*/
#include "VideoGame.h"

/*
    Name: VideoGame
    Parameters: A pointer to a text object containing Game title, developer, and publisher. Then an int for year
    Purpose: Initializes all the attributes for a VideoGame object.
*/
VideoGame::VideoGame(Text* titleptr, Text* developerptr, Text* publisherptr, int year){
   this->title = new Text(titleptr->getText());
   this->developer = new Text(developerptr->getText());
   this->publisher = new Text(publisherptr->getText());
   this->year = year;
}

/*
    Name: ~VideoGame
    Parameters: None
    Purpose: Releases dynamically allocated memory for the VideoGame attributes
*/
VideoGame::~VideoGame(){
    delete  this->title;
    delete  this->developer;
    delete  this->publisher;
    cout << "\nVideoGame destructor: Released memory for VideoGame object.";
}

/*
    Name: printVideoGameDetails
    Parameters: None
    Purpose: Prints all of the VideoGame attributes to the terminal
*/
void VideoGame::printVideoGameDetails(){
    cout << "\nTITLE:\t\t";
    this->title->displayText();
    cout << "\nDEVELOPER:\t";
    this->developer->displayText();
    cout << "\nPUBLISHER:\t";
    this->publisher->displayText();
    cout << "\nYEAR:\t\t" << this->year;
}

/*
    Name: printVideoGameDetailsToFile
    Parameters: An ofstream object passed by reference
    Purpose: Will print all the VideoGame attributes to a file.
*/
void VideoGame::printVideoGameDetailsToFile(ofstream& output){
    output << this->title->getText();
    output << endl;
    output << this->developer->getText();
    output << endl;
    output << this->publisher->getText();
    output << endl;
    output << this->year;
    output << endl;
}

/*
    Name: getVideoGameTitle
    Parameters: None
    Purpose: Returns a pointer to a Text object that contains the videogame title.
*/
Text* VideoGame::getVideoGameTitle(){
    return this->title;
}