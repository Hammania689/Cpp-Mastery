#include "stack_adt.h"
#include "fstream"


// Use to determine whether are not two chars belong to the same pair 
bool ArePairs(char openingChar,char closingChar);

int main()
{

    PairNodeStack stackTest;
    fstream fileToCheck;
    
    // fileToCheck(argc[1]);
    
    
    auto test = string("{[//]}");
    auto currentChar = 'd';

    // Read Text and find the first (, {, [, /* 
    for(int i = 0; i < test.length(); ++i)
    {
        currentChar = test[i];
		
		if (currentChar == ('(') || currentChar == ('{') 
			|| currentChar == ('[') || currentChar == ('/') || currentChar == ('*'))
				stackTest.push(currentChar);
       if(currentChar == (')') || currentChar == ('}')
			|| currentChar == (']') || currentChar == ('*') || currentChar == ('/'))
            if(!stackTest.empty() && ArePairs(stackTest.top()->data,currentChar))
				stackTest.pop();
    }

    cout << (stackTest.empty() ? "Your program is balanced" : "Your program is not balanced") << endl;
    
	cin.ignore();
    return 0;
}   

// Returns True if two chars are pairs
bool ArePairs(char openingChar,char closingChar)
{
    if(openingChar == ('(') && closingChar == (')')) return true;
	if (openingChar == ('{') && closingChar == ('}')) return true;
	if (openingChar == ('[') && closingChar == (']')) return true;
	if (openingChar == ('/') && closingChar == ('/')) return true;
	if (openingChar == ('*') && closingChar == ('*')) return true;
	return false;
}