#pragma once
#include <iostream>

class characterType {
public:
    uint16_t healthPoints = 100;

    int32_t manaPoints{};
    int32_t attack{};
    int32_t defense{};
    int32_t dexterity{};

    void assault(characterType& enemy) {
        enemy.healthPoints -= (this->attack / 10);
    }

    friend std::ostream& operator << (std::ostream& stream, const characterType type) {
        stream
            << "Mana: " << type.manaPoints << '\n'
            << "Attack: " << type.attack << '\n'
            << "Defense: " << type.defense << '\n'
            << "Dexterity: " << type.dexterity << std::endl;

        return stream;
    }
};

class Archer : public characterType {
public:
    Archer() {
        this->manaPoints = 60;
        this->attack = 75;
        this->defense = 50;
        this->dexterity = 100;
    }
};

class Wizard : public characterType {
public:
    Wizard() {
        this->manaPoints = 100;
        this->attack = 60;
        this->defense = 75;
        this->dexterity = 60;
    }
};

class Tank : public characterType {
public:
    Tank() {
        this->manaPoints = 70;
        this->attack = 70;
        this->defense = 100;
        this->dexterity = 50;
    }
};
