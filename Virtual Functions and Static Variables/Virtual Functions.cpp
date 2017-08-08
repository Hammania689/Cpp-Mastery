/**
This problem is to get you familiar with virtual functions.
Create three classes Person, Professor and Student.
The class Person should have data members name and age.
The classes Professor and Student should inherit from the class Person.
The class Professor should have two integer members : publications and prof_Count.
There will be two member functions : getdata and putdata.
The function getdata should get the input from the user : the name, age and publications of the professor.
The function putdata should print the name, age, publications and the prof_Count of the professor.
The class Student should have two data members : marks, which is an array of size  and stud_Count.It has two member functions : 
getdata and putdata.The function getdata should get the input from the user : the name, age, 
and the marks of the student in  subjects.The function putdata should print the name, age, sum of the marks and the stud_Count of the student.
For each object being created of the Professor or the Student class, sequential id's should be assigned to them starting from .
Solve this problem using virtual functions, constructors and static variables.You can create more data members if you want.
 */

#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person
{
public:
	int age;
	string name;
	Person() : age(0), name("") { }
	virtual ~Person() = default;
	virtual void getdata() { std::cout << "Base class not overrided" << endl; }
	virtual void putdata() const { std::cout << "Base class not overrided" << endl; }
};

class Professor : public Person
{
private:
	int publications;
	const int curr_id;

	static  int prof_Count;

public:
	void getdata() override
	{
		std::cin >> name >> age >> publications;
	}

	void putdata() const override
	{
		std::cout << name << " " << age << " " <<
			publications << " " << curr_id << std::endl;
	}

	Professor() : publications(0), curr_id(prof_Count++)
	{
	}
};

class Student : public Person
{
private:
	int marks[6];
	int curr_id;

	static int stud_Count;

public:

	void getdata() override
	{
		std::cin >> name >> age;

		for (size_t i = 0; i < 6; i++)
		{
			std::cin >> marks[i];
		}
	}

	void putdata() const override
	{
		auto sum = 0;
		for (auto i = 0; i < 6; i++)
			sum += marks[i];

		std::cout << name << " " << age << " " <<
			sum << " " << curr_id << std::endl;
	}

	Student() : curr_id(stud_Count++), marks{ 0 }
	{

	};
};


int Professor::prof_Count = 1;

int Student::stud_Count = 1;



int main() 
{

	int n, val;
	
	//The number of objects that is going to be created.
	cin >> n; 

	//Creating a dynamic array of the size N
	Person *per[n];

	// Iterating through the list 
	// Value determines the type of object instantiated

	for (int i = 0; i < n; i++) {

		cin >> val;
		if (val == 1) 
		{
			// If val is 1 current object is of type Professor
			per[i] = new Professor;

		}
		else per[i] = new Student; // Else the current object is of type Student

		per[i]->getdata(); // Get the data from the user.

	}

	for (int i = 0; i<n; i++)
		per[i]->putdata(); // Print the required output for each object.

	return 0;

}
