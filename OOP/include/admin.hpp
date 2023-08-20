#pragma once

#include <iostream>
#include <fstream>

#include "regex.hpp"
#include "user.hpp"
#include "subject.hpp"

class Admin {
private:
    std::string username, password;
    std::vector<Subject> subjects;

public:
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

        std::ofstream write;
        write.open("admin.txt");
        write << this->username << ' ' << this->password;
        write.close();
    }

    ~Admin() {
        remove("admin.txt");
    }

#pragma region Functions

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

         std::ofstream write;
         write.open("admin.txt");
         write << this->username << ' ' << this->password;
         write.close();
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

         std::ofstream write;
         write.open("admin.txt");
         write << this->username << ' ' << this->password;
         write.close();
     }


    static void addUser() {
        std::string userUsername, userPassword;

        std::cout << "Enter username: ";
        getline(std::cin, userUsername);
        std::cout << "Enter password: ";
        getline(std::cin, userPassword);

        try
        {
            User newUser(userUsername, userPassword);
            newUser.writeUserData();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }


    void removeUser(const std::string& userToRemove) {
        std::string line;
        std::ifstream in;
        std::ofstream out;

        in.open("data.txt");
        out.open("tmp.txt");

        while(std::getline(in, line))
        {
            std::istringstream string_stream(line);
            std::string tmpUsername, tmpPassword;

            string_stream >> tmpUsername >> tmpPassword;
            if (tmpUsername != userToRemove)
            {
                out << tmpUsername << tmpPassword << ' ' << std::endl;
            }
        }

        in.close();
        out.close();

        remove("data.txt");
        rename("tmp.txt", "data.txt");
    }


    void editUser(const std::string& userToEdit, uint16_t UP_parameter) {
        /*
            UP_parameter:
                0 - username
                1 - parameter
        */

        std::ifstream in;
        std::ofstream out;
        std::string line;
        in.open("data.txt");
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

        in.close();
        out.close();

        remove("data.txt");
        rename("tmp.txt", "data.txt");
    }


    static void printUsers() {
        std::string line;
        std::ifstream stream("data.txt");
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


    void adminMainFunction() {
        uint16_t choice;
        std::string strLit;
        uint16_t  numLit = 0;

        std::cout
            << "1. Change username" << '\n'
            << "2. Change password" << '\n'
            << "3. Add new user" << '\n'
            << "4. Remove user" << '\n'
            << "5. Edit user" << '\n'
            << "6. Show all users" << '\n'
            << "> ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            this->changeUsername();
            break;

        case 2:
            this->changePassword();
            break;

        case 3:
            addUser();
            break;

        case 4:
            this->printUsers();
            std::cout << "Enter username to remove: ";
            std::getline(std::cin, strLit);
            this->removeUser(strLit);

            break;

        case 5:
            this->printUsers();
            std::cout << "Enter username to edit: ";
            std::getline(std::cin, strLit);
            std::cout
                << "0. Change username" << '\n'
                << "1. Change password" << '\n'
                << "> ";
            std::cin >> numLit;

            if (numLit > 1 or numLit < 0)
            {
                std::cout << "???" << std::endl;
                break;
            }
            else
            {
                this->editUser(strLit, numLit);
            }

            break;

        case 6:
            this->printUsers();
            break;
        
        default:
            break;
        }
    }

#pragma endregion
};

