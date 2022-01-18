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

class Queue {
    Node *front;
    Node *rear;
    int lenght;

public:
    Queue () {
        front = rear = NULL;
    }

    void enqueue (int value) {
        Node *node = new Node(value);

        if (front==NULL) {
            front = rear = node;
        }
        rear->next = node;
        rear=node;
        lenght++;
    }

    void display() {
        Node *temp= front;
        cout << lenght << " Elements: ";
        while (temp != NULL) {
            cout << "Node: " << temp->value << "\t";
            temp = temp->next;
        }
        cout << endl;
    }

    int getFront() {
        return front->value;
    }
    
    int getRear() {
        return rear->value;
    }

    int dequeue() {

        if (front==NULL) {
            cout << "The queue is empty\n";
            return -1;
        } else if (front == rear ){
            delete front;
            front = rear = NULL;
            lenght--;
            return -1;
        } else {
            int value;
            value = front->value;
            
            Node *temp = front;
            front = front->next;
            delete temp;

            lenght--;
            return value;
        }
    }

    int count () {
        return lenght;
    }

    bool isFound(int key) {
        Node *temp = front;
        while(temp != NULL) {
            if (temp->value==key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};

int main () {
    cout << "ADT for queue\n";

    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    if (q.isFound(20)) {
        cout << "Found\n";
    } else {
        cout << "Not found\n";
    }

    q.display();
    cout << "First item to remove: " << q.peek() << endl;

    q.dequeue();
    q.display();
    q.dequeue();
    q.dequeue();
    if (q.isFound(20)) {
        cout << "Found\n";
    } else {
        cout << "Not found\n";
    }
    q.display();
}
