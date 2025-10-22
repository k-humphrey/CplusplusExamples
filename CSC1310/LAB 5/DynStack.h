/*
    Filename: DynStack.h
    Author: Kayla Humphrey 1310-002
    Due Date: 10/16/2023
    Purpose: Dynamic stack class specification file for lab 5
*/
#ifndef DYNSTACK_H
#define DYNSTACK_H

    #include <iostream>
    using namespace std;

    template <typename T>
    class DynStack{
        private:
                struct listNode{
                    T value;
                    listNode* next;
                };
                listNode* top;
        public:
                /*
                    name: DynStack
                    Purpose: Constructor for Dynamic stack. Sets the top to null
                */
                DynStack(){
                    top = nullptr;
                }
                /*
                    name: push
                    Parameters: a variable of type T for the value of the newnode
                    Purpose: adds a new value onto the top of the stack
                */
                void push(T val){
                    //make newNode
                    listNode* newNode = new listNode;
                    newNode->value = val;
                    newNode->next = nullptr;

                    if(!top){ //if empty
                        top = newNode;
                    }
                    else{ //else
                        newNode->next = top;
                        top = newNode;
                    }
                }

                /*  
                    name: pop
                    Parameter: a value, T,  passed by reference which should be changed to whatever is being deleted
                    Purpose: deletes top and updates parameter so that the deleted item can be displayed
                */
                void pop(T& val){
                    //edge case is handled in the driver

                        //change item value to the top, for proper output of what is deleted. 
                        val = top->value;

                        //create a placeholder pointer to top
                        listNode* tbd = top;
                        //move top down
                        top = top->next;
                        //delete
                        delete tbd;

                }

                /*
                    name: isEmpty()
                    purpose: returns true if stack is empty, false if otherwise
                */
                bool isEmpty(){
                    if(!top){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
    };
#endif
