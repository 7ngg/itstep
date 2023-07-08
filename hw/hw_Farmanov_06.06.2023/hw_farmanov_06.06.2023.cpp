#include <iostream>
#include <iso646.h>

#include "overcoat.h"
#include "flat.h"


void boolPrint(bool expression) {
	if (expression)
	{
		std::cout << "True" << std::endl;
	}
	else if (not expression)
	{
		std::cout << "False" << std::endl;
	}
}


int main(int, char**){
    int16_t choice{};
    Overcoat coat_1{}, coat_2{}, coat_3{};
    Flat flat_1{}, flat_2{}, flat_3{};

    std::cout 
        << "Choose task: " << '\n'
        << "1. Overcoat" << '\n'
        << "2. Flat" << '\n'
        << "> ";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        std::cout << "Coat 1 data:" << std::endl;
        std::cin >> coat_1;
        system("cls");
        std::cout << "Coat 2 data:" << std::endl;
        std::cin >> coat_2;

        coat_3 = coat_1;

        std::cout
            << "Coat 1:" << '\n' << '\t' << coat_1 << '\n'
            << "Coat 2:" << '\n' << '\t' << coat_2 << '\n'
            << "Coat 3:" << '\n' << '\t' << coat_3 << '\n';

        std::cout << "Coat 1 price == Coat 2 price: ";
        boolPrint(coat_1 == coat_2);
        
        std::cout << "Coat 1 price > Coat 3 price: ";
        boolPrint(coat_1 == coat_2);

        break;

    case 2:
        std::cout << "Flat 1 data: " << std::endl;
        std::cin >> flat_1;
        system("cls");
        std::cout << "Flat 2 data: " << std::endl;
        std::cin >> flat_2;

        flat_3 = flat_2;

        std::cout << "Flat 3 area == Flat 2 area: ";
        boolPrint(flat_3 == flat_2);

        std::cout << "Flat 1 price > Flat 2 price: ";
        boolPrint(flat_1 > flat_2);

        break;

    }

    return 0;
}
