#include <iostream>

#include "json.hpp"

#include "global_functions.h"
#include "sea_battle.h"
#include "arithmetic.h"

int main() {
	using namespace std;
	using json = nlohmann::json;

	setlocale(LC_ALL, "Russian");

	uint16_t choice = 0;
	cout
		<< "Выберите задание:" << endl
		<< "1. Морской бой" << endl
		<< "2. Пятнашки" << endl
		<< "3. Cписок дел" << endl
		<< "4. Игра \'Память\'" << endl
		<< "5. Подсчет арифметического выражения" << endl
		<< "6. Приложение \'Каталог текстов песен\'" << endl
		<< "> ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		break;

	case 3:


		break;

	case 5:
	{
		char* line = new char[128] {};
		cout
			<< "Введите арифметическое выражение (не более 127 символов)" << endl
			<< "> ";
		cin.ignore();
		cin.getline(line, 127);
		cout << line << endl;
		cout << arithmeticMainFunc(line);

	}
		break;

	case 10:
	{
		json j;
		cin >> j["age"];
		cout << j;
		break;
	}

	default:
		cout << "No such option" << endl;
		break;
	}
	
	return 0;
}