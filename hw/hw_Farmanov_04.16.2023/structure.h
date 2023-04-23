#pragma once

struct Book {
	char* name{};
	char* author{};
	char* publishingOffice{};
	char* genre{};

	Book()
	{
		name = new char[32]{};
		author = new char[32]{};
		publishingOffice = new char[32]{};
		genre = new char[32]{};
	}

	void printBook();
};
