#include <fstream>
#include <iostream>

using namespace std;

//

int main()
{
    // File streams
    ifstream inData("in.txt");
    ofstream outData("test.txt");

    // Variables all of which happen to be double besides the name
    string name;
    auto
            gross = 0.00, bonus = 0.00,
            taxes = 0.00, distance = 0.0,
            hours = 0.0, cupsSold = 0.0,
            costPerCup = 0.0, paycheck = 0.0,
            avgSpeed = 0.0, salesAmt = 0.0;

    // Accessing the input data
    getline(inData,name);
    inData >> gross >> bonus >> taxes;

    // Could turn this into a oneline function for better readability
    paycheck = ((gross * bonus/100) + gross) * ((100 - taxes)/100);

    // Ensure the readstream opened up correctly
    if(!inData)
        outData << "Nothing to show.. Try Agian \n";

    // If everything looks good then carry on and output the data
    outData << "Name: " << name << endl;
    outData << "PayCheck :" << paycheck << endl;

    // Safely close the files
    inData.close();
    outData.close();
    return 0;
}