#include <iostream>

#include "authorization.hpp"


int main() {
    Admin admin();
    bool flag = true;

    while(flag)
    {
        char choice{};
        
        std::cout
            << "1. User sign up" << '\n'
            << "2. Sign in" << '\n'
            << "3. Sign out" << '\n'
            << "0. Exit" << '\n'
            << "> ";
        std::cin >> choice;
        std::cin.ignore();
        uint16_t choiceCheck = atoi(&choice);

        switch (choiceCheck)
        {
        case 0:
            flag = false;
            break;

        case 1:
        {
            try
            {
                User* newUser = sign_up();
                admin.addUser(newUser);
            }
            catch (const std::exception& e)
            {
                std::cerr << e.what() << std::endl;
            }

            break;
        }

        case 2:
        {
            std::string switchUsername;

            std::cout
                << "1. Admin" << '\n'
                << "2. User" << '\n'
                << "> ";
            std::cin >> choice;
            std::cin.ignore();
            
            choiceCheck = atoi(&choice);

            switch (choiceCheck)
            {
            case 1:
                try
                {
                    std::string ID = sign_in(ADMIN);
                    if (isSignedIn == ADMIN)
                    {
                        admin.adminMainFunction();
                    }
                    else
                    {
                        throw InsufficientPermissions();
                    }
                }
                catch (const std::exception& e)
                {
                    std::cerr << e.what() << std::endl;
                }

                break;

            case 2:
                try
                {
                    std::string ID = sign_in(USER);
                    if (isSignedIn == USER)
                    {
                        User* activeUser = admin.getUserData(ID);
                        activeUser->availableTasks = admin.subjects;
                        activeUser->userMainFunction();
                        admin.updateUserGrades(ID, activeUser);
                    }
                    else
                    {
                        throw InsufficientPermissions("You are signed in as admin");
                    }
                }
                catch (const std::exception& e)
                {
                    std::cerr << e.what() << std::endl;
                }

                break;

            default:
                std::cout << "No such option" << std::endl;
                break;
            }

            break;
        }

        case 3:
            sign_out();
            break;

        default:
            std::cout << "No such option" << '\n';
            break;
        }

        system("pause");
        system("cls");
    }

    return 0;
}
