#include <iostream>

template<typename T> class Queue {

	int front, tail;

	size_t CAPACITY;
	T *data;

public:
	Queue (size_t c) : CAPACITY(c) {
		front = tail = -1;
		data = new T[c];
	}

	bool isFull() {
		return (tail+1)%CAPACITY == front;
	}

	bool empty() {
		return (tail == -1);
	}

	void push(const T& val) {
		if (isFull())
			return;
		if (empty())
			front = 0;

		tail = (tail+1)%CAPACITY;
		data[tail] = val;
	}
	void pop() {
		if (empty())
			return;

		if (front == tail)
			front = tail = -1;
		else
			front = (front+1)%CAPACITY;

	}
	void print() {
		if (empty())
			return;
		for (size_t i = front; i != tail; i = (i+1)%CAPACITY)
			std::cout << data[i] << "\t";
		std::cout << data[tail] << "\n";
	}
};

int main() {
	Queue<int> queue(5);

	queue.push(10);
	queue.push(20);
	queue.push(30);
	queue.print();

	queue.pop();
	queue.pop();
	queue.push(40);
	queue.push(50);
	queue.print();
}
