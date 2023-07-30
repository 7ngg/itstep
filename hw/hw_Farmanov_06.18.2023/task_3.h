#include <iostream>

struct Result
{
    double elapsedTime{};
    uint16_t price{};

    Result() = default;

    friend std::ostream& operator << (std::ostream& stream, const Result result) {
        stream 
            << "Elapsed time: " << result.elapsedTime << '\n'
            << "Price: " << result.price << std::endl;

        return stream;
    }
};



class Vehicle {
public:
    uint16_t wheelsCount{};
    uint16_t averageSpeed{};
    uint16_t maxPassengersCount{};
    uint16_t priceForAnHour{};
    std::string color;

    Vehicle() = default;

    Vehicle(uint16_t _wheelsCount, uint16_t _averageSpeed, uint16_t _maxPassengersCount, std::string& _color) {
        this->wheelsCount = _wheelsCount;
        this->averageSpeed = _averageSpeed;
        this->maxPassengersCount = _maxPassengersCount;
        this->color = _color;
    }

    Result* timeCalc() {
        Result* result = new Result{};
        double distance{};

        std::cout << "Enter distance: ";
        std::cin >> distance;

        result->elapsedTime = (distance / this->averageSpeed);
        result->price = result->elapsedTime * priceForAnHour;

        return result;
    }
};


class Car : public Vehicle {
    double engineCapacity{};

public:
    Car() : Vehicle() {
        this->priceForAnHour = 120;
    }

    Car(uint16_t _wheelsCount, uint16_t _averageSpeed, uint16_t _maxPassengersCount, std::string& _color, double _engineCapacity) {
        this->engineCapacity = _engineCapacity;
    }
};


class Bicycle : public Vehicle {
    uint16_t wheelSize{};

public:
    Bicycle() : Vehicle() {
        this->priceForAnHour = 50;
    }

    Bicycle(uint16_t _wheelsCount, uint16_t _averageSpeed, uint16_t _maxPassengersCount, std::string _color, uint16_t _wheelSize) {
        this->wheelSize = _wheelSize;
    }
};


class Wagon : public Vehicle {
public:
    Wagon() : Vehicle() {
        this->priceForAnHour = 200;
    }

    Wagon(uint16_t _wheelsCount, uint16_t _averageSpeed, uint16_t _maxPassengersCount, std::string& _color) : Vehicle() {}
};