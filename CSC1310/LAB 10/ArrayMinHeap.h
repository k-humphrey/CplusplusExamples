/*
    filename: ArrayMinHeap.h
    author: Kayla Humphrey
    date: 11/15/2023
    Purpose: class that implements a minimum heap using creatures
*/
#ifndef ARRAYMINHEAP_H
#define ARRAYMINHEAP_H
#include "Creature.h"


class ArrayMinHeap{
    private:
            Creature* heapArray;
            int capacity;
            int heap_size;


            /*
                name: swap
                Purpose: Takes two pointers to creatures and swaps them
            */
            void swap(Creature* c1, Creature* c2){
                Creature temp = *c1;
                *c1 = *c2;
                *c2 = temp;
            }

            /*
                name: parent
                purpose: Takes the index of a creature and returns the parent index
            */
            int parent(int i){
                return (i - 1) / 2;
            }

            /*
                name: left
                purpose: takes the index of a creature and returns the left child index
            */
            int left(int i){
                return (2 * i + 1); 
            }

            /*
                name: right
                purpose: takes the index of a creature and returns the right child index
            */
            int right(int i){
                return (2 * i + 2);
            }
            
    public:
            /*
                name: ArrayMinHeap
                purpose: takes the capacity and builds an array of creatures of that size
            */
            ArrayMinHeap(int capacity){
                heapArray = new Creature[capacity];
                this->capacity = capacity;
                this->heap_size = 0;
            }

            /*
                name: ~ArrayMinHeap
                purpose: releases the dynamic heap array
            */
           ~ArrayMinHeap(){
            delete [] heapArray;
           }

           /*
                name: minHeapify
                purpose: recursively fixes the heap's integrity.
           */
            void minHeapify(int i){
                //find the index of the left and right children
                int l = left(i);
                int r = right(i);
                int min = i;

                //check if the left child exists and see if it needs to be swapped
                if(l < heap_size && heapArray[l].getName() < heapArray[i].getName()){
                    min = l;
                }
                //check if the right child exists and see if it needs to be swapped
                else if(r < heap_size && heapArray[r].getName() < heapArray[i].getName()){
                    min = r;
                }
                //now, if there is a new minimum, percolate
                if(min != i){
                    swap(&heapArray[i], &heapArray[min]);
                    minHeapify(min);
                }

            }

            /*
                name: peek
                purpose: returns the root node
            */
           Creature peek(){
            if(isEmpty()){
                Creature empty;
                 cout << "\nThere are no nodes in the heap.\n";
                 return empty;
            }
            else{
                return heapArray[0];
            }
           }

           /*
                name: isEmpty
                purpose: returns true if empty
           */
          bool isEmpty(){
            if(heap_size == 0){
                return true;
            }
            else{
                return false;
            }
          }

          /*
                name: remove
                purpose: removes a node and returns true if successful
          */
         bool remove(Creature& tbr){
            //check if empty
            if(isEmpty()){
                return false;
            }
            else if(heap_size == 1){ //if there is only one in the heap
                heap_size--;
                tbr = heapArray[0]; //creature removed
                return true;
            }
            else{
                //DOESNT WORK I THINK MAYBES
                tbr = heapArray[0]; // creature removed
                heapArray[0] = heapArray[heap_size - 1]; //take the last element and swap with the one to be removed
                heap_size--; 
                minHeapify(0); //check integrity
                return true;
            }
         }

         /*
            name: insert
            purpose: Adds a creature to the heap
         */
        void insert(Creature newc){
            if(heap_size == capacity){
                resizeArray();
            }

            //insert the new value at the end
            heapArray[heap_size] = newc;
            heap_size++;
            int i = heap_size - 1;

            //check integrity
            minHeapify(0);
            /*while(i != 0 && heapArray[parent(i)].getName() > heapArray[i].getName()){
                    swap(&heapArray[i], &heapArray[parent(i)]);
                    i = parent(i);
                }
            */

        }

        /*
            name: resizeArray
            purpose: makes the array twice the size as the original
        */
       void resizeArray(){
            //create new array
            int newcapacity = this->capacity * 2;
            Creature* newArray = new Creature[newcapacity];

            //copy old to new
            for(int i = 0; i < this->capacity; i++){
                newArray[i] = heapArray[i];
            }

            //delete the old and place the new in it's place
            delete [] heapArray;
            heapArray = newArray;
            this->capacity = newcapacity;

       }

       /*
            name: getNumberOfNodes
            purpose: returns heap size
       */
        int getNumberOfNodes(){
            return heap_size;
        }

        /*
            name: getHeight
            purpose: returns the height of the heap
        */
        int getHeight(){
            return ceil(log2(heap_size + 1));
        }

        /*
            name:display
            purpose: traverses the array and prints the name of each creature
        */
       void display(){
            for(int i = 0; i < heap_size; i++){
                cout << heapArray[i].getName() << endl;
            }
       }

        /*
            name: saveToFile
            purpose: traverses the array and calls print creature to file
        */
       void saveToFile(){
            for(int i = 0; i < heap_size; i++){
                heapArray[i].printCreatureToFile("savedCreatures.txt");
            }
       }
};

#endif