#include <iostream>

using namespace std;

int main()
{
	int a;
	int b;
	unsigned int c;
	
	cout << "Enter three integer numbers (each separated by a space): ";
	cin >> a;
	cin >> b;
	cin >> c;
	
	cout << "A + B = " << a + b << endl;
	cout << "B + C = " << b + c << endl;
	
	return 0;
}