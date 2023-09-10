#pragma once

#include <iostream>
#include <string>

#include "regex.hpp"
#include "admin.hpp"
#include "exeptions.hpp"

enum permissions
{
    NONE,
    ADMIN,
    USER,
};

static permissions isSignedIn = NONE;
static std::string fileName = "data.json";


std::string printPermissionLevel(permissions level) {
    if (level == ADMIN)
    {
        return "admin";
    }
    else if (level == USER)
    {
        return "user";
    }
}


//uint16_t UNPW_search(const std::string& name, const std::string& searchUsername, const std::string& searchPassword) {
//    /*
//        0 - не найдены ни логин, ни пароль
//        1 - найдены и логин, и пароль
//        2 - найден только логин
//    */
//
//    std::ifstream stream(name);
//
//    std::string line;
//    while (getline(stream, line))
//    {
//        std::istringstream string_stream(line);
//        std::string username, password;
//
//        if (string_stream >> username >> password)
//        {
//            if (username == searchUsername and password == searchPassword)
//            {
//                return 1;
//            }
//            else if (username == searchUsername)
//            {
//                return 2;
//            }
//        }
//    }
//    
//    //if (stream.eof() and !stream.fail())
//    //{
//    //    return 0;
//    //}
//    ///*else if (stream.fail())
//    //{
//    //    std::cout << "File cannot be read" << std::endl;
//    //    throw std::invalid_argument("File cannot be read");
//    //}*/
//    //return 0;
//}


uint16_t UNPW_search(const std::string& name, const std::string& searchUsername, const std::string& searchPassword) {
    std::ifstream stream(name);
    json userDataArray = json::parse(stream);

    for (const auto& item : userDataArray)
    {
        if ((item["username"] == searchUsername) and (item["password"] == searchPassword))
            return 1;
        else if (item["username"] == searchUsername)
            return 2;
    }
    return 0;
}


User* sign_up() {
    std::string input_un, input_pw;

    std::cout << "Enter username: ";
    getline(std::cin, input_un);
    std::cout << "Enter password: ";
    getline(std::cin, input_pw);

    if (std::regex_match(input_un, regular::USERNAME) and std::regex_match(input_pw, regular::PASSWORD))
    {
        if (UNPW_search(fileName, input_un, input_pw) == 1 or UNPW_search(fileName, input_un, input_pw) == 2)
        {
            std::cout << "Username already taken" << std::endl;
            throw std::invalid_argument("Username already taken");
        }
        else
        {
            std::cout << "Registration successful" << std::endl;
            User* newUser = new User{ input_un, input_pw };
            return newUser;
        }
    }
    else if (!std::regex_match(input_un, regular::USERNAME) and std::regex_match(input_pw, regular::PASSWORD))
    {
        throw std::invalid_argument("Invalid username");
    }
    else if (std::regex_match(input_un, regular::USERNAME) and !std::regex_match(input_pw, regular::PASSWORD))
    {
        throw std::invalid_argument("Invalid password");
    }
}


std::string sign_in(permissions level) {
    std::string input_un, input_pw;

    if (isSignedIn)
    {
        throw AlreadySignedIn();
    }
    else
    {
        std::cout << "Username: ";
        getline(std::cin, input_un);
        std::cout << "Password: ";
        getline(std::cin, input_pw);

        if (level == ADMIN)
        {
            fileName = "admin.json";
            if (UNPW_search(fileName, input_un, input_pw) == 1)
            {
                std::cout << "Authorization successful" << std::endl;
                isSignedIn = ADMIN;
                return input_un;
            }
            else
            {
                throw std::invalid_argument("Authorization failed");
            }
        }
        else if (level == USER)
        {
            fileName = "data.json";
            if (UNPW_search(fileName, input_un, input_pw) == 1)
            {
                std::cout << "Authorization successful" << std::endl;
                isSignedIn = USER;
                return input_un;
            }
            else
            {
                throw std::invalid_argument("Authorization failed");
            }
        }
    }
}


void sign_out() {
    if (isSignedIn)
    {
        std::cout << "Log off successful" << std::endl;
        isSignedIn = NONE;
    }
    else
    {
        std::cout << "You are not signed in" << std::endl;
    }
}