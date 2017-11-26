#include "BinaryTree.h"
#include "LinkedList.h"

#include <fstream>
#include <sstream>

// Use to fill POTUS list with data from each line of the file passed in
void LoadFileElementsToList(fstream &, ListOfPresidents &);

// Use to recursively fill POTUS Binary Search Tree from an existing sorted POTUS Linked List
BinarySearchTree FillTree(President *&, BinarySearchTree &);

// NonRecursive Operation
//BinarySearchTree FillTree(ListOfPresidents &, BinarySearchTree &);

using namespace std;

int main(int argc,char *agrv[])
{
	auto bst = BinarySearchTree();
	auto sortedLinkedList = ListOfPresidents();
	auto readFile = fstream("nameAndAges.in");

	if(!readFile)
	{
		cout << "failed" << endl;
		cin.ignore();
		return 1;
	}

	// Load the contents of the file to a linked list to be sorted
	// Then use the existing Merge sort Algorithm to sort them
	LoadFileElementsToList(readFile, sortedLinkedList);
	cout << "Original Contents of file ..." << endl;
	sortedLinkedList.Print();
	sortedLinkedList.MergeSort();
	
	// Fill the tree from the sorted linked list and then print results
	bst = FillTree(sortedLinkedList.head,bst);
	bst.PrintInOrder(bst.root);
	 
	readFile.close();
	cin.ignore();
	cin.ignore();
	return (0);
}

// Reads File line by line and adds ONLY complete entries to the list
void LoadFileElementsToList(fstream &inputFile, ListOfPresidents &potusList)
{
	cout << endl << endl;
	auto line = string(),
		lastName = string(),
		firstName = string();
	auto age = 0;
	auto lineCount = 0;

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

		lineCount++;
	}
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