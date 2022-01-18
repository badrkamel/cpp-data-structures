#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *next;

    Node (int data) {
        value=data;
        next=NULL;
    }
};

class Stack {
    Node *top;

    public:
    Stack () {
        top = NULL;
    }
    void push(int data) {
        Node *node = new Node(data);
        node->next = top;
        top = node;
    }

    void display() {
        Node *temp = top;
        while (temp != NULL) {
            cout << "Node: " << temp->value << "\t";
            temp = temp->next;
        }
        cout << endl;
    }

    int pop() {
        if (top != NULL) {    
            Node *temp = top;
            int value = temp->value;

            top = top->next;

            delete temp;
            return value;
        }
        return -1;
    }

};


int main () {

    Stack stk;
    stk.push(10);
    stk.push(20);
    stk.pop();
    stk.push(30);
    stk.pop();

    stk.display();
}
