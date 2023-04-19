#include <iostream>
#include <ctime>
#include "machine.h"

void machine::print() {
	std::cout << "Entered data:\n";

	std::cout << "Manufacturer - " << name << '\n';
	std::cout << "Color - " << color << '\n';

	std::cout << std::endl;

	std::cout << "Dimensions (width/height/depth): " << width << 'x' << height << 'x' << depth << '\n';

	std::cout << std::endl;

	std::cout << "Power amount - " << power << 'w' << '\n';
	std::cout << "Spin speed - " << spinSpeed << "rpm" << '\n';
	std::cout << "Temperature - " << temp << 'C' << '\n';
}

void machine::turnON(bool flag) {
	if (flag)
	{
		std::cout << "Machine is on\n";
	}
	else
	{
		std::cout << "Machine is of\n";
	}
}

int machine::wash() {
	srand(time(NULL));

	int16_t* duration = new int16_t[5]{ 30, 40, 60, 120, 90 };
	return duration[rand() % 5];
}