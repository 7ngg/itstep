#include <iostream>

#include "vector.h"

int main()
{
    vector<int> myVector {1, 2, 3, 4, 5};
    std::cout << myVector << std::endl;
    
    myVector.push_back(7);
    myVector.push_back(8);
    myVector.push_back(9);
    myVector.push_back(10);
    myVector.push_back(11);
    myVector.push_back(12);
    std::cout << myVector << std::endl;

    myVector.pop_back();
    std::cout << myVector << std::endl;

    std::cout << "Size: " << myVector.get_size() << std::endl;

    if (myVector.isEmpty())
    {
        std::cout << "Vector is empty" << std::endl;
    }
    else
    {
        std::cout << "Vector is not empty" << std::endl;
    }

    std::cout << "First element adress: " << myVector.begin() << ' ' << "First element: " << *myVector.begin() << std::endl;
    
    myVector.insert(1337, 3);
    std::cout << myVector << std::endl;

    return 0;
}
