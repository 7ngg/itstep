#pragma once
#include <iostream>

constexpr int16_t pi = 3;

class circle
{
private:
	int16_t radius{};
	int16_t length{};

public:
	circle(int16_t inputRadius) {
		this->radius = inputRadius;
	}

	int16_t getRadius() {
		return radius;
	}

	int16_t getLength() {
		length = radius * 2 * pi;
		return length;
	}

	void print() {
		std::cout
			<< '\t' << "Radius - " << radius << '\n'
			<< '\t' << "Length - " << getLength() << std::endl;
	}

	bool operator == (const circle& other) {
		return this->radius == other.radius;
	}

	bool operator > (const circle& other) {
		return this->radius > other.radius;
	}

	bool operator < (const circle& other) {
		return this->radius < other.radius;
	}

	bool operator != (const circle& other) {
		return this->radius != other.radius;
	}

	bool operator += (int16_t value) {
		this->radius += value;
		return this->radius;
	}

	bool operator -= (int16_t value) {
		this->radius -= value;
		return this->radius;
	}
};
