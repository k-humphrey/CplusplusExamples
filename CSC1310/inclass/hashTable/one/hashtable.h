/*
    Filename: hashtable.h
    Author: Kayla Humphrey
    Date: 10/11/2023
    Purpose: Header file for a hashtable (closed hashing) LINEAR PROBING... 
*/
#ifndef HASHTABLE_H
#define HASHTABLE_H
    #include <iostream>
    using namespace std;

    class hashtable{
        private:
                struct HashEntry{
                    int key; //think like filename
                    int value; //think words in text file
                };
                int tableSize;
                HashEntry** hashArray;  //pointer to the hashtable


        public:
                hashtable(int size){
                    //create array
                    tableSize = size;
                    hashArray = new HashEntry*[tableSize];

                    //set pointers to nullptr
                    for(int i = 0; i < tableSize; i++){
                        hashArray[i] = nullptr;
                    }
                }

                ~hashtable(){
                    for(int i = 0; i < tableSize; i++){
                        if(hashArray[i] != nullptr){
                            delete hashArray[i];
                        }
                        delete [] hashArray;
                    }
                }

                int getValue(int key){
                    //find what should be the bucket index
                    int bucketIndex = key % tableSize;

                    //for collisions
                    while(hashArray[bucketIndex]  != nullptr && hashArray[bucketIndex]->key != key){
                        bucketIndex = bucketIndex+1 % tableSize;
                    }

                    //if not found
                    if(hashArray[bucketIndex] == nullptr){
                        return -1;
                    }
                    else{ //if found
                        return hashArray[bucketIndex]->value;
                    }

                }

                void putValue(int key, int value){
                    HashEntry* h;
                    h->key = key;
                    h->value = value;
                    int bucketIndex = key % tableSize;
                    cout << "BUCKET " << bucketIndex << endl;

                    while(hashArray[bucketIndex] != nullptr && hashArray[bucketIndex]->key != key){
                        bucketIndex = (bucketIndex+1) % tableSize;
                        cout << "BUCKET " << bucketIndex << endl;
                    }

                    hashArray[bucketIndex] = h;
                }
    };
#endif