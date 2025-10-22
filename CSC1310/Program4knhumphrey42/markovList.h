/*
	Filename: markovList.h
	Author: Kayla Humphrey 1310-002
	Date: 11/22/2023 
	Purpose: class specification for a markov list using and adjacency list
*/
#ifndef MARKOVLIST_H
#define MARKOVLIST_H

	#include<map>
	#include<fstream>
	#include<sstream>
	#include<iostream>
	#include<stdlib.h>

	using namespace std;


	class markovList
	{
		private:
			struct edge{
				string value;
				double weight;
				edge* next;
			};

			map<string, edge*> corpus;
			int corpusSize;

		public:
			markovList(const char*);
			~markovList();
			string generate(int);

	};

	/*
		Name: markovList
		Parameters: a filename
		Purpose: constructor for a markov list, reads in data from a file and maps it to the correct index
	*/
	markovList::markovList(const char* filename)
	{
		ifstream file(filename);
		stringstream parser, splitter;
		string line, index, word;
		float weight;
		edge* newEdge;
		int i = 0;
		srand (time(0));
		
		if(file.good()) {
		file >> this->corpusSize;
		file.ignore(1, '\n');
		
		while(getline(file, line, '\n')) //map every word to a position in the matrix, keep the line in an array of buffers for later
		{
			parser.clear();
			parser << line;
			getline(parser, index,',');	//pulls the first word of the line, which is the node for which we're making a list of neighbors
			//initialize an empty list at the index---
			this->corpus[index] = nullptr;

			//cout << "\ncreating a list for " << index << endl;
			while(getline(parser, word, ','))
			{
				//allocate a new node in the edge list---
				newEdge = new edge;
				newEdge->next = nullptr;

				splitter.clear();
				splitter.str(word);
				splitter >> word >> weight;
				//stick word and weight on the node you've just allocated---
				newEdge->value = word;
				newEdge->weight = weight;

				//make sure your new node is attached to the list---
				if(this->corpus.at(index) == nullptr){ //if the list is empty
					this->corpus.at(index) = newEdge;
				}
				else{
					//add to the end 
					edge* head = this->corpus.at(index);
					while(head->next != nullptr){
						head = head->next;
					}
					head->next = newEdge;
				}
			}
		}
		}

	}

	/*
		Name: ~markovList
		Purpose: deconstructor that deletes all dynamically allocated data
	*/
	markovList::~markovList()
	{
		edge* head;
		for(map<string, edge*>::iterator it = this->corpus.begin(); it != this->corpus.end(); it++){
			head = it->second;
			while(head != nullptr){
				edge* tbd = head;
				head = head->next;
				delete tbd;
			}
		}
		cout << "\nDestructor works.";
	}

	/*
		Name:  generate
		Parameters: An integer for the length of the generation
		Purpose: starting at a random index in the map, will iterate through the list at that index and determine a word based on probability, it adds each word to a
				 string to be output (returned).
	*/	
	string markovList::generate(int length)
	{
		map<string, edge*>::iterator it = corpus.begin();	//initialize an iterator to find a random node in the next line
		advance(it,rand() % corpusSize);	//this grabs a random node from your corpus as a starting point

		string output;
		float roll;
		float past;
		edge* current;

		//looping through to get length words 
		for(int i = 0; i < length; i++){
			//make a random roll
			roll = (float)rand() / RAND_MAX;
			past = 0.0;
			//traverse through every node in the list, finding a node (plus past nodes) that is greater than roll 
			current = it->second; // first in the list

				while(current){
					past = past + current->weight;

					if(past > roll){ //if its a match (DO NOT NEED AN EDGE CASE FOR HITTING THE END OF THE LIST. THIS IS ALWAYS TRIGGERED)
						//add word to output
						it = corpus.find(current->value);
						output = output + " " + current->value;
						break; 
					}
					else{ //not a match, more to look at
						current = current->next;
					}
				}

		}

		return output;
	}
#endif