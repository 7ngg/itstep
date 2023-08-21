#pragma once

#include <iostream>
#include <fstream>

#include "regex.hpp"

static bool isSignedIn = false;
static std::string fileName = "data.txt";

uint16_t UNPW_search(const std::string& name, const std::string& searchUsername, const std::string& searchPassword) {
    /*
        0 - не найдены ни логин, ни пароль
        1 - найдены и логин, и пароль
        2 - найден только логин
    */

    std::ifstream stream(name);

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
}


void sign_in() {
    std::string input_un, input_pw;

    if (isSignedIn)
    {
        throw std::invalid_argument("You are already signed in");
    }
    else
    {
        std::cout << "Username: ";
        getline(std::cin, input_un);
        std::cout << "Password: ";
        getline(std::cin, input_pw);

        if (UNPW_search(fileName, input_un, input_pw) == 1)
        {
            std::cout << "Authorization successful" << std::endl;
            isSignedIn = true;
        }
        else
        {
            throw std::invalid_argument("Authorization failed");
        }
    }
}


void sign_up() {
    std::string input_un, input_pw;

    std::cout << "Enter username: ";
    getline(std::cin, input_un);
    std::cout << "Enter password: ";
    getline(std::cin, input_pw);

    if (std::regex_match(input_un, regular::USERNAME) and std::regex_match(input_pw, regular::PASSWORD))
    {
        if (UNPW_search(fileName, input_un, input_pw) == 1 or UNPW_search(fileName, input_un, input_pw) == 2)
        {
            throw std::invalid_argument("Username already taken");
        }
        else
        {
            std::ofstream write;
            write.open(fileName, std::ios::app);
            write << input_un << ' ' << input_pw << std::endl;

            std::cout << "Registration successful" << std::endl;
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