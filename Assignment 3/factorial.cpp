#include <iostream>

using namespace std;

long long factorial(int n)
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return n * factorial(n - 1);
	}
}

int main()
{
	int number;
	cout << "Enter a number: ";
	cin >> number;
	char next = cin.get();
	
	if (!cin.good() || number > 20 || number < 0)
	{
		cerr << "Error: Invalid Input. Program Terminated." << endl;
		return -1;
	}
	else if (next != ' ' && next != '\n' && next != '\t')
	{
		cerr << "Error: Invalid Input. Program Terminated." << endl;
		return -1;
	}
	
	cout << "Its factorial is " << factorial(number) << endl;

	return 0;
}