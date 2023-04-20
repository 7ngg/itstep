#include <iostream>
#include <ctime>

#include "students.h"

Students* newStudent() {
	char* name = new char[20];
	char* surname = new char[20];
	bool grades[subjectsCount]{};

	std::cout << "Enter surname: ";
	std::cin >> surname;
	std::cout << "Enter name: ";
	std::cin >> name;

	Students* newStudent = new Students(name, surname, grades);
	return newStudent;
}


void inputMarks(Students &student) {
	for (size_t i = 0; i < subjectsCount; i++)
	{
		std::cout << "Enter grade for subject " << i << ". (f - fail / p - pass): ";
		char mark{};
		std::cin >> mark;
		if (mark == 'p')
		{
			student.marks[i] = true;
		}
		else if (mark == 'f')
		{
			student.marks[i] = false;
		}
		else
		{
			std::cout << "No such grade. Subject will be marked as failed\n";
		}
		std::cout << std::endl;
	}
}


int main() {
	using namespace std;
	srand(time(NULL));

	bool flag = true;
	uint16_t choice = 0;
	uint16_t studentsCount = 0;

	Students* stream = new Students[studentsCount]{};

	while (flag)
	{
		uint16_t case2Choice = 0, case4Choice = 0;

		cout
			<< "Choose operation: \n"
			<< "1. Add student\n"
			<< "2. Input student's marks\n"
			<< "3. Print all students' names\n"
			<< "4. Print marks of specific student\n"
			<< "5. Print deptors\n"
			<< "0. Exit\n"
			<< "> ";
		cin >> choice;

		switch (choice)
		{
		case 0:
			flag = false;
			break;

		case 1:
			if (studentsCount == 0)
			{
				studentsCount += 1;
				stream = new Students[studentsCount];
				stream[0] = *newStudent();
			}
			else
			{
				studentsCount += 1;
				Students* tmp = new Students[studentsCount];
				
				for (size_t i = 0; i < studentsCount - 1; i++)
				{
					tmp[i] = stream[i];
				}
				tmp[studentsCount - 1] = *newStudent();

				delete[] stream;
				stream = new Students[studentsCount];

				for (size_t i = 0; i < studentsCount; i++)
				{
					stream[i] = tmp[i];
				}
			}
			
			break;

		case 2:
			cout << "Choose a student: " << endl;
			for (size_t i = 0; i < studentsCount; i++)
			{
				cout << i + 1 << ". ";
				stream[i].printInitials();
			}
			cout << "> ";
			cin >> case2Choice;

			inputMarks(stream[case2Choice - 1]);

			break;

		case 3:
			for (size_t i = 0; i < studentsCount; i++)
			{
				stream[i].printInitials();
			}

			break;

		case 4:
			cout << "Choose a student: " << endl;
			for (size_t i = 0; i < studentsCount; i++)
			{
				cout << i + 1 << ". ";
				stream[i].printInitials();
			}
			cout << "> ";
			cin >> case4Choice;

			stream[case4Choice - 1].printStudentMarks();

			break;

		case 5:
			for (size_t i = 0; i < studentsCount; i++)
			{
				if (stream[i].deptsCount() > 0)
				{
					stream[i].printInitials();
					cout << "\tStudent has " << stream[i].deptsCount() << " depts" << endl;
				}
			}

			break;

		default:
			break;
		}

		cout << endl;
	}

	return 0;
}