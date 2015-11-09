/*
Made By Andrew Hingst (5043535)
This is a program designed to take a text file and feed the output of how frequent
words appear, as well as in alphabetical order. It breaks between white space. This is
the MAIN program. All fucntions are in dictionary.cpp
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
extern ENTRY *LocateWord(DICT& , WORD);
extern BOOL FullDictionary(DICT&);
extern BOOL InsertWord(DICT&,WORD);
extern WORD GetNextWord(void);
extern void DumpDictionary(DICT&);



//***********************************GLOBAL VARIABLES**********************************
extern DICT dictionary;  //Dictionary
extern WORD word;



//********************************THE PLACE WHERE THINGS HAPPEN**************************************
int main (void) {

	ENTRY *pos;

	while (1) {
		word = GetNextWord();
		if ( word.empty() )  {
			DumpDictionary(dictionary);
			break;
		}

		if ((pos = LocateWord(dictionary,word)) >  0 ) pos->count++;
		else if (!InsertWord(dictionary,word)) cout << "dictionary full" << word <<  "cannot be added\n";

	}
	return 0;

}
