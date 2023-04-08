#pragma once

#include <iostream>
#include "lib.h"

int len(const char* str) {
	int length = 0;
	int i = 0;

	while (str[i] != '\0')
	{
		length += 1;
		i += 1;
	}

	return length;
}


int mystrcmp(const char* str1, const char* str2) {
	if (len(str1) == len(str2))
	{
		return 0;
	}
	else if (len(str1) > len(str2))
	{
		return 1;
	}
	else if (len(str1) < len(str2))
	{
		return -1;
	}
}


int StringToNumber(char* str) {
	int length = len(str);
	int result = 0;

	for (size_t i = 0, j = 10; i < length; i++)
	{
		result = result * j + int(str[i]) - 48;
	}

	return result;
}


char* NumberToString(int number) {
	int count = 0;
	int numBackup = number;

	while (number > 0)
	{
		count += 1;
		number /= 10;
	}

	number = numBackup;
	int* ASCII_array = new int[count] {};

	for (size_t i = 0; i < count; i++)
	{
		ASCII_array[count - 1 - i] = 48 + (number % 10);
		number /= 10;
	}

	char* result = new char[count] {};

	for (size_t i = 0; i < count; i++)
	{
		result[i] = char(ASCII_array[i]);
	}

	return result;
}


char* Uppercase(char* str) {
	int length = len(str);
	char* result = new char[length] {};

	for (size_t i = 0; i < length; i++)
	{
		int ASCII_letter = int(str[i]);
		if (ASCII_letter >= 97 and ASCII_letter <= 122)
		{
			ASCII_letter -= 32;
			result[i] = char(ASCII_letter);
		}
		else
		{
			result[i] = str[i];
		}
	}

	return result;
}


char* Lowercase(char* str) {
	int length = len(str);
	char* result = new char[length] {};

	for (size_t i = 0; i < length; i++)
	{
		int ASCII_letter = int(str[i]);
		if (ASCII_letter >= 65 and ASCII_letter <= 90)
		{
			ASCII_letter += 32;
			result[i] = char(ASCII_letter);
		}
		else
		{
			result[i] = str[i];
		}
	}
	
	return result;
}


char* mystrrev(char* str) {
	int length = len(str);
	char* result = new char[length] {};

	for (size_t i = 0; i < length; i++)
	{
		result[length - 1 - i] = str[i];
	}

	return result;
}
