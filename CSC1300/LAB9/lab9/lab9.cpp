/*
    Filename: lab9.cpp
    Author: Kayla Humphrey
    Date: 4/11/2023
    Purpose: Lab 9, paranormal investivation tracker, pointers
*/
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

//function prototypes
void getParanormalData(int, int*, string*, string*);
void getStats(int, int*, int*, double*, int*);


int main(){
    int numInvestigators = 0, totalRecordings = 0, highIndex = 0;
    int* totalptr = &totalRecordings, *highptr = &highIndex;
    double averageRecordings = 0.0;
    double *averageptr = &averageRecordings;
    char location[100];
    int *recordptr = nullptr;
    string *namesptr = nullptr, *datesptr = nullptr;
    cout << fixed << setprecision(2);

    //gather info prt 1
    cout << "Hello! What haunted location are you investigating?\n";
    cin.getline(location, 100);
    cout << "How many investigators will be working this location?\n";
    cin >> numInvestigators;
    while(numInvestigators <= 0 || numInvestigators > 25){
        cout << "Oops! You must enter 1 through 25."
             << "\n\nHow many investigators will be working this location?\n";
        cin >> numInvestigators;
    }
    cin.ignore();

    //DYNAMIC ALLOCATION [must delete]!!!!
    recordptr = new int[numInvestigators];
    namesptr = new string[numInvestigators];
    datesptr = new string[numInvestigators];

    //gather info prt 2
    getParanormalData(numInvestigators, recordptr, namesptr, datesptr);
    
    //calculation
    getStats(numInvestigators, recordptr, totalptr, averageptr, highptr);

    //output
    cout << "---------------------------------------------"
         << "\nThe total amount of EVPS recorded by all " << numInvestigators << " investigators at\n"
         << location << " is " << *totalptr << " recordings."
         << "\n\nThe average amount of EVPs recorded at " << location
         << "\nis " << *averageptr << " recordings."
         << "\nThe investigator who recorded the most (" << *(recordptr + *highptr) << " recordings)"
         << "\nis " << *(namesptr + *highptr) << " on " << *(datesptr + *highptr) << "!!"
         << "\n---------------------------------------------";


    //RELEASE ALLOCATED MEMORY 
    delete [] recordptr;
    delete [] namesptr;
    delete [] datesptr;

    return 0;
}

/*
    Name: getParanormalData
    Purpose: allows the user to put in all the data for the arrays
*/
void getParanormalData(int numInvestigators, int *recordptr, string *namesptr, string *datesptr){
    cout << "Enter the investigator\'s name, the day of their investigation, and the number of EVPs they recorded on their voice recorder.\n";
    for(int i = 0; i < numInvestigators; i++){
        cout << "INVESTIGATOR " << (i + 1) << ":";
        cout << "\n\tNAME - ";
        getline(cin, *(namesptr + i));
        cout << "\tDAY (ex: 04-03-2023) - ";
        getline(cin, *(datesptr + i));
        cout << "\tNUMBER OF EVPs - ";
        cin >> *(recordptr + i);
        cin.ignore();
    }
}

/*
    Name: getStats
    Purpose: Finds the total recordings, average, and the index of the person who had the highest
*/
void getStats(int numInvestigators, int* recordptr, int* totalptr , double* averageptr, int* highptr){
    //highest index and total
    int highest = *(recordptr + 0);
    for(int i = 0; i < numInvestigators; i++){
        if(*(recordptr + i) > highest){
            highest = *(recordptr + i);
            *highptr = i;
        }
        *totalptr = *totalptr + *(recordptr + i);
    }
    //average
    *averageptr = *totalptr / static_cast<double>(numInvestigators);
}

