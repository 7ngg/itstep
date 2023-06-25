#include <iostream>
#include <string>

#include "circle.h"
#include "airplane.h"


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


int main() {
	uint16_t choice = 0;

	std::cout
		<< "Choose task:" << '\n'
		<< "1. Circle" << '\n'
		<< "2. Airplane" << '\n'
		<< "> ";
	std::cin >> choice;

	switch (choice)
	{
	case 1:
	{
		uint16_t rad_1{}, rad_2{};
		bool flag = true;
		choice = 0;

		std::cout << "Enter radius 1: ";
		std::cin >> rad_1;
		circle circle_1(rad_1);

		std::cout << "Enter radius 2: ";
		std::cin >> rad_2;
		circle circle_2(rad_2);

		while (flag)
		{
			std::cout
				<< "1. ==" << '\n'
				<< "2. >" << '\n'
				<< "3. <" << '\n'
				<< "4. Increase radius" << '\n'
				<< "5. Decrease radius" << '\n'
				<< "6. Get circle length" << '\n'
				<< "0. Exit" << '\n'
				<< "> ";
			std::cin >> choice;

			int32_t increment{}, decrement{};

			switch (choice)
			{
			case 0:
				flag = false;
				break;

			case 1:
				boolPrint((circle_1 == circle_2));
				break;

			case 2:
				boolPrint((circle_1 > circle_2));
				break;

			case 3:
				boolPrint((circle_1 < circle_2));
				break;

			case 4:
				std::cout
					<< "Which radius would you like to increase?" << '\n'
					<< "Circle 1. Radius = " << circle_1.getRadius() << '\n'
					<< "Circle 2. Radius = " << circle_2.getRadius() << '\n'
					<< "> ";
				std::cin >> choice;

				std::cout << "Enter increment: ";
				std::cin >> increment;

				switch (choice)
				{
				case 1:
					circle_1 += increment;
					break;

				case 2:
					circle_2 += increment;
					break;

				default:
					break;
				}
				break;

			case 5:
				std::cout
					<< "Which radius would you like to decrease?" << '\n'
					<< "Circle 1. Radius = " << circle_1.getRadius() << '\n'
					<< "Circle 2. Radius = " << circle_2.getRadius() << '\n'
					<< "> ";
				std::cin >> choice;

				std::cout << "Enter decrement: ";
				std::cin >> decrement;

				switch (choice)
				{
				case 1:
					circle_1 -= decrement;
					break;

				case 2:
					circle_2 -= decrement;
					break;

				default:
					break;
				}
				break;

			case 6:
				std::cout
					<< "Which circle length would you like to get?" << '\n'
					<< "Circle 1. Radius = " << circle_1.getRadius() << '\n'
					<< "Circle 2. Radius = " << circle_2.getRadius() << '\n'
					<< "> ";
				std::cin >> choice;

				switch (choice)
				{
				case 1:
					std::cout << "Circle_1 length = " << circle_1.getLength() << std::endl;
					break;
				
				case 2:
					std::cout << "Circle_2 length = " << circle_2.getLength() << std::endl;
					break;

				default:
					break;
				}
				break;

			default:
				break;
			}
		}
		break;
	}

	case 2:
	{
		bool flag = true;
		choice = 0;

		std::cout << "Plane 1" << std::endl;
		Airplane plane_1{};

		std::cout << "Plane 2" << std::endl;
		Airplane plane_2{};

		while (flag)
		{
			std::cout
				<< "1. ==" << '\n'
				<< "2. >" << '\n'
				<< "3. <" << '\n'
				<< "4. ++" << '\n'
				<< "5. --" << '\n'
				<< "6. Get type" << '\n'
				<< "0. Exit" << '\n'
				<< "> ";
			std::cin >> choice;

			switch (choice)
			{
			case 0:
				flag = false;
				break;

			case 1:
				boolPrint(plane_1 == plane_2);
				break;
			
			case 2:
				boolPrint(plane_1 > plane_2);
				break;
			
			case 3:
				boolPrint(plane_1 < plane_2);
				break;
				
			case 4:
				std::cout
					<< "Which plane's passengers count would you like to increase?" << '\n'
					<< "1. Plane 1" << '\n'
					<< "2. Plane 2" << '\n'
					<< "> ";
				std::cin >> choice;

				switch (choice)
				{
				case 1:
					std::cout << "Plane 1 passengers count: " << plane_1.passengersCount << std::endl;
					++plane_1.passengersCount;
					std::cout << "Plane 1 passengers count after incresing: " << plane_1.passengersCount << std::endl;

					break;

				case 2:
					std::cout << "Plane 2 passengers count: " << plane_2.passengersCount << std::endl;
					++plane_2.passengersCount;
					std::cout << "Plane 2 passengers count after incresing: " << plane_2.passengersCount << std::endl;

					break;

				default:
					break;
				}

				break;

			case 5:
				std::cout
					<< "Which plane's passengers count would you like to decrease?" << '\n'
					<< "1. Plane 1" << '\n'
					<< "2. Plane 2" << '\n'
					<< "> ";
				std::cin >> choice;

				switch (choice)
				{
				case 1:
					std::cout << "Plane 1 passengers count: " << plane_1.passengersCount << std::endl;
					--plane_1.passengersCount;
					std::cout << "Plane 1 passengers count after decresing: " << plane_1.passengersCount << std::endl;

					break;

				case 2:
					std::cout << "Plane 2 passengers count: " << plane_2.passengersCount << std::endl;
					--plane_2.passengersCount;
					std::cout << "Plane 2 passengers count after decresing: " << plane_2.passengersCount << std::endl;

					break;

				default:
					break;
				}

				break;

			case 6:
				std::cout
					<< "Which plane's type would you like to get?" << '\n'
					<< "1. Plane 1" << '\n'
					<< "2. Plane 2" << '\n'
					<< "> ";
				std::cin >> choice;

				switch (choice)
				{
				case 1:
					std::cout << plane_1.getType() << std::endl;
					break;
				
				case 2:
					std::cout << plane_2.getType() << std::endl;
					break;

				default:
					break;
				}

				break;

			default:
				break;
			}
		}

		break;
	}

	default:
		break;
	}

	return 0;
}