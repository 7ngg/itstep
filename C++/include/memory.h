#pragma once

struct gameField
{
	uint16_t width{};
	uint16_t height{};

	gameField(uint16_t x, uint16_t y) {
		uint16_t** field = new uint16_t*[height]{};
		for (size_t i = 0; i < height; i++)
		{
			field[i] = new uint16_t[width]{};
		}
	}

	void randomise(gameField field, uint16_t width, uint16_t height);
};

void memoryMainFunction();