/*
    File name: lab_2b.cpp
    Date: 1/31/2023
    Author: Kayla Humphrey
    Purpose: A program that builds a kingdom of puppies for the user
*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
     string breed = "";
     double weight = 0.0;
     int kingdomSize = 0;
     int SNumOfPup = 100; // number of puppies in small, medium, or large kingdoms
     int MNumOfPup = 1000;
     int LNumOfPup = 10000;
     string kingdomName = "";
     double kingdomWeight = 0.0;
     double foodWeight = 0.0;
     int chosenPopulation = 0;

     //user is prompted for information
    cout << "\n========== Puppy Kingdom Builder ==========";

    cout << "\n\nWelcome to the Puppy Kingdom Builder!."
         << "\nThis program will allow you to build an entire kingdom of your favorite puppy."
         << "\nTo start, enter the name of your favorite dog breed."
         << "\nBreed:  ";
     getline(cin,breed);
     
     cout << "\nNow, what's your ideal puppy weight in pounds?"
          << "\nWeight:  ";
     cin >> weight;

     cout << "\nHow big do you want your puppy kingdom to be?"
          << "\n1.small (100 puppies), 2.medium (1,000 puppies), or 3.large (10,000 puppies)."
          << "\n(Enter 1, 2, or 3):  ";
     cin >> kingdomSize;
     cin.ignore(); //using getline next

     cout << "\nLastly, what is the name of your kingdom?"
          << "\nName:  ";
     getline(cin, kingdomName);

     //calculations
     if(kingdomSize == 1)
     {
          chosenPopulation = SNumOfPup;
          kingdomWeight = weight * SNumOfPup;
          foodWeight = 0.25 * SNumOfPup; //assuming each puppy gets 2 cups of food a day (where 2 cups = .25 lbs)

     }
     else if(kingdomSize == 2)
     {
          chosenPopulation = MNumOfPup;
          kingdomWeight = weight * MNumOfPup;
          foodWeight = 0.25 * MNumOfPup;
     }
     else
     {
          chosenPopulation = LNumOfPup;
          kingdomWeight = weight * LNumOfPup;
          foodWeight = 0.25 * LNumOfPup;
     }
     //10 lbs

     cout << "\n\n==========================================="
          << "\nWelcome to " << kingdomName << "!"
          << "\nThere are " << chosenPopulation << " happy " << breed << " residents."
          << "\nIt takes " << foodWeight << " lbs of food a day to feed them."
          << "\n" << kingdomName << "\'s army has the force of " << kingdomWeight << " lbs."
          << "\n     |\'-.__" //dog ascii art
          << "\n    /    --/"
          << "\n   *****    "
          << "\n===========================================";

     return 0;
}