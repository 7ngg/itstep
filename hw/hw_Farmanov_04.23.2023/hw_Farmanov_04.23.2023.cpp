#include <iostream>

#include "struct.h"


animal addAnimal() {
	animal newAnimal{};
	uint16_t x = 0;			// var to choose a gender
	char* animalName = new char[32] {};

	std::cout << "Enter animal's name (32 characters maximum): ";
	std::cin.ignore();
	std::cin.getline(animalName, 32);
	newAnimal.name = animalName;

	std::cout
		<< "Choose animal's gender:" << '\n'
		<< "1. Male" << '\n'
		<< "2. Female" << '\n'
		<< "> ";
	std::cin >> x;

	std::cout << "Enter animal's age: ";
	std::cin >> newAnimal.age;

	newAnimal.gender = (gender)x;
	newAnimal.aviaryCheck = true;

	return newAnimal;
}


int main() {
	using namespace std;

	zoo newZoo{};
	bool flag = true;

	cout << "Enter the name of the zoo (32 characters maximum): ";
	cin.getline(newZoo.name, 32);
	cout << "Enter the maximum count of animals: ";
	cin >> newZoo.maxCount;
	newZoo.animals = new animal[newZoo.maxCount];

	while (flag)
	{
		uint16_t choice = 0;
		uint16_t animalChocie = 0;

		cout
			<< "Choose operation: " << '\n'
			<< "1. Add an animal" << '\n'
			<< "2. Remove an animal" << '\n'
			<< "3. Edit the animals's info" << '\n'
			<< "4. Show all animals" << '\n'
			<< "0. Exit" << '\n'
			<< "> ";
		cin >> choice;
		system("cls");

		switch (choice)
		{
		case 0:
			flag = false;
			break;
			
		case 1:
			if (newZoo.currentCount != newZoo.maxCount)
			{
				newZoo.animals[newZoo.currentCount] = addAnimal();
				newZoo.currentCount += 1;
			}
			else
			{
				cout << "No free aviary" << endl;
				system("pause");
			}

			break;
			
		case 2:
			if (newZoo.currentCount == 0)
			{
				cout << "No animals at the zoo" << endl;
			}
			else
			{
				newZoo.showAllAnimals();
				cout << "Choose an animal to remove: ";
				cin >> animalChocie;
				newZoo.animals[animalChocie - 1].remove();
				newZoo.currentCount -= 1;

				for (size_t i = 0; i < newZoo.maxCount; i++)
				{
					uint16_t index = i;
					while (index < newZoo.maxCount - 1 and not newZoo.animals[index].aviaryCheck)
					{
						animal tmp = newZoo.animals[index];
						newZoo.animals[index] = newZoo.animals[index + 1];
						newZoo.animals[index + 1] = tmp;
						index += 1;
					}
				}
			}

			break;

		case 3:
			newZoo.showAllAnimals();
			cout << "Choose an animal to edit: ";
			cin >> animalChocie;
			newZoo.edit(animalChocie - 1);

			break;

		case 4:
			newZoo.showAllAnimals();
			system("pause");
			break;

		default:
			break;
		}
		system("cls");
	}

	return 0;
}