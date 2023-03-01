#include <iostream>
#include <time.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(0));

	int task{};

	cout << "Выберите задание: ";
	cin >> task;

	switch (task)
	{
	case 1:
	{
		int input_num{}, guessed_num{};
		cout << "Угадай число." << '\n';

		guessed_num = rand() % 10;

		while (true)
		{
			cout << "Введите число: ";
			cin >> input_num;

			if (input_num == guessed_num)
			{
				cout << "Вы угадали число." << endl;
				break;
			}
			else if (input_num < guessed_num)
			{
				cout << "Загаданное число больше введенного." << endl;
			}
			else
			{
				cout << "Загаданное число меньше введенного." << endl;
			}
		}
	}

	case 2:
	{
		bool stop = true;
		int amount{};

		cout 
			<< "Конвертер валют.\n"
			<< "Выберите пару валют.\n\n"
			<< "1. Тугрики - шмугрики\n"
			<< "2. Тугрики - бугрики\n"
			<< "3. Шмугрики - бугрики\n\n"
			<< "0. Выход." << endl;

		cout << "Введите количество валюты: ";
		cin >> amount;

		switch (stop)
		{
		case 0:
			stop = false;
			break;

		case 1:
			cout << "Вы получите " << amount * 1.7 << " шмугриков." << endl;

			break;

		case 2:
			cout << "Вы получите " << amount / 40 << " бугриков." << endl;

			break;

		case 3:
			cout << "Вы получите " << amount * 75 << " бугриков." << endl;

			break;

		default:
			break;
		}

		break;
	}

	default:
		break;
	}


	return 0;
}