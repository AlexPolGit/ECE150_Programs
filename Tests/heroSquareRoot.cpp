#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double n = 0;
	cin >> n;
	double guess = n / 2;

	double pctDiff = 1.79769e+308;
	double lastGuess = guess;

    while (abs(pctDiff) >= 0.01)
    {                        
        double r = n / guess;
        guess = (guess + r) / 2;
        pctDiff = ((guess-lastGuess)/lastGuess);
        lastGuess = guess;
        cout << guess << endl;
    }
	
	return 0;
}