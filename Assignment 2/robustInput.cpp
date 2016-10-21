#include <iostream>

using namespace std;

int main()
{
	int input;
	
	cout << "Enter an integer: ";
	cin >> input;
	
	char next = cin.get();
	
	if (cin.fail())
	{
		cerr << "Error: Invalid input. Not a number." << endl;
		return -1;
	}
	else if (next != ' ' && next != '\n' && next != '\t')
	{
		cerr << "Error: Invalid input. Not an integer." << endl;
		return -1;
	}
	else
	{
		cout << "The integer that you have entered is " << input << endl;
	}
	
	return 0;
}