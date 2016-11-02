#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

using namespace std;

int main()
{
	int arr[100] = {0};
	
	for (int i = 0; i < 100; i++)
	{
		arr[i] = -1;
		
		while (arr[i] < 0 || arr[i] > 100)
		{
			arr[i] = abs(rand() % (i + 1) + (i - 1));
			
		}
		cout << i << ": " << arr[i] << endl;
	}
}