#pragma once

<<<<<<< HEAD
struct gameField
{
	int width{};
	int height{};
	int** mainField{};

	gameField(int width, int height) {
		this->width = width;
		this->height = height;
		mainField = new int * [height] {};
		for (size_t i = 0; i < height; i++)
		{
			*(mainField + i) = new int[width]{};
		}
	}

	void show();
	void randomise();
	bool checkForZeros();
};

void memoryMainFunction();
=======
uint16_t dimension = 0;
>>>>>>> f3913e17fd32d1211c71ec2b132bacccfe050e7f
