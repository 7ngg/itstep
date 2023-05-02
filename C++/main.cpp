#include <iostream>

int main() {
	using namespace std;
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

	default:
		cout << "No such option" << endl;
		break;
	}
	
	return 0;
}