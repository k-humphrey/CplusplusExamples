/*
    Filename: Driver.cpp
    Author: Kayla Humphrey
    Date: 11/8/2023
    Purpose: driver for lab 9 on graphs
*/
#include "GraphList.h"

int main(){
    ifstream input;
    int vertices, fromEdge, toEdge;

    
    //open up file and read the vertices, make graph
    input.open("graph.txt");
    input >> vertices;
    cout << "\nThere are " << vertices << " vertices in the graph.\n";
    GraphList graph(vertices);


    //while loop to read in values and add edges
    while(input.good()){
        input >> fromEdge;
        input >> toEdge;

        cout << "\nAdding an edge from " << fromEdge << " to " << toEdge << ".";
        graph.addEdge(fromEdge, toEdge);
    }

    //print list
    cout << "\n\nAdjacency List...";
    graph.printGraph();

}