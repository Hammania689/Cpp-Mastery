#pragma once
#include <string>
#include "AddressNode.h"
#include <fstream>
using namespace std;

//////////////////////////////////////////////////////////////////
//					REQUIRED REFERENCE							//
// needed for ContanctBook and AddressNode classes to be friends//
//////////////////////////////////////////////////////////////////
class AddressNode;

// Holds All Contacts
class ContactBook
{

private:

public:

	// Pointers necessary for travesal and construction 
	// of the linked list
	AddressNode *head = nullptr;
	AddressNode *tail = nullptr;
	AddressNode *current = nullptr;
	AddressNode *newContact = nullptr;

	// Methods to add and print contacts
	void PrintForward();
	void InsertAtEnd();

	// Method to Save Contacts in a text file
	void SaveContacts();

	ContactBook();
	~ContactBook();
};

