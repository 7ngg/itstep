#include <iostream>
#include <regex>

#include "./include/json.hpp"
using json = nlohmann::json;

std::regex regexUsername ("((\\w)(0-9)){4, 16}");

int main(int, char**){
    std::string username;
    std::cin >> username;
    std::cout << std::regex_match(username, regexUsername);
}
