#include <iostream>
#include <string>
using namespace std;

void SwapFirstChar(string &a, string &b);

int main() 
{
   // Complete the program
    string a, b;
  
    std::getline(cin >> ws, a);
    std::getline(cin >> ws, b);
  
    cout << a.length() << " " << b.length() << endl;
    cout << (a + b) << endl;
    
    
  
    SwapFirstChar(a,b);
  
    cout << a << " " << b << endl;
    return 0;
}

void SwapFirstChar(string &a, string &b)
{
  auto temp = ' ';
  temp = a[0];
  a[0] = b.at(0);
  b[0] = temp; 
}
