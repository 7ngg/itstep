#include <iostream>

#include "struct.h"


void zoo::showAllAnimals() {
	for (size_t i = 0; i < maxCount; i++)
	{
		if (animals[i].aviaryCheck)
		{
			const char* _gender = new char[6] {};

			switch (animals[i].gender)
			{
			case MALE:
				_gender = "male";
				break;
			case FEMALE:
				_gender = "female";
				break;
			default:
				break;
			}

			std::cout
				<< "Aviary " << i + 1 << '\n' << '\t'
				<< "Name: " << animals[i].name << '\t' << "Gender: " << _gender << '\t' << "Age: " << animals[i].age << '\n';
		}
	}
}


void animal::remove() {
	aviaryCheck = false;
}


void zoo::edit(uint16_t aviaryNum) {
	uint16_t choice = 0;

	std::cout
		<< "Choose a variable to edit:" << '\n'
		<< "1. Name" << '\n'
		<< "2. Gender" << '\n'
		<< "3. Age" << '\n'
		<< "> ";
	std::cin >> choice;

	switch (choice)
	{
	case 1:
		delete[] animals[aviaryNum].name;
		animals[aviaryNum].name = new char[32];

		std::cout << "Enter new name of the animal (32 characters maximum): ";
		std::cin.ignore();
		std::cin.getline(animals[aviaryNum].name, 32);

		break;
	
	case 2:
		std::cout << "You can't change gender lol" << '\n';
		system("pause");
		break;

	case 3:
		std::cout << "Enter animal's age: ";
		std::cin >> animals[aviaryNum].age;

		break;

	default:
		break;
	}
}
