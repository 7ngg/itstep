#pragma once

#include <iostream>
#include "students.h"

void Students::printStudentMarks() {
	int length = 10;

	std::cout 
		<< surname << ' ' << name << std::endl
		<< "Marks: " << std::endl;
	for (size_t i = 0; i < length; i++)
	{
		std::cout << "\tSubject " << i + 1 << ": ";
		if (marks[i])
		{
			std::cout << "Pass\n";
		}
		else
		{
			std::cout << "Fall\n";
		}
	}
}


void Students::printInitials() {
	std::cout << name << ' ' << surname << std::endl;
}


double Students::averageGrade() {
	double result = 0;

	for (size_t i = 0; i < subjectsCount; i++)
	{
		result += marks[i];
	}

	result /= subjectsCount;

	return result;
}


uint16_t Students::deptsCount() {
	uint16_t result = 0;

	for (size_t i = 0; i < subjectsCount; i++)
	{
		if (marks[i] == false)
		{
			result += 1;
		}
	}

	return result;
}