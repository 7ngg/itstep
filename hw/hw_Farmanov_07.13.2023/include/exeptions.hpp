#pragma once
#include <iostream>

class OutOfRange : std::exception {
    const char* message = "Out of range";
public:
    OutOfRange() = default;
    OutOfRange(const char* message) {
        this->message = message;
    }

    const char* what() const throw() override {
        return this->message;
    }
};


class PrimeNumberExeption : std::exception {
    const char* message = "Prime number exeption";
public:
    PrimeNumberExeption() = default;
    PrimeNumberExeption(const char* message) {
        this->message = message;
    }

    const char* what() const throw() override {
        return this->message;
    }
};