#include "hashtable.h"
#include "linkedlist.h"
#include <iostream>
#include <fstream>

using namespace std;

// Use to fill Hash Table with text file line entries
void FillDictionaryHashTable(fstream &,DictionaryHash &);

// Use to check whether a files words are in the dictionary or mispelled(not in the dictionary)
void CheckFileForTypos(fstream &checkInputWords, DictionaryHash &dict);

int main(int argc,char *argv[])
{
	auto dict = DictionaryHash();

	if(argc != 3)
		cout << "usage: " << argv[0] << " <filename>\n";
	else
	{
		// Variables to store file name of cli arguments
		// Dictrionary file is first and the file to check is subsequent
		auto dictionaryFile = std::fstream(argv[1]);
		auto fileToCheck = std::fstream(argv[2]);

		// if Either file is faulty or cannot be found
		if (!dictionaryFile || !fileToCheck)
		{
			cout << "Can't find one or both of the input files given. Please check file name and directory. \n";
			cout << "Dictrionary file is first and the file to check for spelling errors is subsequent \n";
			return 1;
		}

		FillDictionaryHashTable(dictionaryFile, dict);
		CheckFileForTypos(fileToCheck, dict);

		dictionaryFile.close();
		fileToCheck.close();
	}

	cout << "Press Enter..." << endl;
	cin.ignore();
	return 0;
}

// Fills the hash table with words from dictionary file
void FillDictionaryHashTable(fstream &inputWords,DictionaryHash &dict)
{
	auto line = string();

	while (getline(inputWords, line))
		if (line != "")
			dict.InsertInTable(line);
	// Print Results
	// dict.PrintTable();
}

// Check words and print out result
void CheckFileForTypos(fstream &checkInputWords,DictionaryHash &dict)
{
	auto line = string();

	while (getline(checkInputWords, line))
		if (!dict.isInDictionary(line))
			cout << line << " is mispelled." << endl;
}