#include "BinnaryTree.hpp"

#include <iostream>

template<typename T>
BinnaryTree<T>::BinnaryTree(T value) {
    data = new Node(value);
}

template <typename T>
BinnaryTree<T>::std::ostream& operator<<(std::ostream& stream) {
    stream
        << "Value: " << value << '\n'
        << "Right: " << right << '\n'
        << "Left: " << data.left << '\n';

    return stream;
}
