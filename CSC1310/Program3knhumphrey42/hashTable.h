/*
	filename: hashTable.h
	author: Kayla Humphrey
	date: 11/1/2023
	purpose: header file for hashTable class
*/
#ifndef HASHTABLE_H
#define HASHTABLE_H
	#include <string>
	using std::string;

	class hashTable
	{
		private:
				class entry;
				int tableSize;
				entry** hashArray;
				int hash(string);
				entry* getEntry(string);
		public:
			hashTable(int);
			~hashTable();
			string generateSalt();
			string getSalt(string);
			void addEntry(string, string, string);
			bool validateLogin(string, string);
			bool removeUser(string, string);
	};

	class hashTable::entry
	{
		private:
			string uname;
			string salt;
			string passHash;
		public:
			entry* next;

			/*
				Name: entry
				Parameters: three strings, one for each attribute
				Purpose:  assigns each attribute to the given parameter, and sets the next pointer to null.
			*/
			entry(string un, string s, string hp){
				this->uname = un;
				this->salt = s;
				this->passHash = hp;
				next = nullptr;
			}

			/*
				Name: getUsername
				Purpose: returns username
			*/
			string getUsername(){
				return this->uname;
			}
			/*
				Name: getSalt
				Purpose: Returns salt
			*/
			string getSalt(){
				return this->salt;
			}

			/*
				Name: getHashedpwd
				Purpose: returns hashedpwd
			*/
			string getHashedpwd(){
				return this->passHash;
			}

	};

#endif