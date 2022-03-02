#include <iostream>

using namespace std;

class Stack {
    private:
    size_t capacity;
    size_t top;
    int *items;

    public:
    Stack (size_t c) : capacity(c) {
        top = 0;
        items = new int[c];
    }

    void push(int value) {

        if (isFull()) {
            cout << "Error - The stack is full\n";
            return;
        }
        items[top] = value;
        top++;
    }

    void pop() {
        items[--top] = 0;
    }

    bool isFull() {
        return (top==capacity);
    }

    bool isEmpty() {
        return (top==0);
    }

    int peek() {
        return items[top-1];
    }

    int count() {
        return top;
    }

    void display() {
        for (int i=0; i<top; i++)
            cout << items[i] << "\t";
        cout << endl;
    }

    bool search(int item) {

        for (int i=0;i<top; i++) {
            if (items[i] == item) {
                return true;
            }
        }
        return false;
    }

};

int main () {

    cout << "Stack ADT\n";

    // Create stack
    Stack stk(10);


    // Check if stack is empty
    stk.isEmpty() ? cout << "The stack is empty\n" : cout << "The stack has " << stk.count() << " elements\n";

    // Push data
    stk.push(10);
    stk.push(20);
    stk.push(30);

    stk.isEmpty() ? cout << "The stack is empty\n" : cout << "The stack has " << stk.count() << " elements\n";

    // Display stack data
    stk.display();

    // Return last element in the stack
    cout << stk.peek() << endl;

    // Search
    stk.search(40) ? cout << "found\n" : cout << "not found!\n";

    // Pop
    stk.pop();
    stk.isEmpty() ? cout << "The stack is empty\n" : cout << "The stack has " << stk.count() << " elements\n";
    stk.display();

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
            - Search

    */

}
