#include <iostream>
#include <regex>
#include <string>
#include <fstream>

#include "./include/json.hpp"
using json = nlohmann::json;

std::regex regular (R"([a-zA-Z0-9]{4,16})");

class userData {
    std::string username;
    std::string password;

public:
    userData() = default;

    userData(std::string _username, std::string _password) {
        if (not std::regex_match(_username, regular))
        {
            throw std::invalid_argument("Invalid username");
        }
        if (not std::regex_match(password, regular))
        {
            throw std::invalid_argument("Invalid password");
        }
        
        this->username = _username;
        this->password = _password;
    }


    // friend std::istream& operator >> (std::istream& stream, userData user) {
    //     std::string tmp_username, tmp_password;

    //     while (std::regex_match(tmp_username, regular))
    //     {
    //         std::cout << "Username: ";
    //         std::getline(std::cin, tmp_username);

    //         if(not std::regex_match(tmp_username, regular))
    //         {
    //             std::cout << "Invalid username. Try again..." << std::endl;
    //         }
    //     }

    //     while (std::regex_match(tmp_password, regular))
    //     {
    //         std::cout << "Username: ";
    //         std::getline(std::cin, tmp_password);

    //         if(not std::regex_match(tmp_password, regular))
    //         {
    //             std::cout << "Invalid password. Try again..." << std::endl;
    //         }
    //     }
        
    //     user.username = tmp_username;
    //     user.password = 
        
    // }
};


int main(int, char**){
    static uint16_t choice = 0;
    std::string username, password;

    std::cout
        << "1. Sign in" << '\n'
        << "2. Sign up" << '\n'
        << "> ";
    std::cin >> choice;
    std::cin.ignore();

    switch (choice)
    {
    case 1:
    {
        json j = {
            {"First", 1},
            {2, 2},
        };

        std::cout << j[0].dump();
    }
    
    case 2:
    {
        std::cout << "Username: ";
        std::getline(std::cin, username);
        std::cout << "Password: ";
        std::getline(std::cin, password);

        try
        {
            userData(username, password);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            break;
        }
        
        std::ofstream load;
        load.open("data.json", std::ios::app);
        json data = {
            {username, password},
        };
        load << std::setw(4) << data << std::endl;

        break;
    }

    default:
        break;
    }
}
