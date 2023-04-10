#include <iostream>
#include "lib.h"

template <typename T>
void print(T* arr, const int length) {
	for (size_t i = 0; i < length; i++)
	{
		std::cout << *(arr + i);
	}
	std::cout << std::endl;
}


int digitCount(int x) {
	int result = 0;
	while (x > 0)
	{
		result += 1;
		x /= 10;
	}

	return result;
}


int main() {
	using namespace std;

	char* str1 = new char[9] {"string_1"};
	char* str2 = new char[11] {"string_Two"};
	char* str2num = new char[5] {"1337"};
	char* num2str = new char[0];

	int num = 0;

	int choice = 0;
	cout
		<< "1. Mystrcmp\n"
		<< "2. StringToNumber\n"
		<< "3. NumberToString\n"
		<< "4. Uppercase\n"
		<< "5. Lowercase\n"
		<< "6. Mystrrev\n"
		<< "> ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		cout
			<< "String 1 - " << str1 << endl
			<< "String 2 - " << str2 << endl
			<< "Result - " << mystrcmp(str1, str2) << endl;

		break;
	
	case 2:
		num = StringToNumber(str2num);
		cout
			<< "String - " << str2num << endl
			<< "Number - " << num << endl;

		break;

	case 3:
		num = 12345;

		delete[] num2str;
		num2str = NumberToString(num);

		cout
			<< "Number - " << num << endl
			<< "String - " << num2str << endl;

		break;

	case 4:
		cout << Uppercase(str1) << endl;
		
		break;

	case 5:
		cout << Lowercase(str2) << endl;

		break;

	case 6:
		cout
			<< mystrrev(str1) << endl
			<< mystrrev(str2) << endl;

		break;

	default:
		break;
	}
}