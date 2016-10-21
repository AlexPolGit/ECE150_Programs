#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int num;
	int pos;
	//int toPrint;
	int intSize = sizeof(int) * 8;
	//char numBin[sizeof(int) * 8];
	
	cout << "Enter two integer numbers (each separated by a space): ";
	cin >> num;
	cin >> pos;
	
	int ans = num << (31 - pos);
	ans >> 31;
	
	cout << "The value of Bit " << pos << " is " << ans << endl;
	
	/*
	int x = 0;
	while (true)
	{
		if (num == 1)
		{
			numBin[x] = '1';
			x++;
			break;
		}
		else if (num%2 == 1)
		{
			numBin[x] = '1';
		}
		else if (num%2 == 0)
		{
			numBin[x] = '0';
		}		
		num = (int)(num / 2);
		x++;
	}

	for (int i = 0; i < (int)(x / 2); i++)
	{
		char temp = numBin[i];
		numBin[i] = numBin[x - 1 - i];
		numBin[x - 1 - i] = temp;
		//cout << numBin << endl;
	}
	
	if (pos < x && pos >= 0)
	{
		cout << "The value of Bit " << pos << " is " << numBin[x - pos - 1] << endl;
	}
	else
	{
		cout << "The value of Bit " << pos << " is 0" << endl;
	}
	*/
	
	
	return 0;
}