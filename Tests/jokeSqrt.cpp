#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

using namespace std;

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

int main()
{
	double n = 0;
	cin >> n;
	
	double guess;
	
	while (true)
	{
		guess = fRand(0, n);
		if ((guess * guess) == n)
		{
			break;
		}
	}
	
	cout << guess << endl;
	
	return 0;
}