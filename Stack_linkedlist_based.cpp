#include <iostream>

using namespace std;

class Node {
    public:
    int value;
    Node *next;

    Node () {
        value = 0;
        next = NULL;
    }
};

class Stack {
    Node *top;

    int SIZE;
    int lenght;
    int *items;

    public:
    Stack(int MAX_SIZE) {
        top = NULL;
        lenght = 0;
        SIZE = MAX_SIZE;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Error - Stack is full\n";
            return;
        }
        Node *newNode = new Node();
        newNode->value = value;

        if (isEmpty()) {
            newNode->next = NULL;
        } else {
            newNode->next = top;
        }

        top = newNode;
        lenght++;
    }
    int pop() {
        if (isEmpty()) {
            cout << "The stack is empty\n";
            return -1;
        }
        int value = top->value;
        Node *temp = top;
        top = top->next;
        delete temp;

        return value;
    }

    bool isFound(int key) {
        Node *temp = top;
        while (temp != NULL) {
            if (temp->value == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    bool isEmpty() {
        return (top==NULL);
    }

    bool isFull() {
        return (lenght==SIZE);
    }

    int count() {
        return lenght;
    }

    int peek() {
        if (!isEmpty())
            return top->value;
        cout << "The stack is empty\n";
        return 0;
    }

    void display() {
        Node *temp = top;
        while (temp != NULL) {
            cout << temp->value << "\t";
            temp = temp->next;
        }
        cout << endl;
    }

};

int main () {
    cout << "Stack ADT LinkedList based Implementation\n";

    // Create stack
    Stack stk(10);


    // Check if stack is empty
    stk.isEmpty() ? cout << "The stack is empty\n" : cout << "The stack have " << stk.count() << " elements\n";

    // Push data
    stk.push(10);
    stk.push(20);

    if (stk.isFound(20)) {
        cout << "Found!\n";
    } else {
        cout << "Not found!\n";
    }

    stk.isEmpty() ? cout << "The stack is empty\n" : cout << "The stack have " << stk.count() << " elements\n";
    
    // Display stack data
    stk.display();

    // Return last element in the stack
    cout << stk.peek() << endl;

    stk.pop();
    stk.display();
    stk.pop();

    if (stk.isFound(20)) {
        cout << "Found!\n";
    } else {
        cout << "Not found!\n";
    }
    
    cout << stk.peek() << endl;

        /*
        Methods:
            - Create
            - Push
            - Pop
            - isEmpty
            - isFull
            - Count
            - Display
            - peek
            - isFound

    */
}
