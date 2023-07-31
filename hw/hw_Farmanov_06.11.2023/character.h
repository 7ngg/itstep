#pragma once
#include <iostream>

#include "characterType.h"
#include "characterRace.h"

class Character
{
private:
    characterType* type{};
    characterRace* race{};

public:
    Character() = default;

    void selectCharacterType() {
        uint16_t choice{};

        std::cout 
            << "Choose type: " << '\n'
            << "1. Archer" << '\n'
            << "2. Tank" << '\n'
            << "3. Wizard" << '\n'
            << "> ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            this->type = new Archer{};
            break;

        case 2:
            this->type = new Tank{};
            break;

        case 3:
            this->type = new Wizard{};
            break;
        
        default:
            break;
        }
    }


    void selectCharacterRace() {
        uint16_t choice{};

        std::cout
            << "Choose race: " << '\n'
            << "1. Elf" << '\n'
            << "2. Human" << '\n'
            << "3. Orc" << '\n'
            << "> ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice)
        {
        case 1:
            this->race = new Elf{};
            break;

        case 2:
            this->race = new Human{};
            break;

        case 3:
            this->race = new Orc{};
            break;
        
        default:
            break;
        }
    }


    friend std::ostream& operator << (std::ostream& stream, const Character character) {
        stream
            << "Name: " << character.race->name << '\n'
            << "Race: " << character.race->race << '\n'
            << "Gender: " << character.race->get_gender(character.race->gender) << '\n'
            << character.type << '\n';

        return stream;
    }
};


