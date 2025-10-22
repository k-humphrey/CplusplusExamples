/*
	Filename: driver.cpp
	Author: Kayla Humphrey 1310-002
	Date: 11/22/2023 
	Purpose: Driver for a word generator program using an Adjacency list
*/
#include<iostream>
#include "markovList.h"
using namespace std;

int main()
{
	markovList* chain = new markovList("corpus.txt");
	//markovList* chain = new markovList("corpusTest.txt");
	
	
	cout << chain->generate(100) << endl;
	
	delete chain;
	return 0;
}