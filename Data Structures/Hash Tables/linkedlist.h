#pragma once
#include <iostream>
using namespace std;

// Struct to store dictionary entries
struct EntryNode
{
	// Node's value and link variables
	string word;
	EntryNode *next;

	// Set's the default values for each node upon instantion
	EntryNode()		:	word(""),		next(nullptr) {}
};

class LinkedList
{
public:

	EntryNode *head;
	int count;

	// Use to insert a node into the end of the list
	void Append();

	// Use to Print the Linked List from head to tail
	void PrintForward() const;

	// Use to Empty Linked List
	void EmptyList();

	// Default Constructor and Destructors
	LinkedList()	:	head(nullptr),		count(0) {}
};


