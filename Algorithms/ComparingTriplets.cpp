#include <iostream>
#include <string>

using namespace std;


const auto index = 3;
auto fooScore = 0;
auto barScore = 0;

void DealScore(int &, int &);

int main()
{
	int foo[index];
	int bar[index];


	for (auto i = 0; i < index; i++)
	{
		cin >> foo[i] >> bar[i];
		DealScore(foo[i], bar[i]);
	}

	cout << fooScore << " " << barScore;
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */

	system("pause");
	return 0;
}


void DealScore(int &a, int &b)
{
	cout << "A : " << a << endl;
	cout << "B : " << b << endl;

	if (a < b)
		barScore += 1;
	else if (a > b)
		fooScore += 1;
}