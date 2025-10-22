/*
    Filename: VideoGameLibrary.h
    Author: Kayla Humphrey
    Due date: 09/18/2023
    Course and Section: Data Structures 1310-002
    Purpose: Header file for VideoGameLibrary class
*/
#ifndef VIDEOGAMELIBRARY_H
#define VIDEOGAMELIBRARY_H
    #include "VideoGame.h"

    class VideoGameLibrary{
            private:
                VideoGame ** videoGamesArray;
                int maxGames;
                int numGames;
            public:
                void resizeVideoGameArray();
                VideoGameLibrary(int);
                ~VideoGameLibrary();
                void addVideoGameToArray();
                void displayVideoGames();
                void displayVideoGameTitles();
                void loadVideoGamesFromFile(char*);
                void removeVideoGameFromArray();
                void saveToFile(char*);
    };
#endif