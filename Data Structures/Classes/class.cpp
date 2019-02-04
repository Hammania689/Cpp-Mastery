#include <iostream>
#include <string>

using namespace std;

class Student{
  private:
    int age;
    int standard;
    string first_name;
    string last_name;
  
  public:
      void SetAge(int a){
          age = a;
      } 
      
      void SetFirstName(string f){
          first_name = f;
      } 
      
      void SetLastName(string l){
          last_name = l;
      }

      void SetStandard(int s){
          standard = s;
      }

      string GetFirstName(){
        return first_name;
      }

      string GetLastName(){
        return last_name;
      }

      int GetStandard(){
        return standard;
      }

      int GetAge(){
        return age;
      }

      Student(int a, string f_name, string l_name, int s){
       age = a;
       first_name = f_name;
       last_name = l_name;    
       standard = s;
      }
};

int main(){
  string brk = "\n";
  int age;
  string fname;
  string lname;
  int standard;
  
  cout << "Enter in the Age, First Name , Last Name, and Rank of the Student" << "\n";
    
  cin >> age >> fname >> lname >> standard;
  
  cout << "Made it \n";
//  auto st = Student(age, fname, lname, standard);

  //cout << "Age: " <<  st.GetAge() << brk << "Full Name: " <<  st.GetFirstName() << st.GetLastName() << brk << "Standard: " <<  st.GetStandard();

  return 0;
}
