/*
    Filename: lab5.cpp
    Author: Kayla Humphrey
    Date: 02/21/23
    Purpose: A program that calculates totals for a customers order at "The Cauldron"
*/
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;
int main(){
    const double PIZZA = 20.00;
    const double PIZZA_TOP = 2.00;
    const double BURGER = 15.00;
    const double SANDWICH = 10.00;
    double total = 0.0;
    int count = 0; //how many items a user wants 
    int toppings = 0;
    int choice = 0;
    bool fp = true; //first pizza
    bool fb = true; //first burger
    bool fs = true; //first sandwich
    double pizzaCost = 0.0;
    double burgerCost = 0.0;
    double sandwichCost = 0.0;
    ofstream output; //output is the name of the output file variable

    output.open("restaurant.txt");
    cout << fixed  << setprecision(2);
    output << fixed << setprecision(2) << showpoint; //have to format output file a little differently for some reason

    do{
        cout << "\nWelcome to The Cauldron Restaurant!"
             << "\nPlease choose one of the following options:"
             << "\n\t1 - PIZZA"
             << "\n\t2 - BURGER"
             << "\n\t3 - SANDWHICH"
             << "\n\t4 - Done Ordering"
             << "\nCHOICE:  ";
             cin >> choice;
             while(choice < 1 || choice > 4){ //input validation
                cout << "\nOops! That is not a valid choice. Choose 1-4."
                     << "\nCHOICE:  ";
                cin >> choice;
             }
        switch(choice){
            case 1: 
                cout << "\nHow many pizzas do you want to order?  ";
                cin >> count;
                while(count <= 0){ //input validation
                    cout << "\nYou cannot have negative or zero pizzas."
                         << "\nTry again:  ";
                         cin >> count;
                }
                for(int i = 1; i <= count; i++){ // i = the pizza number 
                    cout << "\nFor pizza " << i << ", how many toppings?  ";
                    cin >> toppings;
                    while(toppings <= 0){ //input validation
                    cout << "\nYou cannot have negative or zero toppings."
                         << "\nTry again:  ";
                         cin >> toppings;
                }
                    pizzaCost = PIZZA + (PIZZA_TOP * toppings);
                    if(fp){ //if its the first pizza, 20% off.
                        pizzaCost = pizzaCost - (pizzaCost * .2);
                        fp = false;
                    }
                    total = total + pizzaCost;
                    cout << "This pizza costs $" << pizzaCost;
                }
                cout << "\n\n" << count << " pizzas were added and the total is now $" << total << endl;
                output << count << " pizzas were added and the total is now $" << total << endl; //added to output file.
                break;

            case 2:
                    cout << "\nHow many burgers do you want to order?  ";
                    cin >> count;
                    while(count <= 0){ //input validation
                    cout << "\nYou cannot have negative or zero burgers."
                         << "\nTry again:  ";
                         cin >> count;
                    }
                    for(int i = 1; i <= count; i++){
                        burgerCost = BURGER;
                        if(fb){
                        burgerCost = burgerCost - (burgerCost * .15); // 15% discount
                        fb = false;
                    }
                    total = total + burgerCost;
                    }
                    cout << "\n" << count << " burgers were added and the total is now $" << total << endl;
                    output << count << " burgers were added and the total is now $" << total << endl;
                    break;
            case 3: 
                    cout << "\nHow many sandwiches do you want to order?  ";
                    cin >> count;
                     while(count <= 0){ //input validation
                    cout << "\nYou cannot have negative or zero sandwiches."
                         << "\nTry again:  ";
                         cin >> count;
                    }
                    for(int i = 1; i <= count; i++){
                        sandwichCost = SANDWICH;
                        if(fs){
                        sandwichCost = sandwichCost - (sandwichCost * .1); // 10% discount
                        fs = false;
                    }
                    total = total + sandwichCost;
                    }
                    cout << "\n" << count << " sandwiches were added and the total is now $" << total << endl;
                    output << count << " sandwiches were added and the total is now $" << total << endl;
                    break;
            default: break;//they wish to end the program. break out of switch.
        } 

    }while(choice != 4);
    cout << "\nThe total for your order is $" << total;
    output << "\n\nThe total for your order is $" << total;
    output.close();
    return 0;
}