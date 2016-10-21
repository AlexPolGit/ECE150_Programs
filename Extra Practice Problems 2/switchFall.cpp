#include <iostream>

using namespace std;

int main()
{
	char in = ' ';
	cout << "Please input a valid character: ";
	cin >> in;
	char next = cin.get();
	
	if (!cin.good())
	{
		cerr << "Error: invalid input." << endl;
		return -1;
	}
	else if (next != ' ' && next != '\n' && next != '\t')
	{
		cerr << "Error: invalid input." << endl;
		return -1;
	}
	else if (in < 'A' || in > 'D')
	{
		cerr << "Error: invalid input." << endl;
		return -1;
	}
	
	for (int i = 0; i < 'E' - in; i++)
	{
		for (int j = in + i; j < 'E'; j++)
		{
			cout << (char)j << " ";
		}
		cout << endl;
	}
	
	return 0;
}