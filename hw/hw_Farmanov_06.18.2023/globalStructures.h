#pragma once
#include <iostream>

enum Gender {
    MALE = 1,
    FEMALE,
};

struct Date {
    uint16_t day{};
    uint16_t month{};
    uint16_t year{};

    friend std::ostream& operator << (std::ostream& stream, const Date date) {
        stream << date.day << '.' << date.month << '.' << date.year;
        return stream;
    }

    friend std::istream& operator >> (std::istream& stream, Date& date) {
        std::cout << "DD<space>MM<space>YY" << '\n' << "> ";
        stream >> date.day >> date.month >> date.year;
        return stream;
    }
};