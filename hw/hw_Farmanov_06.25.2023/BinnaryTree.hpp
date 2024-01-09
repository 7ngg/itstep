#include <iostream>
#include <ostream>

template <typename T>
class BinnaryTree {
private:
    struct Node {
        T value;
        Node* right;
        Node* left;

        Node(T value): value(value), right(nullptr), left(nullptr) {}
    };

    Node* data = nullptr;

public:
    BinnaryTree() = default;
    BinnaryTree(T value);
    std::ostream operator<<(std::ostream& stream);
};
