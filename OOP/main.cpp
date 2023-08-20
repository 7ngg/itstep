#include <iostream>

#include "authorization.hpp"
#include "admin.hpp"


int main() {
    Admin admin{};
    uint16_t choice = 0;

    std::cout
        << "1. Sign up" << '\n'
        << "2. Sign in" << '\n'
        << "2. Sign out" << '\n'
        << "0. Exit"
        << "> ";

    while(std::cin >> choice)
    {
        std::cin.ignore();
        switch (choice) {
            case 0: {
                admin.printUsers();
                break;
            }
            case 1:

                break;

            case 2: {
                std::cout
                        << "1. Admin" << '\n'
                        << "2. User" << '\n'
                        << "> ";
                std::cin >> choice;

                switch (choice) {
                    case 1:
                        sign_in('a');
                        break;

                    case 2:
                        sign_in('u');
                        break;

                    default:
                        std::cout << "Authorization failed" << std::endl;
                        break;
                }
            }

            default:
                std::cout << "No such option" << std::endl;
                break;
        }
    }

    return 0;
}
