/*
    filename: Heap.h
    Author: Kayla Humphrey
    Date: 11/27/2023
    Purpose: a Max heap class
*/
#ifndef HEAP_H
#define HEAP_H
    #include <cmath>
    #include <iostream>
    
    using namespace std;

    class Heap{
        private:
            int* heapArray;
            int heap_size;
            int capacity;

            /*
                SWAP
                swaps two items in the array
            */
            void swap(int* x, int* y){
                int temp = *x;
                *x = *y;
                *y = temp;
            }

            /*
                Parent, left and right
                return the index of the specificied node in the array given the index of the node
            */
           int parent(int i){
            return (i - 1) / 2;
           }
           int left(int i){
            return (2 * i + 1);
           }
           int right(int i){
            return (2 * i + 2);
           }

           /*
                isLeaf
                Returns true if the node is a leaf
           */
          bool isLeaf(int nodeIndex){
            return (left(nodeIndex) >= heap_size);
          }

          //converts a semiheap to a heap
          void heapRebuild(int subTreeRootIndex){
            if(!isLeaf(subTreeRootIndex)){ //if the node is not a leaf node
                //find larger child
                int leftChildIndex = left(subTreeRootIndex);
                int largerChildIndex = leftChildIndex;
                int rightChildIndex = right(subTreeRootIndex);

                //see if right child exists, then check whether it is larger
                if(rightChildIndex < heap_size){
                    if(heapArray[rightChildIndex] > heapArray[largerChildIndex]){
                    largerChildIndex = rightChildIndex;
                    }
                }

                //if the root is smaller than that larger child, swap, then continue rebuilding
                if(heapArray[subTreeRootIndex] < heapArray[largerChildIndex]){
                    swap(&heapArray[largerChildIndex], &heapArray[subTreeRootIndex]);
                    heapRebuild(largerChildIndex);
                }
            }
          }

          //creates a heap from an unordered array
          void heapCreate(){
            for(int i = heap_size / 2; i >= 0; i--){
                heapRebuild(i);
            }
          }

        public:
                //constructor, using int size
                Heap(int num){
                    heap_size = 0;
                    capacity = num;
                    heapArray = new int[capacity];
                }

                //destructor
                ~Heap(){
                    delete [] heapArray;
                }

                //checks to see if its empty
                bool isEmpty() const{
                    if(heap_size == 0){
                        return true;
                    }
                    else{
                        return false;
                    }
                }

                //gets number of nodes 
                int getNumberOfNodes() const{
                    return heap_size;
                }

                //gets height 
                int getHeight() const{
                    return ceil(heap_size + 1);
                }

                //peek
                int peek() const{
                    return heapArray[0];
                }

                //insert
                void insert(int newNode){
                    //if full make bigger
                    if(heap_size == capacity){
                        resizeArray();
                    }

                    //insert new value at the end
                    heapArray[heap_size] = newNode;
                    heap_size++;

                    //fix max heap property if it is violated
                    /*
                        start at the last in the heap, while it is not at the first, and the parent is less that the current,
                        swap, and put the new i as the parent of i.
                    */
                    int i = heap_size - 1;
                    while(i != 0 && heapArray[parent(i)] < heapArray[i]){
                        swap(&heapArray[i], &heapArray[parent(i)]);
                        i = parent(i);
                    }
                }

                //resizeArray
                void resizeArray(){
                    int cap = capacity * 2;
                    int* newHeapArray = new int[cap];

                    for(int i = 0; i < capacity; i++){
                        newHeapArray[i] = heapArray[i];
                    }
                    delete [] heapArray;
                    heapArray = newHeapArray;
                    capacity = cap;
                }

                //remove
                int remove(){
                    int temp;
                    if(!isEmpty()){
                        temp = heapArray[0];
                        heapArray[0] = heapArray[heap_size - 1];
                        heap_size--;
                        heapRebuild(0);
                    }
                    else{
                        cout << "\nHeap is empty. did not remove";
                    }
                    
                    return temp;
                }
    };
#endif