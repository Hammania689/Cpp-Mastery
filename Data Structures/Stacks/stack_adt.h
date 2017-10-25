#include "iostream"

using namespace std;
    
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
public:
    
    int size;
    PairNode * head;

    bool empty()
    { 
        size = getSize();
        if(size == 0) 
            return true;
        return false;
    }
    
    int getSize()
    {
        size = 0;
        
        if(head == 0)
        {
            cout << "The stack is empty \n";
            return size;
        }

        PairNode *current = head;

        while(current != 0)
        {
            size++;
            current = current->next;
        }
        
        return size;
    }
    
    PairNode *top()
    {
        if(this->getSize() == 0)
            return NULL;

        PairNode *topOfStack = new PairNode;
        topOfStack->data = head->data;
        topOfStack->next = 0;
        cout << "The Stack's current top : " << topOfStack->data << endl;
        return topOfStack;   
    }
    
    void pop()
    {
        if(head->next = 0)
        {
            head = 0;
            delete head;
            return;
        }

        PairNode *tmp = head->next;
        delete head;
        head = tmp;
        
    }

    void push(char d)
    {
        PairNode *lastIn = new PairNode;

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
        PairNode *tmp;
        while(head != 0)
        {
            tmp = head->next;
            delete head; 
            head = tmp;   
        }
    }
};
