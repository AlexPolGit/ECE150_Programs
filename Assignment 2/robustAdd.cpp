#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int main()
{
	int inA;
	int inB;
	
	cout << "Enter two integers to add: ";
	
	cin >> inA;
	char next = cin.get();
	
	if (cin.fail())
	{
		cerr << "Error: Invalid input. Not a number." << endl;
		return -1;
	}
	else if (next != ' ' && next != '\n' && next != '\t')
	{
		cerr << "Error: Invalid input. Non-integer detected. " << endl;
		return -1;
	}
	
	cin >> inB;
	next = cin.get();
	
	if (cin.fail())
	{
		cerr << "Error: Invalid input. Not a number." << endl;
		return -1;
	}
	else if (next != ' ' && next != '\n' && next != '\t')
	{
		cerr << "Error: Invalid input. Non-integer detected. " << endl;
		return -1;
	}
	
	if ((inA > 0 && inB > 0) && INT_MAX - inA < inB)
	{
		cerr << "Error: Summed value out of the signed int range." << endl;
		return -1;
	}
	else if ((inA < 0 && inB < 0) && -INT_MAX - inA > inB)
	{
		cerr << "Error: Summed value out of the signed int range." << endl;
		return -1;
	}
	else
	{
		cout << "Sum of two numbers is: " << inA + inB << endl;
	}
	
	return 0;
}