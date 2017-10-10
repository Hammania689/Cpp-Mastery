#pragma once
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class President
{
  public:
    int age;
    string firstName;
    string lastName;
    President *next;

  President() : age(0), next(nullptr) {}
	~President(){}
};

class ListOfPresidents
{
  public:
    President *head;

    int lengthOfList;

	void MergeSort()
	{
		// 1) Divide into two list
		auto *list1 = new ListOfPresidents;
		auto *list2 = new ListOfPresidents;

		auto half1 = 0;
		auto half2 = 0;

		if (lengthOfList % 2 == 0)
			half1 = half2 = lengthOfList / 2;
		else
		{
			half1 = (lengthOfList / 2) + 1;
			half2 = lengthOfList / 2;
		}

		list1 = list1->DeepCopyList(this->PresidentAtIndex(head,0), this->PresidentAtIndex(head,half1));
		list2 = list2->DeepCopyList(this->PresidentAtIndex(head, (half1 + 1)), this->PresidentAtIndex(head, half2));

		// 2) Selective Sort the list
		list1->SelectionSort(list1);

		list1->Print();
		list2->SelectionSort(list2);

		CheckSubListContents(list1,list2);
	}
    

	void  SelectionSort(ListOfPresidents *listToSort)
	{
		
		for (auto i = 0; i < listToSort->GetLengthOfList(listToSort->head); i++)
		{
			// Variables to store the current element's data
			auto currentPres = listToSort->PresidentAtIndex(listToSort->head, i);

			auto currentLast = currentPres->lastName;
			auto currentFirst = currentPres->firstName;
			auto currentAge = currentPres->age;

			// Assume that the current index is the smallest in the list
			auto minIndex = i;

			// Nested for loop to check the check against other indexes in the list(Starting from after the current index)
			for (auto j = (i + 1); j < listToSort->GetLengthOfList(listToSort->head); j++)
			{

				auto testPres = listToSort->PresidentAtIndex(listToSort->head, j);
				auto minCurrentPres = listToSort->PresidentAtIndex(listToSort->head, minIndex);

				auto testLast = testPres->lastName;
				auto testFirst = testPres->firstName;
				auto testAge = testPres->age;

				// if the test age is less than the current index's age
				// AND  if the test age is less than the current minIndex
				// This finds the absolute lowest value in the list and ensure it will not be change by a "local minima"
				//if (testAge < age && listToSort->PresidentAtIndex(listToSort->head, minIndex)->age > testAge)
				if (testLast.compare(currentLast) <= 0)
				{
					if (testLast.compare(minCurrentPres->lastName) == 0)
					{
						//// test the first
						if (testFirst.compare(minCurrentPres->firstName) == 0)
						{
							/*if (testAge == minCurrentPres->age)
								cout << "We have two " << testLast << endl << endl << endl << endl;*/
							if(minCurrentPres->age > testAge)
								minIndex = j;
						}
						else if (minCurrentPres->firstName > testFirst)
							minIndex = j;
					}
					else if(minCurrentPres->lastName > testLast)
						minIndex = j;
				}
			}

			// If i isn't the lowest value then change the list
			if (minIndex != i)
				listToSort->SwapTwoElementsInList(listToSort->head, minIndex, i);
		}
	}


	void DeletePotusAtIndex(President *currHead,int index)
	{
		auto *current = currHead;
		int count = 0; /* the index of the node we're currently
					   looking at */
		while (current != NULL)
		{
			if (count == index)
			count++;
			current = current->next;
		}
	}

    void SwapTwoElementsInList(President *listHead, int n, int m)
    {
		auto *node1 = listHead;
		auto *node2 = listHead;

		for (auto i = 0; i < n; i++)
			node1 = node1->next;

		for (auto j = 0; j < m; j++)
			node2 = node2->next;

		auto tempLast = node1->lastName;
		auto tempFirst = node1->firstName;
		auto tempAge = node1->age;

		node1->lastName = node2->lastName;
		node1->firstName = node2->firstName;
		node1->age = node2->age;

		node2->lastName = tempLast;
		node2->firstName = tempFirst;
		node2->age = tempAge;
	}

    // Use to visualize the elements in each sublist 
    void CheckSubListContents(ListOfPresidents *list1, ListOfPresidents *list2){
            list1->Print();
            cout << endl << endl;
            cout << endl << endl;
            list2->Print();
    }
    // Appends a node at the end of a occupied OR The head of an empty linked list
    // Use to add a single element to the list
    void Append(string last,string first, int age)
    {
      // Instantiate the new Node
      auto *current = head;
      auto *queuedNode = new President;
      
      // Add the passed in variables to the node
      queuedNode->firstName = first;
      queuedNode->lastName = last;
      queuedNode->age = age;
      
      // Iterate to the begining of an empty list 
      // OR Iterate to the end of the list
      // then insert the node
      
      if(head == nullptr)
		head = queuedNode;
      else
      {
        while(current->next != nullptr)
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
      auto *current = head;
      
      // Iterate to the begining of an empty list 
      // OR Iterate to the end of the list
      // then insert the node
      
      if(head == nullptr)
      head = existingNode;
      else
      {
        while(current->next != nullptr)
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
      auto *current = head;
      lengthOfList = 0;
      // Iterates until the very last element
      while (current != nullptr)
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
    ListOfPresidents *DeepCopyList(President *startNode,President *endNode)
	{
      // Create a new List ptr
      // Boolean flag to see stop loop if the list is at the endNode index
      auto *tmp = new ListOfPresidents;
      auto sublistComplete = false;
      
      // Current Ptr points to the Original list's starting index
      // A new ptr that will hold an independent address 
      auto *current = startNode;
      auto *copy = new President;
      
      // Copies the data of head
      copy->firstName = current->firstName;
      copy->lastName = current->lastName;
      copy->age = current->age;

      // Doesn't Point to the next Node in the List
      copy->next =  nullptr;
      
      // Const Instance of the head for the new list 
      // Eletronic Insurance to ensure nothing gets altered
      // Sets the head of the new list
      // Increments the index accordingly
      auto *const newHead = copy;
      tmp->head = newHead;
      tmp->lengthOfList +=1;
      
      // We can only copy a list that isn't empty
      // So we've already have copied the header
      // Traverses to the next element
      current = current->next;
      
      // While current points to data that isn't NULL
      while(current != nullptr && sublistComplete != true)
		{
			// Rinse and repeat what we did before the loop
			// Create a newly alloc ptr for the next node and Prepare to deep copy
			copy = copy->next = new President;

			// Deep copy for each variable
			copy->firstName = current->firstName;
			copy->lastName = current->lastName;
			copy->age = current->age;
			copy->next = nullptr;

			// Increase the length
			tmp->lengthOfList += 1;

			// If the current index is the specifed index to stop at then don't move on 
			if (current == endNode)
				sublistComplete = true;
			// Otherwise move to the next node
			else
				current = current->next;
		}

      // Return the newly copied list
      return tmp;
    }

	// We can only copy a list that isn't empty
	// So we've already have copied the header
	// Finds the President at the index passed in
	// Use to find one president at a specific element index
	// WARNING RETURNS AN ELEMENT AND ALL OF THE SUBSEQUENT NODES
	President*  PresidentAtIndex (President * currHead,int index) const
	{
		auto *current = currHead;
		int count = 0; /* the index of the node we're currently
						looking at */
		while (current != NULL)
		{
			if (count == index)
				return current;
			count++;
			current = current->next;
		}
	return nullptr;
	}
        
    int GetLengthOfList(President *H)
    {
      // Points to the head for travesal
      auto *current = H;
      lengthOfList = 0;
      // Iterates until the very last element
      while (current != nullptr)
      {
        lengthOfList += 1;
        current = current->next;
      }
	    return lengthOfList;
    }
    
    ListOfPresidents(){ head = nullptr; lengthOfList = 0;}
    ~ListOfPresidents(){
      while (head != nullptr)
      {
          President *tmpNode = head->next;
          delete head;
          head = tmpNode;
      }
    }
  };