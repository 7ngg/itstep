#include <iostream>
#include <iso646.h>

int len(char* str) 
{
	int result = 0;
	for (size_t i = 0; str[i] != '\0'; ++i)
	{
		result += 1;
	}

	return result;
}

bool isLetter(char symbol) 
{
	if (65 <= int(symbol) and int(symbol) <= 90)
	{
		return true;
	}
	else if (97 <= int(symbol) and int(symbol) <= 122)
	{
		return true;
	}
	return false;
}


char* lower(char* str)
{
	int length = len(str);
	char* loweredStr = new char[length + 1] {};

	for (size_t i = 0; i < length; ++i)
	{
		int ASCII_num = int(str[i]);
		if (ASCII_num >= 65 and ASCII_num <= 90)
		{
			ASCII_num += 32;
		}
		loweredStr[i] = char(ASCII_num);
	}

	return loweredStr;
}


bool compareStr(char* str, char* word, int index) {
	bool flag = false;
	for (size_t i = index, j = 0; i < index + len(word); i++, j++)
	{
		if (str[i] == word[j])
		{
			flag = true;
		}
		else
		{
			flag = false;
			return flag;
		}
	}
	return flag;
}


void findReplace(char*& str, char* find, char* replace) {
	int length = len(str);

	char* tmp = new char[length + 1] {};
	for (size_t i = 0; i < length; i++)
	{
		tmp[i] = str[i];
	}

	int index = 0;
	for (size_t i = 0; i < length; i++)
	{
		if (compareStr(str, find, i))
		{
			index = i;
		}
	}

	if (index == 0 and not compareStr(str, find, 0))
	{
		std::cout << "No such word in text\n";
		return;
	}

	std::cout << index << std::endl;

	delete[] str;
	length = length - len(find) + len(replace);
	str = new char[length + 1] {};

	for (size_t i = 0, j = 0, k = 0; i < length; i++)
	{
		if (i >= index and i < index + len(replace))
		{
			str[i] = replace[k];
			k++;
			j = index + len(find);
			continue;
		}
		str[i] = tmp[j];
		j++;
	}
}


void capitalize(char* &str)
{
	int length = len(str);

	str[0] = char(int(str[0]) - 32);

	for (size_t i = 1; i < length; ++i) 
	{
		if (isLetter(str[i]) and !isLetter(str[i - 1]))
		{
			int ASCII_num = int(str[i]);
			ASCII_num -= 32;
			str[i] = char(ASCII_num);
		}
	}
}


void letterCount(char* str) {
	int length = len(str);
	char* strForSearch = lower(str);

	for (size_t i = 0; i < length; i++)
	{
		if (int(strForSearch[i]) > 32)
		{
			int count = 0;
			for (size_t j = 0; j < length; j++)
			{
				if (str[i] == strForSearch[j])
				{
					count += 1;
					strForSearch[j] = char(32);
				}
			}
			std::cout << "Count of \"" << str[i] << "\" in text - " << count << std::endl;
		}
	}
}


int numbersCount(char* str) {
	int length = len(str);
	int count = 0;

	for (size_t i = 0; i < length; i++)
	{
		int ASCII_num = int(str[i]);
		if (ASCII_num >= 48 and ASCII_num <= 57)
		{
			count += 1;
		}
	}

	return count;
}


int main() {
	using namespace std;

	int choice = 0;
	char* text = new char[17] {"ggg ddd ff o1337"};

	char* task1WordFind = new char[20] {};
	char* task1WordReplace = new char[20] {};

	cout
		<< "1. Find and replace\n"
		<< "2. Capitalize all sentences' beginnig\n"
		<< "3. Every letter's count in text\n"
		<< "4. Numbers count in text\n"
		<< "> ";
	cin >> choice;

	cout << "Text - " << text << endl;

	switch (choice)
	{
	case 1:
		cout << "Enter word you want to replace: ";
		cin >> task1WordFind;
		cout << "Enter word to replace: ";
		cin >> task1WordReplace;

		findReplace(text, task1WordFind, task1WordReplace);
		cout << "Text - " << text << endl;

		break;

	case 2:
		capitalize(text);
		cout << "Text after remarks -  " << text << endl;

		break;

	case 3:
		letterCount(text);
		
		break;

	case 4:
		cout << "Numbers count in text - " << numbersCount(text) << endl;

		break;

	default:
		break;
	}

	return 0;
}
