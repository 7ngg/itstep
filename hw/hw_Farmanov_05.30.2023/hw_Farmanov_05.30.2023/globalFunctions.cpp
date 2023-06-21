#include <iostream>
#include <iso646.h>

#include "globalFunctions.h"
#include "fractions.h"

int32_t euclid(int32_t denom1, int32_t denom2) {
	int32_t result = (denom2 == 0) ? denom1 : euclid(denom2, denom1 % denom2);
	return result;
}


int32_t averageDenomirator(uint32_t x, uint32_t y) {
	if (euclid(x, y) != 1)
	{
		return euclid(x, y);
	}

	return x * y;
}


void boolPrint(bool expression) {
	if (expression)
	{
		std::cout << "True" << std::endl;
	}
	else if (not expression)
	{
		std::cout << "False" << std::endl;
	}
}