//
// Created by hamma on 8/16/2017.
//

#include <iostream>

using namespace std;


/*Write the class AddElements here*/
template <class T>
class AddElements
{
    T element1;
public:
    AddElements(T a) {element1 = a;}
    T add(T b) { return  (element1 + b);}
    T concatenate(T b) { return (element1 + b);}
};

int main()
{
    int n,i;
    cin >> n;
    for(i=0;i<n;i++) {
        string type;
        cin >> type;
        if(type=="float") {
            double element1,element2;
            cin >> element1 >> element2;
            AddElements<double> myfloat (element1);
            cout << myfloat.add(element2) << endl;
        }
        else if(type == "int") {
            int element1, element2;
            cin >> element1 >> element2;
            AddElements<int> myint (element1);
            cout << myint.add(element2) << endl;
        }
        else if(type == "string") {
            string element1, element2;
            cin >> element1 >> element2;
            AddElements<string> mystring (element1);
            cout << mystring.concatenate(element2) << endl;
        }
    }
    return 0;
}


