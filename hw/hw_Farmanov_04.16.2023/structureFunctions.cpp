#include "structure.h"
#include <iostream>

void Book::printBook()
{
	std::cout
		<< "Name - " << name << '\n'
		<< "Author - " << author << '\n'
		<< "Publishing office - " << publishingOffice << '\n'
		<< "Genre - " << genre << '\n'
		<< std::endl;
}
