/*
    Filename: List.h
    Author: Kayla Humphrey
    Due: October 2, 2023
    Purpose: class file for a dynamic linked list that holds a string.
*/
#ifndef LIST_H
#define LIST_H
    #include <string>
    using namespace std;

    class List{
        private:
                struct ListNode{
                    string value;
                    ListNode* next;
                };
                ListNode* head;
                ListNode* tail;
        public:
                void appendNode(string word){
                    //create a new node
                    ListNode* newNode = new ListNode;
                    newNode->value = word;

                    //if empty case
                    if(!tail){
                        head = newNode;
                        tail = newNode;
                    }
                    else{ //place at the end of the list
                        tail->next = newNode;
                        tail = newNode;
                    }
                }
                void insertNode(string word){
                    //create a new node
                    ListNode* newNode = new ListNode;
                    newNode->value = word;

                    //if empty case
                    if(!head){
                        head = newNode;
                        tail = newNode;
                    }
                    else{ //place alphabetically
                        ListNode* curr = head;

                        //compare strings and iterate through, minding the edge
                        while(newNode->value >= curr->next->value && curr->next != tail){
                            if(curr->next->value <= newNode->value){
                                curr = curr->next;
                            }
                        }

                        //insert
                        newNode->next = curr->next;
                        curr->next = newNode;
                    }
                }

                void deleteNode(string word){
                    ListNode* curr = head;
                    ListNode* prev = head;
                    if(!head){
                        cout << "\nEmpty list, no deletion";
                    }
                    else{ //find value, minding the edge
                        while(curr->value != word && curr != tail){
                            prev = curr;
                            curr = curr->next;
                        }
                        //check to see if current is the string passed, delete
                        if(curr->value == word){
                            prev->next = curr->next;
                            delete curr;
                        }
                        else{ //if not found
                            cout << "\nValue was not in the list.";
                        }
                    }
                }
                void displayList(){
                    if(!head){
                        cout << "\nList is empty";
                    }
                    else{
                        ListNode* curr = head;
                        while(curr){
                            cout << curr->value << endl;
                            curr = curr->next;
                        }
                    }
                }
                List(){
                    head = nullptr;
                    tail = nullptr;
                }
                ~List(){
                    ListNode* curr;
                    while(head && head != tail){
                        curr = head;
                        head = curr->next;
                        delete curr;
                    }
                    
                    delete head; // delete last one
                    cout << "\nAll list nodes have been removed.";
                }


    };
#endif