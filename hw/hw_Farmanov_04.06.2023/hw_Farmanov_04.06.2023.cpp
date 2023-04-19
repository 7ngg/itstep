#include <iostream>
#include <iso646.h>

int len(char* str) {
	int result = 0;
	for (size_t i = 0; str[i] != '\0'; i++)
	{
		result += 1;
	}

	return result;
}


void replaceSym(char*& str, char symFind, char symReplace) {
	for (size_t i = 0; i < len(str); i++)
	{
		if (str[i] == symFind)
		{
			str[i] = symReplace;
		}
	}
}


void ASCII_sort(char*& str) {
	int length = len(str);

	for (size_t i = 1; i < length; i++)
	{
		int index = i;
		while (index > 0 and int(str[index - 1]) > int(str[index]))
		{
			char tmp = str[index - 1];
			str[index - 1] = str[index];
			str[index] = tmp;
			index -= 1;
		}
	}
}


int main() {
	using namespace std;

	char* text = new char[300] {};
	int choice = 0;

	char task2CharFind{};
	char task2CharReplace{};

	cout << "Enter text: " << endl;
	cin.getline(text, 300);


	cout
		<< "Choose opeation:" << endl
		<< "1. Find text length" << endl
		<< "2. Replace symbol" << endl
		<< "3. ASCII sort" << endl
		<< "> ";
	cin >> choice;

	cout
		<< "Text:" << endl
		<< '\t' << text << endl;

	switch (choice)
	{
	case 1:
		cout << "Length - " << len(text);

		break;

	case 2:
		cout << "Enter symbol you want to replace: ";
		cin >> task2CharFind;
		cout << "Enter symbol to repalce: ";
		cin >> task2CharReplace;

		replaceSym(text, task2CharFind, task2CharReplace);

		cout
			<< "Text - " << endl
			<< '\t' << text;

		break;

	case 3:
		ASCII_sort(text);

		cout
			<< "Text - " << endl
			<< '\t' << text;

		break;

	default:
		break;
	}

	return 0;
}