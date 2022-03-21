#include <iostream>

template<typename T> struct Node {
    T val;
    Node *next = nullptr;

    Node () {}
    Node (const T& v) : val(v) {}
};

template<typename T>  class Stack {
    Node<T> *top;

    public:
    Stack () {
        top = nullptr;
    }

    void push(const T& val) {
        Node<T> *node = new Node<T>(val);
        
        node->next = top;
        top = node;
    }

    void pop() {
        Node<T> *temp = top;
        top = top->next;
        delete temp;
    }

    void print() {
        if (top == nullptr)
            return;
        Node<T> *curr = top;
        while (curr) {
            std::cout << curr->val << "\t";
            curr = curr->next;
        }
        std::cout << "\n";
    }
};

int main() {
    Stack<std::string> stk;

    stk.push("Hello");
    stk.push("World");
    stk.print();

    stk.pop();
    stk.print();
}
