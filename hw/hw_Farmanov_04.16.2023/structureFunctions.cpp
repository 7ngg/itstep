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



