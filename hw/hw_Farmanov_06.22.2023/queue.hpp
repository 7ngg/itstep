#pragma once
#include <iostream>

template<typename type>
class Queue {
private: 
    type* elements;
    int size;

    struct FirstLast
    {
        type first;
        type last;

        FirstLast(type first, type last)
        {
            this->first = first;
            this->last = last;
        }

        friend std::ostream& operator << (std::ostream& stream, const FirstLast& var)
        {
            stream << "First: " << var.first << '\t' << "Last: " << var.last << std::endl;
            return stream;
        }
    };

public:
    
    Queue() = default;

    Queue(type newElement)
    {
        size = 1;
        elements = new type[size]{newElement};
    }

    Queue(std::initializer_list<type> list)
    {
        size = list.size();
        elements = new type[size]{};
        size_t iterator = 0;

        for(auto& item : list)
        {
            elements[iterator++] = item;
        }
    }

    ~Queue()
    {
        delete[] elements;
    }


    uint32_t GetSize()
    {
        return this->size;
    }


    void Push(type newElement)
    {
        type* tmp = new type[size + 1]{};

        for (size_t i = 0; i < size; ++i)
        {
            tmp[i] = elements[i];
        }

        tmp[size] = newElement;
        size += 1;
        delete[] elements;
        elements = tmp;
    }


    void Pop()
    {
        type* tmp = new type[size - 1];

        for (size_t i = 0; i < size - 1; ++i)
        {
            tmp[i] = elements[i + 1];
        }

        delete[] elements;
        size -= 1;
        elements = tmp;
    }


    FirstLast Peek()
    {
        return FirstLast(elements[0], elements[size - 1]);
    }


    bool IsEmpty()
    {
        return (size <= 0) ? true : false;
    }


    friend std::ostream& operator << (std::ostream& stream, Queue<type>& var)
    {
        for (size_t i = 0; i < var.size; ++i)
        {
            stream << var.elements[i] << ' ';
        }

        return stream;
    }
};