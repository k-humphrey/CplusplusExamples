/*
    Name: Course.cpp
    Author: Kayla Humphrey
    Date: 08/29/2023
    Purpose: A file that outlines the functions that can be used with the Course struct for lab 1 1310

*/
#include "Course.h"

Course* createCourse(string n, string l, int s, int c){
    //a temporary course is made
    Course* tempCourse = new Course;

    //values are assigned to the temporary course
    tempCourse->name = n;
    tempCourse->location = l;
    tempCourse->numSections = s;
    tempCourse->creditHours = c;

    //dynamically create the sections array
    tempCourse->sections = new string[s];

    return tempCourse;

}

void destroyCourse(Course* myCourse){
    //delete the sections array
    delete [] myCourse->sections;
    //delete the course
    delete myCourse;
}

void printCourse(Course* myCourse){
    //print out Course
    cout << left << setw(30) << "COURSE NAME:" << myCourse->name << endl;
    cout << setw(30) << "COURSE LOCATION:" << myCourse->location << endl;
    cout << setw(30) << "COURSE HOURS:" << myCourse->creditHours << endl;
    cout << setw(30) << "COURSE SECTIONS:" << endl;
    //iterate through sections array to print all of it
    for(int i = 0; i < myCourse->numSections; i++){
        cout << right <<  setw(30) << " " << myCourse->sections[i] << endl;
    }
}