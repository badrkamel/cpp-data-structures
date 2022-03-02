#include <iostream>

class Queue {
    
    int *queue;
public:
    size_t capacity;
    int front, tail;

    Queue (size_t c) : capacity(c) {
        tail = front = -1;
        queue = new int[c];
    }

    bool isFull() {
        return (front == 0 && tail==capacity-1 || front == tail+1);
    }

    bool isEmpty() {
        return (front==-1);
    }

    void enQueue(int val) {
        if (isFull()) {
            std::cout << "Queue is full\n";
        } else {
            if (front == -1)
                front = 0;
            tail = (tail + 1) % capacity;
            queue[tail] = val;
        }
    }

    void deQueue() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return;
        }
        queue[front] = 0;

        if (front == tail)
            front = tail = -1;
        else {
            front = (front + 1)%capacity;
        }
    }

    void print() {
        size_t i;
        for (i = front; i != tail; i = (i+1)%capacity)
            std::cout << queue[i] << " ";
        std::cout << queue[i] << "\n";
    }
};


int main() {
    Queue q(5);

    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.print();

    std::cout << "front: " << q.front << " tail: " << q.tail << "\n";

    q.deQueue();
    q.deQueue();
    q.print();
    std::cout << "front: " << q.front << " tail: " << q.tail << "\n";

    q.enQueue(10);
    q.enQueue(20);
    q.print();
    std::cout << "front: " << q.front << " tail: " << q.tail << "\n";
    
    return 0;
}
