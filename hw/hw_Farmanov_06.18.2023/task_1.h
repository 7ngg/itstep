#pragma once
#include <iostream>

#include "globalStructures.h"

class Student {
    std::string name, surname;
    std::string groupName;
    Date birthday;

public:
    Student(std::string name, std::string surname, std::string groupName, Date date) {
        this->name = name;
        this->surname = surname;
        this->groupName = groupName;
        this->birthday = date;
    }

    friend std::ostream& operator << (std::ostream& stream, const Student student) {
        stream << student.name << ' ' << student.surname << ", " << student.birthday << ", " << student.groupName;
        return stream;
    }

    // friend std::istream& operator >> (std::istream& stream, Student student) {
    //     std::cout << "Name, surname: ";
    //     stream >> student.name >> student.surname;
    //     std::cout << "Group name: ";
    //     stream >> student.groupName;
    //     std::cout << "Birth date: " << '\n';
    //     stream >> student.birthday;

    //     return stream;
    // }
};

class Aspirant : public Student {
    std::string PhD_thesis;

public:
    Aspirant(std::string name, std::string surname, std::string groupName, Date date, std::string thesis) : Student(name, surname, groupName, date) {
        this->PhD_thesis = PhD_thesis;
    }

    friend std::ostream& operator << (std::ostream& stream, const Aspirant aspirant) {
        stream
            << "PhD thesis: " << aspirant.PhD_thesis;
    }

    // friend std::istream& operator >> (std::istream& stream, Aspirant aspirant) {
    //     std::cout << "PhD thesis: ";
    //     stream >> aspirant.PhD_thesis;

    //     return stream;
    // }
};