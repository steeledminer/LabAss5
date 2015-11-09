/*
Made By Andrew Hingst (5043535)
This is a program designed to take a text file and feed the output of how frequent
words appear, as well as in alphabetical order via Linked List structure.
It breaks between white space of the input stream. MAIN is under main.cpp
*/

//**************************************INITIALIZE************************************
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;
using std::string;

const int MAX = 100;

typedef string STRING;
typedef bool BOOL;
typedef string WORD;    


//*************************************STRUCTURES**************************************
typedef struct entry {	//	Entry structure, for a part of a dictionary
	int count;                  // frequency of word
	WORD w;                     // Word contained within entry
	struct entry *nextWord;     // points to next entry

} ENTRY;


typedef struct dict {	//  Dictionary Structure

	int maxEntries;			// Max Entries (For a linked list...)
	int numWords;			// Number of words availble
	ENTRY *Words;			// Points to the first value of the dictionary
} DICT;

//**************************************PROTOTYPES*************************************
ENTRY *LocateWord(DICT& , WORD);
BOOL FullDictionary(DICT&);
BOOL InsertWord(DICT&,WORD);
WORD GetNextWord(void);
void DumpDictionary(DICT&);



//***********************************GLOBAL VARIABLES**********************************
DICT dictionary={MAX,0,0};  //Dictionary
WORD word;					//input word


//**************************************FUNCTIONS**************************************
BOOL InsertWord(DICT &dict, WORD word) {
	//  adds word to dictionary , if word can't be added returns false else returns true
	//cout << "Inserting Word : <" << word << "> " << endl;	//TESTLINE

	ENTRY *currentWord = dict.Words;
	
	if(!FullDictionary(dict)){						//Make sure the INFINITE SPACE DICTIONARY isn't full
		ENTRY *tmp=new ENTRY;						//Make initial entry
			tmp -> count = 1;
			tmp -> w = word;
			tmp -> nextWord = 0;
		if (dict.Words != 0) {							//Check if it's the first entry or not
			while (currentWord->nextWord != 0) {
				//cout << "Moving to Next Entry" << endl;
				currentWord = currentWord->nextWord;			//Go through entries until the end
			}
			currentWord->nextWord = tmp;
			dict.numWords++;
		}else{
			//cout << "Making first entry" << endl;		//TESTLINE	
			
			dict.Words = tmp;
			
			//cout << "First Entry Made" << endl; 		//TESTLINE
			dict.numWords++;

		} return true;
		
	} else return false;

}
//------------------------------------------------------------------------------------

void DumpDictionary(DICT &dict) {
//  will sort the dictionary, and display the contents
	ENTRY *sorter[dict.numWords];				//Make an array of pointers
	ENTRY *currentWord = dict.Words;			//Make a way to track where in Dict we are
	ENTRY *tmp = 0;
	
	for (int i = 0; i < dict.numWords; i++){		//Get pointers to Sorter
		sorter[i] = currentWord;
		currentWord = currentWord -> nextWord;
	}

	for (int i = 0; i < dict.numWords; i++){		//Lazyman... I mean "Bubble Sort" pointers
		for (int j = i+1; j < dict.numWords; j++){
			if (sorter[i]->w.compare(sorter[j]->w) > 0){
				tmp = sorter[j];
				sorter[j] = sorter[i];
				sorter[i] = tmp;
			}
		}
	}

	cout << "Word:               Frequency: \n";	//Output head of chart
	cout << "-------------------------------\n";
	
	for (int i = 0; i < dict.numWords; i++){		//Output data
		cout << sorter[i]->w << "         " << sorter[i]->count << endl;
	}

}
//------------------------------------------------------------------------------------

WORD GetNextWord(void) {			//Gets the next word from the input stream
	//cout << "Getting Next Word" << endl;

	WORD tmp = "";					//Make word
	cin >> tmp;
	if (tmp.compare("") == 0){		//check if empty
		return "";					//return proper value
	} else {
		//cout << "Word Captured : <" << tmp << ">" << endl;	//TESTLINE

		return tmp;
	}
}
//------------------------------------------------------------------------------------

BOOL FullDictionary(DICT &dict) {

	if(dict.numWords == dict.maxEntries) return 1;		//check number of words versus max, return based on such
	else return 0;

}
//------------------------------------------------------------------------------------

ENTRY *LocateWord(DICT &dict, WORD word) {
//   will determine if dictionary contains word. if found, returns pointer to entry else returns  0
	//cout << "Looking for word : <" << word << ">" << endl;
	
	if (dict.Words == 0){		//Make sure dictionary isn't empty
		//cout << "Dictionary Empty." << endl; 	//TESTLINE
		return 0;				//if empty, return empty
	} else {
		//cout << "Dictionary Not Empty." << endl; 	//TESTLINE
		ENTRY *currentWord = dict.Words;	//Get variables to search

		while (currentWord->nextWord != 0){							//Look through dictionary
			if (currentWord->w.compare(word) == 0 ){
				//cout << "Word found" << endl; 		//TESTLINE
				return currentWord;					//Return the entry if word is found
			}
			//cout << "Moving to Word"<< endl;
			currentWord = currentWord->nextWord;

		}	//cout << "Word Not found " << endl;
			return 0;
	}

}


