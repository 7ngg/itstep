#include <iostream>
#include <stdint.h>
#include <iso646.h>

#include "json.hpp"
using json = nlohmann::json;


bool fileExists(const char* name) {
	FILE* file{};
	fopen_s(&file, name, "r");

	if (file == nullptr)
	{
		return false;
	}
	return true;
}


class phoneBook {
public:
    std::string name{};
    std::string surname{};
    std::string description{};

    std::string homePhone{};
    std::string selfPhone{};
    std::string workPhone{};
    
    phoneBook() = default;
    phoneBook(std::string name, std::string surname, std::string description, std::string homePhone, std::string selfPhone, std::string workPhone) {
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
            << "\tHome: " << homePhone << '\n'
            << "\tSelf: " << selfPhone << '\n'
            << "\tWork: " << workPhone << '\n'
            << "\tDescription: " << description << std::endl;
    }
};


phoneBook addPerson(){
    std::string name = new char[32]{};
    std::string surname = new char[32]{};
    std::string description = new char[128]{};
    std::string homePhone = new char[14]{};
    std::string selfPhone = new char[14]{};
    std::string workPhone = new char[14]{};

    std::cout << "Enter name: ";
    std::getline(std::cin, name);

    std::cout << "Enter surname: ";
    std::getline(std::cin, surname);

    std::cout 
        << "Enter description: " << '\n'
        << "> ";
    std::getline(std::cin, description);

    std::cout << "Enter home-phone number: ";
    std::getline(std::cin, homePhone);

    std::cout << "Enter selfphone number: ";
    std::getline(std::cin, selfPhone);

    std::cout << "Enter work-phone number: ";
    std::getline(std::cin, workPhone);

    phoneBook newPerson(name, surname, description, homePhone, selfPhone, workPhone);
    return newPerson;
}


int main() {
    uint16_t bookSize = 32;
    uint16_t step = 0;
    uint16_t choice = 0;

    char* fileName{};

    phoneBook* newBook = new phoneBook[bookSize] {};
    bool flag = true;

    while (flag) 
    {
        uint16_t case2Choice = 0;

        std::cout
            << "Choose operation: " << '\n'
            << "1. Add" << '\n'
            << "2. Remove" << '\n'
            << "3. Show" << '\n'
            << "4. Load from file" << '\n'
            << "5. Save to file" << '\n'
            << "0. Exit" << '\n'
            << "> ";
        std::cin >> choice;
        std::cin.ignore();
        system("cls");

        switch (choice)
        {
            case 0:
                flag = false;
                break;

            case 1:
                newBook[step] = addPerson();
                step += 1;
                break;

            case 2:
                for (size_t i = 0; i < step; ++i) 
                {
                    std::cout << i + 1 << ". ";
                    newBook[i].print();
                }

                std::cout << "Choose field to delete: ";
                std::cin >> case2Choice;

                newBook[case2Choice - 1].name = new char[32]{};
                newBook[case2Choice - 1].surname = new char[32]{};
                newBook[case2Choice - 1].description = new char[128]{};
                newBook[case2Choice - 1].homePhone = new char[14]{};
                newBook[case2Choice - 1].selfPhone = new char[14]{};
                newBook[case2Choice - 1].workPhone = new char[14]{};
                
                break;

            case 3:
                if (step == 0)
                {
                    std::cout << "The book is empty" << std::endl;
                }

                for (size_t i = 0; i < step; i++)
                {
                    newBook[i].print();
                }
                break;

            case 4:
            {
                FILE* file{};
                fileName = new char[32] {};
                char* tmpStr = new char[128] {};

                std::cout << "Enter file name: ";
                std::cin.getline(fileName, 32);

                if (fileExists(fileName))
                {
                    fopen_s(&file, fileName, "r");
                    while (!feof(file))
                    {
                        fgets(tmpStr, 128, file);
                        std::cout << tmpStr;
                    }
                }
                else
                {
                    std::cout << "File not found" << std::endl;
                }


                break;
            }
                
            case 5:
            {
                fileName = new char[32] {};
                std::cout << "Enter file name: ";
                std::cin.getline(fileName, 32);
                
                FILE* file{};

                fopen_s(&file, fileName, "w");
                for (size_t i = 0; i < step; i++)
                {
                    fprintf(file, "Name: %s %s\nHome: %s\nSelf: %s\nWork: %s\nDescription: %s", 
                        newBook[i].name.c_str(), newBook[i].surname.c_str(), newBook[i].homePhone.c_str(), newBook[i].selfPhone.c_str(), newBook[i].workPhone.c_str(), newBook[i].description.c_str());
                }

                break;
            }

        }
    }    
    
    system("pause");
    return 0; 
}
