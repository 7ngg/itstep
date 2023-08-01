#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <regex>
#include <fstream>

#include "regex.h"
#include "json.hpp"

using json = nlohmann::json;

static bool first_boot = false;

int main() {
    std::string admin_username, admin_password;
    static uint16_t choice = 0;

    if (first_boot)
    {
        first_boot = false;

        while (not std::regex_match(admin_username, USERNAME))
        {
            std::cout << "Enter admin username: ";
            std::getline(std::cin, admin_username);
        }
        while (not std::regex_match(admin_password, PASSWORD))
        {
            std::cout << "Enter admin password: ";
            std::getline(std::cin, admin_password);
        }

        json data = {
                {"Password", admin_password},
                {"Username", admin_username},
        };

        std::ofstream stream("admin.json");
        stream << std::setw(4) << data << std::endl;
    }

    std::cout 
        << "1. Administrator" << '\n'
        << "2. User" << '\n'
        << "> ";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        

        break;
    
    default:
        break;
    }   


    return 0;
}
