#include <iostream>

using namespace std;

int main()
{
	int base = 0;
	int height = 0;
	
	cout << "Please enter an odd size for the base of the triangle: ";
	cin >> base;
	char next = cin.get();
	
	if (!cin.good())
	{
		cerr << "Error: Invalid Input." << endl;
		return -1;
	}
	else if (next != ' ' && next != '\n' && next != '\t')
	{
		cerr << "Error: Invalid Input." << endl;
		return -1;
	}
	else if (base % 2 == 0)
	{
		cerr << "Error: Base must be odd!" << endl;
		return -1;
	}
	else if (base < 0)
	{
		cerr << "Error: Base must positive!" << endl;
		return -1;
	}
	
	height = (base / 2) + 1;
	int x = 0;
	
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < base - x; j++)
		{
			if (j < x)
			{
				cout << ' ';
			}
			else
			{
				cout << '*';
			}	
		}
		cout << endl;
		x++;
	}
	
	return 0;
}