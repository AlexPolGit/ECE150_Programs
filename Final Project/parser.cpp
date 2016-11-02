#include <iostream>
#include <fstream>

using namespace std;

ifstream fin;
ofstream fout;

const int maxNumOfWords = 1000;
const int maxWordLength = 25;

char words[maxNumOfWords][maxWordLength] = {{0}, {0}};
int currWord, currLetter, numOfInst, longestWord, currWordLength = 0;
int opcodeLengths[25];

int numASMInst, numLoadStore, numALU, numCompJmup = 0;

bool wordAfterSpace = false;
bool incrInst = false;
bool currOnOp = true;

void readNextChar()
{
	char c;
	fin >> noskipws >> c;
	switch(c)
	{
		case ' ':
		{
			cout << "Read a space." << endl;
			currWordLength = 0;
			
			if (wordAfterSpace)
			{
				currWord++;
				currLetter = 0;
				wordAfterSpace = false;
			}
			
			break;
		}
		case '\t':
		{
			cout << "Read a tab." << endl;
			currWordLength = 0;
			
			if (wordAfterSpace)
			{
				currWord++;
				currLetter = 0;
				wordAfterSpace = false;
			}
			
			break;
		}
		case '\n':
		{
			cout << "Read a newline." << endl;
			currWordLength = 0;
			if (incrInst)
			{
				numOfInst++;
				cout << "INCREASED INSTRUCTION COUNT" << endl;
				incrInst = false;
			}
			
			if (!currOnOp)
			{
				cout << "NO LONGER READING A COMMENT" << endl;
			}
			currOnOp = true;
			
			if (wordAfterSpace)
			{
				currWord++;
				currLetter = 0;
				wordAfterSpace = false;
			}
			
			break;
		}
		case '#':
		{
			cout << "CURRENTLY READING COMMENT." << endl;
			currOnOp = false;
			if (incrInst)
			{
				numOfInst++;
				cout << "INCREASED INSTRUCTION COUNT" << endl;
				incrInst = false;
			}
			break;
		}
		default:
		{
			if (currOnOp)
			{
				cout << "Read: " << c << endl;
				currWordLength++;
				if (currWordLength > longestWord)
				{
					longestWord = currWordLength;
				}
				
				words[currWord][currLetter] = c;
				currLetter++;
				wordAfterSpace = true;
				incrInst = true;
			}	
			break;
		}
	}
}

void checkInstructionValidity()
{
	const int n = numOfInst;
	const int l = longestWord;
	
	cout << "Num of instr: " << n << endl;
	cout << "Longest word: " << l << endl;
	
	int OPCODE[n];
}

int main()
{
	fin.open("asm_code/addTwo.asm");
	fout.open("asm_output.txt");
	
	while (!fin.eof())
	{
		readNextChar();
	}
	cout << "Reached end of file." << endl;
	
	int numOfWords = 0;
	for (int i = 0; i < maxNumOfWords; i++)
	{
		if (words[i][0] != ' ' && words[i][0] != '\n' && words[i][0] != '\t' && words[i][0] != 0)
		{
			numOfWords++;
		}
	}
	
	cout << "Num of words: " << numOfWords << endl;
	
	checkInstructionValidity();
	
	cout << "Total number of assembly instructions: " << numASMInst << endl;
	cout << "Number of Load/Store: " << numLoadStore << endl;
	cout << "Number of ALU: " << numALU << endl;
	cout << "Number of Compare/Jump: " << numCompJmup << endl;
	
	fin.close();
	fout.close();
	
	return 0;
}