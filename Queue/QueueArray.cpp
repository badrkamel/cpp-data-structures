#include <iostream>

class Queue {
    size_t capacity;
    int front, tail;

    int *queue;

public:
    Queue (size_t c) : capacity(c) {
        front = tail = -1;
        queue = new int[c];
    }

    bool isFull() {
        return (tail+1)%capacity == front;
    }

    bool isEmpty() {
        return (front == -1);
    }

    void enQueue(int val) {
        if (isFull()) {
            std::cout << "Queue is full\n";
        } else {
            if (isEmpty())
                front = 0;
            tail = (tail + 1)%capacity;
            queue[tail] = val;
        }
    }

    void deQueue() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
        } else {
            queue[front] = 0;
            if (front == tail)
                front = tail = -1;
            else
                front = (front+1)%capacity;
        }
    }

    void print() {
        if (isEmpty())
            return;
        size_t i;
        for (i = front; i != tail; i = (i+1)%capacity)
            std::cout << queue[i] << " ";
        std::cout << queue[tail] << "\n";
    }
};

int main() {
    Queue q(5);

    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.print(); // 10 20 30

    q.deQueue();
    q.deQueue();
    q.print(); // 30

    q.enQueue(40);
    q.enQueue(50);
    q.enQueue(60);
    q.enQueue(70);
    q.enQueue(80);
    q.print(); // 30 40 50 60 70

    q.deQueue();
    q.print(); // 40 50 60 70

    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.print(); // 70
}
