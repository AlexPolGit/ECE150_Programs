#include <iostream>

using namespace std;

int add(int* a, int* b)
{
	return *a + *b;
}

int main()
{
	int x = 10;
	int* y = &x;
	
	char a[] = "WORDS YAY";
	char* b = a;
	
	cout << "x: " << x << endl;
	cout << "y: " << *y << endl;
	
	cout << "a: " << a << endl;
	for (int i = 0; i < 9; i++)
	{
		cout << "b " << i << ": " << *(b+i) << endl;
	}
	
	int num1 = 0;
	int num2 = 0;
	
	cout << "Enter a number: ";
	cin >> num1;
	cout << "Enter another number: ";
	cin >> num2;
	
	cout << "These sum to: " << add(&num1, &num2) << endl;
	
	return 0;
}