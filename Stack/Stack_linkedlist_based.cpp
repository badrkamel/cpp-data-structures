#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *next = nullptr;

    Node () {}
    Node (int v) : val(v) {}
};

class Stack {
    Node *head;

    size_t CAPACITY;
    size_t top;

    public:
    Stack(size_t c) : CAPACITY(c) {
        top = 0;
        head = nullptr;
    }

    void push(int val) {
        if (isFull()) {
            cout << "Error - Stack is full\n";
            return;
        }
        Node *newNode = new Node(val);
        
        newNode->next = head;
        head = newNode;
        top++;
    }
    int pop() {
        if (isEmpty()) {
            cout << "The stack is empty\n";
            return -1;
        }
        int val = head->val;
        Node *temp = head;
        head = head->next;
        delete temp;

        return val;
    }

    bool isFound(int key) {
        Node *temp = head;
        while (temp != nullptr) {
            if (temp->val == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    bool isEmpty() {
        return (head==nullptr);
    }

    bool isFull() {
        return (top==CAPACITY);
    }

    int count() {
        return top;
    }

    void display() {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->val << "\t";
            temp = temp->next;
        }
        cout << endl;
    }

};

int main () {
    cout << "Stack ADT LinkedList Based Implementation\n";

    // Create stack
    Stack stk(10);


    // Check if stack is empty
    stk.isEmpty() ? cout << "The stack is empty\n" : cout << stk.count() << " Nodes\n";

    // Push data
    stk.push(10);
    stk.push(20);

    if (stk.isFound(20))
        cout << "Found!\n";
    else
        cout << "Not found!\n";
    
    stk.isEmpty() ? cout << "The stack is empty\n" : cout << stk.count() << " Nodes\n";
    
    // Display stack data
    stk.display();


    stk.pop();
    stk.display();
    stk.pop();

    if (stk.isFound(20))
        cout << "Found!\n";
    else
        cout << "Not found!\n";
    
    /*
    Methods:
        - Create
        - Push
        - Pop
        - isEmpty
        - isFull
        - Count
        - Display
        - isFound

    */
}
