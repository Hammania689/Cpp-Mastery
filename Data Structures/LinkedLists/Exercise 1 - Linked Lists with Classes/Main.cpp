#include "AddressNode.h"
#include "ContactBook.h"
#include <fstream>

int main()
{
	ContactBook contactBook;

	for (int i = 0; i < 5; i++)
	{
		contactBook.InsertAtEnd();
			
		cout << "Hello, " << contactBook.newContact->GetName() << endl;
		//cout << contactBook.newContact->PrintContactList();
	}
	
	system("cls");
	
	///////////////////////////
	// EXCEPTION HANDLING????//
	///////////////////////////

	contactBook.PrintForward();

	cout << "The end \n";
	
	//contactBook.SaveContacts();
	
	system("pause");
	return (0);
}

