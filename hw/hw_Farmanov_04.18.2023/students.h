#define subjectsCount 10

#pragma once

struct Students {
	char* name{};
	char* surname{};
	bool marks[subjectsCount]{};

	Students()
	{
		name = new char[20];
		surname = new char[20];
		marks;
	}

	Students(char* _name, char* _surname, bool _marks[subjectsCount]) {
		name = _name;
		surname = _surname;
		for (size_t i = 0; i < subjectsCount; i++)
		{
			marks[i] = _marks[i];
		}
	}

	void printStudentMarks();
	double averageGrade();
	void printInitials();
	uint16_t deptsCount();
};