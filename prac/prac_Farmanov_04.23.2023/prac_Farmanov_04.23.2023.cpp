#include <iostream>
#include <stdint.h>

struct Animal{
	char* name{};
	char* gender{};
	uint16_t age{};
	
	Animal()
	{
		name = new char[16];
		gender = new char[6];
		age = 0;
	}

	Animal(char* _name, char* _gender, uint16_t _age)
	{
		name = _name;
		gender = _gender;
		age = _age;
	}
};

struct Zoo{
	char* name = new char[16] {};
	int max = 10;
	int current = 0;
	Animal* animals = new Animal[current];

	void showAllAnimals()
	{
		for (size_t i = 0; i < current; ++i) 
		{
			std::cout 
				<< name << " Zoo" << std::endl
				<< animals[i].name << '\t' << animals[i].gender << '\t' << animals[i].age << std::endl;
		}
	}
};


Animal AddAnimal()
{
	char* name = new char[16];
	char* gender = new char[6];
	uint16_t age = 0;

	std::cout << "Enter name: ";
	std::cin.getline(name, 16);
	std::cout << "Enter genedr: ";
	std::cin.getline(gender, 6);
	std::cout << "Enter age: ";
	std::cin >> age;

	Animal newAnimal = Animal(name, gender, age);
	return newAnimal;
}


int main(){
	using namespace std;

	Zoo newZoo{};

	cout << "Enter name of the zoo: ";
	cin >> newZoo.name;
	cout << "Enter maximum count of animals: ";
	cin >> newZoo.max;

	return 0;
}
