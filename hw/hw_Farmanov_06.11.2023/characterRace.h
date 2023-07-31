#pragma once
#include <iostream>
#include <iostream>

enum Gender {
    MALE,
    FEMALE,
};


class characterRace {
public:
    std::string name;
    std::string race;
    Gender gender;

    virtual void rename() = 0;
    virtual void print() = 0;

    characterRace() {
        uint16_t gender{};

        std::cout
            << "Select gender: " << '\n'
            << "1. Male" << '\n'
            << "2. Female" << '\n'
            << "> ";
        std::cin >> gender;
        this->gender = Gender(gender);
    }


    std::string get_gender(Gender gender) {
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
    enum elfNames {
        FEANOR = 1,
        FINGOLFIN,
        FINARFIN,
    };

public:
    Elf() {
        this->race = "Elf";
    }

    Elf(int16_t _gender) {
        rename();
        this->race = "Elf";
        this->gender = Gender(_gender);
    }


    void rename() override {
        int16_t choice = 0;
        
        std::cout << "Choose new name: " << '\n';
        printNames();
        std::cout << "> ";
        std::cin >> choice;

        this->name = elfNames(choice);
    }

    void print() override {
        std::cout << "Name: " << name << '\t' << "Race: " << race << '\t' << "Gender: " << get_gender(gender) << std::endl;
    }

    void printNames() {
        std::cout
            << "1. Feanor" << '\n'
            << "2. Fingolfin" << '\n'
            << "3. Finarfin" << '\n';
    }

};


class Human : public characterRace {
private:
    enum humanNames {
        TUOR = 1,
        HUOR,
        HURIN,
    };

public:
    Human() {
        this->race = "Human";
    }

    Human(int16_t _gender) {
        rename();
        this->race = "Human";
        this->gender = Gender(_gender);
    }


    void rename() override {
        int16_t choice = 0;

        std::cout << "Choose new name: " << '\n';
        printNames();
        std::cout << "> ";
        std::cin >> choice;

        this->name = humanNames(choice);
    }

    void print() override {
        std::cout << "Name: " << name << '\t' << "Race: " << race << '\t' << "Gender: " << get_gender(gender) << std::endl;
    }

    void printNames() {
        std::cout
            << "1. Tuor" << '\n'
            << "2. Huor" << '\n'
            << "3. Hurin" << '\n';
    }

};

class Orc : public characterRace {
private:
    enum orcNames {
        AZOG,
        BOLG,
        BALCMEG,
    };

public:
    Orc() {
        this->race = "Orc";
    }

    Orc(int16_t _gender) {
        rename();
        this->race = "Orc";
        this->gender = Gender(_gender);
    }


    void rename() override {
        int16_t choice = 0;

        std::cout << "Choose new name: " << '\n';
        printNames();
        std::cout << "> ";
        std::cin >> choice;

        this->name = orcNames(choice);
    }

    void print() override {
        std::cout << "Name: " << name << '\t' << "Race: " << race << '\t' << "Gender: " << get_gender(gender) << std::endl;
    }

    void printNames() {
        std::cout
            << "1. Azog" << '\n'
            << "2. Bolg" << '\n'
            << "3. Bolcmeg" << '\n';
    }
};