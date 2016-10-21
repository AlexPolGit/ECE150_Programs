#include <iostream>

using namespace std;

int main()
{
	char input[3] = {};
	int outputNum = 0;
	
	cout << "Enter three characters consecutively without space: ";
	cin >> input;
	
	outputNum = (1000000 * (int)input[0]) + (1000 * (int)input[1]) + (int)input[2];
	
	cout << "The corresponding passcode is: " << outputNum;
	
	return 0;
}