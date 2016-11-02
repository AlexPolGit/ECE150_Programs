#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	cout << "Total args: " << argc - 1 << endl;
	cout << "Your arguments were: " << endl;
	
	for (int i = 1; i < argc; i++)
	{
		cout << i << ": " << argv[i] << endl;
	}
	
	return 0;
}