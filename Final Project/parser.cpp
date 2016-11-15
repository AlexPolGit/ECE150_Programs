#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

ifstream fin;

const int maxNumOfWords = 1000;
const int maxWordLength = 25;

char words[maxNumOfWords][maxWordLength] = {{0}, {0}};

int currWord, currLetter, numOfInst,
	numOfWords, longestWord, currWordLength,
	numLoadStore, numALU, numCompJump = 0;

bool wordAfterSpace = false;
bool incrInst = false;
bool currOnOp = true;

bool isEqual(char* word, char* toCompare, int* len)
{	
	for (int i = 0; i < *len; i++)
	{
		if (*(word + i) != *(toCompare + i))
		{
			return false;
		}
	}
	
	return true;
}

bool isInteger(char* word, int* len)
{
	for (int i = 0; i < *len; i++)
	{
		if (((int)word[i] < 47 || (int)word[i] > 57) && (int)word[i] != (int)',')
		{
			return false;
		}
	}
	
	return true;
}

bool isRegister(char* word, int* len)
{
	if (word[0] != 'R')
	{
		return false;
	}
	else
	{
		for (int i = 1; i < *len; i++)
		{
			if (((int)word[i] < 47 || (int)word[i] > 57) && (int)word[i] != (int)',')
			{
				return false;
			}
		}	
	}
	
	return true;
}

char OPCODES[][6] = {"Code:", "Data:", "LD", "LDi", "SD", "SDi", "ADD", "ADDi", "SUB", "SUBi", "MUL", "MULi", "DIV", "DIVi", "JMP", "JZ", "JZN", "JGZ", "JGEZ", "JLZ", "JLEZ"};
int numOperands[] = {1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 1, 2, 2, 2, 2, 2, 2};
int numOPTypes = 19;

bool isOpcode(char* word, int* len)
{
	for (int i = 0; i < numOPTypes; i++)
	{
		if (isEqual(word, (OPCODES[i]), len))
		{
			return true;
		}
	}
	
	return false;
}

bool isJumpPoint(char* word, int* len)
{
	if (*(word) == '[' && *(word + (*len - 1)) == ']')
	{
		return true;
	}
	
	return false;
}

int getNumOperands(char* word, int* len)
{
	for (int i = 0; i < numOPTypes; i++)
	{
		if (isEqual(word, (OPCODES[i]), len))
		{
			return numOperands[i];
		}
	}
	
	return 0;
}

void whitespaceCase()
{
	////cout << "Read a space or tab." << endl;
	currWordLength = 0;

	if (wordAfterSpace)
	{	
		currWord++;
		currLetter = 0;
				
		wordAfterSpace = false;
	}
}

void readNextChar()
{
	char c;
	fin >> noskipws >> c;
	switch(c)
	{
		case ' ':
		case '\t':
		{
			whitespaceCase();
			
			break;
		}
		case '\n':
		{
			////cout << "Read a newline." << endl;
			currWordLength = 0;
			if (incrInst)
			{
				numOfInst++;
				////cout << "INCREASED INSTRUCTION COUNT" << endl;
				incrInst = false;
			}
			
			if (!currOnOp)
			{
				////cout << "NO LONGER READING A COMMENT" << endl;
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
			////cout << "CURRENTLY READING COMMENT." << endl;
			currOnOp = false;
			if (incrInst)
			{
				numOfInst++;
				////cout << "INCREASED INSTRUCTION COUNT" << endl;
				incrInst = false;
			}
			break;
		}
		default:
		{
			if (currOnOp)
			{
				////cout << "Read: " << c << endl;
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

int main(int argc, char* argv[])
{
	fin.open(*(argv + 1));

	while (!fin.eof())
	{
		readNextChar();
	}
	
	////cout << "Reached end of file." << endl << "--------------------------------------------------" << endl;
	
	for (int i = 0; i < maxNumOfWords; i++)
	{
		if (words[i][0] != ' ' && words[i][0] != '\n' && words[i][0] != '\t' && words[i][0] != 0)
		{
			numOfWords++;
		}
	}

	//const int n = numOfWords;
	//const int l = longestWord;
	
	int* wordLengths = new int[numOfWords];
	
	for (int i = 0; i < numOfWords; i++)
	{
		wordLengths[i] = 0;
		for (int j = 0; j < longestWord; j++)
		{
			if (words[i][j] == 0)
			{
				break;
			}
			else
			{
				wordLengths[i]++;
			}
		}
		////cout << "Length of word  (" << words[i] << ")" << (i+1) << ": " << wordLengths[i] << endl;
	}

	char ops[sizeof(words)][longestWord];

	////cout << endl << "Num of words: " << numOfWords << endl;
	////cout << "Num of instr: " << numOfInst << endl;
	////cout << "Longest word: " << longestWord << endl << endl;

	for (int i = 0; i < numOfWords; i++)
	{
		for (int j = 0; j < wordLengths[i]; j++)
		{
			ops[i][j] = words[i][j];
			if (words[i][j] == ':')
			{
				break;
			}
		}
		
		////cout << "Word " << i << ": " << ops[i] << endl;
	}
	
	////cout << "--------------------------------------------------" << endl;

	int word = 0;
	int x = 0;
	int line = 1;

	while (x < numOfWords)
	{
		//cout << x << ": " << endl;
		//cout << "Line: " << line << endl;
		//cout << ">>>>> Found '" << ops[x] << "'" << endl;
		//cout << "Legal number of operands: " << getNumOperands(ops[x], wordLengths + x) << endl;
		
		if (isEqual(ops[x], (char*)"Code:", wordLengths + x) || isEqual(ops[x], (char*)"Data:", wordLengths + x))
		{
			//cout << "Expected: 1 integer." << endl;
			if (isInteger(ops[x+1], wordLengths + x + 1))
			{
				//cout << ">>>>> Found Integer After, VALID!" << endl;
				x++;
			}
			else
			{
				//cerr << "Error on line " << line << ": ";
			}

			numLoadStore++;

		}
		else if (isEqual(ops[x], (char*)"LD:", wordLengths + x) || isEqual(ops[x], (char*)"SD:", wordLengths + x))
		{
			//cout << "Expected: 2 registers or integers." << endl;
			for (int i = 1; i < 3; i ++)
			{
				if (isInteger(ops[x+i], wordLengths + x + i) || isRegister(ops[x+i], wordLengths + x + i))
				{
					
					//cout << ">>>>> Found Register After, VALID!" << endl;
				}
				else
				{
					
					//cerr << "Error: Didn't Find Register After, INVALID!" << endl;
				}
			}
			
			x += 2;
			numLoadStore++;
		}
		else if (isEqual(ops[x], (char*)"LDi:", wordLengths + x))
		{
			//cout << "Expected: 1 integer then 1 register." << endl;
			
			if (isInteger(ops[x+1], wordLengths + x + 1))
			{
				//cout << ">>>>> Found Integer After, VALID!" << endl;
			}
			else
			{
				//cerr << "Error: Didn't Find Integer After, INVALID!" << endl;
			}
			
			if (isRegister(ops[x+2], wordLengths + x + 2))
			{
				//cout << ">>>>> Found Register After, VALID!" << endl;
			}
			else
			{
				//cerr << "Error: Didn't Find Register After, INVALID!" << endl;
			}
			
			x += 2;
			numLoadStore++;
		}
		else if (isEqual(ops[x], (char*)"SDi:", wordLengths + x))
		{
			//cout << "Expected: 1 integer then 1 register or integer." << endl;
			
			if (isInteger(ops[x+1], wordLengths + x + 1))
			{
				//cout << ">>>>> Found Integer After, VALID!" << endl;
			}
			else
			{
				//cerr << "Error: Didn't Find Integer After, INVALID!" << endl;
			}
			
			if (isInteger(ops[x+2], wordLengths + x + 2) || isRegister(ops[x+2], wordLengths + x + 2))
			{
				//cout << ">>>>> Found Integer or Register After, VALID!" << endl;
			}
			else
			{
				//cerr << "Error: Didn't Find Integer or Register After, INVALID!" << endl;
			}
			
			x += 2;
			numLoadStore++;
		}
		else if (isEqual(ops[x], (char*)"ADD:", wordLengths + x) || isEqual(ops[x], (char*)"SUB:", wordLengths + x) ||
				 isEqual(ops[x], (char*)"MUL:", wordLengths + x) || isEqual(ops[x], (char*)"DIV:", wordLengths + x))
		{
			//cout << "Expected: 3 registers." << endl;
			
			for (int i = 1; i < 4; i ++)
			{
				if (isRegister(ops[x+i], wordLengths + x + i))
				{
					//cout << ">>>>> Found Register After, VALID!" << endl;
				}
				else
				{
					//cerr << "Error: Didn't Find Register After, INVALID!" << endl;
				}
			}
			
			numALU++;
			x += 3;
		}
		else if (isEqual(ops[x], (char*)"ADDi:", wordLengths + x) || isEqual(ops[x], (char*)"SUBi:", wordLengths + x) ||
				 isEqual(ops[x], (char*)"MULi:", wordLengths + x)	|| isEqual(ops[x], (char*)"DIVi:", wordLengths + x))
		{
			//cout << "Expected: integer, then register, then integer." << endl;
			
			if (isRegister(ops[x+1], wordLengths + x + 1))
			{
				//cout << ">>>>> Found Register After, VALID!" << endl;
			}
			else
			{
				//cerr << "Error: Didn't Find Register After, INVALID!" << endl;
			}
			if (isInteger(ops[x+2], wordLengths + x + 2))
			{
				//cout << ">>>>> Found Register After, VALID!" << endl;
			}
			else
			{
				//cerr << "Error: Didn't Find Register After, INVALID!" << endl;
			}
			if (isRegister(ops[x+3], wordLengths + x + 3))
			{
				//cout << ">>>>> Found Register After, VALID!" << endl;
			}
			else
			{
				//cerr << "Error: Didn't Find Register After, INVALID!" << endl;
			}
			
			numALU++;
			x += 3;
		}
		else if (isEqual(ops[x], (char*)"JMP:", wordLengths + x))
		{
			//cout << "Expected: jump point or integer." << endl;
			
			if (isInteger(ops[x+1], wordLengths + x + 1) || isJumpPoint(ops[x+1], wordLengths + x + 1))
			{
				//cout << ">>>>> Found Integer or Jump Point After, VALID!" << endl;
			}
			else
			{
				//cerr << "Error: Didn't Find Integer or Jump Point After, INVALID!" << endl;
			}
			
			x++;
			numCompJump++;
		}
		else if (isEqual(ops[x], (char*)"JZ:", wordLengths + x) || isEqual(ops[x], (char*)"JNZ:", wordLengths + x) ||
				isEqual(ops[x], (char*)"JGZ:", wordLengths + x) || isEqual(ops[x], (char*)"JGEZ:", wordLengths + x) ||
				isEqual(ops[x], (char*)"JLZ:", wordLengths + x) || isEqual(ops[x], (char*)"JLEZ:", wordLengths + x))
		{	
			//cout << "Expected: register or integer, then register, integer or jump point." << endl;
	
			if (isInteger(ops[x+1], wordLengths + x + 1) || isRegister(ops[x+1], wordLengths + x + 1))
			{
				//cout << ">>>>> Found Register or Integer After, VALID!" << endl;
			}
			else
			{
				//cerr << "Error: Didn't Find Integer After, INVALID!" << endl;
			}
			if (isInteger(ops[x+2], wordLengths + x + 2) || isRegister(ops[x+2], wordLengths + x + 2) || isJumpPoint(ops[x+2], wordLengths + x + 2))
			{
				//cout << ">>>>> Found Register, Integer or Jump Point After, VALID!" << endl;
			}
			else
			{
				//cerr << "Error: Didn't Find Register, Integer or Jump Point, INVALID!" << endl;
			}
			
			x += 2;
			numCompJump++;
		}
		else
		{
			bool good = false;
			for (int i = 0; i < longestWord; i++)
			{
				if (ops[x][i] == ':')
				{
					//cout << ">>>>> Found Jump Point!" << endl;
					numOfInst--;
					good = true;
				}
				
				if (good)
				{
					break;
				}
			}
		}
		x++;
		line++;
	}
	
	//cout << "--------------------------------------------------" << endl;
	cout << "Total number of assembly instructions: " << numOfInst << endl;
	cout << "Number of Load/Store: " << numLoadStore << endl;
	cout << "Number of ALU: " << numALU << endl;
	cout << "Number of Compare/Jump: " << numCompJump << endl;
	
	fin.close();

	return 0;
}