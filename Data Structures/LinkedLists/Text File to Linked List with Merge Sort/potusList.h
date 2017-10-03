// #pragma once
#include <iostream>

using namespace std;

class President
{
  public:
    int age;
    string firstName;
    string lastName;
    President *next;
    President() {this->next = NULL;}
    ~President(){}
};


class ListOfPresidents
{
  public:
    President *head;

    int lengthOfList;
    //*President Sort();
    
    // Finds the President at the index passed in
    // Use to find one president at a specific element index
    President* PresidentAtIndex(int index)
    {
      President *current = head;
      
      if(index > lengthOfList)
      {
        cout << "Invalid element index of the list";
        return NULL;
      } 
      for(int i = 1; i < index;i++)
        current = current->next;
      return current;
    }

    // Appends a node at the end of a occupied OR The head of an empty linked list
    // Use to add a single element to the list
    void Append(string last,string first, int age)
    {
      // Instantiate the new Node
      President *current = head;
      President *queuedNode = new President;
      
      // Add the passed in variables to the node
      queuedNode->firstName = first;
      queuedNode->lastName = last;
      queuedNode->age = age;
      
      // Iterate to the begining of an empty list 
      // OR Iterate to the end of the list
      // then insert the node
      
      if(head == NULL)
      head = queuedNode;
      else
      {
        while(current->next != NULL)
          current = current->next;
        current->next = queuedNode;
      }
      
      // Add to the index of the list
      lengthOfList += 1;
    }

    // Prints the contents of the List
    // Use to display every element of the list
    void Print()
    {
      // Points to the head for travesal
      President *current = head;
      
      // Iterates until the very last element
      while (current != NULL)
      {
        // Prints data 
        // Goes to the next element
        cout << current->lastName << " " << current->firstName
        << " " << current->age << endl;
        current = current->next;
      }
    }

    ListOfPresidents(){ head = NULL; lengthOfList = 0;}
    ~ListOfPresidents(){delete head;}
};