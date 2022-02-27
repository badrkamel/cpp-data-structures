#include <iostream>

struct Node {
	int val;
	Node *next = nullptr;

	Node (int x) : val(x) {}
};

class SinglyLinkedList {
	Node *head = nullptr;

	public:
	// add node
	void insert_first(int);
	void insert_before(int,int);
	void append(int);

	// delete node
	void del(int);
	void delete_front();
	void delete_back();

	// display
	void print();
};

int main() {

	std::cout << "Singly LinkedList\n";

	SinglyLinkedList list;

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


void SinglyLinkedList::insert_first(int val) {

	Node *node = new Node(val);
	node->next = head;
	head = node;
}

void SinglyLinkedList::insert_before(int item, int val) {

	if (!head)
		return;
	if (head->val == item){
		insert_first(val);
	} else {

		Node *node_before = head;

		while (node_before->next && node_before->next->val != item) {
			node_before = node_before->next;
		}

		if (node_before->next && node_before->next->val == item) {
			Node *node = new Node(val);
			node->next = node_before->next;
			node_before->next = node;
		}
	}
}

void SinglyLinkedList::append(int val) {

	Node *last = head;
	while (last->next) {
		last = last->next;
	}
	Node *node = new Node(val);

	last->next = node;
}

void SinglyLinkedList::del(int item) {
	if (!head)
		return;

	if (head->val == item) {
		delete_front();
	} else {

		Node *prev = head;
		while (prev->next && prev->next->val != item) {
			prev = prev->next;
		}

		if (prev->next && prev->next->val == item) {
			Node *temp = prev->next;
			prev->next = prev->next->next;
			delete temp;
		}
	}
}

void SinglyLinkedList::delete_front() {
	if (!head)
		return;

	Node *temp = head;
	head = head->next;
	delete temp;
}

void SinglyLinkedList::delete_back() {
	if (!head)
		return;
	Node *prev = head;

	while (prev->next && prev->next->next)
		prev = prev->next;

	if (prev->next) {

		Node *temp = prev->next;
		prev->next = nullptr;
		delete temp;
	}
	else {
		delete head;
		head = nullptr;
	}
}

void SinglyLinkedList::print() {
	Node *temp = head;
	while (temp) {
		std::cout << temp->val << " -> ";
		temp = temp->next;
	}
	std::cout << "NULL\n";
}
