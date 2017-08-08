//////////////////////////////////////////////////////////////////////////////////////////////////
// This program is open source and not subject to any license 
//******************************************************************************
// General Purpose : To further my understanding of Linked List as Abstract Data Types
// Author : Hameed Abdul
// Date : 6/24/2017
/////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <iostream>
#include <string>
#include <memory>

template <class Type>
struct NodeType
{ 
	Type info;
	NodeType<Type> *link;
	void SetInfo()
	{
		std::cout << "What information do you wish to store in this node?"
			<< endl << "... Chose Wisely and Press Enter" << endl;
		
		std::cin >> info;

		link = NULL;
	}
};

template <class Type>
class LinkedListManager
{

protected:
	// Number of elements in the list
	int count;

	// Ptrs for the beginning and ending elements
	NodeType<Type> *head = NULL;
	NodeType<Type> *tail = NULL;

public:

	// Inserts an Element at the end of the Linked List
	// If the Linked List is empty then the Element becomes the Head
	void InsertAtTheEnd();

	// Prints the Linked List in order of stored Elements
	void PrintForward() const;

	// 
	void EmptyList();

	// Default Constructor and Destructors
	LinkedListManager();
	~LinkedListManager();
};

// Use to Add a node to the end of the element list
template <class Type>
void LinkedListManager<Type> :: InsertAtTheEnd() 
{
	if(head == NULL)
	{
		head = new NodeType<Type>;
		head->SetInfo();
		tail = head;
		tail->link = nullptr;
	}
	else
	{
		NodeType<Type> *temp = new NodeType<Type>;
		
		temp->SetInfo();
		
		tail->link = temp;
		tail = temp;
	}
}

// Use to Print the Element list from Head to Tail
template <class Type>
void LinkedListManager<Type> :: PrintForward() const
{
	//pointer to traverse the list
	NodeType<Type> *current = new NodeType<Type>;

	// set current so that it points to head
	current = head;

	// Increments sequentially through the element list 
	// Until current reaches the end of the list (unallocated memory)

	std::cout << "==============================================================" << endl;
	while(current != nullptr)
	{
		std::cout << current->info << " || ";
		current = current->link; 
	}
	delete current;

	std::cout << endl <<"==============================================================" << endl;
	std::cout << endl << " Fin " << endl;
}

template <class Type>
void LinkedListManager<Type> ::EmptyList() 
{
	//pointer to traverse the list
	NodeType<Type> *current = new NodeType<Type>;

	// set current so that it points to head
	current = head;

	// Increments sequentially through the element list 
	// Until current reaches the end of the list (unallocated memory)
	std::cout << "==============================================================" << endl;
	while (current != nullptr)
	{
		head = head->link;
		current = NULL;
		current = head;
	}

	delete current;
	std::cout << endl << "==============================================================" << endl;
	std::cout << endl << " Fin " << endl;
}

// Use to Construct new Linked Lists
template <class Type>
LinkedListManager<Type> :: LinkedListManager()
{
	// Assigns a value to the Smart pointers upon instantiation
	//head = new NodeType<Type>;
	//tail = new NodeType<Type>;
}

// Use to Destroy Linked Lists (and let std::shared_ptr free allocated memory)
template <class Type>
LinkedListManager<Type> :: ~LinkedListManager()
{
	EmptyList();
	// No need to free malloc here
	// The Use of std::shared_ptr(Smart Ptr) does that for us
	delete head;
	delete tail;
}