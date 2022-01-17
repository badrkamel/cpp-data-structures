// Doubly Linked list implementation in C++

#include <iostream>
using namespace std;

// Creating a node
class Node {
	public:
	int value;
	Node* next;
	Node* prev;
};

int main() {
	Node* head;
	Node* one = NULL;
	Node* two = NULL;
	Node* three = NULL;

	// allocate 3 nodes in the heap
	one = new Node();
	two = new Node();
	three = new Node();

	// Assign value values
	one->value = 1;
	two->value = 2;
	three->value = 3;

	// Connect nodes
	one->next = two;
	one->prev = NULL;

	two->next = three;
	two->prev = one;

	three->next = NULL;
	three->prev = two;

	// print the linked list value
	head = one;
	while (head != NULL) {
		cout << head->value <<"\t";
		head = head->next;
	}
	cout << endl;

	head = one;
	while (head != NULL) {
		if (head->prev == NULL) {
			cout << head->value << " prev: 0\t";
			head = head->next;
		} 
		cout << head->value << " prev:" << head->prev->value  <<"\t";
		head = head->next;
	}

	cout << endl;
}
