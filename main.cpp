/*
 * Author : Hameed Abdul
 * Date : Aug 22nd, 2017
 * Purpose : To learn more about file formatting and raw data through the creation of a binary file
 * Licence : The MIT License (MIT)
 * University of Southern Mississippi, GulfPark Campus
 */

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Person {
    char name[80];
    int age;
public:
    // Default constructor
    Person() {
        strcpy(name, "No name");
        age = 0;
    }

    // Constructor takes in and sets values to parameters
    Person(char *name, int age) {
        strcpy(this->name, name);
        this->age = age;
    }

    // Prints Object Data
    void whoAreYou() {
        cout << "Hi, I am " << name << " and I am "
             << age << " years old" << endl;
    }

    void change() {
        strcpy(name, "Papa Smurf");
        age = 453;
    }
};

int main()
{
    // Default person
    Person firstPerson((char *) "Hameed", 20);

    // Initialized Binary File that reads, writes, and truncates in the event that a file
    // with the same name already exists
    fstream binFile("person.bin", ios::binary | ios::in | ios::out | ios::trunc);

    // if the file can't be opened or read
    if (!binFile)
        cout << "Error while opening the file";
    else {
        // write the information of the first to the binary file
        // Indicate that the file will beginning reading from the beginning of the file
        binFile.write((char *) &firstPerson, sizeof(Person));
        binFile.seekg(0);

        // Create a second Person
        Person secondPerson;

        // Reads the binfile and copies the object data
        // Proceeds to print and show that the copy was successful
        binFile.read((char *) &secondPerson, sizeof(Person));
        firstPerson.whoAreYou();
        secondPerson.whoAreYou();

        // Change the Contents of the first person
        // Reprint object data
        firstPerson.change();
        firstPerson.whoAreYou();
        secondPerson.whoAreYou();

        // Safely close file
        binFile.close();
    }
    return 0;
}