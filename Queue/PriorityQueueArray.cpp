#include <iostream>

class priorityQueue
{
    size_t capacity, size;
    int* pQueue;

    // int leftChildIndex(size_t parentIndex) {return 2*parentIndex+1;}
    // int rightChildIndex(size_t parentIndex) {return 2*parentIndex+2;}

    int leftChild(size_t parentIndex) {
        int ind = 2*parentIndex + 1;
        return pQueue[ind];
    }
    int rightChild(size_t parentIndex) {
        int ind = 2*parentIndex + 2;
        return pQueue[ind];
    }
    int parent(size_t childIndex) {
        int ind = (childIndex-1) / 2;
        return (pQueue[ind]);
    }
    
public:    
    priorityQueue (size_t c) : capacity(c), size(0) {
        pQueue = new int [c];
    }
    void enQueue(int);
    void print();
    void reheapUp();
    void reheapDown(int);
    void deQueue();
};

int main() {
    priorityQueue h(12);

    int arr[] { 87,5,4,2,18,88,45,1 };

    int size = sizeof arr / sizeof *arr;
    for (int i : arr)
        h.enQueue(i);

    h.print();
    h.deQueue();
    h.print();
}

void priorityQueue::enQueue(int item) {
    if (size<capacity) {
        pQueue[size] = item;
        reheapUp();
        size++;
    }
}

void priorityQueue::reheapUp() {
    int index = size;
    while (index != 0 && parent(index) > pQueue[index]) {
        std::swap(pQueue[(index-1)/2], pQueue[index]);
        index = (index-1)/2;
    }
}

void priorityQueue::reheapDown(int size) {
    size_t index = 0;
    size_t rightChildIndex = 2, leftChildIndex = 1;
    while (leftChildIndex<size) {
        int smallChildIndex = leftChildIndex;
        if (rightChildIndex < size && rightChild(index)<leftChild(index))
            smallChildIndex = rightChildIndex;

        if (pQueue[index]<pQueue[smallChildIndex])
            break;
        else
            std::swap(pQueue[index], pQueue[smallChildIndex]);
        
        index = smallChildIndex;
        leftChildIndex = (2*index)+1;
        rightChildIndex = (2*index)+2;
    }
}

void priorityQueue::deQueue() {
    size--;
    std::swap(pQueue[0], pQueue[size]);
    reheapDown(size);
}

void priorityQueue::print() {
    std::cout << "{ ";
    for (int i{}; i < size; i++)
        std::cout << pQueue[i] << " ";
    std::cout << " }\n";
}
