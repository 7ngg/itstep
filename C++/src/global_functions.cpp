#include <iostream>

#include "../include/global_functions.h"

uint32_t len(char* str) {
	uint32_t result = 0;
	for (size_t i = 0; str[i] != '\0'; i++)
	{
		result += 1;
	}

	return result;
}