#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	int i = 0;
	while (i < 100)
	{
		system("cls");
		for (int x = 0; x < i; x++)
		{
			cout << "...";
		}
		i++;
	}
	return 0;
}