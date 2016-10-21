#include <iostream>

using namespace std;

int main()
{
	int wtw = 0;
	int sl = 0;
	int wts = 0;
	char next[3] = {0};
	
	cout << "Wall-to-wall dimension: ";
	cin >> wtw;
	next[0] = cin.get();
	cout << "Snake length: ";
	cin >> sl;
	next[1] = cin.get();
	cout << "Wall-to-snake tail distance: ";
	cin >> wts;
	next[2] = cin.get();
	
	if (!cin.good())
	{
		cerr << "Error: Invalid input." << endl;
		return -1;
	}
	else if (next[0] != ' ' && next[0] != '\n' && next[0] != '\t')
	{
		cerr << "Error: Invalid input." << endl;
		return -1;
	}
	else if (next[1] != ' ' && next[1] != '\n' && next[1] != '\t')
	{
		cerr << "Error: Invalid input." << endl;
		return -1;
	}
	else if (next[2] != ' ' && next[2] != '\n' && next[2] != '\t')
	{
		cerr << "Error: Invalid input." << endl;
		return -1;
	}
	
	if (sl > wtw - 2)
	{
		cerr << "Error: Bad snake length." << endl;
		return -1;
	}
	else if (wtw < 2)
	{
		cerr << "Error: Bad wall distance." << endl;
		return -1;
	}
	else if (wts < 0 || wts  > (wtw - 2 - sl))
	{
		cerr << "Error: Invalid wall to snake distance." << endl;
		return -1;
	}
	
	char scene[1000] = {0};
	
	scene[0] = '|';
	scene[wtw - 1] = '|';
	
	for (int i = 1; i < wts + 1; i++)
	{
		scene[i] = ' ';
	}
	if (sl > 0)
	{
		for (int j = wts + 1; j < wts + sl; j++)
		{
			scene[j] = '*';
		}
		scene[wts + sl] = 'O';
	}
	for (int k = wts + sl + 1; k < wtw - 1; k++)
	{
		scene[k] = ' ';
	}
	
	cout << scene << endl;
	/*
	for (int a = 0; a < 10; a++)
	{
		for (int b = 0; b < 10; b++)
		{
			if (b == 0)
			{
				cout << ' ';
			}
			else
			{
				cout << b;
			}
		}
	}
	cout << endl;
	*/
	return 0;
}