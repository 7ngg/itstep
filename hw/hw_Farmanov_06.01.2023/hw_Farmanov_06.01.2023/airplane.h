#pragma once
#include <iostream>

enum airplaneType
{
	PASSENGER = 1,
	CARGO,
	MILITARY
};

class Airplane
{
	airplaneType type{};
	uint16_t maxPassengersCount{};
	
public:
	uint16_t passengersCount{};

	Airplane() {
		uint16_t num = 0;
		std::cout
			<< "Choose plane type: " << '\n'
			<< "1. Passenger" << '\n'
			<< "2. Cargo" << '\n'
			<< "3. Military" << '\n'
			<< "> ";
		std::cin >> num;

		this->type = airplaneType(num);

		std::cout << "Enter max passengers count: ";
		std::cin >> this->maxPassengersCount;

		std::cout << "Enter current passengers count: ";
		std::cin >> this->passengersCount;
	}


	std::string getType() {
		if (type == PASSENGER)
		{
			return "PASSENGER";
		}
		else if (type == CARGO)
		{
			return "CARGO";
		}
		else if (type == MILITARY)
		{
			return "MILITARY";
		}
	}

	uint16_t getMaxPassengersCount() {
		return maxPassengersCount;
	}


	friend bool operator == (Airplane plane_1, Airplane plane_2) {
		return plane_1.type == plane_2.type;
	}

	Airplane& operator ++ () {
		passengersCount += 1;
		return *this;
	}

	Airplane& operator -- () {
		passengersCount -= 1;
		return *this;
	}

	friend bool operator > (Airplane plane_1, Airplane plane_2) {
		return plane_1.maxPassengersCount > plane_2.maxPassengersCount;
	}
	
	friend bool operator < (Airplane plane_1, Airplane plane_2) {
		return plane_1.maxPassengersCount < plane_2.maxPassengersCount;
	}
};

