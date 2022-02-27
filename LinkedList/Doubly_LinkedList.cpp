// Doubly Linked list implementation in C++

#include <iostream>

struct Node {
	int val;

	Node *next = nullptr;
	Node *prev = nullptr;

	Node (int x) : val(x) {}
};

class DoublyLinkedList {

	Node *head = nullptr;
	public:
		// Add node
	void insert_first(int);
	void insert_before(int,int);
	void append(int);

		// Delete node
	void del(int);
	void delete_front();
	void delete_back();

		// display
	void print();
};

int main() {
	DoublyLinkedList list;

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
}

void DoublyLinkedList::insert_first(int val) {
	Node *node = new Node(val);
	if (head) {
		head->prev = node;
		node->next = head;
	}	
	head = node;
}

void DoublyLinkedList::print() {
	Node *temp = head;
	while (temp) {
		std::cout << temp->val << " -> ";
		temp = temp->next;
	}
	std::cout << "NULL\n";
}

void DoublyLinkedList::insert_before(int item, int val) {
	if (!head)
		return;
	if (head->val == item)
		insert_first(val);
	else {
		Node *node_before = head;
		while (node_before->next && node_before->next->val != item)
			node_before = node_before->next;

		if (node_before->next && node_before->next->val == item) {
			Node *node = new Node(val);
			node->next = node_before->next;
			node_before->next = node;
		}
	}
}

void DoublyLinkedList::append(int val) {
	Node *last = head;

	while (last->next)
		last = last->next;

	Node *node = new Node(val);
	last->next = node;
}

void DoublyLinkedList::del(int val)  {

	if (!head)
		return;
	if (head->val == val)
		delete_front();
	else {

		Node *node_before = head;

		while (node_before->next && node_before->next->val != val)
			node_before = node_before->next;

		if (node_before->next && node_before->next->val == val) {
			Node *temp = node_before->next;
			node_before->next = node_before->next->next;
			delete temp;
		}
	}
}

void DoublyLinkedList::delete_front() {
	if (!head)
		return;

	Node *temp = head;
	head = head->next;
	delete temp;
}

void DoublyLinkedList::delete_back() {

	if (!head)
		return;
	if (!head->next)
		delete_front();
	else {
			
		Node *temp = head;

		while (temp->next && temp->next->next)
			temp = temp->next;

		Node *deleted = temp->next;
		temp->next = nullptr;
		delete deleted;
	}
}
