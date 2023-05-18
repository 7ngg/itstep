#pragma once

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