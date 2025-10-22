/*
	filename: BST.h
	author: Kayla Humphrey
	date: 11/2/2023
	purpose: class specification for binary search tree. 
*/
#ifndef BST_H
#define BST_H

#include<iostream>
using namespace std;

class BST
{
	private:
		struct treeNode
		{
			int value;
			treeNode* left;
			treeNode* right;
		};
		treeNode* root;

		void copy(treeNode*&, treeNode*);
		void insert(treeNode*&, treeNode*);
		void displayInOrder(treeNode*) const;
		void destroySubTree(treeNode*);

	public:
		BST();			//default constructor
		BST(const BST &tree);	//copy constructor
		~BST();

		void insertNode(int);
		void display();
};

/*
	name: BST
	purpose: default constructor for the BST object
*/
BST::BST(){
	root = nullptr;
}

/* 
	name: BST
	parameters: a bst object
	purpose: constructor given a tree, copies the tree to a new tree using the copy function
*/
BST::BST(const BST &tree){
	//need to call copy(root, tree object starting at the beginning)
	root = nullptr;
	copy(root, tree.root);
}

/*
	name: copy
	parameters: a node sent by reference that represents nodes being added, a node to reference the tree that is being copied from
	purpose: recursively copies a tree to another tree PreOrder
*/
void BST::copy(treeNode*& newTreeCurrent, treeNode* oldTreeNode){
	//create a new node from the second parameter
	treeNode* newNode = new treeNode;
	newNode->value = oldTreeNode->value;
	newNode->left = nullptr;
	newNode->right = nullptr;

	//insert newNode at current
	insert(newTreeCurrent, newNode);

	//IM NOT SURE HOW TO TRAVERSE
	if(oldTreeNode->left){
		copy(newTreeCurrent->left, oldTreeNode->left);
	}//right
	if(oldTreeNode->right){
		copy(newTreeCurrent->right, oldTreeNode->right);
	}
}

/*
	name:insertNode
	parameters: an integer for the value
	purpose: calls the insert function to insert a node
*/
void BST::insertNode(int key){
	//have to make the new node
	treeNode* newNode = new treeNode;
	newNode->value = key;
	newNode->left = nullptr;
	newNode->right = nullptr;

	//CHECK TO SEE IF THESE ARE IN THE RIGHT ORDER
	insert(root, newNode);
}

/*
	name: insert
	parameters: a reference to the tree that is being added to, then a pointer to the new node
	purpose: adds a node in the spot it's supposed to go :) it starts looking from "root" (not necessarily root though)
*/
void BST::insert(treeNode*& root, treeNode* newNode){
	if(root == nullptr){ //if there is an empty space
		root = newNode;
	}
	else if(newNode->value < root->value){ //if the value needs to be placed on the left of current
		insert(root->left, newNode);
	}
	else{ //right 
		insert(root->right, newNode);
	}
}

/*
	name: display
	purpose: calls the displayInOrder function starting at the root note
*/
void BST::display(){
	displayInOrder(root);
}

/*
	name: displayInOrder
	parameters: a tree node pointer
	purpose: uses recursion to print the tree in order
*/
void BST::displayInOrder(treeNode* current) const{
	//go all the way left
	if(current->left){
		displayInOrder(current->left);
	}
	//print
	cout << current->value << " ";
	//go right once the left has been used up
	if(current->right){
		displayInOrder(current->right);
	}
}

/*
	name: ~bst
	purpose: calls the destory subtree function 
*/
BST::~BST(){
	destroySubTree(root);
}

/*
	name: destroySubTree
	parameter: a pointer to the starting node of the deletion
	purpose:uses a postorder traversal to delete 
*/
void BST::destroySubTree(treeNode* current){
	if(current->left){
		destroySubTree(current->left);
	}
	if(current->right){
		destroySubTree(current->right);
	}
	delete current;

}
#endif