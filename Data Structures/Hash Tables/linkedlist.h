#pragma once
#include <iostream>
#include <string>
using namespace std;

// Struct to store dictionary entries
struct EntryNode
{
	// Node's value and link variables
	string word;
	int key;
	EntryNode *next;

	// Set's the default values for each node upon instantion
	EntryNode() : word(""), key(45), next(nullptr)
	{
	}
};

class LinkedList
{
public:

	EntryNode *head = {nullptr};
	int count;

	// Use to insert a node into the end of the list
	void Append(string value)
	{
		// Ptrs to store new node and to traverse the list
		auto newWord = new EntryNode;
		auto current = head;

		newWord->word = value;

		// if the list is empty
		if (head == nullptr) 
			head = newWord;
		// otherwise add to the end
		else 
		{
			while (current->next != nullptr)
				current = current->next;
			current->next = newWord;
		}
	}

	// Use to Print the Linked List from head to tail
	void PrintForward() const
	{
		auto current = head;
		
		cout << " ||";

		if (head == nullptr)
		{
			cout << "The list is empty...";
			cout << " ||" << endl;
			return;
		}

		while (current!= nullptr)
		{
			cout << current->word <<  " -> ";
			current = current->next;
		}
		cout << "\t\t\t ||" << endl;
	}

	// Use to Empty Linked List
	void EmptyList()
	{
		auto tmp = head;

		while (head != nullptr)
		{
			tmp = head;
			head = head->next;
			delete tmp;
		}
	}

	// Default Constructor and Destructors
	LinkedList()	:	head(nullptr),		count(0) {}
	
	~LinkedList()
	{
		// Empty list
		EmptyList();

		// Deallocate memory
		delete head;
		head = nullptr;
	}
};


