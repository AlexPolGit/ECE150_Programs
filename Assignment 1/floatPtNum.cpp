#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double a;
	double b;
	
	cout << setprecision(20) << fixed;
	cout << "Enter two numbers (each separated by a space): ";
	
	cin >> a;
	cin >> b;
	
	cout << "A/B = " << a / b;
	
	return 0;
}