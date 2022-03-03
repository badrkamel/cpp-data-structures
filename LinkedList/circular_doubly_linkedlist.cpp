#include <iostream>

struct Node {
	int val;

	Node *next = nullptr;
	Node *prev = nullptr;

	Node () : val(0) {}
	Node (int x) : val(x) {}
};

class CircularDoublyLinkedList {

	Node *head = nullptr;
	Node *rear = nullptr;
	public:

		// Add node
	void insert_first(int);      // O(1)
	void insert_before(int,int);
	void append(int);            // O(1)

		// Delete node
	void del(int);
	void delete_front();         // O(1)
	void delete_back();          // O(1)

		// display
	void print();
};

int main() {

	std::cout << "Circular Doubly LinkedList\n";

	CircularDoublyLinkedList list;

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

	list.insert_first(30);
	list.insert_first(40);
	list.print();
}

void CircularDoublyLinkedList::insert_first(int val) {
	Node *node = new Node(val);

	if (!head) {
		head = rear = node->next = node->prev = node;
	} else {
		node->next = head;
		node->prev = rear;
		head->prev = node;
		rear->next = node;
		head = node;
	}
}

void CircularDoublyLinkedList::print() {
	Node *temp = head;
	std::cout << " <-> ";
	while (temp != rear) {
		std::cout << temp->val << " -> ";
		temp = temp->next;
	}
	std::cout << temp->val << " <->\n";
}

void CircularDoublyLinkedList::insert_before(int item, int val) {
	if (!head)
		return;

	if (head->val == item)
		insert_first(val);
	else {
		Node *node_before = head;

		while (node_before->next != rear && node_before->next->val != item)
			node_before = node_before->next;

		if (node_before->next->val == item) {
			Node *node = new Node(val);

			node->next = node_before->next;
			node_before->next->prev = node;
			node_before->next = node;
			node->prev = node_before;
		}
	}
}

void CircularDoublyLinkedList::append(int val) {
	
	if (!head)
		insert_first(val);
	else {
		Node *node = new Node(val);

		node->prev = rear;
		node->next = rear->next;
		rear->next= node;
		rear = node;
		head->prev = rear;
	}
}

void CircularDoublyLinkedList::del(int item) {
	if (!head)
		return;

	if (head->val == item)
		delete_front();
	else if (rear->val == item)
		delete_back();
	else {
		Node *node_before = head;

		while (node_before->next->next != rear && node_before->next->val != item)
			node_before=node_before->next;

		if (node_before->next->val == item) {
			Node *temp = node_before->next;
			
			node_before->next->next->prev = node_before;
			node_before->next = temp->next;

			delete temp;
		}
	}
}

void CircularDoublyLinkedList::delete_front() {
	if (!head)
		return;

	Node *temp = head;

	rear->next = head->next;
	head->next->prev = rear;
	head = head->next;

	delete temp;
}

void CircularDoublyLinkedList::delete_back() {
	if (!head)
		return;

	Node *temp = rear;

	rear = rear->prev;
	rear->next = head;
	head->prev = rear;

	delete temp;
}
