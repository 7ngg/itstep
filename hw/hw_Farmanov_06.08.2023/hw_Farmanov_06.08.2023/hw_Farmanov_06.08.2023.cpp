#include <iostream>
#include <string>
#include <list>

using namespace std;

template<typename T>
class MyList {
public:
    struct Node {
        T data{}; // значение
        Node* next{}; // указатель на следующий элемент
        Node* previous{}; // указатель на предыдущий элемент

        Node(T data) {
            this->data = data;
        }
    };

    MyList() = default;

    MyList(T data) {
        head = new Node(data);
    }

    MyList(initializer_list<T> list) {
        for (T item : list) {
            pushBack(item);
        }
    }

    void pushBack(T data) {
        if (head == nullptr) {
            head = new Node(data);
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new Node(data);
    }


    friend ostream& operator<<(ostream& os, const MyList& list) {
        Node* current = list.head;
        while (current != nullptr) {
            os << "Value: " << current->data << '\t' << "Previous: " << current->previous << '\t' << "Next: " << current->next << endl;
            current = current->next;
        }
        return os;
    }

    T operator[](int index) {
        Node* current = head;
        int counter = 0;
        while (current != nullptr) {
            if (counter == index) {
                return current->data;
            }
            current = current->next;
            counter++;
        }
        return T();
    }

private:
    Node* head{};
};

int main() {

    MyList<int> newList{};
    
    newList.pushBack(10);
    newList.pushBack(20);
    newList.pushBack(30);

    cout << newList << endl;

    return 0;
}