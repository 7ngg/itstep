#pragma once
#include <iostream>
#include "globalFunctions.h"

class fraction {
	int32_t numerator{};
	uint32_t denomirator{};

public:
	fraction() = default;
	fraction(int32_t numerator, uint32_t denomirator) {
		this->numerator = numerator;

		if (denomirator == 0)
		{
			while (denomirator == 0)
			{
				std::cout << "Denomirator shouldn't be 0" << std::endl;
				std::cout << "Enter denominator: ";
				std::cin >> denomirator;
			}
		}

		this->denomirator = denomirator;
	}

	int32_t getNumerator() {
		return this->numerator;
	}

	uint32_t getDenomirator() {
		return this->denomirator;
	}

	friend std::ostream& operator << (std::ostream& stream, fraction& x) {
		stream << x.numerator << '/' << x.denomirator << std::endl;
		return stream;
	}

	friend std::istream& operator >> (std::istream& stream, fraction& x) {
		std::cout << "<numerator><SPACE><denomirator>" << std::endl;
		stream >> x.numerator >> x.denomirator;

		if (x.denomirator == 0)
		{
			while (x.denomirator == 0)
			{
				std::cout << "Denomirator shouldn't be 0" << std::endl;
				std::cout << "Enter denominator: ";
				stream >> x.denomirator;
			}
		}

		return stream;
	}

	friend fraction operator + (fraction& num1, fraction& num2) {
		int32_t denomiratorOld = num1.denomirator;
		num1.denomirator = averageDenomirator(num1.denomirator, num2.denomirator);
		num1.numerator = (num1.denomirator / denomiratorOld * num1.numerator) + (num1.denomirator / num2.denomirator * num2.numerator);

		return num1;
	}

	friend fraction operator - (fraction& num1, fraction& num2) {
		int32_t denomiratorOld = num1.denomirator;
		num1.denomirator = averageDenomirator(num1.denomirator, num2.denomirator);
		num1.numerator = (num1.denomirator / denomiratorOld * num1.numerator) - (num1.denomirator / num2.denomirator * num2.numerator);

		return num1;
	}

	friend fraction operator * (fraction& num1, fraction& num2) {
		num1.numerator = num1.numerator * num2.numerator;
		num1.denomirator = num1.denomirator * num2.denomirator;

		return num1;
	}

	friend fraction operator / (fraction& num1, fraction& num2) {
		num1.numerator = num1.numerator * num2.denomirator;
		num1.denomirator = num1.denomirator * num2.numerator;

		return num1;
	}

	friend bool operator > (fraction num1, fraction num2) {
		num1.numerator = num1.numerator * averageDenomirator(num1.denomirator, num2.denomirator) / num1.denomirator;
		num2.numerator = num2.numerator * averageDenomirator(num1.denomirator, num2.denomirator) / num2.denomirator;

		return num1.numerator > num2.numerator;
	}

	friend bool operator < (fraction num1, fraction num2) {
		num1.numerator = num1.numerator * averageDenomirator(num1.denomirator, num2.denomirator) / num1.denomirator;
		num2.numerator = num2.numerator * averageDenomirator(num1.denomirator, num2.denomirator) / num2.denomirator;

		return num1.numerator < num2.numerator;
	}

	friend bool operator == (fraction num1, fraction num2) {
		num1.numerator = num1.numerator * averageDenomirator(num1.denomirator, num2.denomirator) / num1.denomirator;
		num2.numerator = num2.numerator * averageDenomirator(num1.denomirator, num2.denomirator) / num2.denomirator;

		return num1.numerator == num2.numerator;
	}
};