#include <iostream>

using namespace std;

int main()
{
	int *a;
	
	a = new int[10];
	
	for (int i = 0; i < 10; i++)
	cout << *(a + 1) << endl;
	
	/*
	while (true)
	{
		cin >> in;
		if (in != 'x')
		{
			a[i] = in;
			i++;
		}
		else
		{
			break;
		}
	}
	*/
	
	return 0;
}