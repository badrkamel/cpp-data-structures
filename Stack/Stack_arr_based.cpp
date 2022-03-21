#include <iostream>

template<typename T> class Stack {
    size_t CAPACITY;
    size_t top;

    T* data;

public:
    Stack (size_t c) : CAPACITY(c) {
        top = 0;
        data = new T[c];
    }

    void push(const T& val) {
        if (top < CAPACITY)
        data[top++] = val;
    }

    void pop() {
        if (top)
        data[--top] = 0;
    }

    void print() {
        if (top == 0)
            return;
        for (size_t i{}; i < top; i++)
            std::cout << data[i] << "\t";
        std::cout << "\n";
    }
};

int main() {
    Stack<int> stk(10);

    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.print();

    stk.pop();
    stk.print();
}
