#include "stack_adt.h"
#include "fstream"


bool ArePairs(char openingChar,char closingChar);

int main()
{
    PairNodeStack stackTest;
    // fstream fileToCheck;
    
    // fileToCheck(argc[1]);
    
    // Read Text and find the first (, {, [, /* 
    
    string test = "{(d((((})";
        
    char currentChar = 0;

    for(int i = 0; i < test.length(); ++i)
    {
        currentChar = test[i];
        
        if(currentChar == ('('))
            stackTest.push(currentChar);
        
        else if(currentChar == (')'))
        {
            if(!stackTest.empty() && ArePairs(stackTest.top()->data,currentChar))
                stackTest.pop();
        }
    }

    cout << stackTest.getSize() << endl;

    if(stackTest.empty())
        cout << "Your program is balanced" << endl;
    else 
        cout << "Your program is not balanced" << endl;
        
    return 0;
}   


bool ArePairs(char openingChar,char closingChar)
{
    if(openingChar == ('(') && closingChar == (')')) return true;
    return false;
}