#include "AddressNode.h"
#include<iostream>

#ifndef ADDRESSNODE
#define ADDRESSNODE

void AddressNode::CreateContact()
{
	cout << "Name : \t";
	getline(cin, name);
	SetName(name);
	cout << endl;

	/*
	cout << "Phone Number : \t";
	cin.ignore();
	getline(cin, phoneNumber);
	cout << endl;

	cout << "City : \t";
	cin.ignore();
	getline(cin, city);
	cout << endl;

	cout << "State : \t";
	cin.ignore();
	getline(cin, state);
	cout << endl;

	cout << "Zip Code : \t";
	cin.ignore();
	getline(cin, zipCode);
	cout << endl;
	string response;
	int counter = 0;

	while (response != "")
	{
		cout << "Birthdays to know : \t";
		cin >> response;
		cout << endl;

		birthdaysToKnow[counter] = response;
		counter++;
	}
	*/
	cout << "Contact Stored! \n";
}

void AddressNode::EditContact()
{

}

string AddressNode::PrintContactList()
{
	string contactInfo;
	contactInfo =  name + "\n" + "========================== \n" +
		"Phone Number: \t" + phoneNumber + "\n" +
		city + ", " + state + " " + zipCode + "\n";

	return contactInfo;
}

string AddressNode::SetName(string n)
{
	return name = n;
}

string AddressNode::SetCity(string c)
{
	return city = c;
}

string AddressNode::SetState(string s)
{
	return state = s;
}

string AddressNode::SetZipCode(string z)
{
	return zipCode = z;
}

string AddressNode::SetPhoneNumber(string p)
{
	return phoneNumber = p;
}

string * AddressNode::SetBirthdaysToKnow(string *b)
{
	return birthdaysToKnow = b;
}

string AddressNode::GetName()
{
	return name;
}

string AddressNode::GetCity()
{
	return city;
}

string AddressNode::GetState()
{
	return state;
}

string AddressNode::GetZipCode()
{
	return zipCode;
}

string AddressNode::GetPhoneNumber()
{
	return phoneNumber;
}

string * AddressNode::GetBirthdaysToKnow()
{
	return birthdaysToKnow;
}

AddressNode::AddressNode()
{
}

AddressNode::~AddressNode()
{
	delete birthdaysToKnow;
	delete prev;
	delete link;
}
#endif // !AddressNode
