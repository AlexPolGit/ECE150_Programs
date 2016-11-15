#include <iostream>
#include <fstream>

using namespace std;

bool isEqual(char word[], char toCompare[], int len)
{	
	for (int i = 0; i < len; i++)
	{
		if (word[i] != toCompare[i])
		{
			return false;
		}
	}
	
	return true;
}

int main()
{
	char test[] = "abc13";
	char look[] = "abc123";
	
	if (isEqual(test, look, 6))
	{
		cout << "SUCCESS" << endl;
	}
	
	return 0;
}