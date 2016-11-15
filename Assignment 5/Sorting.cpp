#include <iostream>
#include "Sorting.h"

using namespace std;

void bubbleSort(int numNames, char* firstName[], char* lastName[], int age[])
{
	for (int i = 0; i < numNames; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (stringCmp(*(lastName + i), *(lastName + j)) == 1)
			{
				stringSwap(*(lastName + i), *(lastName + j));
				stringSwap(*(firstName + i), *(firstName + j));
				
				int temp3 = age[i];
				age[i] = age[j];
				age[j] = temp3;
			}
			else if (stringCmp(*(lastName + i), *(lastName + j)) == 0)
			{
				if(stringCmp(*(firstName + i), *(firstName + j)) == 1)
				{
					stringSwap(*(lastName + i), *(lastName + j));
					stringSwap(*(firstName + i), *(firstName + j));
					
					int temp3 = age[i];
					age[i] = age[j];
					age[j] = temp3;
				}
				else if (stringCmp(*(firstName + i), *(firstName + j)) == 0)
				{
					if (age[i] < age[j])
					{
						stringSwap(*(lastName + i), *(lastName + j));
						stringSwap(*(firstName + i), *(firstName + j));
						
						int temp3 = age[i];
						age[i] = age[j];
						age[j] = temp3;
					}
				}
			}
		}
	}
}

void displayNames(int numNames, char* firstName[], char* lastName[], int age[])
{
	for (int i = 0; i < numNames; i++)
	{
		cout << *(firstName + i) << " " << *(lastName + i) << " " << age[i] << endl;
	}
}

int stringCmp(char str1[], char str2[])
{
	int x = 0;
	while (true)
	{
		if (str1[x] > str2[x])
		{
			return -1;
		}
		else if (str1[x] < str2[x])
		{
			return 1;
		}
		
		if (str1[x] == 0 || str2[x] == 0)
		{
			return 0;
		}
		x++;
	}
}

void stringSwap(char* &str1, char* &str2)
{
	char* temp = str1;
	str1 = str2;
	str2 = temp;
}