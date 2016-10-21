#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	char input[4] = {};
	char codes[13] = {'k', 'n', 'R', 'O', 'Y', 'G', 'B', 'V', 'y', 'W', 'd', 'S', 'N'};
	
	double resistance = 0;
	double tolerance = 0;
	
	cout << "Enter the four resistor color codes: ";
	cin >> input;

	float bandValue[3] = {};
	
	for (int i = 0; i < 3; i++)
	{
		switch(input[i])
		{
			case ('k'):
			{
				bandValue[i] = 0;
				break;
			}
			case ('n'):
			{
				bandValue[i] = 1;
				break;
			}
			case ('R'):
			{
				bandValue[i] = 2;
				break;
			}
			case ('O'):
			{
				bandValue[i] = 3;
				break;
			}
			case ('Y'):
			{
				bandValue[i] = 4;
				break;
			}
			case ('G'):
			{
				bandValue[i] = 5;
				break;
			}
			case ('B'):
			{
				bandValue[i] = 6;
				break;
			}
			case ('V'):
			{
				bandValue[i] = 7;
				break;
			}
			case ('y'):
			{
				bandValue[i] = 8;
				break;
			}
			case ('W'):
			{
				bandValue[i] = 9;
				break;
			}
			case ('d'):
			{
				if (i == 2)
				{
					bandValue[i] = -1;
					break;
				}
				else
				{
					cerr << "Error: Invalid color code entered!" << endl;
					return -1;
				}
				
			}
			case ('S'):
			{
				if (i == 2)
				{
					bandValue[i] = -2;
					break;
				}
				else
				{
					cerr << "Error: Invalid color code entered!" << endl;
					return -1;
				}
			}
			default:
			{
				cerr << "Error: Invalid color code entered!" << endl;
				return -1;
			}
		}
	}
	
	float errorVal;
	
	switch(input[3])
		{
			case ('n'):
			{
				errorVal = 1;
				break;
			}
			case ('R'):
			{
				errorVal = 2;
				break;
			}
			case ('G'):
			{
				errorVal = 0.5;
				break;
			}
			case ('B'):
			{
				errorVal = 0.25;
				break;
			}
			case ('V'):
			{
				errorVal = 0.1;
				break;
			}
			case ('y'):
			{
				errorVal = 0.05;
				break;
			}
			case ('d'):
			{
				errorVal = 5;
				break;
			}
			case ('S'):
			{
				errorVal = 10;
				break;
			}
			case ('N'):
			{
				errorVal = 20;
				break;
			}
			default:
			{
				cerr << "Error: Invalid color code entered!" << endl;
				return -1;
			}
		}
	
	resistance = ((bandValue[0] * pow(10, bandValue[2] + 1)) + (bandValue[1] * pow(10, bandValue[2])));
	tolerance = (resistance / 100) * errorVal;
	
	cout << "Resistance is " << resistance << " ohms (+/-" << tolerance << " ohms tolerance)" << endl;
	
	return 0;
}