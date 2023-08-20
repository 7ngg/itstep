#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include "regex.hpp"
#include "admin.hpp"

static bool isSignedIn = false;
static std::string fileName = "data.txt";

uint16_t UNPW_search(const std::string& name, const std::string& searchUsername, const std::string& searchPassword) {
    /*
        0 - не найдены ни логин, ни пароль
        1 - найдены и логин, и пароль
        2 - найден только логин
    */

    std::ifstream stream(name);

    if (!stream)
    {
        std::cout << "Cannot open the file" << std::endl;
        throw std::invalid_argument("Cannot open the file");
    }

    std::string line;
    while (getline(stream, line))
    {
        std::istringstream string_stream(line);
        std::string username, password;

        if (string_stream >> username >> password)
        {
            if (username == searchUsername and password == searchPassword)
            {
                return 1;
            }
            else if (username == searchUsername)
            {
                return 2;
            }
        }
    }
    
    if (stream.eof() and !stream.fail())
    {
        return 0;
    }
    /*else if (stream.fail())
    {
        std::cout << "File cannot be read" << std::endl;
        throw std::invalid_argument("File cannot be read");
    }*/
    return 0;
}


void sign_in(char parameter) {
    std::string username, password;
    std::string input_un, input_pw;

    if (isSignedIn)
    {
        std::cout << "You are already signed in" << std::endl;
    }
    else
    {
        std::cout << "Username: ";
        getline(std::cin, input_un);
        std::cout << "Password: ";
        getline(std::cin, input_pw);

        if (parameter == 'a')
        {
            fileName = "admin.txt";
        }

        if (UNPW_search(fileName, input_un, input_pw) == 1)
        {
            std::cout << "Authorization successful" << std::endl;
            isSignedIn = true;
        }
        else
        {
            std::cout << "Authorization failed" << std::endl;
        }
    }
}


User sign_up() {
    std::string input_un, input_pw;
    User f;

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
            std::ofstream write;
            write.open("data.txt", std::ios::app);
            write << input_un << ' ' << input_pw << std::endl;

            std::cout << "Registration successful" << std::endl;
            User newUser { input_un, input_pw };
            return newUser;
        }
    }
    else if (!std::regex_match(input_un, regular::USERNAME) and std::regex_match(input_pw, regular::PASSWORD))
    {
        std::cout << "Invalid username" << std::endl;
    }
    else if (std::regex_match(input_un, regular::USERNAME) and !std::regex_match(input_pw, regular::PASSWORD))
    {
        std::cout << "Invalid password" << std::endl;
    }

    return f;
}


void sign_out() {
    if (isSignedIn)
    {
        std::cout << "Log off successful" << std::endl;
        isSignedIn = false;
    }
    else
    {
        std::cout << "You are not signed in" << std::endl;
    }
}