#pragma once
#include <iostream>

#include "globalStructures.h"

const uint16_t visasMaxCount = 8;

class Passport {
#pragma region Variables
    size_t passportNo{};
    
    std::string name, surname;
    std::string nationality;
    std::string placeOfBirth;

    Date birthday{};
    Date issuedOn{}, expiresOn{};
    
    Gender gender;
#pragma endregion

public:
    Passport() = default;

    Passport(size_t _passportNo, std::string _name, std::string _surname, std::string _nationality, std::string _placeOfBirth, Date _birthday, 
                Date _issuedOn, Date _expiresOn, Gender _gender) 
    {
        this->passportNo = _passportNo;
        this->name = _name;
        this->surname = _surname;
        this->nationality = _nationality;
        this->placeOfBirth = _placeOfBirth;
        this->birthday = _birthday;
        this->issuedOn = _issuedOn;
        this->expiresOn = _expiresOn;
        this->gender = _gender;
    }


    friend std::ostream& operator << (std::ostream& stream, Passport passport) {
        stream
            << "Nationality: " << passport.nationality << "\t\t" << "Passport no: " << passport.passportNo << '\n'
            << std::endl
            << "Name: " << passport.name << '\n'
            << "Surname: " << passport.surname << '\n'
            << std::endl
            << "Gender: " << passport.getGender() << "\t\t" << "Date of birth: " << passport.birthday << '\n'
            << "Place of birth: " << passport.placeOfBirth << '\n'
            << "Issued on: " << passport.issuedOn << "\t" << "Expires on: " << passport.expiresOn
            << std::endl;

        return stream;
    }


    char getGender() {
        if (this->gender == MALE)
        {
            return 'M';
        }
        else if (this->gender == FEMALE)
        {
            return 'F';
        }
    }
};

class ForeignPassport : public Passport {
    std::string* visas{};

public:
    ForeignPassport() : Passport() {
        this->visas = new std::string[visasMaxCount]{};
    }

    ForeignPassport(size_t _passportNo, std::string _name, std::string _surname, std::string _nationality, std::string _placeOfBirth, Date _birthday, 
                    Date _issuedOn, Date _expiresOn, Gender _gender, std::string* _visas) : Passport()
    {
        this->visas = _visas;
    }


    friend std::ostream& operator << (std::ostream stream, const ForeignPassport passport) {
        std::cout << "Visas: " << std::endl;
        for (size_t i = 0; i < visasMaxCount; i++)
        {
            std::cout << passport.visas[i] << std::endl;
        }
        
    }
};