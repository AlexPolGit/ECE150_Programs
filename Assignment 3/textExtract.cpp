#include <iostream>

using namespace std;

int main()
{
	char word[101] = {0};
	char wordX[101] = {0};
	int s = 0;
	int e = 0;
	
	cout << "Please input a word: ";
	cin >> word;
	cout << "Please input the starting index: ";
	cin >> s;
	cout << "Please input the ending index: ";
	cin >> e;
	
	if (s < 0 || s > 100 || e < 0 || e > 100 || s > e)
	{
		cerr << "Error: Illegal end or start index(es)." << endl;
	}
	
	if (s == e)
	{
		wordX[0] = word[s];
	}
	else
	{
		int x = 0;
		for(int i = s; i <= e; i++)
		{
			wordX[x] = word[i];
			x++;
		}
	}
	
	cout << "The extracted word is: " << wordX << endl;

	return 0;
}