/*
    Filename: VideoGame.h
    Author: Kayla Humphrey
    Due date: 09/18/2023
    Course and Section: Data Structures 1310-002
    Purpose: Header file for VideoGame class
*/
#ifndef VIDEOGAME_H
#define VIDEOGAME_H
    #include "Text.h"

    using namespace std;

    class VideoGame{
        private:
                Text* title;
                Text* developer;
                Text* publisher;
                int year;
        public:
                VideoGame(Text*, Text*, Text*, int);
                ~VideoGame();
                void printVideoGameDetails();
                void printVideoGameDetailsToFile(ofstream& output);
                Text* getVideoGameTitle();

    };

#endif 