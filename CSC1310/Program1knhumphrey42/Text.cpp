/*
    Filename: Text.cpp
    Author: Kayla Humphrey
    Due date: 09/18/2023
    Course and Section: Data Structures 1310-002
    Purpose: Text class, a parody of the string class
*/
#include "Text.h"

/*
    Name: Text
    Parameters: const cstring
    Purpose: the constructor for Text objects. It will set textLength to the length of the text. Then it sets textArray
             to the actual text that is passed to the object.
*/
Text::Text(const char* t){
    this->textLength = strlen(t);  //set length
    //Dynamic creation of a cstring to be assigned to textArray 
    char* dynamict = new char[this->textLength + 1];
    strcpy(dynamict, t);
    this->textArray = dynamict;
}

/*
    Name: ~Text
    Parameters: None
    Purpose: The destructor for Text objects. releases dynamic memory created to hold the cstring in textArray
*/
Text::~Text(){
    delete [] this->textArray;
    cout << "\nText destructor: Released memory for textArray.";
}

/*
    Name: displayText
    Parameters: None
    Purpose: This will cout the cstring
*/
void Text::displayText(){
    cout << this->textArray;
}

/*
    Name: getText
    Parameters: const cstring
    Purpose: this will return the const cstring
*/
const char* Text::getText() const{
    return this->textArray;
}

/*
    Name: getLength
    Parameters: None
    Purpose: Returns an int that is the textLength
*/
int Text::getLength(){
    return this->textLength;
}