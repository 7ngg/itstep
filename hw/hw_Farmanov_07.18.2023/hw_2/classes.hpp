#pragma once
#include "regex.h"
#include "exceptions.hpp"

class Transort {
private:
    void SetMake(std::string make)
    {
        if (not std::regex_match(make, Regular::make))
        {
            throw RegexInconsistencyException("Make doesn't match the pattern");
        }

        this->make = make;
    }


    void SetModel(std::string model)
    {
        if (not std::regex_match(model, Regular::model))
        {
            throw RegexInconsistencyException("Model doesn't match the pattern");
        }

        this->model = model;
    }


    void SetYear(std::string year)
    {
        if (not std::regex_match(year, Regular::year))
        {
            throw RegexInconsistencyException("Year doesn't match the pattern");
        }

        this->year = year;
    }

protected:
    std::string make;
    std::string model;
    std::string year;
    std::string color;
    size_t price = 0;

    Transort() = default;
    Transort(std::string make, std::string model, std::string year, std::string color, size_t price)
    {
        try
        {
            SetMake(make);
            SetModel(model);
            SetYear(year);
            SetColor(color);
            SetPrice(price);
        }
        catch (std::exception& e)
        {
            SaveException(e);
        }
    }

public:
    virtual ~Transort()
    {
        std::cout << "Transport destructor called" << std::endl;
    }


    void SetColor(std::string color)
    {
        if (not std::regex_match(color, Regular::color))
        {
            throw RegexInconsistencyException("Color doesn't match the pattern");
        }

        this->color = color;
    }


    void SetPrice(size_t price)
    {
        if (price < 0)
        {
            throw InvalidRangeException("Price cannot be negative");
        }

        this->price = price;
    }
};


class Car : Transort {
private:
    int milage;

public:
    Car() : Transort()
    {
        milage = 0;
    }

    Car(std::string make, std::string model, std::string year, std::string color, size_t price, int milage) : Transort(make, model, year, color, price)
    {
        SetMilage(milage);
    }


    int GetMilage()
    {
        return milage;
    }


    void SetMilage(int value)
    {
        if (value < 0 or value < this->milage)
        {
            throw InvalidRangeException("Milage cannot be lower than current value");
        }

        this->milage = value;
    }
};


class Plane : Transort {

};


class Boat : Transort {

};