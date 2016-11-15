#include <iostream>

using namespace std;

struct LinkedIntegerList
{
	int item;
	LinkedIntegerList* connection;
};

LinkedIntegerList* finalElementofIntegerList(LinkedIntegerList* list)
{
	LinkedIntegerList* pointer;
	pointer = list;
	
	while(true)
	{	
		if (pointer == NULL)
		{
			break;
		}
		
		pointer = list -> connection;
	}
	
	return pointer;
}

void addToLinkedIntegerList(LinkedIntegerList* list, int toAdd)
{
	LinkedIntegerList newList;
	newList.item = toAdd;
	
	finalElementofIntegerList(list) -> connection = &newList;
}

void removeFromPosInLinkedIntegerList(LinkedIntegerList* list, int posToRemove)
{
	
}

void removeFirstInstanceFromLinkedIntegerList(LinkedIntegerList* list, int toRemove)
{
	
}

void sortLinkedIntegerList(LinkedIntegerList* list)
{
	
}

void sortBackwardsLinkedIntegerList(LinkedIntegerList* list)
{
	
}

void printList(LinkedIntegerList* list)
{
	LinkedIntegerList* pointer;
	int x = 1;
	pointer = list;
	
	while(true)
	{
		cout << x << ": " << pointer -> item << endl;
		
		if (pointer == NULL)
		{
			break;
		}
		
		pointer = list -> connection;
		x++;
	}
}

int main()
{
	
	return 0;
}