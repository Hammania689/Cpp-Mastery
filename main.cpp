#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

// Use to calculate NetIncome after taxes and bonuses
double NetIncome(double &, double &, double &);

// Use to calculate Average Speed
double AvgSpeed(double &d, double &h);

// Use to calculate Gross Sales Amount
double SalesAmt(double &, double &);

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
    // Should be stored in a loop to have everything complete
    getline(inData,name);
    inData >> gross >> bonus >> taxes
           >> distance >> hours >> cupsSold >> costPerCup;

    // Store the function return values in categorical values
    avgSpeed = AvgSpeed(distance,hours);
    salesAmt = SalesAmt(cupsSold,costPerCup);
    paycheck = NetIncome(gross, bonus, taxes);


    // If everything looks good then carry on and output the data
    if(inData)
    {
            outData << "Name: " << name << endl;
            outData << "Monthly Gross Salary: $" << gross
                    << ", Monthly Bonus: " << bonus << "%, " << "Taxes: " << taxes <<"%" << endl;
            outData << "NetIncome : $" << paycheck << endl << endl;

            outData << "Distance Traveled: " << distance << " miles, Traveling Time: " << hours
                    << " hours" << endl << "Average Speed: " << avgSpeed << " miles per hour" << endl << endl;

            outData << "Number of Coffee Cups Sold: " << cupsSold << ", Cost: $" << costPerCup << " per cup" << endl
                    << "Sales Amount: $" << salesAmt << endl << endl;
    }
    else // Ensure the read stream opened up correctly
        outData << "Nothing to show.. Try Again \n";

    // Safely close the files
    inData.close();
    outData.close();
    return 0;
}

double SalesAmt(double &sold, double &cupCost)
{ return sold*cupCost;
}

double AvgSpeed(double &d, double &h)
{
    return d / h;
}

double NetIncome(double &g, double &b, double &t)
{
    return (((g * b / 100) + g) * ((100 - t) / 100));
}

