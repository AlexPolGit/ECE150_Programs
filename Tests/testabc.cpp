#include <iostream>

using namespace std;

int main()
{
	cout << "Enter a word to reverse: ";
	char word[100] = {0};
	cin >> word;
	int wordLength = 0;
	
	for (int i = 0; i < 100; i++)
	{
		if (word[i] != '\0')
		{
			wordLength++;
		}
		else
		{
			break;
		}
	}
	
	char newWord[wordLength] = {0};
	
	for (int i = 0; i < wordLength; i++)
	{
		newWord[i] = word[wordLength - 1 - i];
		cout << (i + 1) << ": " << newWord << endl;
	}
	
	//cout << "Reversed: " << newWord << endl;
	
	return 0;
}