#pragma once

#include <iostream>
#include <fstream>
#include <sstream>

#include "regex.hpp"
#include "user.hpp"
#include "subject.hpp"
#include "json.hpp"

using json = nlohmann::json;

static std::string userDataFileName = "data.json";

class Admin {
private:
    std::string username, password;
    std::vector<User*> users;

public:
    std::vector<Subject*> subjects;
    
    Admin() {
        std::string tmpUsername, tmpPassword;

        std::cout << "Enter admin username: ";
        getline(std::cin, tmpUsername);

        if (not std::regex_match(tmpUsername, regular::USERNAME))
        {
            while (not std::regex_match(tmpUsername, regular::USERNAME))
            {
                system("cls");
                std::cout 
                    << "Invalid username" << '\n'
                    << "Enter admin username: ";
                getline(std::cin, tmpUsername);
            }
        }
        this->username = tmpUsername;
        
        std::cout << "Enter admin password: ";
        getline(std::cin, tmpPassword);

        if (not std::regex_match(tmpPassword, regular::PASSWORD))
        {
            while (not std::regex_match(tmpPassword, regular::PASSWORD))
            {
                system("cls");
                std::cout
                    << "Invalid password" << '\n'
                    << "Enter admin password: ";
                    getline(std::cin, tmpPassword);    
            }
        }
        this->password = tmpPassword;

        this->updateAdminFile();
        this->loadUsers();
    }

    Admin(std::string username, std::string password) {
        this->username = username;
        this->password = password;
        this->updateAdminFile();
        this->loadUsers();
    }

    ~Admin() {
        remove("admin.json");

        for (size_t i = 0; i < this->users.size(); i++)
        {
            delete this->users[i];
        }

        for (size_t i = 0; i < this->subjects.size(); i++)
        {
            delete this->subjects[i];
        }
    }

#pragma region Functions

    void adminMainFunction();


    /*void loadUsers() {
        std::ifstream in;
        std::string line;

        for (size_t i = 0; i < this->users.size(); i++)
        {
            delete this->users[i];
        }
        this->users.clear();

        in.open(userDataFileName);
        while (std::getline(in, line))
        {
            std::string tmpUsername, tmpPassword;
            std::istringstream string_stream(line);

            string_stream >> tmpUsername >> tmpPassword;
            User* tmpUser = new User{ tmpUsername, tmpPassword };
            this->users.push_back(tmpUser);
        }
    }*/


    void loadUsers() {
        std::ifstream in;

        for (size_t i = 0; i < this->users.size(); i++)
        {
            delete this->users[i];
        }
        this->users.clear();

        in.open(userDataFileName);
        json userDataArray = json::parse(in);
        for (const auto& item : userDataArray)
            this->users.push_back(new User{ item["username"], item["password"] });
        in.close();
    }


    /*void uploadUsers() {
        std::ofstream out;

        remove(userDataFileName.c_str());
        out.open(userDataFileName);

        for (size_t i = 0; i < this->users.size(); i++)
        {
            out << this->users[i]->username << ' ' << this->users[i]->password << std::endl;
        }
    }*/


    void uploadUsers() {
        std::ofstream out;
        json userDataArray = json::array();

        out.open(userDataFileName);
        for (const auto& item : this->users)
        {
            json userData;
            userData["username"] = item->username;
            userData["password"] = item->password;
            userDataArray.push_back(userData);
        }

        out << userDataArray;
        out.close();
    }

#pragma region Admin self functions

    /*void updateAdminFile() const {
        std::ofstream write;
        write.open("admin.txt");
        write << this->username << ' ' << this->password;
        write.close();
    }*/


    void updateAdminFile() {
        std::ofstream stream("admin.json");
        json dataToWrite = json::array();
        json adminData;
        adminData["username"] = this->username;
        adminData["password"] = this->password;
        dataToWrite.push_back(adminData);
        stream << std::setw(4) << dataToWrite;
        stream.close();
    }


    void changeUsername() {
        std::cout << "Enter admin username: ";
        getline(std::cin, this->username);

        if (not std::regex_match(this->username, regular::USERNAME))
        {
            while (not std::regex_match(this->username, regular::USERNAME))
            {
                system("cls");
                std::cout
                    << "Invalid username" << '\n'
                    << "Enter admin username: ";
                getline(std::cin, this->username);
            }
        }

        this->updateAdminFile();
    }


    void changePassword() {
        std::cout << "Enter admin password: ";
        getline(std::cin, this->password);

        if (not std::regex_match(this->password, regular::PASSWORD))
        {
            while (not std::regex_match(this->password, regular::PASSWORD))
            {
                system("cls");
                std::cout
                    << "Invalid password" << '\n'
                    << "Enter admin password: ";
                    getline(std::cin, this->password);
            }
        }

        this->updateAdminFile();
    }

#pragma endregion

#pragma region User manipulations

void addUser() {
    std::string userUsername, userPassword;

    std::cout << "Enter username: ";
    getline(std::cin, userUsername);
    std::cout << "Enter password: ";
    getline(std::cin, userPassword);

    try
    {
        User* newUser = new User{ userUsername, userPassword };
        this->users.push_back(newUser);
        this->uploadUsers();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}


void addUser(User* newUser) {
    this->users.push_back(newUser);
    this->uploadUsers();
}


/*
void removeUser(const std::string& userToRemove) {
    std::string line;
    std::ifstream in;
    std::ofstream out;

    in.open(userDataFileName);
    out.open("tmp.txt");

    while(std::getline(in, line))
    {
        std::istringstream string_stream(line);
        std::string tmpUsername, tmpPassword;

        string_stream >> tmpUsername >> tmpPassword;
        if (tmpUsername != userToRemove)
        {
            out << tmpUsername << ' ' << tmpPassword << std::endl;
        }
    }

    this->loadUsers();

    in.close();
    out.close();

    remove(userDataFileName.c_str());
    rename("tmp.txt", userDataFileName.c_str());
}
*/


void removeUser(uint16_t index) {
    this->users.erase(this->users.begin() + index - 1);
    this->uploadUsers();
}


/*
void editUser(const std::string& userToEdit, uint16_t UP_parameter) {
//        UP_parameter:
//            0 - username
//            1 - parameter

    std::ifstream in;
    std::ofstream out;
    std::string line;
    in.open(userDataFileName);
    out.open("tmp.txt");

    while(std::getline(in, line))
    {
        std::istringstream string_stream(line);
        std::string tmpUsername, tmpPassword;
        string_stream >> tmpUsername >> tmpPassword;

        if (userToEdit == tmpUsername)
        {
            std::string tmp;

            if (UP_parameter == 0)
            {
                std::cout << "Enter new username: ";
                std::getline(std::cin, tmp);
                out << tmp << ' ' << tmpPassword << std::endl;
            }
            else if (UP_parameter == 1)
            {
                std::cout << "Enter new password: ";
                std::getline(std::cin, tmp);
                out << tmpUsername << ' ' << tmp << std::endl;
            }
        }
        else
        {
            out << line << std::endl;
        }
    }

    this->loadUsers();

    in.close();
    out.close();

    remove(userDataFileName.c_str());
    rename("tmp.txt", userDataFileName.c_str());
}
*/


void editUser(uint16_t index) {
    std::string str;
    char choice{};
    uint16_t choiceCheck{};

    std::cout
        << "1. Edit username" << '\n'
        << "2. Edit password" << '\n'
        << "> ";
    std::cin >> choice;
    std::cin.ignore();
    choiceCheck = atoi(&choice);

    switch (choiceCheck)
    {
    case 1:
        std::cout << "Enter new username: ";
        std::getline(std::cin, str);

        while (not std::regex_match(str, regular::USERNAME))
        {
            std::cout << "Invalid username" << '\n' << "Enter new username: ";
            std::getline(std::cin, str);
            system("cls");
        }

        this->users[index]->username = str;

        break;

    case 2:
        std::cout << "Enter new password: ";
        std::getline(std::cin, str);

        while (not std::regex_match(str, regular::PASSWORD))
        {
            std::cout << "Invalid password" << '\n' << "Enter new password: ";
            std::getline(std::cin, str);
            system("cls");
        }

        this->users[index]->password = str;

        break;

    default:
        break;
    }

    this->uploadUsers();
}


/*
void printUsers() {
    std::string line;
    std::ifstream stream(userDataFileName);
    uint16_t outputIterator = 1;

    while(std::getline(stream, line))
    {
        std::istringstream string_stream(line);
        std::string tmpUsername;

        if (string_stream >> tmpUsername)
        {
            std::cout << outputIterator << ". " << tmpUsername << std::endl;
            outputIterator += 1;
        }
    }

    stream.close();
}
*/


void printUsers() {
    for (size_t i = 0; i < this->users.size(); i++)
    {
        std::cout << i + 1 << ". " << this->users[i]->username << '\n';
    }
}


User* getUserData(std::string _username) {
    for (size_t i = 0; i < this->users.size(); i++)
    {
        if (_username == this->users[i]->username)
        {
            return this->users[i];
        }
    }
}


void updateUserGrades(std::string _username, User* userNewData) {
    for (size_t i = 0; i < this->users.size(); i++)
    {
        if (_username == this->users[i]->username)
        {
            this->users[i]->grades = userNewData->grades;
        }
    }
}


void getUserStatistics(uint16_t index) {             // Учитываются только завершенные тесты
    TestResult* result = new TestResult{};

    std::cout << "Tests completed: " << this->users[index]->grades.size() << std::endl;
    for (size_t i = 0; i < this->users[index]->grades.size(); i++)
    {
        result->correctAnswers += this->users[index]->grades[i].correctAnswers;
        result->mark += this->users[index]->grades[i].mark;
        result->persentage += this->users[index]->grades[i].persentage;
    }

    result->correctAnswers /= this->users[index]->grades.size();
    result->mark /= this->users[index]->grades.size();
    result->persentage = this->users[index]->grades.size();

    std::ofstream out(this->users[index]->username + "Stats.txt");
    out
        << '\t' << "Correct answers: " << result->correctAnswers << '\n'
        << '\t' << "Mark: " << result->mark << '\n'
        << '\t' << "Persentage: " << result->persentage << '\n';
    std::cout << "Statistics written to file " + this->users[index]->username + "Stats.txt" << std::endl;
    delete result;
    out.close();
}

#pragma endregion

#pragma region Subjects manipulations

void printSubjects() {
    for (size_t i = 0; i < this->subjects.size(); i++)
    {
        std::cout << i + 1 << ". " << this->subjects[i]->getSubjectName() << std::endl;
    }
}

void addSubject() {
    std::string subjectName;
    
    std::cout << "Enter new subject name: ";
    std::getline(std::cin, subjectName);
    this->subjects.push_back(new Subject{ subjectName });
}


void expandSubject(uint16_t index) {
    this->subjects[index]->addTask();
}


void exportSubject(uint16_t index) {
    std::ofstream out(this->subjects[index]->getSubjectName() + ".txt");

    out << this->subjects[index]->getSubjectName() << ':' << std::endl;
    for (size_t i = 0; i < this->subjects[index]->tasksList.size(); i++)
    {
        out << '\t' << i + 1 << ". " << this->subjects[index]->tasksList[i]->statement << std::endl;
    }
}


void exportSubjectFromFile(std::string exportingFileName) {
    std::string line;
    std::ifstream in(exportingFileName);

    if (in.is_open())
    {
        while (std::getline(in, line))
        {

        }
    }
    else
    {
        throw std::invalid_argument("Cannot open the file");
    }
}


void getSubjectStatistics(std::string subject) {
    TestResult* result = new TestResult{};

    for (size_t i = 0; i < this->users.size(); i++)
    {
        for (size_t j = 0; j < this->users[i]->grades.size(); j++)
        {
            if (subject == this->users[i]->grades[j].subjectName)
            {
                result->correctAnswers += this->users[i]->grades[j].correctAnswers;
                result->mark += this->users[i]->grades[j].mark;
                result->persentage += this->users[i]->grades[j].persentage;
            }
        }
    }

    result->correctAnswers /= this->users.size();
    result->mark /= this->users.size();
    result->persentage /= this->users.size();

    std::ofstream out(subject + "Stats.txt");
    out
        << '\t' << "Correct answers: " << result->correctAnswers << '\n'
        << '\t' << "Mark: " << result->mark << '\n'
        << '\t' << "Persentage: " << result->persentage << '\n';
    std::cout << "Statistics written to file " + subject + "Stats.txt" << std::endl;
    delete result;
    out.close();
}

#pragma endregion

#pragma endregion
};


void Admin::adminMainFunction() {
    bool flag = true;

    while (flag)
    {
        uint16_t choice{};
        uint16_t choiceCheck{};
        uint16_t  numLit = 0;
        std::string strLit;

        std::cout
            << "0. Quit admin panel" << '\n'
            << "1. Change username" << '\n'
            << "2. Change password" << '\n'
            << "3. Add new user" << '\n'
            << "4. Remove user" << '\n'
            << "5. Edit user" << '\n'
            << "6. Show all users" << '\n'
            << '\n'
            << "7. Add new subject" << '\n'
            << "8. Add new task to subject" << '\n'
            << "9. Show all subjects" << '\n'
            << "10. Import subject to file" << '\n'
            << '\n' 
            << "11. Get user statistics" << '\n'
            << "12. Get subject statistics" << '\n'
            << "> ";
        std::cin >> choice;
        std::cin.ignore();
        //choiceCheck = atoi(&choice);

        switch (choice)
        {
        case 0:
            flag = false;
            break;

        case 1:
            this->changeUsername();
            break;

        case 2:
            this->changePassword();
            break;

        case 3:
            this->addUser();
            break;

        case 4:
            this->printUsers();
            std::cout << "Choose user to remove: ";
            std::cin >> numLit;
            this->removeUser(numLit);

            break;

        case 5:
            this->printUsers();
            std::cout << "Enter username to edit: ";
            std::cin >> numLit;
            this->editUser(numLit - 1);

            break;

        case 6:
            this->printUsers();
            break;

        case 7:
            this->addSubject();
            break;

        case 8:
            this->printSubjects();
            std::cout << "Choose subject to add task to: ";
            std::cin >> numLit;
            std::cin.ignore();
            this->expandSubject(numLit - 1);

            break;

        case 9:
            this->printSubjects();
            break;

        case 10:
            this->printSubjects();
            std::cout << "Choose subject to export: ";
            std::cin >> numLit;
            try
            {
                this->exportSubject(numLit - 1);
            }
            catch (const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }

            break;

        case 11:
            this->printUsers();
            std::cout << "Select user: ";
            std::cin >> numLit;
            try
            {
                this->getUserStatistics(numLit - 1);
            }
            catch (const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }

            break;

        case 12:
            this->printSubjects();
            std::cout << "Enter subject name: ";
            std::getline(std::cin, strLit);
            this->getSubjectStatistics(strLit);

            break;

        default:
            std::cout << "No such option" << std::endl;
            break;
        }

        system("pause");
        system("cls");
    }
}

