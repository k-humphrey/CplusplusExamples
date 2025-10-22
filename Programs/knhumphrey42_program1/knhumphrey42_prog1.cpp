/*
    Title:knhumphrey42_prog1.cpp
    Author: Kayla Humphrey
    Date: January 25, 2023
    Purpose: To calculate and display a user's life expectancy based on user input
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    //VARIABLES
    string name;
    int age;
    char gender;
    int weight;
    char smoke;
    char alcohol;
    int exercise;
    char pet;
    int relationship;
    char caretaker;
    int job;
    char breakfast;
    char familyDeath;
    char fruit;
    char vegetables;
    int friends;
    int education; 
    int le; //life expectancy running total
    
    // to do: calculation, and output
    //page setup
    cout << "\n********** Life Expectancy Calculator **********\n\n";

    //Prompts and inputs.
    cout << "Enter your name:  ";
    getline(cin,name);
    
    cout << "\nEnter your current age:  ";
    cin >> age;

    cout << "\nAre you male or female? (Enter m or f):  ";
    cin >> gender;

    cout << "\nWhat is your weight status?"
         << "\n(1)Underweight, (2)Just right, (3)Overweight, (4)Obese"
         << "\n(Enter 1, 2, 3, or 4):  ";
    cin >> weight;

    cout << "\nDo you smoke cigarettes? (Enter y or n):  ";
    cin  >> smoke;

    cout << "\nDo you drink more than one alcoholic beverage every day?"
         << "\n(Enter y or n):  ";
    cin  >> alcohol;

    cout << "\nDo you exercise?"
         << "\n(1)None, (2)Very Little, (3)Periodically, (4)Active, (5)Athlete"
         << "\n(Enter 1, 2, 3, 4, or 5):  ";
    cin  >> exercise;
    
    cout << "\nDo you have a pet? (Enter y or n):  ";
    cin  >> pet;

    cout << "\nAre you married?"
         << "\n(1)Divorced, (2)Single, (3)Married, (4)Happily Married"
         << "\n(Enter 1, 2, 3, or 4):  ";
    cin  >> relationship;

    cout << "\nAre you a caretaker? (Enter y or n):  ";
    cin  >> caretaker;

    cout << "\nHow do you feel about your job?"
         << "\n(1)Hate it!, (2)Dislike it, (3)It's ok, (4)Enjoyable, (5)Love it!"
         << "\n(Enter 1, 2, 3, 4, or 5):  ";
    cin  >> job;
    
    cout << "\nDo you eat breakfast every day? (Enter y or n):  ";
    cin >> breakfast;

    cout << "\nDid either of your biological parents of any of your biological"
         << "\ngrandparents die before of age 50? (Enter y or n):  ";
    cin  >> familyDeath;

    cout << "\nDo you eat fruits every day? (Enter y or n):  ";
    cin  >> fruit;

    cout << "\nDo you eat vegetables every day? (Enter y or n):  ";
    cin  >> vegetables;

    cout << "\nDo you hang out with your friends?"
         << "\n(1)Never, (2)Periodically, (3)Often"
         << "\n(Enter 1, 2, or 3):  ";
    cin  >> friends;
    
    cout << "\nWhat is your education level?"
         << "\n(1)No degrees, (2)Highschool degree, (3)Associates degree,"
         << "\n(4)Bachelors degree, (5)Masters/PHD degree"
         << "\n(Enter 1, 2, 3, 4, or 5):  ";
    cin  >> education;

     //CALCULATIONS, plus outputs of the results of each calculation
     if(age <= 60)
     {
          le = 60;
          cout << "\nStarting Life Expectancy:  " << le;
     }
     else if(age > 60)
     {
          le = age;
          cout << "\nStarting Life Expectancy:  " << le;
     }
     if(gender == 'f')
     {
          le += 4;
          cout << "\nLife Expectancy after gender:  " << le;
     }
     else if(gender == 'm')
     {
          cout << "\nLife Expectancy after gender:  " << le;
     }
     if(weight == 1)
     {
          le -= 1;
          cout << "\nLife Expectancy after weight:  " << le;
     }
     else if(weight == 2)
     {
          le += 5;
          cout << "\nLife Expectancy after weight:  " << le;
     }
     else if(weight == 3)
     {
          le -= 2;
          cout << "\nLife Expectancy after weight:  " << le;
     }
     else if(weight == 4){
          le -= 5;
          cout << "\nLife Expectancy after weight:  " << le;
     }
     if(smoke == 'y')
     {
          le -= 5;
          cout << "\nLife Expectancy after smoke:  " << le; //fix
     }
     else if(smoke == 'n')
     {
          le += 5;
          cout << "\nLife Expectancy after smoke:  " << le; //fix
     }
     if(alcohol == 'y')
     {
          le -= 5;
          cout << "\nLife Expectancy after alcohol:  " << le;
     }
     else if(alcohol == 'n')
     {
          le += 2;
          cout << "\nLife Expectancy after alcohol:  " << le;
     }
     if(exercise == 1)
     {
          le -= 5;
          cout << "\nLife Expectancy after exercise:  " << le;
     }
     else if(exercise == 2)
     {
          le -= 2;
          cout << "\nLife Expectancy after exercise:  " << le;
     }
     else if(exercise == 3)
     {
          cout << "\nLife Expectancy after exercise:  " << le;
     }
     else if(exercise == 4)
     {
          le += 5;
          cout << "\nLife Expectancy after exercise:  " << le;
     }
     else if(exercise == 5)
     {
          le += 7;
          cout << "\nLife Expectancy after exercise:  " << le;
     }
     if(pet == 'y')
     {
          le += 3;
          cout << "\nLife Expectancy after pet:  " << le;
     }
     else if(pet == 'n')
     {
          le -= 1;
          cout << "\nLife Expectancy after pet:  " << le;
     }
     if(relationship == 1)
     {
          le -= 5;
          cout << "\nLife Expectancy after married:  " << le;
     }
     else if(relationship == 2)
     {
          le -= 2;
          cout << "\nLife Expectancy after married:  " << le;
     }
     else if(relationship == 3)
     {
          le += 2;
          cout << "\nLife Expectancy after married:  " << le;
     }
     else if(relationship == 4)
     {
          le += 5;
          cout << "\nLife Expectancy after married:  " << le;
     }
     if(caretaker == 'y')
     {
          le -= 2;
          cout << "\nLife Expectancy after caretaker:  " << le;
     }
     else if(caretaker == 'n')
     {
          cout << "\nLife Expectancy after caretaker:  " << le;
     }
     if(job == 1)
     {
          le -= 5;
          cout << "\nLife Expectancy after job stress:  " << le;
     }
     else if(job == 2)
     {
          le -= 2;
          cout << "\nLife Expectancy after job stress:  " << le;
     }
     else if(job == 3)
     {
          cout << "\nLife Expectancy after job stress:  " << le;
     }
     else if(job == 4)
     {
          le += 2;
          cout << "\nLife Expectancy after job stress:  " << le;
     }
     else if(job == 5)
     {
          le += 5;
          cout << "\nLife Expectancy after job stress:  " << le;
     }
     if(breakfast == 'y')
     {
          le += 5;
          cout << "\nLife Expectancy after breakfast:  " << le;
     }
     else if(breakfast == 'n')
     {
          le -= 2;
          cout << "\nLife Expectancy after breakfast:  " << le;
     }
     if(familyDeath == 'y')
     {
          le -= 2;
          cout << "\nLife Expectancy after died:  " << le;
     }
     else if(familyDeath == 'n')
     {
          le += 5;
          cout << "\nLife Expectancy after died:  " << le;
     }
     if(fruit == 'y')
     {
          le += 5;
          cout << "\nLife Expectancy after fruits:  " << le;
     }          
     else if(fruit == 'n')
     {
          le -= 5;
          cout << "\nLife Expectancy after fruits:  " << le;
     }
     if(vegetables == 'y')
     {
          le += 5;
          cout << "\nLife Expectancy after vegetables:  " << le;
     }
     else if(vegetables == 'n')
     {
          le -= 5;
          cout << "\nLife Expectancy after vegetables:  " << le;
     }
     if(friends == 1)
     {
          le -= 2;
          cout << "\nLife Expectancy after friends:  " << le;
     }
     else if(friends == 2)
     {
          cout << "\nLife Expectancy after friends:  " << le;
     }
     else if(friends == 3)
     {
          le += 2;
          cout << "\nLife Expectancy after friends:  " << le;
     }
     if(education == 1)
     {
          le -= 5;
          cout << "\nLife Expectancy after education level:  " << le;
     }
     else if(education == 2)
     {
          le -= 2;
          cout << "\nLife Expectancy after education level:  " << le;
     }
     else if(education == 3)
     {
          le += 2;
          cout << "\nLife Expectancy after education level:  " << le;
     }
     else if(education == 4)
     {
          le += 5;
          cout << "\nLife Expectancy after education level:  " << le;
     }
     else if(education == 5)
     {
          le += 7;
          cout << "\nLife Expectancy after education level:  " << le;
     }
     if(le < age)
     {
          le = age;
     }
     
     // final output
     cout << "\n\n" << setfill('*') << setw(50) << ""; //row of stars
     cout << "\n" << setfill(' ') << right << setw(22) << "Name:" << name;
     cout << "\n" << setw(22) << "Current Age:" << age;
     cout << "\n" << setw(22) << "Life Expectancy:" << le;
     cout << "\n" << setfill('*') << setw(50) << ""; // last row of stars
}