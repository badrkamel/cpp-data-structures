#include <iostream>

using namespace std;

struct Node {
	int value;
	Node *next;

	Node (int data) {
		value = data;
		next = NULL;
	}
};

int main () {
	cout << "Queue (quick impl)\n";

    // Allocate the three nodes in the heap
    Node *one = new Node(10);
    Node *two = new Node(20);
    Node *three = new Node(30);

    // Connect nodes
    one->next = two;
    two->next = three;
    three->next = NULL;


    Node *front;
    Node *rear;

    front = one;
    rear = three;

    // enQueue
    Node *four = new Node(40);

    rear->next = four;
    rear = four;

    // deQueue
    Node *delptr = front;
    front = front->next;
    delete delptr;

    // display
    Node *temp = front;
    while (temp != NULL)
    {
        cout << "Node: " << temp->value << "\t";
        temp = temp->next;
    }
    cout << endl;
    
}
