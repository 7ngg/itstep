#include <iostream>
#include <stdint.h>
#include <time.h>

struct myStruct {
	int index = 0;
	int count = 0;
};


uint32_t len(char* text) {
	uint32_t length = 0;
	for (size_t i = 0; text[i] != '\0'; ++i) 
	{
		length += 1;	
	}
	return length;
}


char* lower(char* text) {
	uint32_t length = len(text);

	for (size_t i = 0; i < length; ++i)
	{
		uint16_t ASCII_num = uint16_t(text[i]);
		if (ASCII_num >= 65 and ASCII_num <= 90) 
		{
			ASCII_num += 32;
		}
		text[i] = char(ASCII_num);
	}

	return text;
}


myStruct findText(char* text, char* searchingText) {
	myStruct result{};

	char* loweredText = lower(text);
	char* loweredSearchingText = lower(searchingText);
	uint32_t textLength = len(text);
	uint32_t searchingTextLength = len(searchingText);

	for (size_t i = 0; i < textLength; ++i) 
	{
		uint32_t lengthCheck = 0;
	
		size_t j = i, k = 0;
		while (loweredSearchingText[k] == loweredText[i + searchingTextLength - j - 1] and loweredText[j] != '\0')
		{
			lengthCheck += 1;
			j += 1;
			k += 1;
		}

		if (lengthCheck == searchingTextLength)
		{
			result.count += 1;
			result.index = i;
		}
	}

	return result;
}


int main() {
	using namespace std;

	char* text = new char[300] {};
	char* searchingText = new char[300] {};
	
	cout << "Enter text: " << endl;
	cin.getline(text, 300);

	cout
		<< "Text: " << endl
		<< text << endl
		<< "Enter text to search: ";
	cin.getline(searchingText, 300);

	cout
		<< "Searching text starting index - " << findText(text, searchingText).index << endl
		<< "Searching text count - " << findText(text, searchingText).count << endl;

	return 0;
}
