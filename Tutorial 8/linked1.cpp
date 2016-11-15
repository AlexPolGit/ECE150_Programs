#include <iostream>

using namespace std;

struct Node
{
	Node* next;
	int payload;
};

int main()
{
	Node my_first_node;
	Node my_second_node;
	Node my_third_node;
	
	my_first_node.payload = 123;
	my_second_node.payload = 987;
	my_third_node.payload = 0xDEADBEEF;
	
	cout << "My first node payload: " << my_first_node.payload << endl;
	cout << "My first node address: " << &my_first_node << endl;
	cout << "My second node payload: " << my_second_node.payload << endl;
	cout << "My second node address: " << &my_second_node << endl;
	cout << "My third node payload: " << my_third_node.payload << endl;
	cout << "My third node address: " << &my_third_node << endl;
	
	my_first_node.next = &my_second_node;
	my_second_node.next = &my_third_node;
	
	cout << "My first node next: " << my_first_node.next << endl;
	
	Node* traverse;
	
	traverse = &my_first_node;
	
	cout << (*traverse).payload << endl;
	cout << traverse -> payload << endl;
	
	traverse = traverse -> next;
	
	cout << traverse -> payload << endl;
	
	traverse = traverse -> next;
	
	cout << traverse -> payload << endl;

	return 0;
}