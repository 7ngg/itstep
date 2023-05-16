#include <iostream>
#include <ctime>

#include "../include/memory.h"
#include "../include/global_functions.h"


void gameField::randomise(gameField field, uint16_t width, uint16_t height) {
	for (size_t i = 0; i < height; i++)
	{
		for (size_t j = 0; j < width; j++)
		{
			uint16_t value = rand() % (width * height) + 1;

			uint16_t x1 = rand() % width, x2{};
			while (x2 == x1)
			{
				x2 = rand() % width;
			}

			uint16_t y1 = rand() % height, y2{};
			while (y2 == y1)
			{
				x2 = rand() % height;
			}

			field.
		}
	}
}


void memoryMainFunction() {
	srand(time(NULL));

	uint16_t width{}, height{};

	while (true)
	{
		std::cout << "Enter dimensions. Multiplication has to be even" << '\n';
		std::cout << "Enter field width: ";
		std::cin >> width;
		std::cout << "Enter field height: ";
		std::cin >> height;

		if ((height * width) % 2 == 0)
		{
			break;
		}
		std::cout << "Wrong dimensions" << std::endl;
	}

	gameField newField(width, height);

}