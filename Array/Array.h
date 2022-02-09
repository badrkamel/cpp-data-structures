#include <iostream>
#include <cstring>

template<typename T, size_t S>
class Array
{
    T m_Data[S];
public:
    constexpr size_t Size() const {return S;}

    T& operator[](size_t index)
    {
        return m_Data[index];
    }
    const T& operator[](size_t index) const
    {
        return m_Data[index];
    }

    // T& Data() {return m_Data;}
    // const T& Data() const {return m_Data;}
    void display() {
        for (size_t i{}; i<S; i++)
            std::cout << m_Data[i] << " ";
        std::cout << "\n";
    }
};

int main()
{
    Array<int, 4> arr;

    // static_assert(arr.Size() < 10, "Size is too large!");
    // Array<std::string, arr.Size()> arr2;

    std::memset(&arr[0], 0, arr.Size() * sizeof(arr[0]));

    arr[0] = 8;
    arr[3] = 5;

    arr.display();

    return 0;
}
