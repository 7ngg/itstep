#include <iostream>

class characterType {
public:
    int32_t manaPoints{};
    int32_t attack{};
    int32_t defense{};
    int32_t dexterity{};
};

class Archer : public characterType {
    Archer() {
        this->manaPoints = 60;
        this->attack = 75;
        this->defense = 50;
        this->dexterity = 100;
    }
};

class Wizard : public characterType {
    Wizard() {
        this->manaPoints = 100;
        this->attack = 60;
        this->defense = 75;
        this->dexterity = 60;
    }
};

class Tank : characterType {
    Tank() {
        this->manaPoints = 70;
        this->attack = 70;
        this->defense = 100;
        this->dexterity = 50;
    }
};
