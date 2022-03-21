#include <iostream>

template<typename T> struct Node {
	T val;
	Node *next = nullptr;

	Node () {}
	Node (const T& v) : val(v) {}
};

template<typename T> class Queue {
	Node<T> *front, *tail;

public:
	Queue () {
		front = tail = nullptr;
	}

	void push(const T& val) {
		Node<T> *node = new Node<T>(val);

		if (front == nullptr)
			front = tail = node;
		tail->next = node;
		tail = node;
	}

	void pop() {
		if (front) {
			Node<T> *temp = front;
			front = front->next;
			delete temp;
		}
	}

	void display() {
		if (front) {
			Node<T> *curr = front;
			while (curr) {
				std::cout << curr->val << "\t";
				curr = curr->next;
			}
			std::cout << "\n";
		}
	}
};

int main() {
	Queue<int> queue;

	queue.push(10);
    queue.push(20);
    queue.push(30);
    queue.display(); // 10 20 30

    queue.pop();
    queue.pop();
    queue.display(); // 30

    queue.push(40);
    queue.push(50);
    queue.display(); // 30 40 50
}
