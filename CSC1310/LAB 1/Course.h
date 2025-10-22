/*
    Name: Course.h
    Author: Kayla Humphrey
    Date: 08/29/2023
    Purpose: Header file for lab 1 1310
*/
#ifndef COURSE_H
#define COURSE_H
    #include <iostream>
    #include <iomanip>
    
    using namespace std;

    struct Course{
        string name;
        string location;
        string* sections;
        int numSections;
        int creditHours;
    };

    Course* createCourse(string, string, int, int);
    void destroyCourse(Course* myCourse);
    void printCourse(Course* myCourse);
#endif