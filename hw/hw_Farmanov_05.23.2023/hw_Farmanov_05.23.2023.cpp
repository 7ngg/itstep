#include <algorithm>
#include <iostream>

class phoneBook {
public:
    char* name{};
    char* surname{};
    char* description{};

    char* homePhone{};
    char* selfPhone{};
    char* workPhone{};
    
    phoneBook() = default;
    phoneBook(char* name, char* surname, char* description, char* homePhone, char* selfPhone, char* workPhone) {
        this->name = name;
        this->surname = surname;
        this->description = description;
        this->homePhone = homePhone;
        this->selfPhone = selfPhone;
        this->workPhone = workPhone;
    }


    void print() {
        std::cout
            << name << ' ' << surname << '\n'
            << "Home: " << homePhone << '\n'
            << "Self: " << selfPhone << '\n'
            << "Work: " << workPhone << '\n'
            << "Description: " << description << std::endl;
    }
};


phoneBook addPerson(){
    char* name = new char[32]{};
    char* surname = new char[32]{};
    char* description = new char[128]{};
    char* homePhone = new char[14]{};
    char* selfPhone = new char[14]{};
    char* workPhone = new char[14]{};

    std::cout << "Enter name: ";
    std::cin.getline(name, 32);
    std::cin.ignore();

    std::cout << "Enter surname: ";
    std::cin.getline(surname, 32);
    std::cin.ignore();

    std::cout 
        << "Enter description: " << '\n'
        << "> ";
    std::cin.getline(description, 128);
    std::cin.ignore();

    std::cout << "Enter home-phone number: ";
    std::cin.getline(homePhone, 14);
    std::cin.ignore();

    std::cout << "Enter selfphone number: ";
    std::cin.getline(selfPhone, 14);
    std::cin.ignore();

    std::cout << "Enter work-phone number: ";
    std::cin.getline(workPhone, 14);
    std::cin.ignore();

    phoneBook newPerson(name, surname, description, homePhone, selfPhone, workPhone);
    return newPerson;
}


int main() {
    phoneBook* newBook = new phoneBook[32] {};
    uint16_t choice = 0;

    std::cout 
        << "Choose option: " << '\n'
        << "1. Write" << '\n'
        << "2. Read" << '\n'
        << "> ";
    std::cin >> choice;

    switch (choice) 
    {
        case 1:
            

            break;
    }

    return 0; 
}
