#include <iostream>
#include <iomanip>
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

int charsToInt(char* array)
{
	int out = 0;
	int x = 0;
	bool neg = false;

	if (*(array) == '-')
	{
		x++;
		neg = true;
	}
	
	while (true)
	{
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

float* getSlidingAverages(int volts[], int window, int numElements)
{
	float* ret = new float[numElements - window + 1];
	for (int i = 0; i < (numElements - window + 1); i++)
	{
		float sum = 0;
		//cout << "sum = ";
		for (int j = 0; j < window; j++)
		{
			//cout << volts[i + j] << " ";
			sum += volts[i + j];
		}
		*(ret + i) = (sum / window);
		//cout << " = " << *(ret + i) << endl;
	}
	
	return ret;
}

int slideAvg(int inputVoltages[], int sampleSize, int windowSize, float slidingAverage[])
{	
	return sampleSize - windowSize + 1;
}

void displayHistogram(int numElements, float array[])
{
	cout << "100V------105V------110V------115V------120V------125V------130V------135V------140V" << endl;
	int c = 0;
	
	for (int i = 0; i < numElements; i++)
	{
		if (array[i] < 100)
		{
			cout << "!" << endl;
		}
		else if (array[i] > 140)
		{
			cout << "#################################################################################+" << endl;
		}
		else
		{
			c = 2 * array[i] - 200;
			for (int j = 0; j < c + 1; j++)
			{
				cout << "#";
			}
			cout << endl;
		}
	}
}

void displayPreFilterHistogram(int numElements, int array[])
{
	cout << "100V------105V------110V------115V------120V------125V------130V------135V------140V" << endl;
	int c = 0;
	
	for (int i = 0; i < numElements; i++)
	{
		if (array[i] < 100)
		{
			cout << "!" << endl;
		}
		else if (array[i] > 140)
		{
			cout << "#################################################################################+" << endl;
		}
		else
		{
			c = 2 * array[i] - 200;
			for (int j = 0; j < c + 1; j++)
			{
				cout << "#";
			}
			cout << endl;
		}
	}
}

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		cerr << "Error: not enough input arguments." << endl;
		return -1;
	}
	else if (argc > 22)
	{
		cerr << "Error: too many inputs." << endl;
		return -1;
	}
	
	int windowSize = charsToInt(*(argv + 1));
	
	if (windowSize < 1)
	{
		cerr << "Error: Window size cannot less than one." << endl;
		return -1;
	}
	else if (windowSize > argc - 2)
	{
		cerr << "Error: Window size cannot be greater than number of arguments." << endl;
		return -1;
	}
	
	const int a = argc - 2;
	int* voltages = new int[a];
	int x = 0;
	
	for (int i = 2; i < argc; i++)
	{	
		voltages[x] = charsToInt(*(argv + i));
		//cout << "VOLT" << i - 1 << ": " << voltages[x] << endl;
		x++;
	}
	
	const int b = argc - windowSize + 1;
	float* slidingAverages = new float[b];
	
	//cout << "WIN: " << windowSize << endl;
	//cout << "ARG C: " << a << endl;
	
	for (int i = 0; i < argc - windowSize; i++)
	{
		slidingAverages[i] = *(getSlidingAverages(voltages, windowSize, a) + i);
		//cout << "AVG" << i + 1 << ": " << slidingAverages[i] << " (";
		slidingAverages[i] = floor(slidingAverages[i] * 2 + 0.5) / 2;
		//cout << slidingAverages[i] << ")" << endl;
	}
	
	displayPreFilterHistogram(argc - 2, voltages);
	cout << endl;
	displayHistogram(argc - windowSize - 1, slidingAverages);
	

	return 0;
}