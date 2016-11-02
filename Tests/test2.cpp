#include <iostream>

using namespace std;

int main()
{
	char word[15] = "Testing_word";
	char* letter = word;
	
	cout << "Word: " << word << endl;
	cout << "Address of word: " << &letter << endl;
	
	for (int i = 0; i < 15; i++)
	{
		cout << letter + i << endl;
	}
}