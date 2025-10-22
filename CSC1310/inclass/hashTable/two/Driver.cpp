#include "HashTable.h"

int main(){
    //create a hashtable with 3 buckets
    HashTable hash(3);
    int temp;

    //add 3 values
    hash.putValue(0, 33);
    hash.putValue(1, 22);
    hash.putValue(2, 44);

    //find those values
    temp = hash.getValue(0);
    cout << "SEARCH IN BUCKET 0 RETURNS " << temp << endl;

    temp = hash.getValue(1);
    cout << "SEARCH IN BUCKET 1 RETURNS " << temp << endl;

    temp = hash.getValue(2);
    cout << "SEARCH IN BUCKET 2 RETURNS " << temp << endl;
}