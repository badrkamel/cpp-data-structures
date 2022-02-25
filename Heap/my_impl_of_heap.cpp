#include <iostream>

class MinHeap
{
    size_t size;
    size_t capacity;
    int* heap;

    // int leftChildIndex(size_t parentIndex) {return 2*parentIndex+1;}
    // int rightChildIndex(size_t parentIndex) {return 2*parentIndex+2;}

    int leftChild(size_t parentIndex) {
        int ind = 2*parentIndex + 1;
        return heap[ind];
    }
    int rightChild(size_t parentIndex) {
        int ind = 2*parentIndex + 2;
        return heap[ind];
    }
    int parent(size_t childIndex) {
        int ind = (childIndex-1) / 2;
        return (heap[ind]);
    }
    
public:    
    MinHeap (size_t c) : capacity(c), size(0) {
        heap = new int [c];
    }
    void add(int);
    void print();
    void reheapUp(int);
    void reheapDown();
    void sort();
};

int main() {
    MinHeap h(8);

    int arr[] { 87,5,4,2,18,88,45,1 };
    int size = sizeof arr / sizeof *arr;
    for (int i : arr)
        h.add(i);

    h.print();
    h.sort();
    h.print();
}

void MinHeap::add(int item) {
    if (size<capacity) {
        heap[size] = item;
        reheapUp(size);
        size++;
    }
}

void MinHeap::reheapUp(int index) {
    while (parent(index) > heap[index]) {
        std::swap(heap[index], heap[(index-1)/2]);
        index = (index-1)/2;
    }
}

void MinHeap::reheapDown() {
    size_t index = 0;
    size_t rightChildIndex = 2, leftChildIndex = 1;
    while (leftChildIndex<size) {
        int smallChildIndex = leftChildIndex;
        if (rightChildIndex < size && rightChild(index)<leftChild(index))
            smallChildIndex = rightChildIndex;

        if (heap[index]<heap[smallChildIndex])
            break;
        else
            std::swap(heap[index], heap[smallChildIndex]);
        
        index = smallChildIndex;
        leftChildIndex = (2*index)+1;
        rightChildIndex = (2*index)+2;
    }
}

void MinHeap::sort() {
    size_t s = size;
    while (size) {
        std::swap(heap[0], heap[size-1]);
        heap[size-1] = INT32_MAX;
        reheapDown();
        size--;
    }
    size = s;
}

void MinHeap::print() {
    std::cout << "{ ";
    for (int i{}; i < size; i++)
        std::cout << heap[i] << " ";
    std::cout << " }\n";
}
