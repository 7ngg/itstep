#include <iostream>

#include "character.h"
#include "characterRace.h"
#include "characterType.h"

int main(int, char**){
    Character newC;
    newC.selectCharacterRace();
    newC.selectCharacterType();
    std::cout << newC << std::endl;
}
