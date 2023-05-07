#include <iostream>

#include "../include/arithmetic.h"
#include "../include/global_functions.h"

/*
	ASCII:
		43 - +
		45 - -
		42 - *
		47 - /
		40 - (
		41 - )
*/

bool isNum(char sym) {
	bool flag = (48 <= sym and sym <= 57) ? true : false;
	return flag;
}


bool isOperation(char sym) {
	bool flag = (sym == char(43) or sym == char(45) or sym == char(42) or sym == char(47) or sym == char(40) or sym == char(41)) ? true : false;
	return flag;
}


int32_t arithmeticMainFunc(char* str) {
	uint32_t strLength = len(str);
	uint32_t numsCount = 0;
	uint32_t symbolsCount = 0;

	for (size_t i = 0; i < strLength; i++)
	{	
		if (isNum(str[i]))
		{
			numsCount += 1;
		}
		else if (isOperation(str[i]))
		{
			symbolsCount += 1;
		}
	}

	uint32_t* nums = new uint32_t[numsCount];
	char* symbols = new char[symbolsCount];

	std::cout << strLength << std::endl;
	std::cout << numsCount << '\t' << symbolsCount << std::endl;

	return 1337;
}