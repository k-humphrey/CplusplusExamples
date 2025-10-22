/*
    filename: Queue.h
    Author: Kayla Humphrey
    Due Date: 10/23/2023
    Purpose: Header file for lab 6, class specification for a queue class
*/
#ifndef QUEUE_H
#define QUEUE_H

    #include <iostream>

    using namespace std;

    class Queue{
        private:
                struct QueueNode{
                    string riderName;
                    QueueNode* next;
                };
                int numNodes;
                QueueNode* head;
                QueueNode* tail;
        
        public:
                /* 
                    Name: Queue
                    Purpose: Constructor for a Queue object.
                */
                Queue(){
                    //empty list
                    head = nullptr;
                    tail = nullptr;
                    numNodes = 0;
                }

                /*
                    Name: enqueue
                    Parameters: A string for the name of the person
                    Purpose: adds a person to the back of the line (queue)
                */
               void enqueue(string name){
                //create a new node
                QueueNode* newNode = new QueueNode;
                newNode->riderName = name;
                newNode->next = nullptr;

                if(!head){ //checks if empty
                    head = newNode;
                    tail = newNode;
                }
                else{
                    //new person is the new tail
                    tail->next = newNode;
                    tail = newNode;
                }
                //increment num of nodes
                numNodes++;

               }

               /*
                    Name: dequeue
                    Parameters: A reference to the name variable to print out who is riding
                    Purpose: removes the front of the line (queue)
               */
              void dequeue(string &name){
                //empty line handled by driver
                QueueNode* tbd = head;

                name = tbd->riderName; // change name for correct output in driver
                if(numNodes >= 1){ // guard against segmentation
                    head = head->next;
                }
                delete tbd;
                numNodes--;
              }
              
              /*
                    Name:isEmpty
                    Returns: Boolean, true if empty
                    Purpose: Checks whether the list is empty or not
              */
             bool isEmpty(){
                if(numNodes == 0){
                    return true;
                }
                return false;
             }

             /*
                Name: ~Queue
                Purpose: Destructor for nodes left
             */
            ~Queue(){
                while(numNodes >= 1){ //stops from going too far
                   QueueNode* tbd = head;
                   cout << "\nOh shoot, I am sorry, our park is closed so " << tbd->riderName << " will not get to ride today.";
                   if(numNodes > 1){
                    head = head->next;
                   }
                   delete tbd;
                   numNodes--;
                }

            }
                
    };
#endif