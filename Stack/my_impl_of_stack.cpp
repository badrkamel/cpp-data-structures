#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *next;
};

class Stack {
    Node *top;

    public:
    Stack () {
        top = NULL;
    }
    void push(Node *node) {
        if (top==NULL) {
            node->next = NULL;
        } else {
            node->next = top;
        }
        top = node;
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

    // ALLOCATE THREE NODES IN THE HEAP
    Node *one = new Node();
    Node *two = new Node();
    Node *three = new Node();

    // Assing value values
    one->value = 10;
    two->value = 20;
    three->value = 30;

    Stack stk;
    stk.push(one);
    stk.push(two);
    stk.push(three);

    stk.display();
}
