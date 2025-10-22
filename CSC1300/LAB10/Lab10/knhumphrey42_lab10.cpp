/*
    filename: knhumphrey42_lab10.cpp
    author: Kayla Humphrey
    date: 4/18/2023
    Purpose: Pastry Chef competition. LAB 10.
*/
#include <iostream>

using namespace std;

struct PastryCategory{
    string catName;
    int awardNum;
};

struct Chef{
    string name;
    string hometown;
    int numcategories;
    int awardswon;
};

int main(){
    Chef *chefs = nullptr; //pointer to chefs array.
    PastryCategory ** awardsArray = nullptr; //awardsArray is a pointer to a pointer array
    int competitors = 0;
    int mostAwards = 0; //index for the highest 
    int total = 0; //temporary


    //find how many chefs
    cout << "\nHow many chefs are competing?  ";
    cin >> competitors;
    while(competitors <= 0){
        cout << "\nError! Impossible number of chefs. Enter a number greater than 0."
             << "\nCHEFS:  ";
        cin >> competitors;
    }
    cin.ignore();

    //dynamically allocate chefs and awards array
    chefs = new Chef[competitors];
    awardsArray = new PastryCategory*[competitors];

    //get information about each Chef
    cout << "\n\nPlease enter in information about each chef.\n";

    for(int i = 0; i < competitors; i++){
        cout << "\n****CHEF " << i + 1 << "****"
             << "\n\tNAME:  ";
        getline(cin, chefs[i].name);
        cout << "\tHOMETOWN:  ";
        getline(cin, chefs[i].hometown);
        cout << "\n\tHow many categories has " << chefs[i].name << " won awards in?:  ";
        cin >> chefs[i].numcategories;
        cin.ignore();

        //dynamically allocate an array of PastryCategory that is the size of numcategories
        awardsArray[i] = new PastryCategory[chefs[i].numcategories];
        //run through this array to gather more info
        total = 0;
        for(int x = 0; x < chefs[i].numcategories; x++){
            cout << "\n\tFOR CATEGORY " << x + 1 << ":"
                 << "\n\t\tName of category - ";
            getline(cin, awardsArray[i][x].catName);
            cout << "\t\tNumber of awards in " << awardsArray[i][x].catName << " - ";
            cin >> awardsArray[i][x].awardNum;
            total += awardsArray[i][x].awardNum;
            cin.ignore();
        }
        //add total awards into chefs.
        chefs[i].awardswon = total;
    }

    //find out who has the most awards
    total = chefs[0].awardswon;
    for(int i = 0; i < competitors; i++){
        if(chefs[i].awardswon > total){
            total = chefs[i].awardswon;
            mostAwards = i;
        }
    }

    //print out most awards
    cout << "\nThe pastry chef who has won the most awards (" << total << " awards) is " << chefs[mostAwards].name << ", with awards in"
         << "\nthe following categories:";
    for(int i = 0; i < chefs[mostAwards].numcategories; i++){
        cout << "\n\t" << awardsArray[mostAwards][i].catName << " (" << awardsArray[mostAwards][i].awardNum << ")";
    }

    //release allocated memory
    for(int i = 0; i < competitors; i++){
        delete [] awardsArray[i];
    }
    delete [] awardsArray;
    delete [] chefs;
    
}