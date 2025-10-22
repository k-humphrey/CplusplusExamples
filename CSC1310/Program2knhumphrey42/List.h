/*
    Filename: List.h
    Author: Kayla Humphrey
    Due Date: 10/2/2023
    Course: Data Structures, 1310-002
    Purpose: Doubly linked list class specification file
*/
#ifndef LIST_H
#define LIST_H
    #include <iostream>

    using namespace std;

    template <typename T>
    class List{
        private:
                //node set up
                struct listNode{
                    T value;
                    listNode* next;
                    listNode* prev;
                };
                listNode* head;
                listNode* tail;

                //PRIVATE FUNCTIONS

                /*
                    Name: print
                    Parameters: a pointer to the starting node
                    Purpose: prints each node from start to finish
                */
                void print(listNode* start){
                    //make a current node
                    listNode* curr = start;

                    //from start to tail
                    if(start){ //printing out the starting value
                        cout << *(curr->value) << endl;
                    }
                    else{ //and not printing if empty
                        return;
                    }

                    while(curr->next != nullptr){ //everything from 1 after start to tail
                        curr = curr->next;
                        cout << *(curr->value) << endl;
                    }
                }

                /*
                    Name: mergesort
                    Parameters: The first and last node of the partition
                    Returns: The first in the list partiton that has been merged
                    Purpose: Manages recursive calls for mergesort
                */
                typename List<T>::listNode* mergesort(listNode* first, listNode* last){
                    //base case, 1 or 0 left in partition
                    if(first == last || first->next == nullptr){
                         return first; 
                    }
                    else{ //recursive case
                        listNode* firstref = first;
                        listNode* secondref = split(first, last); 

                        //lower and upper bound
                        secondref = mergesort(secondref, last);
                        firstref = mergesort(firstref, secondref->prev);
                        return merge(firstref, secondref);

                    }
                }

                /*
                    Name: merge
                    Parameters: the first nodes for both of the list partitions
                    Returns: a reference to the first in the list partition that has been merged
                    Purpose: merges two partitions together
                */
                typename List<T>::listNode* merge(listNode* first1, listNode* first2){
                    if(first1 == nullptr){ //if 1 is empty
                        return first2;
                    }
                    else if(first2 == nullptr){ //if 2 is empty
                        return first1;
                    }
                    else{
                        if(*(first1->value) > *(first2->value)){ //first1 is larger
                            listNode* temp = merge(first1->next,first2);
                            first1->next = temp;
                            temp->prev = first1;
                            first1->prev = nullptr;
                            return first1;
                        }
                        else{ //first 2 is larger
                            listNode* temp = merge(first2->next,first1);
                            first2->next = temp;
                            temp->prev = first2;
                            first2->prev = nullptr;
                            return first2;
                        }
                    }
                }

                /*
                    Name: split
                    Parameters: first and last nodes of the partition to be split
                    Returns: middle node
                    Purpose: make a partition into two
                */
                typename List<T>::listNode* split(listNode* first, listNode* last){
                    listNode* middle;
                    //find middle
                    while(first != last && first < last){
                        first = first->next;
                        last = last->prev;
                    }
                    middle = first;

                    //save the node before severing it
                    listNode* temp = middle->next;
                    middle->next = nullptr;
                    return temp; //node after middle
                }
        public:
                //PUBLIC FUNCTIONS

                /*
                    Name: List (constructor)
                    Purpose: creates an empty list, setting head and tail to null.
                */
                List(){
                    head = nullptr;
                    tail = nullptr;
                }

                /*
                    Name: List (destructor)
                    Purpose: releases dynamic memory allocation for remaining nodes
                */
                ~List(){
                    //create a temporary value for the deletion
                    listNode* temp;

                    //step through and delete
                    while(tail){
                        temp = tail;
                        tail = tail->prev;
                        delete temp;
                    }
                }

                /*
                    Name: print
                    Purpose: To print the list values, using private print function
                */
                void print(){
                    //print all starting at head
                    print(head);
                }

                /*
                    Name: append
                    Parameter: value being passed to list
                    Purpose: Adds the value to the end of the list
                */
                void append(T val){
                    //create new node
                    listNode* newNode = new listNode;
                    newNode->value = val;

                    //if empty
                    if(!head){
                        head = newNode;
                        tail = newNode;
                    }
                    else{ //add to the end
                        tail->next = newNode;
                        newNode->prev = tail;
                        tail = newNode;
                        newNode->next = nullptr;
                    }
                }

                /*
                    Name: mergesort
                    purpose: calls the other mergesort function, resetting head and tail
                */
                void mergesort(){
                    head = mergesort(head, tail);
                    //reset head and tail
                    listNode* newTail = head;
                    while(newTail->next){
                        newTail = newTail->next;
                    } 
                    tail = newTail;
                }
    };
    
#endif 