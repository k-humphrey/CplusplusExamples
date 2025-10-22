#include "Timer.h"
#include <iostream>
#include <fstream>
using namespace std;

struct wordCount{
	string word;
	int count;
};

void insertionSort(wordCount *wordArray, int numWords);
void bubbleSortReverse(wordCount *wordArray, int numWords);
void quicksort(wordCount *wordArray, int low, int high);
int partition(wordCount *wordArray, int left, int right);

int main()
{
	wordCount* wordArray = new wordCount[150000];
	int numWords = 0;
	string temp;
	int num;
	
	ofstream outfile;
	ifstream infile;

	time_t start, end;
	char filename[50];
	cout << "\nWhich file are you opening?\n";
	cin >> filename;
	infile.open(filename);
	
	if(!infile)
	{
		cout << "\nSorry, I couldn't find that file.\n";
		return 1;
	}

	while(getline(infile, temp) && numWords != 150000)
	{
		wordArray[numWords].word = temp;
		infile >> num;
		infile.ignore();
		wordArray[numWords].count = num;
		numWords++;
	}
	cout << "you've read in " << numWords << " words.\n";

	//sort the songs using insertion sort and print them out to the text file sortFileInsertion.txt
	start = getTime(); //Starts timer.   

	//LOOK!!!!  CALL THE INSERTION SORT ALGORITHM HERE
	insertionSort(wordArray, numWords);

	end = getTime(); //Ends timer.
	outfile.open("sortFileInsertion.txt");
	cout << "\nInsertion sort: " << totalTime(start, end) << " seconds\n\n";
	for(int x=0; x<numWords; x++)
	{
		outfile << wordArray[x].word << " : " << wordArray[x].count << endl;
	}
	outfile.close();

	//sort the songs in reverse order using bubble sort & print them out to the text file sortFileReverseBubble.txt
	start = getTime(); //Starts timer. 

	//LOOK!!!!  CALL THE REVERSE BUBBLE SORT ALGORITHM HERE
	bubbleSortReverse(wordArray, numWords);

	end = getTime(); //Ends timer.
	outfile.open("sortFileReverseBubble.txt");
	cout << "\nReverse bubble sort: " << totalTime(start, end) << " seconds\n\n";
	for(int x=0; x<numWords; x++)
	{
		outfile << wordArray[x].word << " : " << wordArray[x].count << endl;
	}
	outfile.close();

	//sort the songs with quick sort & print them out to sortFileQuick.txt
	start = getTime(); //Starts timer. 
	
	//LOOK!!!!  CALL THE QUICKSORT ALGORITHM HERE
	quicksort(wordArray, 0, numWords);

	end = getTime(); //Ends timer.
	cout << "\nQuicksort: " << totalTime(start, end) << " seconds\n\n";
	outfile.open("sortFileQuick.txt");
	for(int x=0; x<numWords; x++)
	{
		outfile << wordArray[x].word << " : " << wordArray[x].count << endl;
	}
	outfile.close();
	
	delete [] wordArray;
	return 0;
}

/*
	Name: insertionSort
	Parameters: A pointer to an array of wordCount (struct), and an int holding the number of words in array
	Purpose: Uses insertion sort to sort the array in ascending order
*/
void insertionSort(wordCount *wordArray, int numWords){
	int i, j, lowest;
	string lowestWord;
	//ITERATE THROUGH ARRAY
	for(i = 1; i < numWords; i++){ 
		//KEEP TRACK OF KEY FOR SWAP
		lowest = wordArray[i].count;
		lowestWord = wordArray[i].word;
		j = i - 1; 

		//MOVE NUMBERS OVER TO MAKE A PLACE FOR THE LOWEST VALUE
		while(j >= 0 && lowest < wordArray[j].count){
			wordArray[j+1].count = wordArray[j].count;
			wordArray[j+1].word = wordArray[j].word;
			j--;
		}

		//it will stop when j is before the place where lowest needs to go, so place it in the correct spot
		//INSERT LOWEST VALUE INTO SORTED PART
		wordArray[j+1].count = lowest;
		wordArray[j+1].word = lowestWord;
	}
}



/*
	Name: bubbleSortReverse
	Parameters: a pointer to an array of wordCount (struct) and an int that holds the size
	Purpose: uses reverse bubblesort to sort the array in descending order 
*/
void bubbleSortReverse(wordCount *wordArray, int numWords){
	int temp;
	string tempWord;

	//step through array for every single number
	for(int i = 0; i < numWords; i++){
		for(int j = 0; j < numWords - 1; j++){
			if(wordArray[j].count < wordArray[j+1].count){ //if previous is smaller than next, swap (descending order)
				temp = wordArray[j].count;
				tempWord = wordArray[j].word;

				wordArray[j].count = wordArray[j+1].count;
				wordArray[j].word = wordArray[j+1].word;
				wordArray[j+1].count = temp;
				wordArray[j+1].word = tempWord;
			}
		}
	}
}



//LOOK!  WRITE YOUR RECURSIVE QUICK SORT FUNCTION HERE
void quicksort(wordCount *wordArray, int low, int high){
	int partitionI;
	if(low < high){
		//Find the partition index first
		partitionI = partition(wordArray, low, high);

		//recursively sort the left and right partitions now
		quicksort(wordArray, low, partitionI - 1); //left
		quicksort(wordArray, partitionI + 1, high); //right
	}
}


//LOOK!  WRITE YOUR PARTITION FUNCTION HERE
int partition(wordCount *wordArray, int left, int right){
	int pivot = wordArray[left].count; //pivot is the first value in the array
	int pivotIndex = left;
	int numOfLower = 0;

	//find out how many should be in the lower partition
	for(int i = left + 1; i < right; i++){
		if(wordArray[i].count <= pivot){
			numOfLower++;
		}
	}
	//set the pivot's index to be after everything that should be in the lower half
	pivotIndex = pivotIndex + numOfLower;

	//swap left and pivotindex
	int temp = wordArray[left].count;
	string tempWord = wordArray[left].word;
	wordArray[left].count = wordArray[pivotIndex].count;
	wordArray[left].word = wordArray[pivotIndex].word;
	wordArray[pivotIndex].count = temp;
	wordArray[pivotIndex].word = tempWord;

	//i and j starting at the low and high
	int i = left, j = right;

	while(i < pivotIndex && j > pivotIndex){ //makes sure i and j dont cross 
		while(wordArray[i].count < wordArray[pivotIndex].count){
			i++; //i moves inwards if no swap needed
		}
		while(wordArray[j].count > wordArray[pivotIndex].count){
			j--; //j moves inwards if no swap needed
		}
		if(i < pivotIndex && j > pivotIndex){
			//swap i and j as long as we are within bounds
			temp = wordArray[i].count;
			tempWord = wordArray[i].word;
			wordArray[i].count = wordArray[j].count;
			wordArray[i].word = wordArray[j].word;
			wordArray[j].count = temp;
			wordArray[j].word = tempWord;
			//both more inwards
			i++; 
			j--;
		}
	}

	return pivotIndex;
}