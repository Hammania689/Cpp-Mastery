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
    
    void MergeSort()
    {
      // Divide into two list
      ListOfPresidents list1;
      ListOfPresidents list2;

      int half1 = 0;
      int half2 = 0;

      if(lengthOfList % 2 == 0)
      {
        half1 = lengthOfList / 2;
        half2 = lengthOfList / 2;
      }
      else
      {
        half1 = (lengthOfList / 2) + 1;
        half2 = lengthOfList / 2;
      }

        
      cout << "List 2 : head is " << list2.head->firstName << endl;
      list2.Print();

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
    
    // Appends a node at the end of a occupied OR The head of an empty linked list
    // Use for Merge Sort. Appends existing node from original list
    void Append(President *existingNode)
    {
      // Instantiate the new Node
      President *current = head;
      
      // Iterate to the begining of an empty list 
      // OR Iterate to the end of the list
      // then insert the node
      
      if(head == NULL)
      head = existingNode;
      else
      {
        while(current->next != NULL)
        current = current->next;
        current->next = existingNode;
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
      lengthOfList = 0;
      // Iterates until the very last element
      while (current != NULL)
      {
        // Prints data 
        // Goes to the next element
        cout << current->lastName << " " << current->firstName
        << " " << current->age << endl;
        lengthOfList += 1;
        current = current->next;
      }
    }
    
    // Duplicates a Deep Copy Instance of the List that doesn't point to the same adress
    // Use to Create Independent Instances(Deep Copy) of a list with prexisting data
    ListOfPresidents *DeepCopyList(const ListOfPresidents &L)
    {
      // Create a new List ptr
      ListOfPresidents *tmp = new ListOfPresidents;
      
      // Ptr that point to the Original list's head
      // A new ptr that will hold an independent address 
      President *current = L.head;
      President *copy = new President;
      
      // Copies the data of head
      copy->firstName = current->firstName;
      copy->lastName = current->lastName;
      copy->age = current->age;
      // Doesn't Point to the next Node in the List
      copy->next =  NULL;
      
      // Const Instance of the head for the new list 
      // Eletronic Insurance to ensure nothing gets altered
      // Sets the head of the new list
      // Increments the index accordingly
      President *const newHead = copy;
      tmp->head = newHead;
      tmp->lengthOfList +=1;
      
      // We can only copy a list that isn't empty
      // So we've already have copied the header
      // Traverses to the next element
      current = current->next;
      
      // While current points to data that isn't NULL
      while(current != NULL)
      {
        // Rinse and repeat what we did before the loop
        // Create a newly alloc ptr for the next node and Prepare to deep copy
        copy = copy->next = new President;
        
        // Deep copy for each variable
        copy->firstName = current->firstName;
        copy->lastName = current->lastName;
        copy->age = current->age;
        copy->next =  NULL;
        
        // Increase the length
        tmp->lengthOfList += 1;
        
        // Move to the next node
        current = current -> next;
      }
      
      // Return the newly copied list
      return tmp;
    }
    
    // Finds the President at the index passed in
    // Use to find one president at a specific element index
    // WARNING RETURNS AN ELEMENT AND ALL OF THE SUBSEQUENT NODES
    President* PresidentAtIndex(int index)
    {
      President *current = head;
      
      // if(index > lengthOfList)
      // {
      //   cout << "Invalid element index of the list";
      //   return NULL;
      // } 
      for(int i = 1; i < index;i++)
        current = current->next;
    // WARNING RETURNS INDEXED ELEMENT AND ALL OF THE SUBSEQUENT NODEs
      return current;
    }
    
    int GetLengthOfList()
    {
      // Points to the head for travesal
      President *current = head;
      lengthOfList = 0;
      // Iterates until the very last element
      while (current != NULL)
      {
        lengthOfList += 1;
        current = current->next;
      }
    }
    
    ListOfPresidents(){ head = NULL; lengthOfList = 0;}
    ~ListOfPresidents(){delete head;}
  };