/*
	filename: hashTable.cpp
	author: Kayla Humphrey
	Date: 11/1/2023
	Purpose: functions for the hashTable class
*/
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "hashTable.h"
using std::string;
using std::cout;

/*
	Name: hashTable
	Purpose: constructor for hashTable class
*/
hashTable::hashTable(int size)
{	
	//set table size and make array
	this->tableSize = size;
	this->hashArray = new entry*[this->tableSize];

	//set all to null
	for(int i = 0; i < this->tableSize; i++){
		this->hashArray[i] = nullptr;
	}

	//seed random
	srand (time(0));	//this needs to be in the constructor, otherwise every user gets the same salt
}

/*
	Name: ~hashTable
	Purpose: destructor for hashTable class
*/
hashTable::~hashTable(){
	//loops through array
	for(int i = 0; i < this->tableSize; i++){
		//if there is something in the bucket, need to delete the contents
		if(this->hashArray[i] != nullptr){
			//create the stopping point at head
			hashTable::entry* head = this->hashArray[i];

			if(head->next != nullptr){ //there is more than 1 node in the list
				//delete the linked list nodes except head
				while(head->next != nullptr){
					hashTable::entry* tbd = head->next;
					hashTable::entry* previous = head;

					//find tbd and previous
					while(tbd->next){
						previous = tbd;
						tbd = tbd->next;
					}

					//delete node
					previous->next = tbd->next;
					delete tbd;
				}
			}
			//delete head because it is all that is left
			delete head;
		}	
	}

	//delete array
	delete [] this->hashArray;
	cout << "\ndeconstruction complete.";
}

//don't touch this!
string hashTable::generateSalt()
{
	string s = "";
	
	for(int i = 0; i < tableSize; i++)
		s = s + char('!' + (rand() % 93));
	return s;
}

/*
	name: getSalt
	parameters: a string for the username
	purpose: if a user exists in the hashTable, return that user's salt as a string
*/
string hashTable::getSalt(string user){
	//true if found, false if not
	hashTable::entry* found = this->getEntry(user);
	
	if(!found){
		return "NOTFOUND";
	}
	else{
		return found->getSalt();
	}
}

/*
	name: addEntry
	parameters: string for username, string for salt, and string for hashedpassword
	purpose: adds a user to the hashtable
*/
void hashTable::addEntry(string username, string salt, string hashedpasswrd){
	//make sure user doesn't already exist
	hashTable::entry* found = this->getEntry(username);
	if(found){
		cout << "\nERROR: this username already exists";
	}
	else{ //user doesn't exist so we can add it
		//create the newNode
		hashTable::entry* newNode = new hashTable::entry(username, salt, hashedpasswrd);

		//find key
		int bucketIndex = this->hash(username);

		//search
		if(this->hashArray[bucketIndex] == nullptr){ //if the bucket is empty
			this->hashArray[bucketIndex] = newNode;
		}
		else{
			//add to end of list
			//make placeholder
			hashTable::entry* current = this->hashArray[bucketIndex];

			while(current->next != nullptr){
				current = current->next;
			}

			//adds to the end of the list 
			current->next = newNode;
		}
	}
	
}

/*
	name: validateLogin
	parameters: string for username, string for password(has to be hashed already)
	purpose: Returns true if a user exists and puts in the correct password
*/
bool hashTable::validateLogin(string username, string password){
	//call getEntry to find entry
	hashTable::entry* validating = getEntry(username);

	if(validating){ //username exists
		if(validating->getHashedpwd() == password){ //if they put in the right password
			return true;
		}
		else{ //wrong password
			return false;
		}
	}
	else{ //doesn't exist
		return false;
	}

}

/*
	name: removeUser
	parameters: string for username and string for password(must be already hashed)
	purpose: returns true if a user logs in correctly and their account has been deleted successfully
*/
bool hashTable::removeUser(string username, string password){
	//if they log in correctly, and they exist
	if(this->validateLogin(username, password)){
		//make a pointer to the node that we are deleting
		hashTable::entry* tbd = this->getEntry(username);
		
		//find bucket it will be in
		int bucketIndex = this->hash(username);

		//search and delete
		if(tbd->next == nullptr){ //if to be deleted is the only one in the list
			delete tbd;
			return true;
		}
		else{ //search through list 
			//set previous
			hashTable::entry* previous = this->hashArray[bucketIndex];

			//if it is the front of the list
			if(previous == tbd){
				this->hashArray[bucketIndex] = tbd->next;
				delete tbd;
				return true;
			}
			
			//make previous the one before to be deleted
			while(previous->next != tbd){
				previous = previous->next;
			}

			//set up the links so tbd can be deleted
			previous->next = tbd->next;

			//delete
			delete tbd;
			return true;
		}
	}
	else{
		return false; //login failed
	}
}


//don't touch this!
int hashTable::hash(string key)
{
	int sum = 0;
	for(int i = 0; i < key.size(); i++)
		sum += key[i];
	
	return sum % tableSize;
}

/*	
	name: getEntry
	parameter: a string for username (used as a key)
	purpose: searches through the hashtable to find an entry that matches the key, returns that entry if found, or null if not found

*/
hashTable::entry* hashTable::getEntry(string key){
	//find bucket
	int bucketIndex = this->hash(key);

	//create a placeholder
	hashTable::entry* current = this->hashArray[bucketIndex];

	//check to see if bucket is empty
	if(hashArray[bucketIndex] == nullptr){
		return nullptr;
	}

	if(current->getUsername() != key){ 
		current = current->next;

		while(current != nullptr){
			if(current->getUsername() == key){
				return current;
			}
			else{
				current = current->next;
			}
		}
		return nullptr;
	}
	else{
		return current; //found
	}
	
}




