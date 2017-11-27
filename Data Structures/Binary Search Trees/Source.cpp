#include "BinaryTree.h"
#include "LinkedList.h"

#include <fstream>
#include <sstream>
#include <vector>

// Use to recursively fill POTUS Binary Search Tree from an existing sorted POTUS Linked List
BinarySearchTree FillTree(President *&, BinarySearchTree &);
// NonRecursive Operation
//BinarySearchTree FillTree(ListOfPresidents &, BinarySearchTree &);

// Use to fill POTUS list with data from each line of the file passed in
void LoadFileElementsToList(fstream &, ListOfPresidents &);

using namespace std;

int main(int argc,char *argv[])
{
	auto bst = BinarySearchTree();
	auto sortedLinkedList = ListOfPresidents();

	if (argc != 2)
		cout << "Error; Usage: " << argv[0] << argv[1] << " <filename> \n";
	else
	{
		auto readFile = fstream(argv[1]);

		if(!readFile)
		{
			cout << "Failed to open input file" << endl;
			cin.ignore();
			return 1;
		}

		// Load the contents of the file to a linked list to be sorted
		// Then use the existing Merge sort Algorithm to sort them Alphabetically
		LoadFileElementsToList(readFile, sortedLinkedList);
		sortedLinkedList.MergeSort();
	
		// Fill the tree from the sorted linked list, print results and close files
		bst = FillTree(sortedLinkedList.head,bst);
		cout << "Printing the Binary Search Tree (Inorder Traversal)" << endl
			<< "Left -- Root -- Right" << endl;
		bst.PrintInOrder(bst.root);
		readFile.close();
	}

	cin.ignore();
	cin.ignore();
	return (0);
}


// Reads File line by line and adds ONLY complete entries to the list
void LoadFileElementsToList(fstream &inputFile, ListOfPresidents &potusList)
{
	auto line = string(),
		lastName = string(),
		firstName = string();
	
	auto age = 0,
		lineCount = 0;

	auto listOfLastNames = std::vector<string>();

	cout << endl << endl;
	while (getline(inputFile, line))
	{
		istringstream iss(line);

		if (!(iss >> lastName >> firstName >> age))
		{
			if (line != "")
				cout << "Failed to add contents : \"" << line << "\" at line " << lineCount << ". Not a complete record." << " \n";
		}
		else if(potusList.PotusExistInList(lastName))
			cout << "Duplicate. Potus with lastname \"" + lastName + "\" already exist." << endl;
		else 
			potusList.Append(lastName, firstName, age);

		if (iss)
				listOfLastNames.push_back(lastName);
		lineCount++;
	}
	
	cout << endl << endl;
	cout << "POTUS Last Names in order of Presidency (provided by input file)" << endl
	 << "Before the addition to the Binary Search Tree" << endl;
	for (auto i = listOfLastNames.begin(); i != listOfLastNames.end(); ++i)
		cout << *i << endl;

	cout << endl << endl;
}

// Recursively store each node of the linked list into the Binary search Tree
BinarySearchTree FillTree(President *&recursiveHead,BinarySearchTree &bst)
{

	if (recursiveHead != nullptr)
	{
		bst.root = bst.AddToTree(bst.root, recursiveHead->lastName);
		FillTree(recursiveHead->next,bst);
	}

	return bst;
}

// Reads each node of the sorted linked list and proceeds to copy and fill the Binary Search Tree
//BinarySearchTree FillTree(ListOfPresidents &sortedList, BinarySearchTree &bst)
//{
//	auto current = sortedList.head;
//
//	while (current != nullptr)
//	{
//		bst.root = bst.AddToTree(bst.root, current->lastName);
//		current = current->next;
//	}
//
//	return bst;
//}