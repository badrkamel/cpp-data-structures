#include <iostream>

using namespace std;

struct Node {
	int value;
	Node *next;

	Node (int v) {
		value = v;
		next = NULL;
	}
};

class Queue {
	Node *front, *rear;
	int CAPACITY, length;

public:
	Queue(int c) {
		CAPACITY = c;
		length = 0;
		front = rear = NULL;
	}

	void enqueue(int value) {
		Node *node = new Node(value);

		if (length<CAPACITY) {
			if (front==NULL) {
				front = node;
			} else {
				rear->next = node;
			}
			rear = node;
			rear->next = front;

		} else {
			cout << "Queue is full\n";
		}
	}

	int dequeue() {

		if (front==NULL) {
			cout << "Queue is empty!\n";
			return -1;
		}

		int value = front->value;
		if (front == rear) {
			delete front;
			front=rear=NULL;
		} else {
			Node *temp = front;
			front = front->next;
			rear->next = front;
			delete temp;
		}

		return value;
	}

	void display() {
		if (front==NULL) {
			cout << "Queue is empty!\n";
			return;
		}
		Node *temp = front;
		while (temp->next != front) {
			cout << temp->value << " ";
			temp=temp->next;
		}
		cout << temp->value << " ";
		cout << endl;
	}
};

int main () {
	cout << "Circulr Queue\n";

	Queue q(5);

	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);

	q.display();

	q.dequeue();

	q.display();

	q.dequeue();
	q.dequeue();
	q.dequeue();

	q.display();

}
