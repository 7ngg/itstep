#pragma once
#include <iostream>

template<typename type>
class Deque {
private:
    type* elements;
    int size;

public:
    Deque() = default;
    Deque(type newElement)
    {
        size = 1;
        elements = new type[size]{ newElement };
    }

    Deque(std::initializer_list<type> list)
    {
        size = list.size();
        elements = new type[size]{};
        int iterator = 0;
        
        for (const auto& item : list)
        {
            elements[iterator++] = item;
        }
    }

    ~Deque()
    {
        delete[] elements;
    }


    void PushBack(type newElement)
    {
        type* tmp = new type[size + 1]{};

        for (size_t i = 0; i < size; i++)
        {
            tmp[i] = elements[i];
        }

        tmp[size] = newElement;
        delete[] elements;
        size += 1;
        elements = tmp;
    }


    void PushFront(type newElement)
    {
        type* tmp = new type[size + 1]{ newElement };


        for (size_t i = 0; i < size; i++)
        {
            tmp[i + 1] = elements[i];
        }

        size += 1;
        delete[] elements;
        elements = tmp;
    }


    void PopFront()
    {
        type* tmp = new type[size - 1]{};

        for (size_t i = 0; i < size - 1; i++)
        {
            tmp[i] = elements[i + 1];
        }

        size -= 1;
        delete[] elements;
        elements = tmp;
    }


    void PopBack()
    {
        type* tmp = new type[size - 1]{};

        for (size_t i = 0; i < size - 1; i++)
        {
            tmp[i] = elements[i];
        }

        size -= 1;
        delete[] elements;
        elements = tmp;
    }


    type Front()
    {
        return elements[0];
    }


    type Back()
    {
        return elements[size - 1];
    }


    int GetSize()
    {
        return size;
    }


    bool IsEmpty()
    {
        return (size <= 0) ? true : false;
    }


    friend std::ostream& operator << (std::ostream& stream, const Deque& var)
    {
        for (size_t i = 0; i < var.size; ++i)
        {
            stream << var.elements[i] << ' ';
        }

        return stream;
    }
};