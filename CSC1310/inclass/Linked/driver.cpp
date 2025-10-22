#include <iostream>
using namespace std;

class LinkedList{
    private: 
            struct node{
                int value;
                node* next;
            };
            node* head;
            node* tail;
            int length;
    public:
            LinkedList(){
                this->head = nullptr;
                this->length = 0;
                this->tail = nullptr;
            }

            ~LinkedList(){
                node* current = this->head; 
                node* previous = nullptr;

                while(current->next != nullptr){ // can also just put current
                    previous = current;
                    cout << "\n previous, " << previous->value;
                    current = current->next;
                    delete previous;
                    cout << ", has been deleted.";
                } 
            }
            
            void append(int val){
                //make a new node and initialize it 
                node* newNode = new node;
                newNode->value = val;
                newNode->next = nullptr;

                //find the end of the list, but make sure head is not null
                node* current = this->head; //track current
                
                if(head == nullptr){ //or !head
                    //list is empty
                    head = newNode;
                    return; //dont move on
                }

            
                while(current != nullptr){
                    current = current->next;
                }

                //make the last node point to the newNode
                current->next = newNode;
            }

            void appendTail(int val){ //how to append if you have a tail
                //make a new node and initialize it 
                node* newNode = new node;
                newNode->value = val;
                newNode->next = nullptr;

                //find the end of the list, but make sure head is not null
                
                if(head == nullptr){ //or !head
                    //list is empty, head and tail point to the only node
                    head = newNode;
                    tail = newNode;
                    return; //dont move on
                }
                //else put newNode in, and make tail point to newNode
                tail->next = newNode;
                tail = newNode;
            }

            void insert(int place, int val){
                
            }
            void remove(int place){

            }

            void print(){
                node* current = this->head; 

                while(current->next != nullptr){ // can also just put current
                    current = current->next;
                    cout << "\n" << current->value;
                } 
            }

};



int main(){
    LinkedList l1;

    l1.append(48);
    l1.print();

}