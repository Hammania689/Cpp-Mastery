///////////////////////////////////////////////////////////////////////////////////////
// This program is open source and not subject to any license 
//******************************************************************************
// General Purpose : To further my understanding of Linked List as Abstract Data Types
// Author : Hameed Abdul
// Date : 6/24/2017
///////////////////////////////////////////////////////////////////////////////////////

#include<iostream>

using namespace std;

// Define Macros to avoid Infinite Recursive calls
#ifndef LINKEDLISTMANAGER_H
#define LINKEDLISTMANAGER_H

// Inclusion of the header file that contains Linked List class
#include "LinkedListManager.h"

int main()
{
	
	// Instantiating too list objects
	// The first contains Intergers
	// While the second contains Strings
	LinkedListManager <int> myList;
	LinkedListManager <string> myList2;

	cout << endl << "The First List ONLY works with Intergers" << endl << endl;
	for(int i = 0; i < 3; i++)
	{
		myList.InsertAtTheEnd();
	}

	cout << endl << "The Second List ONLY works with Strings(one word at a time)" << endl;
	for (int i = 0; i < 3; i++)
	{
		myList2.InsertAtTheEnd();
	}

	// Printing each of element of the lists
	cout << endl << "The First List" << endl;
	myList.PrintForward();

	cout << endl << "The Second List" << endl;
	myList2.PrintForward();

	// Destroying the Lists and freeing malloc
	myList.~LinkedListManager();
	myList2.~LinkedListManager();
	
	system("pause");	
	return (0);
}



























#endif
