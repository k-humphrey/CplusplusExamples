#ifndef HASHTABLE_H
#define HASHTABLE_H

    #include <iostream>
    using namespace std;

    class HashTable{
        private:
                struct HashEntry{
                    int key;
                    int value;
                    HashEntry* next;
                };
                int tableSize;
                HashEntry** hashArray;
        public:
                HashTable(int size){
                    tableSize = size;
                    hashArray = new HashEntry*[tableSize];
                    for(int i = 0; i < tableSize; i++){
                        hashArray[i] = nullptr;
                    }
                }
                ~HashTable(){
                    for(int i = 0; i < tableSize; i++){
                        if(hashArray[i] != nullptr){
                            HashEntry* prevEntry = nullptr;
                            HashEntry* entry = hashArray[i];
                            while(entry != nullptr){
                                prevEntry = entry;
                                entry = entry->next;
                                delete prevEntry;
                            }
                        }
                    }
                    delete [] hashArray;
                }
                int getValue(int key){
                    int bucketIndex = key % tableSize;
                    /* This edge case is not needed because the while loop down there catches the null case
                        It avoids a segmentation fault because we are not checking entry->next, just entry. 
                        With &&, if the left is false, compiler will not try to access null->key
                    */
                    if(hashArray[bucketIndex] == nullptr){
                        return -1; //key not found
                    }
                    else{
                        //linear search in linked list :)
                        HashEntry* entry = hashArray[bucketIndex];
                        while(entry != nullptr && entry->key != key){
                            entry = entry->next;
                        }
                        if(entry == nullptr){
                            return -1; //not found inside bucket
                        }
                        else{
                            return entry->value; //found inside bucket
                        }
                    }
                }
                void putValue(int key, int value){
                    //dynamically allocate a new entry
                    HashEntry* newHash = new HashEntry;
                    newHash->value = value;
                    newHash->key = key;
                    newHash->next = nullptr;

                    //find the bucket it needs to be in
                    int bucketIndex = key % tableSize;
                    cout << "BUCKET  " << bucketIndex << endl;
                    //add to the end
                    if(hashArray[bucketIndex] == nullptr){
                        hashArray[bucketIndex] = newHash; //no collision
                    }
                    else{
                        HashEntry* entry = hashArray[bucketIndex];
                        while(entry->next != nullptr && entry->key != key){ // search for the key inside the bucket, or get to the end
                            entry = entry->next;
                        }
                        if(entry->key == key){
                                entry->value = value; //just overwrite the value if it already exists
                        }
                        else{
                            entry->next = newHash; //if there is no other collisions, just add to the end
                        }
                    }
                }
                void removeValue(int key){

                }
    };
#endif