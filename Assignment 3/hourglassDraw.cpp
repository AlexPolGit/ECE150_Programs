#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	
	cout << "Please enter the base/height (odd number) of the hour-glass: ";
	cin >> n;
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
	else if (n % 2 == 0)
	{
		cerr << "Error: Input must be odd!" << endl;
		return -1;
	}
	else if (n < 0)
	{
		cerr << "Error: Input must positive!" << endl;
		return -1;
	}
	
	int x = 0;
	
	for (int i = 0; i < (n / 2) + 1; i++)
	{
		for (int j = 0; j < n - x; j++)
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
	x -= 2;
	for (int i = 0; i < (n / 2); i++)
	{
		for (int j = 0; j < n - x; j++)
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
		x--;
	}
	
	return 0;
}