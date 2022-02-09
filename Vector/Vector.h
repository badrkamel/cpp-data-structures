#pragma once

template<typename T>
class Vector {
    // `size_t` is an unsigned integer data type 
    // which can assign only 0 and greater than 0 integer values.
    size_t m_Size{};
    size_t m_Capacity = 2;
    T* m_Data = nullptr;
public:

    Vector() {
        m_Data = new T[m_Capacity];
    }

    void PushBack(const T& value)
    {
        if (m_Size>=m_Capacity)
            reAlloc(m_Capacity + m_Capacity/2);

        // new(&m_Data[m_Size++]) T(std::move(value));
        m_Data[m_Size++] = value;
    }

    size_t Size() const {return m_Size;}

    const T& operator[](size_t index) const
    {

        if (index >= m_Size)
        {
            // assert        
        }
        return m_Data[index];
    }

    T& operator[](size_t index)
    {
        // std::cout << "Called" << std::endl;
        if (index >= m_Size)
        {
            // assert
        }
        return m_Data[index];
    }

    void display() {
        for (size_t i{}; i < m_Size;i++)
            std::cout << m_Data[i] << " ";
        std::cout << "\n";
    }

private:
    void reAlloc(size_t newCapacity)
    {
        // allocate a new block of memory
        // copy/move old elements into new  block
        // delete the old block

        T* newBlock = new T[newCapacity];

        if (newCapacity<m_Size)
            m_Size = newCapacity;
        
        for (size_t i=0; i<m_Size; i++)
            newBlock[i] = m_Data[i];

        delete[] m_Data;
        m_Data = newBlock;
        m_Capacity = newCapacity;
    }
};
