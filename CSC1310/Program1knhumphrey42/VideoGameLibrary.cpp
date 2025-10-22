/*
    Filename: VideoGameLibrary.cpp
    Author: Kayla Humphrey
    Due date: 09/18/2023
    Course and Section: Data Structures 1310-002
    Purpose: VideoGameLibrary class, it holds an array of videogame objects.
*/
#include "VideoGameLibrary.h"

/*
    Name: resizeVideoGameArray
    Parameters: None
    Purpose: resizes the videoGameArray to twice the size of maxGames, doubles maxGames
*/
void VideoGameLibrary::resizeVideoGameArray(){
    cout << "\nresizing videoGameArray from " << this->maxGames;
    //create a new array that is twice the size of max games, resize max games
    VideoGame** bigger = new VideoGame*[this->maxGames * 2];
    this->maxGames = this->maxGames * 2;

    //Move all the games to the bigger array
    for(int i = 0; i < this->numGames; i++){
        bigger[i] = this->videoGamesArray[i];
    }

    cout << " to " << this->maxGames;
    //point the videoGamesArray to the bigger array
    videoGamesArray = bigger;
}

/*
    Name: VideoGameLibrary constructor 
    Parameters: an integer that contains the max number of games the library can hold
    Purpose: initializes the class attributes for VideoGameLibrary
*/
VideoGameLibrary::VideoGameLibrary(int maxSize){
    this->maxGames = maxSize;
    this->numGames = 0;
    this->videoGamesArray = new VideoGame*[this->maxGames];
}

/*
    Name: ~VideoGameLibrary
    Parameters:none
    Purpose: releases any dynamic memory used for the videogamelibrary object and any other objects used
*/
VideoGameLibrary::~VideoGameLibrary(){
    for(int i = 0; i < this->numGames; i++){
        delete this->videoGamesArray[i];
    }
    delete videoGamesArray;
    cout << "\nVideoGameLibrary destructor: Released memory for each game in the video game array and the array itself.";
}

/*
    Name: addVideoGameToArray
    Parameters: None
    Purpose: Reads in userinput and creates a new Videogame object that is placed in the correct spot
    of the videoGamesArray
*/
 void VideoGameLibrary::addVideoGameToArray(){
    //Temporary variables needed
    char temp[100]; 
    char* title = new char(100);
    char* developer = new char(100);
    char* publisher = new char(100);
    int userYear;

    cout << "\n\nTitle of Videogame: ";
    cin.ignore();
    cin.getline(temp, 100);
    strcpy(title, temp);
    Text* gameTitle = new Text(title);
    delete [] title;

    cout << "\nVideogame's developer: ";
    cin.getline(temp, 100);
    strcpy(developer, temp);
    Text* gameDeveloper = new Text(developer);
    delete [] developer;

    cout << "\nVideogame's publisher: ";
    cin.getline(temp, 100);
    strcpy(publisher, temp);
    Text* gamePublisher = new Text(publisher);
    delete [] publisher;

    cout << "\nVideogame's release year: ";
    cin >> userYear;

    //creates new videogame
    VideoGame* game = new VideoGame(gameTitle, gameDeveloper, gamePublisher, userYear);

    //check for resize
    if(this->numGames == this->maxGames){
        this->resizeVideoGameArray();
    }

    //assigns the new videogame object to it's pointer in videogamesarray and increments numgames
    this->videoGamesArray[this->numGames] = game;
    this->numGames++;

 }

 /*
    Name: displayVideoGames
    Parameters: None
    Purpose: Prints out all the games in videoGamesArray
 */
void VideoGameLibrary::displayVideoGames(){
    for(int i = 0; i < this->numGames; i++){
        cout << "\n\nVIDEOGAME " << i+1 << " ---------------------";
        this->videoGamesArray[i]->printVideoGameDetails();
    }
}

/*
    Name: displayVideoGameTitles
    Parameters: None
    Purpose: prints out all the videogame titles in videogamesarray
*/
void VideoGameLibrary::displayVideoGameTitles(){
    Text* tempTitle;
    for(int i = 0; i < this->numGames; i++){
        tempTitle = this->videoGamesArray[i]->getVideoGameTitle();
        cout << "\n" << i+1 << ". ";
        tempTitle->displayText();
    }
}

/*
    Name: loadVideoGamesFromFile
    Parameters: c pointer to a character string that contains filename
    Purpose: Opens a file and reads all the videogame details in to videogamesarray
*/
void VideoGameLibrary::loadVideoGamesFromFile(char* filename){
    //temporary variables needed
    ifstream input;
    char temp[100]; 
    char* title = new char(100);
    char* developer = new char(100);
    char* publisher = new char(100);
    int userYear;
    int gameCount = 0; //keeps track of how many games are added

    input.open(filename);

    //insure proper opening
    while(!input.is_open()){
        cout << "\nError opening file. Retype the filename in the format \"filename.txt\"."
             << "\nDo NOT include the quotes" << endl;
        cin.getline(filename, 60);
        input.open(filename);
    }
    
    //loop to read through till end of file
    while(input.peek() != EOF){
        //read in data for one game
        input.getline(temp, 100);
        strcpy(title, temp);
        Text* gameTitle = new Text(title);

        input.getline(temp, 100);
        strcpy(developer, temp);
        Text* gameDeveloper = new Text(developer);

        input.getline(temp, 100);
        strcpy(publisher, temp);
        Text* gamePublisher = new Text(publisher);

        input >> userYear;
        input.ignore();

        //create VideoGame object with info
        VideoGame* game = new VideoGame(gameTitle, gameDeveloper, gamePublisher, userYear);

        //check if array needs to be resized
        if(this->numGames == this->maxGames){
            this->resizeVideoGameArray();
        }
        
        //assign new videogame to correct place
        this->videoGamesArray[this->numGames] = game;

        //print out new game
        cout << "\n";
        this->videoGamesArray[numGames]->getVideoGameTitle()->displayText();
        cout << " was added sucessfully.";

        //increment numGames and gameCount
        gameCount++;
        numGames++;
    }

    //delete temporary variables
    delete title;
    delete publisher;
    delete developer;
    //print how many games were added 
    cout << "\n" << gameCount << " games were read from the file and added to the library.";
}

/*
    Name: removeVideoGameFromArray
    Parameters: None
    Purpose: Releases dynamic allocation for a videogame object and slides all the 
             video game array elements back into place
*/
void VideoGameLibrary::removeVideoGameFromArray(){
    int gameTBD = 0; //index for the game to be deleted

    if(numGames <= 1){
        cout << "\nERROR: There should always be one video game in the library.";
    }
    else{
        //display games and take user input
        cout << "\nGame list:";
        this->displayVideoGameTitles();
        cout << "\nPick a game 1 through " << this->numGames << " to delete.";
        cout << "\nGAME NUMBER: ";
        cin >> gameTBD;

        cout << endl;
        this->videoGamesArray[gameTBD-1]->getVideoGameTitle()->displayText();
        cout << " has been successfully deleted.";

        //delete game
        delete this->videoGamesArray[gameTBD - 1];

        //move array back one
        for(int i = gameTBD-1; i < this->numGames; i++){
            this->videoGamesArray[i] = this->videoGamesArray[i+1];
        }
        
        //decrement numGames
        this->numGames--;
    }
}

/*
    Name: saveToFile
    Parameters: c pointer to a c string that contains filename
    Purpose: opens a file and prints all the videogamearray details to it
*/
void VideoGameLibrary::saveToFile(char* filename){
    //open file
    ofstream output;
    output.open(filename);

    //loop through and print each game
    for(int i = 0; i < this->numGames; i++){
        this->videoGamesArray[i]->printVideoGameDetailsToFile(output);
    }

    //close file and confirmation message
    output.close();
    cout << "\n\nAll video games have been printed to \"" << filename << "\"";
}