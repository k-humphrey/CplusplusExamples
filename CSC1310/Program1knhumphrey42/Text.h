/*
    Filename: Text.h
    Author: Kayla Humphrey
    Due date: 09/18/2023
    Course and Section: Data Structures 1310-002
    Purpose: Header file for Text class
*/
#ifndef TEXT_H
#define TEXT_H

    #include <iostream>
    #include <cstring>
    #include <fstream>
    #include <cstdlib>
    #include <limits>

    using namespace std;

    class Text{
        private:
                const char* textArray;
                int textLength;
        public:
                Text(const char*);
                ~Text();
                void displayText();
                const char* getText() const;
                int getLength();
    };

#endif