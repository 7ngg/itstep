#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <regex>
#include <fstream>

#include "regex.h"
#include "json.hpp"

using json = nlohmann::json;

bool first_boot = true;

int main() {
    std::string admin_username, admin_password;

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
                {"Username", admin_username},
                {"Password", admin_password},
        };

        std::ofstream stream("admin.json");
        stream << std::setw(4) << data << std::endl;
    }


    return 0;
}
