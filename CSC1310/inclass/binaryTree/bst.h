/*  
    filename: bst.h
    author: Kayla Humphrey
    Date: 10/23/2023
    Purpose: class specification file for a binary search tree
*/
#ifndef BST_H
#define BST_H
    #include <iostream>
    using namespace std;

    class bst{
        private:
            struct node{
                int value;
                node* left;
                node* right;
            };
            node* root;

            //recursive search
                int rsearch(node* current, int key){
                    if(current == nullptr){
                        return -1;
                    }
                    else if (current->value == key){
                        return current->value;
                    }
                    else if(key < current->value){
                        return rsearch(current->left, key);
                    }
                    else{
                        return rsearch(current->right, key);
                    }
                }

                void insert(node*& current, node*& newNode){
                    if(current == nullptr){//if the tree is empty
                        current = newNode;
                    }
                    else if(newNode->value < current->value){
                        insert(current->left,newNode);
                    }
                    else{
                        insert(current->right, newNode);
                    }
                }

                //recursive print function Inorder
                void printI(node* current){
                    if(current->left){
                        printI(current->left);
                    }
                    cout << current->value << " ";
                    if(current->right){
                        printI(current->right);
                    }
                }

                //recursive print function Preorder
                void printPre(node* current){
                    cout << current->value << " ";
                    if(current->left){
                        printPre(current->left);
                    }
                    if(current->right){
                        printPre(current->right);
                    }
                }

                //recursive print function PostOrder
                void printPost(node* current){
                    if(current->left){
                        printPost(current->left);
                    }
                    if(current->right){
                        printPost(current->right);
                    }
                    cout << current->value << " ";
                }

                //actual destructor
                void destroybst(node* current){
                    if(current->left){
                        destroybst(current->left);
                    }
                    if(current->right){
                        destroybst(current->right);
                    }
                    delete current;
                }
        
        public:
                bst(){
                    root = nullptr;
                }

                ~bst(){
                    destroybst(root);
                    cout << "\n\nAll bst nodes have been deleted :)";
                }

                //recursive version of this also
                void search(int key){
                    node* current = root;
                    while(current){
                        if(current->value == key){
                            //found
                            cout << "\nfound!";
                            return;
                        }
                        else if(key < current->value){
                            current = current->left; //go left
                        }
                        else{
                            current = current->right; //go right
                        }
                    }
                    cout << "\n Not found.";
                }

                //recursive search helper function
                void rsearch(int key){
                    int found = rsearch(root, key);
                    cout << "\nThe r search function returned " << found;
                } 

                //insertion 
                void insert(int key){
                    //make newNode
                    node* newNode = new node;
                    newNode->value = key;
                    newNode->left = nullptr;
                    newNode->right = nullptr;
                    
                    //call the helper
                    insert(root, newNode);
                    
                }
                
                //print helper function
                void print(){
                    if(root){
                        cout << "\nInOrder search:  " << endl;
                        printI(root);
                        cout << "\nPreOrder search:  " << endl;
                        printPre(root);
                        cout << "\nPostOrder search:  " << endl;
                        printPost(root);
                    }
                }
    };
#endif