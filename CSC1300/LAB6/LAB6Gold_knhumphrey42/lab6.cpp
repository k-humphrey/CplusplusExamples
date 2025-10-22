/*
    Filename: lab6.cpp
    Author: Kayla Humphrey
    Date: 2/28/2023
    Purpose: A monster fight program
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

//function prototypes
void readData(ifstream&, string, int&, int&, string&);
bool normalRound(string, string, int&, int&, string&);

int main(){
    //variables
    ifstream input;
    ofstream output;
    string name1 = " ", name2 = " ", filename = " ", winner = " ";
    int hitP1 = 0, hitP2 = 0, health1 = 0, health2 = 0, i = 1;
    bool again = true;
    srand(time(0));


    //opening and getting files from user.
    cout << endl << setfill('*') << setw(50) << " " << setfill(' '); //line
    cout << "\n\n\t\tMonster Colosseum\n";
    cout << endl << setfill('*') << setw(50) << " " << setfill(' '); //line

    cout << "\nPlease type in the first monster file you want to open in the format of \"filename.txt\""
         << "\nDO NOT include the quotes." << endl;
    getline(cin, filename);
    readData(input, filename, hitP1, health1, name1); //reading data from first file
    
    cout << "\nPlease type in the second monster file you want to open in the format of \"filename.txt\""
         << "\nDO NOT include the quotes." << endl;
    getline(cin,filename);
    readData(input, filename, hitP2, health2, name2); //reading data from second file
    

    //FIGHTING :D
    cout << "\n\n" << setfill('=') << setw(50) << " " << setfill(' '); //line
    cout << "\nIt's monster fighting time!";
    do{
        cout << "\n\n\t\tROUND " << i;
        again = normalRound(name1, name2, hitP1, health2, winner);
        if(again != false){ // incase a monster dies in the first attack.
        again = normalRound(name2, name1, hitP2, health1, winner);
        }
        i++;

    }while(again == true && i <= 5);

    //Winner calculation and output
    if(health1 > health2)
        winner = name1;
    else
        winner = name2;
    cout << "\n\n" << setfill('=') << setw(50) << " " << setfill(' '); //line
    cout << "\n\nWINNING MONSTER: " << winner;

    //TO OUTPUT FILE
    output.open("winner.txt");
    output << endl << " ____      ____  _ "
           << endl << "|_  _|    |_  _|(_)"
           << endl << "  \\ \\  /\\  / /  __   _ .--.   _ .--.  .---.  _ .--. "
           << endl << "   \\ \\/  \\/ /  [  | [ `.-. | [ `.-. |/ /__\\\\[ `/'`\\] "
           << endl << "    \\  /\\  /    | |  | | | |  | | | || \\__., | | "\
           << endl << "     \\/  \\/    [___][___||__][___||__]'.__.'[___] "
           << endl
           << endl << "   ,    ,    /\\   /\\"
           << endl << "  /( /\\ )\\  _\\ \\_/ /_"
           << endl << "  |\\_||_/| < \\_   _/ >"
           << endl << "  \\______/  \\|0   0|/"
           << endl << "    _\\/_   _(_  ^  _)_"
           << endl << "   ( () ) /`\\|V\"\"\"V|/`\\"
           << endl << "     {}   \\  \\_____/  /"
           << endl << "     ()   /\\   )=(   /\\"
           << endl << "WINNING MONSTER: " << winner;
    output.close();
    return 0;
}

/* 
    Name: readData()
    Purpose: To open a file, validate it, read all the monster data into variables through reference.
*/
void readData(ifstream& input, string filename, int& hitP, int& health, string& name){
    input.open(filename);
    while(!input.is_open()){
        cout << "\nError opening file. Retype the filename in the format \"filename.txt\"."
             << "\nDO not include the quotes" << endl;
        getline(cin, filename);
        input.open(filename);
    }
    getline(input, name);
    input >> hitP;
    input >> health;
    input.close();
}

/*
    Name: normalRound()
    Purpose: Runs through a round of the monster fight given the attacker, reciever, the attackers hit
    Points, and the reciever's health points.
*/
bool normalRound(string attacker, string reciever, int& hitP, int& health, string& winner){
    int randNum = rand() % (5 - 1 + 1) + 1; //1-5 for attack
    int attack = hitP / randNum; //integer divison is done here on purpose. :)
    health = health - attack;
    randNum = rand() % (3 - 1 + 1) + 1; //1-3 for healing
    //Attacker takes away health, if = or < 0 then the monster passes out and the loop stops
    cout << "\n\nIt is " << attacker << "\'s turn to attack."
         << "\n\t*-.BOOM.-*"
         << "\n" << reciever << " takes " << attack << " damage."
         << "\nYeesh. That's gotta sting.";
    if(health <= 0){
        cout << "\n\t===THUD==="
             << "\n" << reciever << " passed out!";
        return false;
    }else{
        cout << "\n" << reciever << " now has " << health << " health remaining.";
    }
    
    //if the monster hasn't died, 1 in 3 chance to heal 100 pts
    if(randNum == 1){
        health = health + 100;
        cout << "\n\t.-*ZAP*-."
             << "\nWhat?! A mysterious light shines down on " << reciever << "."
             << "\n" << reciever << " gains 100 health points."
             << "\nAhh. That feels better."
             << "\n" << reciever << " now has " << health << " health remaining.";
    }
    return true;
}
