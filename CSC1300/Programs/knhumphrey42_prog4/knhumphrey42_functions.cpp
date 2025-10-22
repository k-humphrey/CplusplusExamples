/*
    Filename: knhumphrey42_functions.cpp
    Author: Kayla Humphrey
    Date: 4/16/2023
    Purpose: The functions for the monster zoo program. (Program 4)
*/

#include "knhumphrey42_prog4.h"

/*
    Name: loadMonstersFromFile()
    Purpose: takes monster data from an input file and loads it into program
*/
int loadMonstersFromFile(int current, Monsters monsterArray[]){
    ifstream input;
    string filename;
    string tempstring;

    //if zoo is full, display warning and exit function
    if(current >= SIZE){ 
        cout << "\nUh Oh! The Zoo is full. Cannot load monsters from file."; 
        input.close();
        return current;
    }

    //else, go ahead and open
    cout << "\nWhat is the name of the file with your monster data? (ex: filename.txt)"
         << "\nFILENAME:  ";
    getline(cin, filename);

    //error for empty files and files that cannot open (.peek() returns the first char. Char values less than 0 means it's PROBABLY empty)
    input.open(filename);
    if(!(input.is_open()) || input.peek() < 0){
        cout << "\nERROR: Unable to open file or the file is empty.";
        return current;
    }
    else{
        //then start extraction
        while(getline(input,monsterArray[current].name, '#') && current < 75){
            getline(input, monsterArray[current].description, '#');
            getline(input, tempstring, '#');
            monsterArray[current].weight = stod(tempstring);
            getline(input, tempstring, '#');
            monsterArray[current].height = stod(tempstring);
            getline(input, monsterArray[current].location, '#');
            getline(input, tempstring, '#');
            monsterArray[current].danger = stoi(tempstring);
            getline(input, tempstring, '#');
            monsterArray[current].Costs.careHours = stod(tempstring);
            getline(input, tempstring, '#');
            monsterArray[current].Costs.careCost = stod(tempstring);
            getline(input, tempstring, '#');
            monsterArray[current].Costs.foodCost = stod(tempstring);
            getline(input, tempstring, '#');
            monsterArray[current].Costs.materialCost = stod(tempstring);
            
            cout << endl << monsterArray[current].name << " has been added.";
            current++;

            if(current == SIZE){ //incase the zoo gets full in the middle of uploading
                cout << "\nERROR: Zoo is full before the file has finished uploading. Remaining monsters cannot enter until space is available."
                    << "\nThe program will continue on, but only with those sucessfully added.";
                input.close();
                return current;
            }
        }

        cout << "\n\nAll creatures from " << filename << " have been added to the program.";
        input.close();
        return current;
    }    
}

/*
    Name: registerMonster
    Purpose: Adds a monster to the end of monster array
*/
int registerMonster(int current, Monsters monsterArray[]){
    int validatei = 0; //temp value for integers
    double validated = 0.0; //temp value for doubles

    //first, check size
    if(current >= SIZE){
        cout << "\nERROR: Zoo is full. No new monsters can be registered until space is available.";
        return current;
    }

    //loading information
    cout << "\nNAME:  ";
    getline(cin, monsterArray[current].name);
    cout << "DESCRIPTION:  ";
    getline(cin, monsterArray[current].description);
    cout << "WEIGHT (in pounds):  ";
    cin >> validated;
    while(validated <= 0){
        cout << "\nERROR: Impossible number! Must be greater than 0."
             << "\nWEIGHT:  ";
        cin >> validated;
    }
    monsterArray[current].weight = validated;
    cout << "HEIGHT (in feet):  ";
    cin >> validated;
    while(validated <= 0){
        cout << "\nERROR: Impossible number! Must be greater than 0."
             << "\nHEIGHT:  ";
        cin >> validated;
    }
    cin.ignore();
    monsterArray[current].height = validated;
    cout << "LAST KNOWN LOCATION:  ";
    getline(cin, monsterArray[current].location);
    cout << "DANGER LEVEL (1-5):  ";
    cin >> validatei;
    while(validatei < 1 || validatei > 5){
        cout << "\nERROR: Must be 1-5"
             << "\nDANGER LEVEL:  ";
        cin >> validatei;
    }
    monsterArray[current].danger = validatei;
    cout << "\nCARE INFORMATION (per week):"
         << "\n\tRequired direct care for monster (in hours): ";
    cin >> validated;
    while(validated < 0){
        cout << "\n\tERROR: Impossible number! Must be positive."
             << "\n\tRequired direct care for monster:  ";
        cin >> validated;
    }
    monsterArray[current].Costs.careHours = validated;
    cout << "\tCost of care: $";
    cin >> validated;
    while(validated < 0){
        cout << "\n\tERROR: Impossible number! Must be positive."
             << "\n\tCost of care: $";
        cin >> validated;
    }
    monsterArray[current].Costs.careCost = validated;
    cout << "\tFood cost: $";
    cin >> validated;
    while(validated < 0){
        cout << "\n\tERROR: Impossible number! Must be positive."
             << "\n\tFood cost: $";
        cin >> validated;
    }
    monsterArray[current].Costs.foodCost = validated;
    cout << "\tMedical & grooming cost: $";
    cin >> validated;
    while(validated < 0){
        cout << "\n\tERROR: Impossible number! Must be positive."
             << "\n\tMedical & grooming cost: $";
        cin >> validated;
    }
    monsterArray[current].Costs.materialCost = validated;
    cin.ignore();

    current++;
    cout << "\n\n" << monsterArray[current - 1].name << " has been added.";
    return current;
}

/*
    Name: removeMonster()
    Purpose: Removes a monster in the list 
*/
int removeMonster(int current, Monsters monsterArray[]){
    string name = " ";
    int index = -1;

    //list monsters
    cout << "\nThe following is a list of all the monsters in the zoo:";
    for(int i = 0; i < current; i++){
        cout << "\n" << monsterArray[i].name;
    }

    //pick name
    cout << "\n\nWhat monster is leaving the zoo?"
         << "\nMONSTER NAME:  ";
    getline(cin, name);

    //find index
    for(int i = 0; i < current; i++){
        if(monsterArray[i].name.compare(name) == 0){
            index = i;
            break;
        }
    }

    //if not found, end function. if found, remove monster.
    if(index == -1){
        cout << "\nSorry, a monster by the name of " << name << " could not be found.";
        return current;
    }
    else{
        //shift to the left 1 except for the last one. (this is only necessary in cases where the zoo is full)
        for(int i = index; i < current - 1; i++){
            monsterArray[i].name = monsterArray[i+1].name;
            monsterArray[i].description = monsterArray[i+1].description;
            monsterArray[i].weight = monsterArray[i+1].weight;
            monsterArray[i].height = monsterArray[i+1].height;
            monsterArray[i].location = monsterArray[i+1].location;
            monsterArray[i].danger = monsterArray[i+1].danger;
            monsterArray[i].Costs.careHours = monsterArray[i+1].Costs.careHours;
            monsterArray[i].Costs.careCost = monsterArray[i+1].Costs.careCost;
            monsterArray[i].Costs.foodCost = monsterArray[i+1].Costs.foodCost;
            monsterArray[i].Costs.materialCost = monsterArray[i+1].Costs.materialCost;
        }
        /* 
            This makes it so that there are two elements of the monster array that have the same data, BUT current is decremented 
            SO, the second occurance is inaccessible. It will be overwritten if someone registers a new monster.
        */
        current--;
        cout << "\nYou have removed " << name << ".";
        return current;

    }
}

/*
    Name: printMonsters()
    Purpose: Prints out all the monsters data
*/
void printMonsters(int current, Monsters monsterArray[]){
    cout << endl; //format purposes

    //check for no monsters, else, print the stuff!
    if(current == 0){
        cout << "\nTHERE ARE NO MONSTERS AT YOUR ZOO!";
    }
    else{
        cout << "\n------------------------------------------------------";
        for(int i = 0; i < current; i++){
            cout << "\n**MONSTER " << i + 1 << "**"
                 << "\nName:\t" << monsterArray[i].name
                 << "\nDescription:\n\t" << monsterArray[i].description
                 << "\nWeight:\t" << monsterArray[i].weight << " pound(s)"
                 << "\nHeight:\t" << monsterArray[i].height << " feet"
                 << "\nLast known location:\t" << monsterArray[i].location
                 << "\nDanger level:\t" << monsterArray[i].danger
                 << "\nWeekly Care Information:"
                 << "\n\t-Hours of care required:\t" << monsterArray[i].Costs.careHours
                 << "\n\t-Cost of care:\t\t\t" << monsterArray[i].Costs.careCost
                 << "\n\t-Food cost:\t\t\t" << monsterArray[i].Costs.foodCost
                 << "\n\t-Grooming & Supplies Cost:\t" << monsterArray[i].Costs.materialCost
                 << "\n\n------------------------------------------------------";
                 
        }
    }
}

/*
    Name: printCostInfo()
    Purpose: Prints out all the costs for each monster and the total
*/
void printCostInfo(int current, Monsters monsterArray[]){
    double total = 0.0;
    double temp = 0.0; //holds the current monsters total so it can be printed

    if(current == 0){
        cout << "\nThere are no monsters in the zoo so the total cost is $0.00.";
    }
    else{
        cout << "\nCOST OF EACH MONSTER FOR ONE WEEK:\n\n"
             << left <<  setw(20) << "MONSTER" <<  " " << right << setw(20) << "CARE COST";
    
        for(int i = 0; i < current; i++){
            temp = monsterArray[i].Costs.careHours * monsterArray[i].Costs.careCost + monsterArray[i].Costs.foodCost + monsterArray[i].Costs.materialCost;
            total += temp;
            cout << left << endl << setw(20) << monsterArray[i].name << "$" << right << setw(20) << temp;
        }

        cout << endl <<  left << setw(20) << "\nTOTAL COST:" << " $" << right << setw(20) << total;
    }
}

/*
    Name: saveMonstersToFile()
    Purpose: saves monsters to an output file
*/
void saveMonstersToFile(int current, Monsters monsterArray[]){
    ofstream output;
    string filename;

    if(current == 0){
        cout << "\nThere are no monsters in the zoo so none can be saved to a file.";
    }
    else{
        cout << "\nWhat is the name of the file you want to save your creatures to?"
             << "\nFILENAME:  ";
        getline(cin, filename);

        output.open(filename);
        output << fixed << setprecision(2);
        for(int i = 0; i < current; i++){
            output << monsterArray[i].name << "#"
                   << monsterArray[i].description << "#"
                   << monsterArray[i].weight << "#"
                   << monsterArray[i].height << "#"
                   << monsterArray[i].location << "#"
                   << monsterArray[i].danger << "#"
                   << monsterArray[i].Costs.careHours << "#"
                   << monsterArray[i].Costs.careCost << "#"
                   << monsterArray[i].Costs.foodCost << "#"
                   << monsterArray[i].Costs.materialCost << "#";
        }

        output.close();
        cout << "\n\nYour monsters currently housed in the zoo were sucessfully saved to the "
             << filename << " file."
             << "\n\nGOODBYE!";
    }
}