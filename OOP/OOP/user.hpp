#pragma once

#include "regex.hpp"
#include "subject.hpp"

class User {
public:
    std::string username, password;
    std::vector<TestResult> grades;
    std::vector<Subject*> availableTasks;

    User() = default;
    User(const std::string& username, const std::string& password) {
        if (std::regex_match(username, regular::USERNAME))
        {
            this->username = username;
        }
        else
        {
            throw std::invalid_argument("Invalid username");
        }
        
        if (std::regex_match(password, regular::PASSWORD))
        {
            this->password = password;
        }
        else
        {
            throw std::invalid_argument("Invalid password");
        }
    }


#pragma region Functions
    
    void userMainFunction();


    void showGrades() {
        for (size_t i = 0; i < this->grades.size(); i++)
        {
            std::cout << this->grades[i] << std::endl;
        }
    }


    void showSubjects() {
        for (size_t i = 0; i < this->availableTasks.size(); i++)
        {
            std::cout << i + 1 << ". " << this->availableTasks[i]->getSubjectName() << std::endl;
        }
    }

#pragma endregion
};


void User::userMainFunction() {
    bool flag = true;

    while (flag)
    {
        char choice{};
        uint16_t choiceCheck{};
        uint16_t  numLit = 0;
    
        std::cout
            << "0. Quit user panel" << '\n'
            << "1. Show all grades" << '\n'
            << "2. Select test and begin testing" << '\n'
            << "> ";
        std::cin >> choice;
        std::cin.ignore();
        choiceCheck = atoi(&choice);

        switch (choiceCheck)
        {
        case 0:
            flag = false;
            break;

        case 1:
            this->showGrades();
            break;

        case 2:
        {
            this->showSubjects();
            std::cout << "Choose test to begin: ";
            std::cin >> numLit;
            std::cin.ignore();
            TestResult result = this->availableTasks[numLit - 1]->beginTest();
            std::cout << result << std::endl;
            this->grades.push_back(result);
        }

            break;

        default:
            std::cout << "No such option" << std::endl;
            break;
        }

        system("pause");
        system("cls");
    }
}