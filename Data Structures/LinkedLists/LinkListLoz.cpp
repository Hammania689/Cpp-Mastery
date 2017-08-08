#include <iostream>

using namespace std;

struct nodeType
{
	int info;
	nodeType *link;
};

// Global node variables to setup and move through the linked list
nodeType *head, *current, *newNode, *tail;

int main()
{
	// Creates 5 nodes and connects them together
	for (int i = 0; i < 5; i++)
	{
		newNode = new nodeType;
		cout << "Number : \t";
		cin >> newNode->info;
		newNode->link = nullptr;

		// if the list is empty
		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			// Change the previous newNode link from null pointer
			// to this current newNode
			tail->link = newNode;
			tail = newNode;
		}
	}

	// Set the current equal to head
	// Shows that we are started from the top
	current = head;

	// Until we get to the tail
	while (current != nullptr)
	{
		// Print out each node's information
		cout << current->info << " || ==>  ";
		current = current->link;
	}

	cout << "End\n";
	system("pause");

	// Deallocate memory and frees space
	delete newNode;
	delete head;
	delete current;
	delete tail;

	newNode = nullptr;
	head = nullptr;
	current = nullptr;
	tail = nullptr;

	return 0;
}

