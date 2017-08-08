#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class AddressNode
{

	//////////////////////////////////////////////////////////////////
	//					REQUIRED REFERENCE							//
	// needed for ContanctBook and AddressNode classes to be friends//
	//////////////////////////////////////////////////////////////////

	// ContactBook has access to all of AddressNodes Functions
	friend class ContactBook;

private:

	// Basic Contact information
	string name = "";
	string city;
	string state;
	string zipCode;
	string phoneNumber;
	string *birthdaysToKnow;

public:

	// Pointer to ajacent nodes 
	AddressNode *prev;
	AddressNode *link;

	// Methods to Fill in, Edit, and Print contact info
	void CreateContact();
	void EditContact();
	string PrintContactList();

	// Definition to set Property values of class
	string SetName(string n);
	string SetCity(string c);
	string SetState(string s);
	string SetZipCode(string z);
	string SetPhoneNumber(string p);
	string *SetBirthdaysToKnow(string *b);
	
	// Definition to grab Property values of class
	string GetName();
	string GetCity();
	string GetState();
	string GetZipCode();
	string GetPhoneNumber();
	string *GetBirthdaysToKnow();

	// Default Constructor and Destructor
	AddressNode();
	~AddressNode();
};

