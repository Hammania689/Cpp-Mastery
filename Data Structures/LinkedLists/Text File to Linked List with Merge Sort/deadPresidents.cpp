#include "potusList.h"
#include <fstream>
#include <sstream>

// Reads File line by line and adds ONLY complete entries to the list
void LoadFileElementsToList(fstream &,ListOfPresidents &);

// Read File line by line and deletes ONLY complete entries that exist in the list
void DeletePotusElements(fstream &, ListOfPresidents &);

int main()
{
	auto potusList = ListOfPresidents();
	auto inputFile = fstream();
	auto deleteParamFile = fstream();
    
	inputFile.open("nameAndAges.in");
	deleteParamFile.open("deleteThese.in");

	if (!inputFile & !deleteParamFile)
	{
		cout << "Failed to Open file. Double check your Directory path for the two files...";
		return 1;
	}
	else
	{
		// Read through File and Append them to the linked list
		LoadFileElementsToList(inputFile,potusList);
		potusList.Print();

		// Sort through all the entries efficiently with Merge Sort
		potusList.MergeSort();
		potusList.Print();

		// Delete elements that are specified in the delete Param file
		DeletePotusElements(deleteParamFile, potusList);
		potusList.Print();

		// Empty the List
		potusList.EmptyPassedInList(&potusList);
		potusList.Print();
	}

    // Safely close the files
    inputFile.close();
	deleteParamFile.close();
	cin.ignore();
	return 0;
}

// Use to fill POTUS list with data from each line of the file passed in
void LoadFileElementsToList(fstream &inputFile,ListOfPresidents &potusList)
{
	cout << endl << endl;
	auto line = string(),
		lastName = string(),
		firstName = string();
	auto age = 0;
	auto lineCount = 0;

    while(getline(inputFile,line))
    {
        istringstream iss(line);
    
		if (!(iss >> lastName >> firstName >> age))
		{
            cout << "Failed to add contents : \"" << line << "\" at line " << lineCount << "\n";
		}
        else
            potusList.Append(lastName,firstName,age);

		lineCount++;
    }
}

// Use to delete POTUS elements by queried data in the the passed in file
// Element data must be present in both Potus List and Delete File passed in
void DeletePotusElements(fstream &deleteParamFile, ListOfPresidents &potusList)
{
	cout << endl << endl;
	auto line = string(),
	lastName = string(),
	firstName = string();

	auto age = 0;
	auto lineCount = 0;


	while (getline(deleteParamFile, line))
	{
		auto iss = istringstream(line);
		if (!(iss >> lastName >> firstName >> age))
			cout << "Failed to delete query contents : \"" << line << "\" at line number " << lineCount << "\n";
		else
			potusList.DeletePotus(lastName, firstName, age);

		lineCount++;
	}
	cout << endl << endl;
}