#include <iostream>

#include "../include/global_functions.h"

uint16_t len(char* str) {
	uint32_t result = 0;
	for (size_t i = 0; str[i] != '\0'; i++)
	{
		result += 1;
	}

	return result;
}


bool compare(char* str1, char* str2) {
	if (len(str1) != len(str2))
	{
		return false;
	}

	uint16_t length = len(str1);
	uint16_t check = 0;

	for (size_t i = 0; i < length; i++)
	{
		if (str1[i] == str2[i])
		{
			check += 1;
		}
	}

	if (check == length)
	{
		return true;
	}
	return false;
}


bool search(char* text, char* word) {
	uint16_t textLength = len(text);
	uint16_t wordLength = len(word);

	for (size_t i = 0; i < textLength; i++)
	{
		uint16_t check = 0;

		for (size_t j = 0; j < wordLength; j++, i++)
		{
			if (text[i] == word[j])
			{
				check += 1;
			}
			else
			{
				break;
			}
		}

		if (check == wordLength)
		{
			return true;
		}
	}
	return false;
}


bool fileExists(const char* name) {
	FILE* file{};
	fopen_s(&file, name, "r");

	if (file == nullptr)
	{
		return false;
	}
	return true;
}