/*
    Filename: dqueue.h
    Author: Kayla Humphrey
    Date: 9/29/2023
    Purpose: class file for a DYNAMIC QUEUE
*/
#ifndef DQUEUE_H
#define DQUEUE_H

    #include <iostream>
    using namespace std;
    
    class dqueue{
        private:
            struct node{
                int value;
                node* next;
            };
            node* front;
            node* rear;

        public:
                dqueue(){
                    front = nullptr;
                    rear = nullptr;
                }
                void enque(int num){
                    node* newNode = new node;
                    newNode->value = num;
                    newNode->next = nullptr;

                    if(!rear){ //if empty
                        front = newNode;
                        rear = newNode;
                    }
                    else{
                        rear->next = newNode;
                        rear = newNode;
                    }
                }
                int peek(){
                    if(!front){ //empty
                        cout << "\nempty list";
                        return 0;
                    }
                    return front->value;
                }
                void pop(){ //remove front
                    if(!front){ // empty
                        return;
                    }
                    else{
                        node* ptr = front; //temp
                        front = front->next; //move
                        delete ptr; //delete temp
                    }
                }
    };
#endif