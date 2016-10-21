#include <iostream>

using namespace std;

int main()
{
	char input[101] = {0};
	cout << "Enter text without whitespace: ";
	cin >> input;

	// check for input length !> 100
	
	int l = 0;
	int i = 0;
	
	while (input[i] != '\0')
	{
		l++;
		i++;
	}
	
	if (l > 100)
	{
		cerr << "Error: text longer than 100 characters!" << endl;
		return -1;
	}
	
	cout << "The length of the entered text is: " << l << endl;

	return 0;
}