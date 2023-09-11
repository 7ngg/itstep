#include "queue.hpp"
#include "deque.hpp"

int main(int, char**){
    Deque<int> q{1, 2, 3, 4, 5};

    q.PushBack(6);
    q.PushFront(0);
    std::cout << q << "Size = " << q.GetSize() << std::endl;
    q.PopBack();
    q.PopFront();
    std::cout << q << "Size = " << q.GetSize() << std::endl;
    std::cout << q.Front() << '\t' << q.Back() << '\t' << q.IsEmpty() << '\t' << q.GetSize() << std::endl;

    return 0;
}
