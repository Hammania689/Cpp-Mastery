#include "ContactBook.h"


void ContactBook::PrintForward()
{
	current = head;
	try
	{
		while (current != nullptr)
		{

				current->PrintContactList();
				cout << endl;

				current = current->link;
			}
	}

	catch (...)
	{
	}
}

void ContactBook::InsertAtEnd()
{
	newContact = new AddressNode;

	newContact->CreateContact();
	
	if (head == nullptr)
	{
		head = newContact;
		//head->prev = nullptr;

		tail = newContact;
	}
	else
	{
		newContact->prev = tail;
		tail->link = newContact;
		tail = newContact;
	}
}

void ContactBook::SaveContacts()
{
	current = head;
	
		fstream file;
		file.open("SavedContacts.txt", ios::out);

		while (current != nullptr)
		{
			file << "d /n";
			current = current->link;
		}
		file.close();
}

ContactBook::ContactBook()
{	
	newContact = new AddressNode;
}

ContactBook::~ContactBook()
{
	delete head;
	delete tail;
	delete newContact;
	delete current;

}
