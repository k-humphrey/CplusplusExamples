/*
	Title:  Lab2.cpp
	Author: Kayla Humphrey
	Date:  09/12/2023
	Purpose:  Demonstrate your knowledge of recursive functions
*/

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>
using namespace std;

//function prototypes for the recursive functions
int sumOfNumbers(int);
bool isMember(int*, int, int);
void stringReverser(string, int);
bool isPalindrome(string);
int multiply(int, int);

const int ARRAY_SIZE = 10;

int main()
{
	int choice, num, num1, num2;
	int myArray[ARRAY_SIZE];
	srand(time(NULL));
	string userString, userStrModified;
	
	do{
		
		cout << "\n\nWhat do you want to do?\n";
		cout << "\t1.  Sum of Numbers\n";
		cout << "\t2.  IsMember Array Function\n";
		cout << "\t3.  String Reverser\n";
		cout << "\t4.  Palindrome Detector\n";
		cout << "\t5.  Recursive Multiplication\n";
		cout << "\t6.  End the Program\n";
		cout << "CHOOSE 1-6:  ";
		cin >> choice;
		while(choice < 1 || choice > 6)
		{
			cout << "\nInvalid input!  CHOOSE 1-6:  ";
			cin >> choice;
		}
		switch(choice)
		{
			case 1:
				cout << "\n\nSUM OF NUMBERS\n";
				cout << "Enter an integer:  ";
				cin >> num;
                cout << "\n\nThe result is:  ";
                cout << sumOfNumbers(num);
				break;
				
				
			case 2:
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					myArray[x] = (rand()%100)+1;
				}
				cout << "\n\nISMEMBER ARRAY FUNCTION\n";
				cout << "Enter an integer:  ";
				cin >> num;
				cout << "\nHere are the array values:  ";
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					cout << myArray[x] << " ";
				}
				//print if the value that the user entered is in the array or not here
                if(isMember(myArray, num, ARRAY_SIZE)){
                    cout << "\n\nYes! " << num << " is in the array.";
                }
                else{
                    cout << "\n\nNo! " << num << " is NOT in the array.";
                }
				break;
				
				
			case 3:
				cout << "\n\nSTRING REVERSER\n";
				cout << "Enter a string and I will reverse it:  ";
				cin.ignore();
				getline(cin, userString);
				stringReverser(userString, userString.size());
				
				break;
				
				
			case 4:
				cout << "\n\nPALINDROME DETECTOR\n";
				cout << "Enter a string and I will tell you if it is a palindrome:  ";
				cin.ignore();
				getline(cin, userString);
				
				//change string to be all uppercase
				for(int x=0; x<userString.length(); x++)
				{
					userString[x] = toupper(userString[x]);
				}
				
				//remove spaces and commas from string
				userStrModified = userString;
				for(int x=0; x<userStrModified.size(); x++)
				{
					if(userStrModified[x] == ' ') 
					{
						userStrModified.erase(x, 1);
					}
					if(userStrModified[x] == ',') 
					{
						userStrModified.erase(x, 1);
					}
				}
				
                if(isPalindrome(userStrModified)){
                    cout << "\n\nYes! " << userString << " IS a palindrome!";
                }
                else{
                    cout << "\n\nNo! " << userString << " is NOT a palindrome.";
                }
				
				
				break;
				
				
			case 5:
				cout << "\n\nRECURSIVE MULTIPLICATION\n";
				cout << "Enter in the first integer:  ";
				cin >> num1;
				cout << "\nEnter in the second integer:  ";
				cin >> num2;
                cout << "\n\nThe value of " << num1 << " x " << num2 << " is " << multiply(num1, num2);
				
				
				break;
				
		}		
	}while(choice != 6);
	
	cout << "\n\nGOODBYE!\n\n";
	return 0;
}


/*
    Name: sumOfNumbers
    Parameters: an integer
    Purpose: A recursive function that adds up all the numbers to the integer passed.
*/
int sumOfNumbers(int x){
	if(x <= 0){ //base case, if 0, stop
        return x;
    }
    else{
        return sumOfNumbers(x - 1) + x; //recursive case
    }
}

/*
    Name: isMember
    Parameters: an array, a key, and the size of array
    Purpose: a recursive function that searches for a key inside an array
*/
bool isMember(int* arr, int key, int size){
    size = size - 1; // for scope errors and to update for recursion
    if(size < 0 && arr[size] != key){ // base, if not found
        return false;
    }
    else if(arr[size] == key){ // base, if found
        return true;
    }
    else{
        return isMember(arr, key, size); //recursive case
    }
}

/*
    Name: stringReverser
    Parameters: a string and the length of the string
    Purpose: A recursive function that prints out a word in reverse
*/
void stringReverser(string word, int length){
    length = length - 1; // for scope errors and to update for recursion
    cout << word.at(length);
    if(length == 1){ //base case, stop at the beginning of the word
        cout << word.at(0);
    }
    else{
        stringReverser(word, length); // recursive case
    }
}

/*
    Name: isPalindrome
    Parameters: a string
    Purpose: a recursive function that returns true if a word is a palindrome
*/
bool isPalindrome(string word){
    if(word.size() == 1){ // base, if word is palindrome and has an odd size
        return true;
    }
    else if((word.size() == 2) && (word.at(0) == word.at(1))){ // base if word is palindrome and word has even size
        return true;
    }
    else if(word.size() == 2){ // base if a words two middle letters are different
        return false;
    }
    else{ 
        return isPalindrome(word.substr(1 , word.size() - 2)); //recursive
    }
}

/*
    Name: multiply
    Parameters: two integers
    Purpose: a recursive function that multiplies two integers
*/
int multiply(int x, int y){
    if(x == 1){ // base, if it is 1 times something
        return y;
    }
    return multiply(x-1, y) + y; //recursion
}

