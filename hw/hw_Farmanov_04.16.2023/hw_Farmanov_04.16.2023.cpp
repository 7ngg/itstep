#include <iostream>
#include "structure.h"


void nameSort(Book*& lib, uint16_t booksCount) {
	for (size_t i = 0; i < booksCount; i++)
	{
		uint16_t index = i;
		while (index > 0 and int(lib[index].name[0]) < int(lib[index - 1].name[0]))
		{
			Book tmp = lib[i - 1];
			lib[index - 1] = lib[index];
			lib[index] = tmp;
			index -= 1;
		}
	}
}


void authorSort(Book*& lib, uint16_t booksCount) {
	for (size_t i = 0; i < booksCount; i++)
	{
		uint16_t index = i;
		while (index > 0 and int(lib[index].author[0]) < int(lib[index - 1].author[0]))
		{
			Book tmp = lib[i - 1];
			lib[index - 1] = lib[index];
			lib[index] = tmp;
			index -= 1;
		}
	}
}


void publishingOfficeSort(Book*& lib, uint16_t booksCount) {
	for (size_t i = 0; i < booksCount; i++)
	{
		uint16_t index = i;
		while (index > 0 and int(lib[index].publishingOffice[0]) < int(lib[index - 1].publishingOffice[0]))
		{
			Book tmp = lib[i - 1];
			lib[index - 1] = lib[index];
			lib[index] = tmp;
			index -= 1;
		}
	}
}


Book addBook()
{
	using namespace std;
	char* test = new char[5] {"test"};

	char* name = new char[32]{};
	char* author = new char[32]{};
	char* publishingOffice = new char[32]{};
	char* genre = new char[32];

	cout << "Enter book name: ";
	cin >> name;
	cout << "Enter author: ";
	cin >> author;
	cout << "Enter publishing office: ";
	cin >> publishingOffice;
	cout << "Enter genre: ";
	cin >> genre;

	Book newBook = Book(name, author, publishingOffice, genre);
	return newBook;
}

int main() {
	using namespace std;

	bool flag = true;
	uint16_t booksCount = 0;
	Book* library = new Book[booksCount]{};

	
	while (flag)
	{
		uint16_t choice = 0;
		char* searchingAuthor = new char[32] {};
		char* searchingBook = new char[32] {};

		cout
			<< "Choose operation: " << endl
			<< "1. Add new book" << endl
			<< "2. Show all books" << endl
			<< "3. Search by author" << endl
			<< "4. Search by book name" << endl
			<< "5. Sort by name" << endl
			<< "6. Sort by author" << endl
			<< "7. Sort by publishing office" << endl
			<< "0. Exit" << endl
			<< "> ";
		cin >> choice;
		
		switch (choice)
		{
		case 0:
			flag = false;
			break;

		case 1:
			if (booksCount == 0)
			{
				booksCount += 1;
				library = new Book[booksCount];
				library[0] = addBook();
			}
			else
			{
				booksCount += 1;
				Book* tmp = new Book[booksCount - 1];

				for (size_t i = 0; i < booksCount - 1; i++)
				{
					tmp[i] = library[i];
				}

				delete[] library;
				library = new Book[booksCount]{};

				for (size_t i = 0; i < booksCount; i++)
				{
					library[i] = tmp[i];
				}
				library[booksCount - 1] = addBook();
			}

			break;

		case 2:
			for (size_t i = 0; i < booksCount; i++)
			{
				library[i].printBook();
			}

			break;

		case 3:
			cout << "Enter searching author: ";
			cin >> searchingAuthor;

			for (size_t i = 0; i < booksCount; i++)
			{
				if (library[i].authorSearch(searchingAuthor))
				{
					library[i].printBook();
				}
			}

			break;

		case 4:
			cout << "Enter name of the book: ";
			cin >> searchingBook;

			for (size_t i = 0; i < booksCount; i++)
			{
				if (library[i].nameSearch(searchingBook))
				{
					library[i].printBook();
				}
			}

			break;

		case 5:
			nameSort(library, booksCount);

			break;

		default:
			break;
		}
	}
	return 0;
}
