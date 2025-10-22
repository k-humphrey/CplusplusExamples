/*
    Filename: HashTable.h
    Author: Kayla Humphrey 1310-002
    Date: 10/25/2023
    Purpose: HashTable class for lab 7
*/
#ifndef HASHTABLE_H
#define HASHTABLE_H
    #include "HashEntry.h"

    class HashTable{
        private: 
                HashEntry** hashArray;
                int tableSize;

        public:
                /*
                    Name: HashTable
                    Purpose: Takes in an integer for size and creates an empty hashtable
                */
                HashTable(int size){
                    tableSize = size;
                    hashArray = new HashEntry*[tableSize];

                    //setting all pointers to null
                    for(int i = 0; i < tableSize; i++){
                        hashArray[i] = nullptr;
                    }
                }

                /*
                    Name: ~HashTable
                    Purpose: Deletes all the dynamic memory if it exists in that place
                */
                ~HashTable(){
                    //if theres something, delete it (Checking isnt necessary for this program but I felt like it)
                    for(int i = 0; i < tableSize; i++){
                        if(hashArray[i] != nullptr){
                            delete hashArray[i];
                        }
                        delete [] hashArray;
                    }
                }

                /*
                    Name: putValue
                    Purpose: Places a value in the hashtable, collisions are handled with linear probing
                */
                void putValue(int key, Costume* newCostume){
                    //make new node
                    HashEntry* newNode = new HashEntry(key, newCostume);

                    //find bucket index
                    int bucketIndex = key % tableSize;

                    //collision handling with linear probing
                    while(hashArray[bucketIndex] != nullptr && hashArray[bucketIndex]->getKey() != key){
                        cout << "\nCollision at bucket " << bucketIndex;
                        bucketIndex = (bucketIndex+1) % tableSize;
                    }

                    //place in bucket
                    cout << "\nBUCKET " << bucketIndex;
                    hashArray[bucketIndex] = newNode;
                }
                
                /*
                    Name: printHashTable
                    Purpose: prints out the hashtable entries
                */
                void printHashTable(){
                    cout << "----------";
                    for(int i = 0; i < tableSize; i++){
                        cout << endl << i << ": " << hashArray[i]->getKey() << ", " << hashArray[i]->getValue()->getCostumeName();
                    }
                    cout << "\n----------";
                }
    };
#endif