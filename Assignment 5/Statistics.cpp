#include <iostream>
#include <cmath>

using namespace std;

int power(int b, int p)
{
	if (p == 0)
	{
		return 1;
	}
	else
	{
		return b * power(b, p - 1);
	}
}

int charsToint(char* array)
{
	int out = 0;
	int x = 0;
	bool neg = false;

	if (*(array) == '-')
	{
		//cout << "NEGATIVE NUMBER" << endl;
		x++;
		neg = true;
	}
	
	while (true)
	{
		//cout << "X = " << x << endl;
		//cout << "DIG = " << *(array + x) << endl;
		if (*(array + x) >= '0' && *(array + x) <= '9')
		{
			x++;
		}
		else
		{
			return 0;
		}
		if (*(array + x) == 0)
		{
			break;
		}
	}
	
	int p = 0;
	int fin = -1;
	
	if (neg)
	{
		fin = 0;
	}
	
	for (int i = x - 1; i > fin; i--)
	{
		p = x - i - 1;
		//cout << "P = " << p << endl;
		//cout << "Pow: " << power(10, p) << endl;
		
		if (p > 8)
		{
			return 0;
		}
		
		out += ((int)(*(array + i)) - 48) * power(10, p);
	}
	
	if (neg)
	{
		return -out;
	}
	else
	{
		return out;
	}
}

int convertTointArray(int argc, char* argv[], int array[])
{
	return 0;
}

int findMax (int array[], int numElements)
{
	int max = array[0];
	for (int i = 0; i < numElements; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return max;
}

int findMin (int array[], int numElements)
{
	int min = array[0];
	for (int i = 0; i < numElements; i++)
	{
		if (array[i] < min)
		{
			min = array[i];
		}
	}
	return min;
}

float average (int array[], int numElements)
{
	float sum = 0;
	for (int i = 0; i < numElements; i++)
	{
		sum += array[i];
	}
	return (sum / numElements);
}

int charsToInts(char* from[], int* to, int n)
{
	for (int i = 0; i < n; i++)
	{
		//cout << "TRYING TO CONVERT: " << *(from + i + 1) << endl;
		*(to + i) = charsToint(*(from + i + 1));
		//cout << "GOT: " << *(to + i) << endl;
		
		if (*(to + i) == 0 && *(from + i + 1)[0] != '0')
		{
			cerr << "Error: Argument " << i + 1 << " is not an integer." << endl;
			return -1;
		}
	}
	return 0;
}

int main(int argc, char* argv[])
{
	const int n = argc - 1;
	int* numbers = new int[n];
	
	convertTointArray(argc, argv, numbers);

	if (n > 20)
	{
		cerr << "Error: too many input arguments; maximum 20 permitted." << endl;
		return -1;
	}
	else if (n < 1)
	{
		cerr << "Error: no arguments entered." << endl;
		return -1;
	}
	
	if (charsToInts(argv, numbers, n) == -1)
	{
		return -1;
	}
	
	cout << "Maximum: " << findMax(numbers, n) << endl;
	cout << "Minimum: " << findMin(numbers, n) << endl;
	cout << "Average: " << average(numbers, n) << endl;

	return 0;
}