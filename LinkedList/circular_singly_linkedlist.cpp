#include <iostream>

struct Node {
	int val;
	Node *next = nullptr;

	Node (int x) : val(x) {}
};

class CircularSinglyLinkedList {

	Node *head = nullptr;
	Node *rear = nullptr;
	public:
	// add node
	void insert_first(int);       // O(1)
	void insert_before(int,int);  // O(n)
	void append(int);             // O(1)

	// delete node
	void del(int);                // O(n)
	void delete_front();          // O(1)
	void delete_back();           // O(n)

	// display
	void print();
};

int main() {

	std::cout << "Circular Singly LinkedList\n";

	CircularSinglyLinkedList list;

	list.insert_first(20);
	list.insert_first(40);

	list.print();

	list.insert_before(20, 30);
	list.print();

	list.append(10);
	list.print();

	list.del(30);
	list.print();

	list.delete_back();
	list.print();

	list.delete_front();
	list.print();

	list.insert_before(20, 40);
	list.insert_before(20, 30);
	list.append(10);
	list.print();
}


void CircularSinglyLinkedList::insert_first(int val) {

	Node *node = new Node(val);
	if (!head) {
		head = rear = node->next = node;
	} 
	else {
		node->next = head;
		head = node;
		rear->next = head;
	}
}

void CircularSinglyLinkedList::insert_before(int item, int val) {

	if (!head)
		return;
	if (head->val == item){
		insert_first(val);
	} else {

		Node *node_before = head;

		while (node_before->next != rear && node_before->next->val != item) {
			node_before = node_before->next;
		}

		if (node_before->next->val == item) {
			Node *node = new Node(val);
			node->next = node_before->next;
			node_before->next = node;
		}
	}
}

void CircularSinglyLinkedList::append(int val) {

	Node *node = new Node(val);

	rear->next = node;
	rear = node;
	rear->next = head;
}

void CircularSinglyLinkedList::del(int item) {
	if (!head)
		return;

	if (head->val == item) {
		delete_front();
	} else {

		Node *prev = head;
		while (prev->next->val != item) {
			prev = prev->next;
		}

		if (prev->next->val == item) {
			Node *temp = prev->next;
			prev->next = prev->next->next;
			delete temp;
		}
	}
}

void CircularSinglyLinkedList::delete_front() {
	if (!head)
		return;

	Node *temp = head;
	head = head->next;
	rear->next = head;
	delete temp;
}

void CircularSinglyLinkedList::delete_back() {
	if (!head)
		return;

	if (head == rear)
		delete_front();
	else {
		Node *prev = head;

		while (prev->next != rear)
			prev = prev->next;

		Node *temp = rear;
		rear = prev;
		rear->next = head;
		delete temp;
	}
}

void CircularSinglyLinkedList::print() {
	Node *temp = head;
	while (temp != rear) {
		std::cout << temp->val << " -> ";
		temp = temp->next;
	}
	std::cout << temp->val << " -> ";
	std::cout << "NULL\n";
}
