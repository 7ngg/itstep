#include <iostream>
#include <string>

#include "globalStructures.h"
#include "task_1.h"
#include "task_2.h"
#include "task_3.h"


// Наверное, так делать нельзя
Passport* addPassport() {
    uint16_t passportType{}, visasCount{}, genderVar{};

    size_t passportNo{};
    
    std::string name, surname;
    std::string nationality;
    std::string placeOfBirth;

    std::string* visas = new std::string[visasMaxCount]{};

    Date birthday{};
    Date issuedOn{}, expiresOn{};
    
    Gender gender;

    std::cout
        << "Select type of the passprot: "
        << "1. Local" << '\n'
        << "2. Foreign" << '\n'
        << "> ";
    std::cin >> passportType;

    std::cout << "Passport No: ";
    std::cin >> passportNo;
    std::cin.ignore();
    std::cout << "Name: ";
    std::getline(std::cin, name);
    std::cout << "Surname: ";
    std::getline(std::cin, surname);
    std::cout << "Nationality: ";
    std::getline(std::cin, nationality);
    std::cout << "Place of birth: ";
    std::getline(std::cin, placeOfBirth);
    std::cout << "Date of birth: ";
    std::cin >> birthday;
    std::cout << "Issued on: ";
    std::cin >> issuedOn;
    std::cout << "Expires on: ";
    std::cin >> expiresOn;

    std::cout
        << "Select gender: " << '\n'
        << "1. Male" << '\n'
        << "2. Female" << '\n'
        << "> ";
    std::cin >> genderVar;
    gender = Gender(genderVar);

    if (passportType == 1)
    {
        Passport* newLocal = new Passport { passportNo, name, surname, nationality, placeOfBirth, birthday, issuedOn, expiresOn, gender };
        return newLocal;
    }
    else if (passportType == 2)
    {
        while (visasCount < 0 or visasCount > visasMaxCount)
        {
            std::cout << "How many visas would you like to add? (8 max)";
            std::cin >> visasCount;
        }

        for (size_t i = 0; i < visasCount; i++)
        {
            std::cout << "Visa 1: ";
            std::getline(std::cin, visas[i]);
        }
        
        ForeignPassport* newForeign = new ForeignPassport { passportNo, name, surname, nationality, placeOfBirth, birthday, issuedOn, expiresOn, gender, visas };
        return newForeign;
    }
}

// И так тоже
Vehicle* addVehicle() {
    uint16_t choice{};

    uint16_t wheelsCount{}, averageSpeed{}, maxPassengersCount{};
    std::string color;

    std::cout
        << "Choose vehicle type: " << '\n'
        << "1. Car" << '\n'
        << "2. Bicycle" << '\n'
        << "3. Wagon" << '\n'
        << "> ";
    std::cin >> choice;

    if (choice < 0 or choice > 3)
    {
        std::cout << "No such choice" << std::endl;
        return;
    }

    std::cout << "Wheels count: ";
    std::cin >> wheelsCount;
    std::cout << "Max passengers count: ";
    std::cin >> maxPassengersCount;
    std::cout << "Average speed: ";
    std::cin >> averageSpeed;
    std::cin.ignore();
    std::cout << "Color: ";
    std::getline(std::cin, color);

    switch (choice)
    {
    case 1:
    {
        double engineCapacity{};
        Car* newCar{};

        std::cout << "Engine capacity: ";
        std::cin >> engineCapacity;
        newCar = new Car { wheelsCount, averageSpeed, maxPassengersCount, color, engineCapacity };
        return newCar;

        break;
    }
    
    case 2:
    {
        uint16_t wheelSize{};
        Bicycle* newBicycle{};

        std::cout << "Wheel size: ";
        std::cin >> wheelSize;
        newBicycle = new Bicycle { wheelsCount, averageSpeed, maxPassengersCount, color, wheelSize };
        return newBicycle;

        break;
    }

    case 3:
    {
        Wagon* newWagon = new Wagon { wheelsCount, averageSpeed, maxPassengersCount, color };
        return newWagon;

        break;
    }

    default:
        return;
        break;
    }

}


int main(int, char**){
    /*
    Passport* p = addPassport();
    std::cout << *p << std::endl;
    */


    return 0;
}
