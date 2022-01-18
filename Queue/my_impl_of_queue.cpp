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


struct Queue {
    Node *front;
    Node *rear;

    Queue () {
        front = rear = NULL;
    }

    void enqueue(Node *node) {

        if (front==NULL) {
            front = rear = node;
        }

        rear->next = node;
        rear = node;

    }

    void dequeue() {
        Node *temp = front;
        front = front->next;
        delete temp;
    }

    void display() {
        Node *temp = front;
        while (temp != NULL)
        {
            cout << "Node: " << temp->value << "\t";
            temp = temp->next;
        }
        cout << endl;
    }

};

int main () {
    cout << "Queue (quick impl)\n";

    // Allocate the three nodes in the heap
    Node *one = new Node(10);
    Node *two = new Node(20);
    Node *three = new Node(30);

    // Create queue
    Queue q;

    // enQueue
    q.enqueue(one);
    q.enqueue(two);
    q.enqueue(three);
    // deQueue
    q.dequeue();

    // display
    q.display();
    
}
