/*
    Filename: lab3.cpp
    Author: Kayla Humphrey
    Date: 2/7/2023
    Purpose: A program that allows the user to build their own vehicle in candyland.
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){

    //variables
    int carColor = 0;
    string colorOutput = ""; //just for output purposes
    int wheels = 0;
    char turbo = 'a';
    char gumballGun = 'a';
    char sugarCoat = 'a';
    int gift = 0;
    double speed = 0.0;
    double traction = 0.0;
    int power = 5; // refering to destruction power
    int level = 0; //enchantment level
    string skill = "";

    srand(time(0)); // allows for psuedo random

    cout << "\n*************Candyland Car Maker!*************" //47
         << "\nWelcome to Candyland! You'll need a car to get around. Let's build one!"
         << "\nTo start, what color do you want your car to be?"
         << "\n1.Peppermint red, 2.Cotton Candy pink, 3.Chocolate brown, or 4.Lemondrop yellow"
         << "\n(Enter 1, 2, 3, or 4):  ";
    cin >> carColor;

    cout << "\nWhat kind of wheels do you want?"
         << "\n1.Gumdrops (speed: 3, traction: 9)"
         << "\n2.Lollipops (speed: 10, traction: 2.5)"
         << "\n3.Marshmellows (speed: 7.5, traction: 5)"
         << "\n4.Skittles (speed: 6, traction: 5)"
         << "\n(Enter 1, 2, 3, or 4):  ";
    cin >> wheels;

    cout << "\nDo you want to add a sugar rush turbo to your car?"
         << "\n(Enter y or n):  ";
    cin >> turbo;

    cout << "\nDo you want to add a gumball gun to your car?"
         << "\n(Enter y or n):  ";
    cin >> gumballGun;

    cout << "\nDo you want to add a sugar coating to your wheels?"
         << "(Enter y or n):  ";
    cin >> sugarCoat;

    cout << "\nLastly, we will visit a wizard to enchant your car with special abilities. What should we gift him?"
         << "\n1.A bag of gold"
         << "\n2.A chocolate bar"
         << "\n3.A new wizard hat"
         << "\n4.A pet cat"
         << "\n(Enter 1, 2, 3, or 4):  ";
    cin >> gift;

     //calculations and input validation
     if( !(carColor >= 1 && carColor <= 4) ){ //if carColor is not 1-4
          cout << "\nERROR: invalid input";
     }
     else if(carColor == 1){
          colorOutput = "Peppermint red"; //variable just for output purposes 
     }
     else if(carColor == 2){
          colorOutput = "Cotton Candy pink"; 
     }
     else if(carColor == 3){
          colorOutput = "Chocolate brown";
     }
     else{
          colorOutput = "Lemondrop yellow";
     }

     switch(wheels){
          case 1: speed = 3.0;
                  traction = 9.0;
                  break;
          case 2: speed = 10.0;
                  traction = 2.5;
                  break;
          case 3: speed = 7.5;
                  traction = 5.0;
                  break;
          case 4: speed = 6.0;
                  traction = 5.0;
                  break;
          default: cout << "\nERROR: invalid input";
     }
     if(turbo == 'y'){
          speed = speed + (speed * 0.1); //10% boost to speed
     }
     else if(turbo == 'n'){
          //no change
     }
     else{
          cout << "\nERROR: invalid input";
     }
     
     if(gumballGun == 'y'){
          power = 10;
     }
     else if(gumballGun == 'n'){
          //no change
     }
     else{
          cout << "\nERROR: invalid input";
     }
     
     if(sugarCoat == 'y'){
          traction = traction + (traction * 0.1); // 10% boost to traction
     }
     else if(sugarCoat == 'n'){
          //no change
     }
     else{
          cout << "\nERROR: invalid input";
     }
     
     switch(gift){
          case 1: level = (rand() % ((5-1) + 1)) + 1; // generates a number between 1 and 5
                  skill = "[Fire Resistance]";
                    cout << "\nWIZARD: Wonderful! I can buy a new orb to ponder with this."
                         << "\nWIZARD: I shall reward your car with level " << level << " " << skill
                         << "\nWIZARD: Now you can navigate through more trecherous lands.";
                    break;

          case 2: level = (rand() % ((5-1) + 1)) + 1; // generates a number between 1 and 5
                  skill = "[Flight]";
                    cout << "\nWIZARD: I love chocolate! This is a perfect gift!"
                         << "\nWIZARD: I shall reward your car with level " << level << " " << skill
                         << "\nWIZARD: You can now fly above danger.";
                    break;
          case 3: level = (rand() % ((5-1) + 1)) + 1; // generates a number between 1 and 5
                  skill = "[Ice Cannon]";
                    cout << "\nWIZARD: This is such a pretty hat! Thank you!"
                         << "\nWIZARD: I shall reward your car with level " << level << " " << skill
                         << "\nWIZARD: Now you can freeze scary monsters.";
                    break;
          case 4: level = (rand() % ((5-1) + 1)) + 1; // generates a number between 1 and 5
                  skill = "[Size Boost]";
                    cout << "\nWIZARD: Ah! A companion! It has been so lonely here. Thank you!"
                         << "\nWIZARD: I shall reward your car with level " << level << " " << skill
                         << "\nWIZARD: Now you have room for friends on your journey.";
                    break;
          default:  cout << "\nERROR: invalid input";
     }

     //results output
     cout << "\n\n" << setfill('*') << setw(47) << " " << setfill(' '); //line of stars
     
     cout << "\nAlright! Let's review your stats!\n" << right << fixed <<  setprecision(2) //right aligned, 2 decimal points
          << setw(20) << "Color:  " << colorOutput << endl
          << setw(20) << "Speed:  " << speed << endl
          << setw(20) << "Traction:  " << traction << endl
          << setw(20) << "Destructive Power:  " << power << endl
          << setw(20) << "Skill:  " << skill << endl
          << setw(20) << "Skill Level:  " << level << endl;

     //ascii art of candy
     cout << " ___      .-\"\"-.      ___"
          << "\n \\  \"-.  /      \\  .-\"  /"
          << "\n  > -=.\\/        \\/.=- <"
          << "\n  > -=\'/\\        /\\\'=- <"
          << "\n /__.-\'  \\      /  \'-.__\\"
          << "\n          \'-..-\'";

     cout << "\n\n" << setfill('*') << setw(47) << " " << setfill(' '); //line of stars

     return 0;
}