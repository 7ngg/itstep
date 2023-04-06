#include <iostream>

int len(char* line) {
	int result = 0;
	int i = 0;

	while (*(line + i) != '\0')
	{
		result += 1;
		i += 1;
	}

	return result;
}


bool isLetter(char x) {
	if (65 <= int(x) and int(x) <= 90)
		return true;
	else if (97 <= int(x) and int(x) <= 122)
		return true;
	return false;
}


bool isNumber(char x) {
	if (48 <= int(x) and int(x) <= 57)
		return true;
	return false;
}


bool isSymbol(char x) {
	if (not isLetter(x) and not isNumber(x))
		return true;
	return false;
}


int main() {
	using namespace std;

	int task = 0;
	cout << "Choose the task: ";
	cin >> task;
	
	char* str = new char[29] {"A clown is playing valorant."};
	int length = len(str);

	switch (task)
	{
	case 1:
	{
		cout << "String - " << str << endl;

		for (size_t i = 0; i < length; i++)
		{
			if (*(str + i) == char(32))
			{
				*(str + i) = '\t';
			}
		}

		cout << str << endl;

		break;
	}

	case 2:
	{
		int numbersCount{}, letterCount{}, symbolCount{};

		cout << "String - " << str << endl;

		for (size_t i = 0; i < length; i++)
		{
			if (isLetter(*(str + i)))
			{
				letterCount += 1;
			}
			else if (isNumber(*(str + i)))
			{
				numbersCount += 1;
			}
			else if (isSymbol(*(str + i)))
			{
				symbolCount += 1;
			}
		}

		cout
			<< "Letters count: " << letterCount << endl
			<< "Numbers count: " << numbersCount << endl
			<< "Symbols count: " << symbolCount << endl;

		break;
	}

	case 3:
	{
		int wordLength = 0;

		int i = 1;
		int wordsCount = 0;
		
		cout << "String - " << str << endl;

		for (size_t i = 1; i < length; i++)
		{
			if (isSymbol(*(str + i)) and not isSymbol(*(str + i - 1)))
			{
				wordsCount += 1;
			}
		}
		if (isLetter(*(str + length - 1)))
		{
			wordsCount += 1;
		}

		int* result = new int[wordsCount] {};

		for (size_t i = 0, j = 0; i != length; i++)
		{
			if (isLetter(*(str + i)))
			{
				wordLength += 1;
			}
			else if (not isLetter(*(str + i)))
			{
				*(result + j) = wordLength;
				wordLength = 0;
				j += 1;
			}
		}
		if (isLetter(*(str + length - 1)))
		{
			*(result + wordsCount - 1) = wordLength;
		}

		for (size_t i = 0; i < wordsCount; i++)
		{
			cout << "Word " << i + 1 << " length - " << *(result + i) << endl;
		}

		break;
	}

	case 4:
	{
		delete[] str;
		str = new char[4] {"101"};

		cout << "String - " << str << endl;

		length = len(str);
		int halfLength = (length % 2 == 0) ? length : length - 1;

		for (size_t i = 0; i < halfLength; i++)
		{
			if (*(str + i) != *(str + length - 1 - i))
			{
				cout << "String is not a palindrome" << endl;
				break;
			}
			
			if (i == halfLength - 1)
			{
				cout << "String is a palindrome" << endl;
			}
		}

		break;
	}

	default:
		break;
	}

	return 0;
}