#pragma once
#include "linkedlist.h"
#include "memory"

class DictionaryHash
{
public:

	// Prime number in hopes to avoid collisions and clustering
	static const auto table_size = 29;

	LinkedList entry[table_size];

	// Use to see determine where in the table the value will be stored. Based on first character
	int GenerateKey(string value)
	{
		return (value.at(0) % table_size);
	}

	// Use to Insert words in to the hash table
	void InsertInTable(string value)
	{
		// Ptr variable to store word value and produced key
		auto node = new EntryNode;
		node->word = value;
		node->key = GenerateKey(node->word);
		
		// Int to easily access node index
		// Ptr to traverse through list if not empty
		auto keyIndex = node->key;
		auto current = entry[keyIndex].head;

		// Inserts the node in proper place
			entry[keyIndex].Append(node->word);
	}

	// Use to fill the table with it's corresponding index ** Only for Testing
	void FillTable()
	{
		for (auto i = 0; i < 31; i++)
		{
			entry[i].head->word = to_string(i);

			if (i == 30)
			{
				entry[i].head->next = new EntryNode;
				entry[i].head->next->word = "testttts";
			}
		}
	}

	// Use to print the entire table - All 31 linked lists and it's contents
	void PrintTable()
	{
		for (auto i = 0; i < table_size; i++)
		{
			cout << "Element " << i << "\t";
			entry[i].PrintForward();
		}
	}

	// Use to check and see if a word is in the dictionary
	bool isInDictionary(string value)
	{
		// Variables to store index and travesal of the linked list
		auto indexToCheck = GenerateKey(value);
		auto current = entry[indexToCheck].head;
		
		// Traverse the linked list until the entry is found or the word is not present
		while (current != nullptr)
		{
			if (current->word == value)
				return  true;
			current = current->next;
		}
		return false;
	}
	DictionaryHash()
	{};
};
