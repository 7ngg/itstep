#pragma once

#include "regex.hpp"

class User {
public:
    std::string username, password;

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


    void writeUserData() const {
        std::ofstream write;
        write.open("data.txt", std::ios::app);
        write << this->username << ' ' << this->password << std::endl;
        write.close();
    }
};