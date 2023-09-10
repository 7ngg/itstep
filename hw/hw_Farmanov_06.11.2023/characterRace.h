#pragma once
#include <iostream>

enum Gender {
    MALE = 1,
    FEMALE,
};


class characterRace {
public:
    std::string name;
    std::string race;
    Gender gender;

    characterRace() {
        uint16_t gender{};

        std::cout
            << "Select gender: " << '\n'
            << "1. Male" << '\n'
            << "2. Female" << '\n'
            << "> ";
        std::cin >> gender;
        std::cin.ignore();
        this->gender = Gender(gender);
    }

    virtual void rename() {
        std::string newName{};

        std::cout << "Enter new name: ";
        getline(std::cin, newName);
        this->name = newName;
    }

    virtual void print() {
        std::cout
            << "Name: " << this->name << '\n'
            << "Race" << this->race << '\n'
            << "Gender: " << this->getGender(this->gender) << std::endl;
    }

    std::string getGender(Gender gender) {
        if (gender == MALE)
        {
            return "male";
        }
        else if (gender == FEMALE)
        {
            return "female";
        }
    }
};


class Elf : public characterRace {
private:

public:
    Elf() {
        this->race = "Elf";
    }

    Elf(int16_t _gender) {
        rename();
        this->race = "Elf";
        this->gender = Gender(_gender);
    }
};


class Human : public characterRace {
private:

public:
    Human() {
        this->race = "Human";
    }

    Human(int16_t _gender) {
        rename();
        this->race = "Human";
        this->gender = Gender(_gender);
    }
};

class Orc : public characterRace {
private:

public:
    Orc() {
        this->race = "Orc";
    }

    Orc(int16_t _gender) {
        rename();
        this->race = "Orc";
        this->gender = Gender(_gender);
    }
};