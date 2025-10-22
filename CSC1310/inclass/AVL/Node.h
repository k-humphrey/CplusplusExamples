#ifndef NODE_H
#define NODE_H

    #include <iostream>
    using namespace std;

    class Node{

        private:
                int value;
                Node* left;
                Node* right;
        
        public: 
                Node(){
                    value = 0;
                    left = nullptr;
                    right = nullptr;
                }

                ~Node(){
                    cout << "\nDeleted a node";
                }
                int getValue(){
                    return value;
                }
                Node* getLeft(){
                    return left;
                }
                Node* getRight(){
                    return right;
                }
                void setValue(int num){
                    value = num;
                }
                void setLeft(Node* nodeptr){
                    left = nodeptr;
                }
                void setRight(Node* nodeptr){
                    right = nodeptr;
                }
    };
#endif