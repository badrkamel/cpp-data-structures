#include <iostream>
#include "Vector.h"

template<typename T>
void printVector(const Vector<T>& vector)
{
    for (size_t i{}; i<vector.Size(); i++)
        std::cout << vector[i] << std::endl;
    std::cout << "----------------------\n";
}

int main()
{

    Vector<int> vec;
    vec.PushBack(10);
    vec.PushBack(20);
    // vec.display();
    printVector(vec);
    
    Vector<std::string> vector;
    vector.PushBack("hello");
    vector.PushBack("world!");
    // vector.display();
    printVector(vector);

    return 0;
}
