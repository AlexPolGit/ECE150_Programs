#include <iostream>

using namespace std;

struct Node
{
	Node* next;
	int payload;
};

int main()
{
	Node* head;
	Node* traverse;
	
	head = new Node;
	head -> payload = 725;
	
	traverse = new Node;
	traverse -> payload = 913;
	
	head -> next = traverse;
	
	traverse -> next = new Node;
	traverse -> next -> payload = 234;
	traverse = traverse -> next;
	
	traverse -> next = new Node;
	traverse -> next -> payload = 824;
	traverse = traverse -> next;

	return 0;
}