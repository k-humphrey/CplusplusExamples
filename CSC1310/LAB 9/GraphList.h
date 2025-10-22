/*
    Filename: GraphList.h
    Author: Kayla Humphrey
    Date: 11/8/2023
    Purpose: Class specification file for a graph
*/
#ifndef GRAPHLIST_H
#define GRAPHLIST_H
    #include <iostream>
    #include <fstream>

    using namespace std;


    class GraphList{
        private: 
                struct ListNode{
                    int value;
                    ListNode* next;
                };
                ListNode** headarray;
                int numVertices;
                int numEdges;
        
        public:
                GraphList(int);
                ~GraphList();
                void addEdge(int, int);
                void printGraph();
    };

    /*
        Name: GraphList
        Purpose: Constructor for the graph, takes in the number of vertices
    */
   GraphList::GraphList(int vertices){
        //set starting vertices and edges values
        this->numVertices = vertices;
        this->numEdges = 0;

        //create the headarray and initialize all pointers to null
        this->headarray = new ListNode*[this->numVertices];

        for(int i = 0; i < this->numVertices; i++){
            this->headarray[i] = nullptr;
        }

   }

   /*
       Name: ~GraphList
       Purpose: deconstructor of the graph
   */
    GraphList::~GraphList(){
        //go through each linked list
        for(int i = 0; i < this->numVertices; i++){

            //if there is a linked list
            if(this->headarray[i] != nullptr){

                //delete linked list
                while(this->headarray[i] != nullptr){
                    ListNode* tbd = this->headarray[i];
                    this->headarray[i] = this->headarray[i]->next;
                    delete tbd;
                }
            }

        }

        //delete array
        delete [] this->headarray;
        cout << "works";
    }

    /*
       Name: addEdge
       Purpose: takes in two vertices, creates the second node and adds it to the graph, adjacent to the first
    */
   void GraphList::addEdge(int existing, int newValue){
        //create new node
        ListNode* newNode = new ListNode;
        newNode->value = newValue;
        newNode->next = nullptr;

        //go to existing index at headarray
        
        if(!this->headarray[existing]){
            this->headarray[existing] = newNode;
        }
        else{
            //start at the head of the linked list at existing index
            ListNode* current = this->headarray[existing];
           
           //get current to the last part of the list
           while(current->next){
             current = current->next;
           }

            //add to the end of the list
           current->next = newNode;
        }
        
   }

   /*
      Name: printGraph
      Purpose: prints out the adjacency list for the graph
   */
  void GraphList::printGraph(){
    for(int i = 0; i < this->numVertices; i++){
        //print vertex number
        cout << "\n" << i << "--->";

        //if there are adjacent nodes
        if(this->headarray[i] != nullptr){
           // cout << "\nentered if statement for " << i;
            //print list
            ListNode* current = this->headarray[i];
            while(current){
                cout << current->value << "--->";
                current = current->next;
            }
        }

        //end of list
        cout << "NULL";
    }
  }
#endif