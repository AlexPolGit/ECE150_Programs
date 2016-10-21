#include <iostream>
#include <iomanip>

using namespace std;

int factorial(int n)
{
	if (n == 1 || n == 0)
	{
		return 1;
	}
	else
	{
		return n * factorial(n - 1);
	}
}

int main()
{
	int x = 0;
	float e = 0;
	cout << "Please input the degree: ";
	cin >> x;
	char next = cin.get();
	
	if (!cin.good())
	{
		cerr << "Error:InvalidInput.Program Terminated." << endl;
		return -1;
	}
	else if (next != ' ' && next != '\n' && next != '\t')
	{
		cerr << "Error:InvalidInput.Program Terminated." << endl;
		return -1;
	}
	else if (x < 0)
	{
		cerr << "Error:InvalidInput.Program Terminated." << endl;
		return -1;
	}
	else if (x > 14)
	{
		cerr << "Error:InvalidInput.Program Terminated.." << endl;
		return -1;
	}

	for (int k = 0; k <= x; k++)
	{
		e += 1.0 / factorial(k);
	}
	
	cout << fixed << setprecision(10) << e << endl;
	
	return 0;
}