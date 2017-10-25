#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>


using namespace std;

// Couts all elements of the 2D array in formatted table
void PrintHourGlass();

// Function that adds proper indexes of 2D Vector
void AddIndexes();

// Loads values from global Int Array into 2D vector
void Fill2DVector();

// Sorts the Array and Places Highest Value at the End
int HighestSum();

// Global variables ... For Now
vector<int> sums;
vector< vector<int> > arr(6, vector<int>(6));

// For Testing
const int defaultValues[] =
{
	1, 1, 1, 0, 0, 0,
	0, 1, 5, 1, 2, 3,
	1, 1, 5, 0, 0, 0,
	0, 9, 2, 4, 4, 0,
	0, 0, 0, 2, 0, 0,
	4, 3, 1, 2, 4, 0,1
};

int main()
{
	Fill2DVector();

	PrintHourGlass();

	cout << endl;
	AddIndexes();
	
	cout << "Highest Sum : " << HighestSum() << endl;
	system("pause");
	return 0;
}

// Use to Load Default Array Values into 2D Vector
void Fill2DVector()
{
	auto arrayIndex = 0;
	for (auto i = 0; i < 6; i++)
	{
		for (auto j = 0; j < 6; j++)
		{
			// For Testing
			arr[i][j] = defaultValues[arrayIndex];

			//cin >> arr[i][j];
			arrayIndex++;
		}
		arrayIndex++;
	}
}

// Use to Print Entire 2D Vector
void PrintHourGlass()
{
	for (auto i = 0; i < arr.size(); i++)
	{
		for (auto j = 0; j < arr[i].size(); j++)
		{
			cout << arr.at(i).at(j) << " ";
		}
		cout << endl;
	}
}

// Use to Add Hour Glass Elements Together
// Use to Add Hour Glass Elements Together
void AddIndexes()
{
	
	auto rootTreeValue = 0;

	// Rows
	auto i = 0;
	auto rowMax = 3;
	auto iResetVal = 0;

	// Columns
	auto j = 0;
	auto colMax = 3;
	auto jResetVal = 0;

	auto rootTreeAreaIndex = 1;


	for (rootTreeAreaIndex; rootTreeAreaIndex < 5; rootTreeAreaIndex++)
	{
		for (i; i < rowMax; i++)
		{
			for (j; j < colMax; j++)
			{
				if (i == (rowMax - 2))
				{
					rootTreeValue += arr[i][rootTreeAreaIndex];
					j = colMax;
				}
				else
					rootTreeValue += arr[i][j];
			}

			// Resets J back to the first Column
			// This is to ensure each row has every element ..
			// reiterated and accounted for
			j = jResetVal;
		}

		auto middleValue = arr.at(rowMax - 2).at(rootTreeAreaIndex);
		// Display the current hour glass sum
		cout << rootTreeValue << endl;

		// Insert the current sum into a vector of other sums
		sums.push_back(rootTreeValue);
		auto sumElements = static_cast<int>(sums.size());

		// Reset the sum and prepare for the next Row Tree
		rootTreeValue = 0;
		cout << "Middle Value : " << middleValue << endl;

		// First conditional checks to see if the all the Root Trees on the current row have been added
		if (colMax < 6)
		{
			// Reset i to the top row of the root tree formation
			// Resets j to the index of the outter loop 
			// (This ensures that J is set to the index that correlates with the current root Tree)
			// Increments the max value that J can be accordingly
			i = iResetVal;
			j = rootTreeAreaIndex;
			jResetVal = j;
			colMax += 1;
		}
		else if (colMax == 6 && sumElements != 16)
		{
			// Reset the outer loop to run all loops again
			rootTreeAreaIndex = 0;

			// Increments the index of i to recognize each Root Tree in the 2D Vector
			iResetVal++;
			i = iResetVal;
			rowMax++;

			// Set J back to the first column to reiterate through each relevant element
			// Default values ... pretty much
			j = rootTreeAreaIndex;
			jResetVal = j;
			colMax = 3;
		}
	}

	//======================================
	cout << "Collective Sums " << endl;
	for (const auto count : sums)
		cout << count << " ";
	cout << endl << endl;
}


// Use to Sort and Find the Highest RootTree sum
int HighestSum()
{
	sort(sums.begin(), sums.end());
	auto highest = sums[ static_cast<int>(sums.size()) - 1];
	return highest;
}
