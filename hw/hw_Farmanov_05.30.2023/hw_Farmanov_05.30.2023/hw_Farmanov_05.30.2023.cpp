#include <iostream>

#include "fractions.h"
#include "classroom.h"
#include "globalFunctions.h"


int main() {
	uint16_t choice{};

	std::cout
		<< "Choose option: " << '\n'
		<< "1. Fractions" << '\n'
		<< "2. Classroom" << '\n'
		<< "> ";
	std::cin >> choice;
	std::cin.ignore();

	switch (choice)
	{
	case 1:
	{
		choice = 0;
		fraction x{}, y{};
		
		std::cout << "Enter fraction 1: ";
		std::cin >> x;
		std::cout << "Enter fraction 2: ";
		std::cin >> y;

		std::cout
			<< "Choose operation: " << '\n'
			<< "1. +" << '\n'
			<< "2. -" << '\n'
			<< "3. *" << '\n'
			<< "4. /" << '\n'
			<< "5. >" << '\n'
			<< "6. <" << '\n'
			<< "7. ==" << std::endl
			<< "> ";
		std::cin >> choice;
		std::cin.ignore();

		switch (choice)
		{
		case 1:
			x + y;
			std::cout << "Result: " << x << std::endl;
			break;

		case 2:
			x - y;
			std::cout << "Result: " << x << std::endl;
			break;

		case 3:
			x * y;
			std::cout << "Result: " << x << std::endl;
			break;

		case 4:
			x / y;
			std::cout << "Result: " << x << std::endl;
			break;

		case 5:
			boolPrint((x > y)); 
			break;

		case 6:
			boolPrint((x < y));
			break;

		case 7:
			boolPrint((x == y));
			break;

		default:
			break;
		}

		break;
	}

	case 2:
	{
		Classroom myClass{};
		bool flag = true;
		choice = 0;

		std::cin >> myClass;
		
		while (flag)
		{
			std::cout
				<< "1. Add student" << '\n'
				<< "2. Show classroom" << '\n'
				<< "0. Exit" << '\n'
				<< "> ";
			std::cin >> choice;

			switch (choice)
			{
			case 0:
				flag = false;
				break;

			case 1:
				if (myClass.iterator < myClass.getStudentsCount())
				{
					std::cin >> myClass.students[myClass.iterator];
					myClass.iterator += 1;
				}
				else
				{
					std::cout << "Classroom is full" << std::endl;
				}

				break;

			case 2:
				std::cout << myClass << std::endl;
				break;

			default:
				break;
			}
		}

	}

	default:
		break;
	}
	

	return 0;
}