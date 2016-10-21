#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	char space = 'o';
	char funcline = 'X';
	char xline = '_';
	char yline = '|';
	
	int xAxisLength = 25;
	int yAxisLength = 25;
	char graph[xAxisLength][yAxisLength];
	
	int xCenter = xAxisLength / 2;
	int yCenter = yAxisLength / 2;
	
	for (int i = 0; i < yAxisLength; i++)
	{
		for (int j = 0; j < xAxisLength; j++)
		{
			graph[i][j] = space;
		}
	}
	
	for (int a = 0; a < yAxisLength; a++)
	{
		graph[a][yCenter] = yline;
	}
	
	for (int b = 0; b < yAxisLength; b++)
	{
		graph[xCenter][b] = xline;
	}
	
	int x = 0;
	int fx = 0;
	int start = 0;
	int stop;
	
	cout << "Start: ";
	cin >> start;
	cout << "Stop: ";
	cin >> stop;
	cout << endl;
	
	for (int i = 0; i < xAxisLength; i++)
	{
		fx = pow(x, 2);
		graph[x - xCenter][x - yCenter] = funcline;
		x++;
	}
	
	for (int i = 0; i < yAxisLength; i++)
	{
		for (int j = 0; j < xAxisLength; j++)
		{
			cout << graph[i][j];
		}
		cout << endl;
	}
	
	cout << endl;
	
	return 0;
}