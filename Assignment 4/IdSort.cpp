#include <iostream>
#include <cmath>

using namespace std;

void bubbleSort(int id[])
{
	int swapcount = 0;
	
	for (int a = 0; a < 5; a++)
	{
		for (int b = 0; b < a; b++)
		{
			if (id[a] > id[b])
			{
				int temp = id[a];
				id[a] = id[b];
				id[b] = temp;
				
				swapcount++;
			}
		}
	}
	
	cout << "Sorted ID: ";
	
	for (int a = 0; a < 5; a++)
	{
		cout << id[a] << " ";
	}
	
	cout << endl << "Swap count: " << swapcount << endl;
}

int main()
{
	int id[6] = {};	
	
	cout << "Enter 5 ID: ";
	
	for (int i = 0; i < 5; i++)
	{
		cin >> id[i];
		
		char next = cin.get();
		
		if (!cin.good())
		{
			cerr << "Error: Invalid input." << endl;
			return -1;
		}
		else if (next != ' ' && next != '\n' && next != '\t')
		{
			
			cerr << "Error: Invalid input." << endl;
			return -1;
		}
		else if (id[i] < 10000000 || id[i] > 99999999)
		{
			cerr << "Error: Invalid ID." << endl;
			return -1;
		}
	}
	
	bubbleSort(id);
	
	cout << "Enter another input: ";
	
	int toAdd;
	cin >> toAdd;
		
	char next = cin.get();
		
	if (!cin.good())
	{
		cerr << "Error: Invalid comparison input." << endl;
		return -1;
	}
	else if (next != ' ' && next != '\n' && next != '\t')
	{
		cerr << "Error: Invalid comparison input." << endl;
		return -1;
	}
	else if (toAdd < 10000000 || toAdd > 99999999)
	{
		cerr << "Error: Invalid comparison ID." << endl;
		return -1;
	}
	
	for (int i = 0; i < 5; i++)
	{
		if (id[i] == toAdd)
		{
			cerr << "Error: This ID exists" << endl;
			return -1;
		}
	}
	
	id[5] = toAdd;
	
	for (int a = 0; a < 6; a++)
	{
		for (int b = 0; b < a; b++)
		{
			if (id[a] > id[b])
			{
				int temp = id[a];
				id[a] = id[b];
				id[b] = temp;
			}
		}
	}
	
	int pos = 0;
	
	cout << "Sorted ID: ";
	
	for (int i = 0; i < 6; i++)
	{
		if (id[i] == toAdd)
		{
			pos = i;
			break;
		}
	}
	
	cout << "The value " << toAdd << " is in position " << pos << endl;

	return 0;
}