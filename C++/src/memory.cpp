#include <iostream>
<<<<<<< HEAD
#include <ctime>

#include "../include/memory.h"
#include "../include/global_functions.h"


void gameField::randomise() {
	int* usedNums = new int[256]{};
	int usedNumsIterator = 0;

	for (size_t i = 0; i < height; i++)
	{
		for (size_t j = 0; j < width; j++)
		{
			if (mainField[i][j] == 0)
			{
				while (true)
				{
					int value = rand() % (width * height) + 1;
	
					if (!isMember(usedNums, 256, value))
					{
						mainField[i][j] = value;
						usedNums[usedNumsIterator] = value;
						break;
					}
				}

				while (true)
				{
					int randX = rand() % width;
					int randY = rand() % height;

					if (mainField[randY][randX] == 0)
					{
						mainField[randY][randX] = usedNums[usedNumsIterator];
						break;
					}
				}

				usedNumsIterator += 1;
			}
		}
	}
}


void gameField::show() {
	for (size_t i = 0; i < height; i++)
	{
		for (size_t j = 0; j < width; j++)
		{
			std::cout.width(3);
			std::cout << mainField[i][j];
		}
		std::cout << std::endl;
	}
}


bool gameField::checkForZeros() {
	for (size_t i = 0; i < height; i++)
	{
		for (size_t j = 0; j < width; j++)
		{
			if (mainField[i][j] == 0)
			{
				return true;
			}
		}
	}
	return false;
}


void memoryMainFunction() {
	srand(time(NULL));

	int width{}, height{};
	bool flag = true;
	int stepsCount = 0;
	uint32_t gameTime = 0;

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
	gameField zeroField(width, height);
	newField.randomise();
	
	uint32_t timeStart = clock();

	while (flag)
	{
		int x{}, y{};
		int* coordCompare = new int[4] {};

		/*
			coordCompare 0 = x1
			coordCompare 1 = y1
			coordCompare 2 = x2
			coordCompare 3 = y2
		*/

		for (size_t i = 0, j = 0; i < 2; i += 1, j+= 2)
		{
			system("cls");
			zeroField.show();
			std::cout << "Make a step or click outside the field to exit" << std::endl;
		
	
			getClick(x, y);
			bool spotCheck = true ? (x % 3 == 0) : false;
			x /= 3;
			coordCompare[j] = x;
			coordCompare[j + 1] = y;

			if (x > width or y > height or spotCheck)
			{
				char choice{};
				
				system("cls");
				
				std::cout 
					<< "Wrong spot clicked, are you sure, you want to exit? y/n" << std::endl
					<< "> ";
				std::cin >> choice;
				
				if (choice == 'y')
				{
					flag = false;
					break;
				}
			}
			else
			{
				zeroField.mainField[y][x] = newField.mainField[y][x];
				system("cls");
				zeroField.show();
			}
		}
		
		bool sameSpotCheck = true ? (coordCompare[0] == coordCompare[2] and coordCompare[1] == coordCompare[3]) : false;			// if user clicked the same spot twice
		bool valueCompare = true ? (zeroField.mainField[coordCompare[1]][coordCompare[0]] == zeroField.mainField[coordCompare[3]][coordCompare[2]]) : false;			// comparing values
		
		if (!valueCompare or sameSpotCheck)
		{
			zeroField.mainField[coordCompare[1]][coordCompare[0]] = 0;
			zeroField.mainField[coordCompare[3]][coordCompare[2]] = 0;
		}

		stepsCount += 1;

		if (!zeroField.checkForZeros())
		{
			uint32_t timeEnd = clock();
			gameTime = timeEnd - timeStart;

			std::cout
				<< "Game is completed." << '\n'
				<< "Steps made - " << stepsCount << '\n'
				<< "Time spent - " << gameTime / 1000 << " seconds" << std::endl;
			flag = false;
		}

		system("pause");
	}
=======

#include "../include/memory.h"


void memoryMainFunction() {
	uint16_t dimensions = 0;
	std::cout << "Enter field dimensions: " << '\n';
	std::cout
>>>>>>> f3913e17fd32d1211c71ec2b132bacccfe050e7f
}