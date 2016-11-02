#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	int rotations = 0;
	char marquee[60] = {};

	cout << "Enter number of rotations: ";
	cin >> rotations;
	
	char next = cin.get();
	if (!cin.good())
	{
		cerr << "Error: bad input." << endl;
		return -1;
	}
	else if (next != ' ' && next != '\n' && next != '\t')
	{
		cerr << "Error: non-integer entered." << endl;
		return -1;
	}

	marquee[0] = '!';
	marquee[1] = 'E';
	marquee[2] = 'C';
	marquee[3] = 'E';
	marquee[4] = '1';
	marquee[5] = '5';
	marquee[6] = '0';
	marquee[7] = '!';
	
	for (int i = 8; i < 60; i++)
	{
		marquee[i] = ' ';
	}
	
	cout << "============================================================" << endl;
	for (int k = 0; k< 60; k++)
	{
		cout << marquee[k];
	}
	cout << endl;
	cout << "============================================================" << endl;
	
	char temp = 0;
	
	for (int i = 0; i < rotations; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			system("cls");
			cout << "============================================================" << endl;
			
			temp = marquee[59];
			for (int k = 59; k > 0; k--)
			{
				marquee[k] = marquee[k-1];
			}
			marquee[0] = temp;
			for (int k = 0; k< 60; k++)
			{
				cout << marquee[k];
			}
			cout << endl;
			cout << "============================================================" << endl;
			
			for (int x = 0; x < 1000000; x++)
			{
				x = (x + x / 2);
			}
		}		
	}
	
	return 0;
}