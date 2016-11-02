#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	for (int i = 0; i < 60; i++)
	{
		system("cls");
		cout << "============================================================" << endl;
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}
		cout << "O" << endl;
		cout << "============================================================" << endl;
		
		for (int k = 0; k < 1000000; k++)
		{
			k = (k + k / 2);
		}	
	}
	
	return 0;
}