#ifndef AVL_H
#define AVL_H
    #include "Node.h"

    class Avl{
        private:
                Node* root;
                int numNodes;

                //LRP 
                void destroyAllNodes(Node* nodeptr){
                    if(nodeptr){ //if node exists
                        if(nodeptr->getLeft() != nullptr){ //if the left exists
                            destroyAllNodes(nodeptr = nodeptr->getLeft());
                        }
                        if(nodeptr->getRight() != nullptr){ //if right exists
                            destroyAllNodes(nodeptr = nodeptr->getRight());
                        }
                        delete nodeptr;
                    }
                }

        public:
                Avl(){
                    root = nullptr;
                    numNodes = 0;
                }

                ~Avl(){
                    destroyAllNodes(root);
                }

                int height(Node* temp){
                    int h = 0;
                    if(temp != nullptr){ //if the node exists
                        int leftheight = height(temp->getLeft()); //recursively finds the number of nodes on the left
                        int rightheight = height(temp->getRight()); //recursively finds the number of nodes on the right
                        int max_height = max(leftheight, rightheight); //max height is the largest number between right and left
                        h = max_height + 1; //h = the largest height + 1
                    }
                    return h; 
                }

                //BALANCE FACTOR IS LEFT HEIGHT - RIGHT HEIGHT
                int diff(Node* temp){
                    int leftheight = height(temp->getLeft());
                    int rightheight = height(temp->getRight());
                    int balancefactor = leftheight - rightheight;
                    return balancefactor;
                }

                Node* Lrotation(Node* parent){
                    Node* temp = parent->getRight();

                    parent->setRight(temp->getLeft());
                    temp->setLeft(parent);

                    return temp;
                }

                Node* Rrotation(Node* parent){
                    Node* temp = parent->getLeft();

                    parent->setLeft(temp->getRight());
                    temp->setRight(parent);

                    return temp;
                }

                Node* LRrotation(Node* parent){
                    Node* temp = parent->getLeft();
                    parent->setLeft(Lrotation(temp));
                    return Rrotation(parent);
                }

                Node* RLrotation(Node* parent){
                    Node* temp = parent->getRight();
                    parent->setRight(Rrotation(temp));
                    return Lrotation(parent);
                }

                //BALANCE THE TREE
                Node* balance(Node* temp){
                    int balancefactor = diff(temp);
                    if(balancefactor > 1){ //2
                        if(diff(temp->getLeft()) > 0){ //2, 1 RIGHT ROTATION
                            temp = Rrotation(temp);
                            cout << "\nRIGHT ROTATION";
                        }
                        else{                           //2, -1 LEFT-RIGHT ROTATION
                            temp = LRrotation(temp);
                            cout << "\nLEFT-RIGHT ROTATION";
                        }
                    }
                    else if(balancefactor < -1){ //-2
                        if(diff(temp->getRight()) > 0){  //-2, 1 RIGHT-LEFT ROTATION
                            temp = RLrotation(temp);
                            cout << "\nRIGHT-LEFT ROTATION";
                        }
                        else{                            //-2, -1 LEFT ROTATION
                            temp = Lrotation(temp);
                            cout << "\nLEFT ROTATION";
                        }
                    }
                    return temp;
                }

                //INSERT NODE
                Node* insert(Node* root, int num){
                    //create the new node
                    Node* newNode = new Node;
                    newNode->setValue(num);

                    //should node be the root?
                    if(root == nullptr){
                        root = newNode;
                        return root;
                    }

                    //find location
                    Node* current = root;
                    while(current != nullptr){
                        if(newNode->getValue() < current->getValue()){ //new needs to go on the left side

                            if(current->getLeft() == nullptr){ //nothing on the left of current, place there
                                current->setLeft(newNode);
                                current = nullptr;
                            }
                            else{
                                current = current->getLeft(); //need to go further to the left
                            }
                        }
                        else{ //need to go to the right if new is bigger than parent

                            if(current->getRight() == nullptr){
                                current->setRight(newNode); //place on the right
                                current = nullptr; //break loop
                            }
                            else{
                                current = current->getRight();  //go further right
                            }
                        }
                    }

                    //balance tree after inserting
                    root = balance(root);

                    return root;

                }


                void display(Node* ptr, int level){
                    int i;
                    if(ptr != nullptr){
                        display(ptr->getRight(), level + 1);
                        printf("\n");
                        for(i = 0; i < level && ptr != root; i++){
                            cout << "        ";
                        }
                        cout << ptr->getValue();
                        display(ptr->getLeft(), level + 1);
                    }
                }

                //LPR
                void inorder(Node* tree){
                    if(tree == nullptr){
                        return;
                    }
                    inorder(tree->getLeft());
                    cout << tree->getValue() << " ";
                    inorder(tree->getRight());
                }

                //PLR
                void preorder(Node* tree){
                    if(tree == nullptr){
                        return;
                    }
                    cout << tree->getValue() << " ";
                    preorder(tree->getLeft());
                    preorder(tree->getRight());
                }

                //LRP
                void postorder(Node* tree){
                    if(tree == nullptr){
                        return;
                    }
                    postorder(tree->getLeft());
                    postorder(tree->getRight());
                    cout << tree->getValue() << " ";
                }

    };
#endif