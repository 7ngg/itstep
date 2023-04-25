#pragma once

struct Book {
	char* name{};
	char* author{};
	char* publishingOffice{};
	char* genre{};

	Book() 
	{
		name = new char[32] {};
		author = new char[32] {};
		publishingOffice = new char[32] {};
		genre = new char[32] {};
	}

	Book(char* _name, char* _author, char* _publishingOffice, char* _genre)
	{
		name = _name;
		author = _author;
		publishingOffice = _publishingOffice;
		genre = _genre;
	}

	void printBook();
	void editBook();
	bool authorSearch(char* searchingAuthor);
	bool nameSearch(char* searchingName);
};


//void nameSort(Book*& lib, uint16_t booksCount);