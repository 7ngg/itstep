#include "structure.h"
#include <iostream>


uint16_t len(char* str) {
	uint16_t result = 0;
	for (size_t i = 0; str[i] != '\0'; i++)
	{
		result += 1;
	}

	return result;
}


bool compareStr(char* str1, char* str2) {
	bool flag = false;

	if (len(str1) != len(str2))
	{
		return flag;
	}

	uint16_t length = len(str1);

	for (size_t i = 0; i < length; i++)
	{
		if (str1[i] == str2[i])
		{
			flag = true;
		}
		else
		{
			flag = false;
			return flag;
		}
	}
	return flag;
}


void Book::printBook() {
	std::cout
		<< "Name - " << name << '\n'
		<< "Author - " << author << '\n'
		<< "Publishing office - " << publishingOffice << '\n'
		<< "Genre - " << genre << '\n'
		<< std::endl;
}


bool Book::authorSearch(char* searchingAuthor) {
	if (compareStr(searchingAuthor, author))
	{
		return true;
	}
	return false;
}


bool Book::nameSearch(char* searchingName) {
	if (compareStr(searchingName, name))
	{
		return true;
	}
	return false;
}


void Book::editBook() {
	uint16_t editChoice = 0;
	std::cout 
		<< "Enter element to edit: \n"
		<< "1. Name\n"
		<< "2. Author\n"
		<< "3. Publishing office\n"
		<< "4. Genre\n"
		<< "> ";
	std::cin >> editChoice;

	switch (editChoice)
	{
	case 1:
		delete[] name;
		name = new char[32];

		std::cout << "Enter new name: ";
		std::cin >> name;

		break;

	case 2:
		delete[] author;
		author = new char[32];

		std::cout << "Enter author: ";
		std::cin >> author;

		break;

	case 3:
		delete[] publishingOffice;
		publishingOffice = new char[32];

		std::cout << "Enter publishing office: ";
		std::cin >> publishingOffice;

		break;

	case 4:
		delete[] genre;
		genre = new char[32];

		std::cout << "Enter genre: ";
		std::cin >> genre;

		break;

	default:
		std::cout << "No such case\n";
		break;
	}
}



