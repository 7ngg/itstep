#include "authorization.hpp"

int main(){
    std::string username, password;
    static uint16_t choice = 0;
    static bool flag = true;

    while (flag)
    {
        std::cout
            << "0. Shut down" << '\n'
            << "1. Sign up" << '\n'    
            << "2. Sign in" << '\n'
            << "3. Sign out" << '\n'
            << "> ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice)
        {
        case 0:
            flag = false;
            break;

        case 1:
            try
            {
                sign_up();
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            break;
        
        case 2:
            try
            {
                sign_in();
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            break;

        case 3:
            try
            {
                sign_out();
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            break;

        default:
            std::cout << "No such option" << std::endl;
            break;
        }
    }
}
