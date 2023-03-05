#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	int task;

	cout << "Выберите задание: ";
	cin >> task;

	switch (task) {
	case 1:
		cout
			<< "\nЛюбовь абстракта\n"
			<< "Красота субъективна\n"
			<< "Пустота абсолютна\n"
			<< "Суждения оценочны\n"
			<< "Кабачкова икра\n"
			<< "\t\tпо акции\n"
			<< "\t\t\t\tА.С. Пушкин\n";

		break;
	case 2:
		cout
			<< "Каждый\n"
			<< "\tохотник\n"
			<< "\t\tжелает\n"
			<< "\t\t\tзнать\n"
			<< "\t\t\t\tгде\n"
			<< "\t\t\t\t\tсидит\n"
			<< "\t\t\t\t\t\tфазан\n";


		break;
	case 3:
	{
		string name = "холодильник 'Зенит'";
		float price = 1337;
		string description = "Классный холодильник. Честно.";
		string number = "+7(800)555-35-35";

		cout
			<< "\n\t\t\t\tОБЪЯВЛЕНИЕ\n"
			<< "Продается " << name << endl
			<< "Цена - " << price << " тугриков" << endl
			<< "Описание: " << description << endl
			<< "Номер телефона: " << number << endl;

		break;
	}

	default:
		cout << "Такого заданя нет." << endl;
	}
}