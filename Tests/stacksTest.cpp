#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<string> s1;
	string x = "";
	
	while (true)
	{
		cin >> x;
		if (x != "x")
		{
			s1.push(x);
		}
		else
		{
			break;
		}
	}
	
	cout << "Size of stack: " << s1.size() << endl;
	
	for (int i = 0; i < 3; i++)
	{
		s1.pop();
		//cout << "Size of " << '"' << x << '"' << " is " << strlen(x) << endl;
	}
	
	return 0;
}