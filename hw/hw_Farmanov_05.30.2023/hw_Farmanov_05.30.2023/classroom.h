#pragma once
#include <iostream>
#include <string>

#include "globalFunctions.h"

class Student
{
private:
	std::string name;
	std::string surname;
	uint16_t age{};

public:
	bool flag = false;

	Student() = default;
	Student(std::string name, std::string surname, uint16_t age) {
		this->name = name;
		this->surname = surname;
		this->age = age;
		flag = true;
	}


	std::string getName() {
		return name;
	}

	std::string getSurname() {
		return surname;
	}

	uint16_t getAge() {
		return age;
	}


	friend std::ostream& operator << (std::ostream& stream, const Student& student) {
		return stream << student.name << ' ' << student.surname << ", " << student.age;
	}

	friend std::istream& operator >> (std::istream& stream, Student& student) {
		std::cout << "<name><SPACE><surname><SPACE><age>" << std::endl;
		stream >> student.name >> student.surname >> student.age;
		student.flag = true;

		/*std::cout << "Name: ";
		stream >> student.name;
		std::cout << "Surname: ";
		stream >> student.surname;
		std::cout << "Age: ";
		stream >> student.age;*/
		
		return stream;
	}

	friend bool operator > (const Student stud_1, const Student stud_2) {
		return stud_1.age > stud_2.age;
	}

	friend bool operator < (const Student stud_1, const Student stud_2) {
		return stud_1.age < stud_2.age;
	}

	friend bool operator == (const Student stud_1, const Student stud_2) {
		return stud_1.age == stud_2.age;
	}

	friend bool operator != (const Student stud_1, const Student stud_2) {
		return stud_1.age != stud_2.age;
	}
};


class Classroom
{
private:
	std::string className;
	uint16_t studentsCount{};

public:
	Student* students{};
	uint16_t iterator = 0;

	Classroom() {
		/*
		std::cout << "Enter class-name: ";
		std::getline(std::cin, className);

		std::cout << "Enter students count: ";
		std::cin >> studentsCount;
		*/
	}

	~Classroom() {
		delete[] students;
	}


	uint16_t getStudentsCount() {
		return studentsCount;
	}

	std::string getClassName() {
		return className;
	}


	friend std::ostream& operator << (std::ostream& stream, const Classroom& myClassroom) {
		stream 
			<< "Class name: " << myClassroom.className << std::endl
			<< "Students count: " << myClassroom.studentsCount << std::endl
			<< "Students: " << std::endl;

		for (size_t i = 0; i < myClassroom.studentsCount; i++)
		{
			if (myClassroom.students[i].flag)
			{
				stream << '\t' << myClassroom.students[i].getName() << ' ' << myClassroom.students[i].getSurname() << ", " << myClassroom.students[i].getAge() << std::endl;
			}
		}

		return stream;
	}

	friend std::istream& operator >> (std::istream& stream, Classroom& myClassroom) {
		std::cout << "Class name: ";
		stream >> myClassroom.className;
		std::cout << "Students count: ";
		stream >> myClassroom.studentsCount;
		myClassroom.students = new Student[myClassroom.studentsCount];
		
		return stream;
	}
};