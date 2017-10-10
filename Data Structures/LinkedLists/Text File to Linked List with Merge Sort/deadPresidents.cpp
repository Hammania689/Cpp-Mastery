#include "potusList.h"
#include <fstream>
#include <sstream>

// Reads File line by line and adds ONLY complete entries to the list
void LoadFileElementsToList(fstream &,ListOfPresidents &);

int main()
{
	ListOfPresidents potusList;
    fstream inputFile, deleteParamFile;
    
	inputFile.open("nameAndAges.in");
	deleteParamFile.open("deleteThese.in");

	if (!inputFile)
		cout << "Failed to Open file. Double check your Directory path for the Names and Ages file...";
	else
		LoadFileElementsToList(inputFile,potusList);

	potusList.MergeSort();


	if (!deleteParamFile)
		cout << "Failed to Open file. Double check your Directory path for the Delete These file..";
	else
		cout << "The file is open and ready to be read. Delete the potus with function here";
    // Safely close the file 
    inputFile.close();
	cin.ignore();
	return 0;
}

// Use to fill POTUS list with data from each line of the file passed in
void LoadFileElementsToList(fstream &inputFile,ListOfPresidents &potusList)
{
    string line,firstName,lastName;
    int age;

    while(getline(inputFile,line))
    {
        istringstream iss(line);
    
        if(!(iss >> lastName >> firstName >> age))
            cout << "Failed to add "  << "\n";
        else
            potusList.Append(lastName,firstName,age);
    }
}