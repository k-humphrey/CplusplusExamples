/****************************************************************
    Filename: knhumphrey42_prog2.cpp
    Author: Kayla Humphrey
    Date: 02/16/2023
    Purpose: A program that predicts a users future.
*****************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

//function prototypes
int displayMenuGetChoice();
int validateNumber(int, int, int, string);
int randomNum(int, int);

int main(){
    //variables
    ifstream inputf;
    int choice = 0;
    int k1 = 0, k2 = 0, k3 = 0, kids = 0;
    string awesome1 = " ", awesome2 = " ", worst = " ", place = " ";
    string like1 = " ", like2 = " ", hate = " ", job = " ";
    int m1 = 0, m2 = 0, m3 = 0, money = 0;
    string spouse = " ", dwelling = " ", location = " ", car = " ";
    int index = 0;
    srand(time(0));

    do{
        choice = displayMenuGetChoice();
        switch(choice){
            case 1: //USER INPUT
                    cout << "\nYou chose to predict your future!\n"
                         << "First, I need just a little information.\n\n"
                         << "Enter three numbers between 1 and 100, seperated by a space.\n";
                    cin >> k1 >> k2 >> k3;
                    k1 = validateNumber(k1, 100, 1, "first");
                    k2 = validateNumber(k2, 100, 1, "second");
                    k3 = validateNumber(k3, 100, 1, "third");
                    
                    cout << "\nEnter in an awesome job title:  ";
                    cin.ignore();
                    getline(cin, awesome1);
                    cout << "Enter in another awesome job title:  ";
                    getline(cin, awesome2);
                    cout << "Enter in the worst job title ever:  ";
                    getline(cin, worst);

                    cout << "\nEnter a company, organization, or restaurant you like:  ";
                    getline(cin, like1);
                    cout << "Enter another company, organization, or restaurant you like:  ";
                    getline(cin, like2);
                    cout << "Enter a company, organization, or restaurant you hate:  ";
                    getline(cin, hate);

                    cout << "\nEnter three numbers between 10,000 and 500,000, separated by a space.\n";
                    cin >> m1 >> m2 >> m3;
                    m1 = validateNumber(m1, 500000, 10000, "first");
                    m2 = validateNumber(m2, 500000, 10000, "second");
                    m3 = validateNumber(m3, 500000, 10000, "third");
                    
                    //CALCULATIONS
                    //spouse
                    inputf.open("PEOPLE.txt");
                    if(!inputf.is_open()){
                        cout << "\nERROR OPENING FILE";
                        return 1;
                    }
                    index = randomNum(15, 1); 
                    for(int i = 1; i <= index; i++){
                        getline(inputf, spouse);
                    }
                    inputf.close();

                    //dwelling
                    inputf.open("DWELLINGS.txt");
                    if(!inputf.is_open()){
                        cout << "\nERROR OPENING FILE";
                        return 1;
                    }
                    index = randomNum(15, 1);
                    for(int i = 1; i <= index; i++){
                        getline(inputf, dwelling);
                    }
                    inputf.close();

                    //location
                    inputf.open("LOCATIONS.txt");
                    if(!inputf.is_open()){
                        cout << "\nERROR OPENING FILE";
                        return 1;
                    }
                    index = randomNum(15, 1);
                    for(int i = 1; i <= index; i++){
                        getline(inputf, location);
                    }
                    inputf.close();

                    //car
                    inputf.open("CARS.txt");
                    if(!inputf.is_open()){
                        cout << "\nERROR OPENING FILE";
                        return 1;
                    }
                    index = randomNum(15, 1);
                    for(int i = 1; i <= index; i++){
                        getline(inputf, car);
                    }
                    inputf.close();

                    //kids
                    index = randomNum(3,1);
                    if(index == 1)
                        kids = k1;
                    else if(index == 2)
                        kids = k2;
                    else
                        kids = k3;
                    
                    //place
                    index = randomNum(3,1);
                    if(index == 1)
                        place = like1;
                    else if(index == 2)
                        place = like2;
                    else
                        place = hate;
                    
                    //job
                    index = randomNum(3,1);
                    if(index == 1)
                        job = awesome1;
                    else if(index == 2)
                        job = awesome2;
                    else
                        job = worst;
                    
                    //money
                    index = randomNum(3,1);
                    if(index == 1)
                        money = m1;
                    else if(index == 2)
                        money = m2;
                    else
                        money = m3;

                    //FINAL OUTPUT
                    cout << "\n\n******  YOUR FUTURE ******\n"
                         << "You and your spouse, " << spouse << " will live in a " << dwelling << " in\n"
                         << location << " and drive a " << car << "." << endl
                         << "You and your spouse will have " << kids << " children." << endl
                         << "You will work at " << place << " as a " << job << " making $" << money
                         << " a year.";
                    break;
            case 2: //Program ends
                    cout << "You chose to end the program\n"
                         << "Bye!\n";
                         return 0;
        }
    }while(choice != 2);
}

/************************************************************
    Name: DisplayMenuGetChoice
    Purpose: To display the menu and return the validated choice from the user
**************************************************************/
int displayMenuGetChoice(){
    int choice = 0;
    cout << "\n\nPick from the following menu:\n"
         << "1.  Let\'s predict your future!\n"
         << "2.  End Program.\n"
         << "CHOOSE 1 or 2:  ";
    cin >> choice;
    while(choice > 2 || choice < 1){
        cout << "Invalid choice. CHOOSE 1 or 2:  ";
        cin >> choice;
    }
    return choice;
}

/************************************************************
    Name: validateNumber
    Purpose: To validate a number based on a possible high and low, and to return the validated number
**************************************************************/
int validateNumber(int num, int high, int low, string place){
    while(num > high || num < low){
        cout << "Invalid choice for the " << place << " number you entered.\n"
             << "Enter a number between " << low << " and " << high << ".\n";
        cin >> num;
    }
    return num;
}

/************************************************************
Name: randomNum
Purpose: To generate a random number between a high and a low
**************************************************************/
int randomNum(int high, int low){
    int random = rand() % (high - low + 1) + low;
    return random;
}