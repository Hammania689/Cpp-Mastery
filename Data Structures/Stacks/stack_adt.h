#pragma once
#include <iostream>

using namespace std;

// Used an Linked List Iteration of a Stack
class PairNode
{
public:
    char data;
    PairNode *next;

    PairNode() {next = 0;}
    ~PairNode()
    {
        next = 0;
        delete next;
    }
};

class PairNodeStack
{
	// Variables to store length and current head of the Stack
    int size;
    PairNode * head;
public:

	// Use to return a boolean value of whether the Stack is empty
    bool empty()
    { 
        size = getSize();
        if(size == 0) 
            return true;
        return false;
    }
    
	// Use to return an integer value of the Stack's number of elements
    int getSize()
    {
        size = 0;
        
        if(head == 0)
        {
            cout << "The stack is empty \n";
            return size;
        }

        auto current = head;

        while(current != 0)
        {
            size++;
            current = current->next;
        }
        
        return size;
    }
    
	// Use to return the PairNode at the current top of the Stack.
    PairNode *top()
    {
        if(this->getSize() == 0)
            return nullptr;

        auto *topOfStack = new PairNode;
        topOfStack->data = head->data;
        topOfStack->next = 0;
        return topOfStack;   
    }
    
	// Use to delete the current top of the Stack
    void pop()
    {
        if(!(head->next == nullptr))
	    {
		    PairNode* tmp = head;
			head = head->next;
		    delete tmp;
		    return;
	    }

	    head = nullptr;
	    delete head;
		cout << "Popped the last node in the stack. The stack is now empty" << endl;
    }

	// Use to add an element to the top of the Stack
    void push(char d)
    {
        auto lastIn = new PairNode;

        lastIn->data = d;
        lastIn->next = head;

        head = lastIn;
    }

    PairNodeStack() 
    {
        head = 0; 
        size = 0;
    }
    ~PairNodeStack()
    {
        while(head != 0)
        {
			auto *tmp = head;
            head = head->next;
            delete tmp; 
        }
    }
};
