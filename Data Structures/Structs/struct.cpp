#include <iostream>
#include <string>

using namespace std;

struct Student{
  int age;
  string first_name;
  string last_name;
  int standard;
};

int main(){
  
  Student st;
  string brk = "\n";

  cout << "Enter in the Age, First Name , Last Name, and Rank of the Student" << "\n";

  cin >> st.age >> st.first_name >> st.last_name >> st.standard;
  
  cout << "Age: " <<  st.age << brk << "Full Name: " <<  st.first_name << st.last_name << brk << "Standard: " <<  st.standard;

  return 0;
}
