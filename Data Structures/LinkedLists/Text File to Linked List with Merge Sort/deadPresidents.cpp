#include "potusList.h"
#include <fstream>
#include <sstream>

// Reads File line by line and adds ONLY complete entries to the list
void LoadFileElementsToList(fstream &,ListOfPresidents &);

int main()
{
    ListOfPresidents potusList;
    fstream inputFile;
    inputFile.open("nameAndAges.in");

    if(!inputFile)
        cout << "Failed to Open file. Double check your Directory path";
    else
        LoadFileElementsToList(inputFile,potusList);
    
    potusList.Print();
    // cout << potusList.lengthOfList << endl << endl << endl;
    
    // President *t = potusList.PresidentAtIndex(16);
    // cout << t->firstName << " " << t->lastName << endl;
    
    // Safely close the file 
    inputFile.close();
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
            cout << "Failed to add " << iss << "\n";
        else 
            potusList.Append(lastName,firstName,age);
    }
}