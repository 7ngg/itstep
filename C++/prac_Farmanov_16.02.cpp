#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	// Задание 1
	/*
	int start, end, check_num;

	cout << "Введите начало промежутка: ";
	cin >> start;

	cout << "Ведите конец промежутка: ";
	cin >> end;

	while (true)
	{
		cout << "Введите число для проверки: ";
		cin >> check_num;

		if (check_num < start || check_num > end)
		{
			continue;
		}
		else
		{
			cout << "Число принадлежит промежутку." << endl;
			break;
		}
	}
	*/


	// Задание 2
	int trees_count = 3, stars_count = 5, toys_count = 10, lights_count = 5;
	float trees_price = 250, stars_price = 30, toys_price = 10, lights_price = 15;

	int choice = 0, next_client_choice = 0;
	float income = 0, cash = 0, percent = 0;
	bool check = true;

	cout
		<< "Ассортимент:" << endl
		<< "1. Новогодняя елка.\t" << "Количество - " << trees_count << ".\t\tЦена за шт - " << trees_price << " т." << endl
		<< "2. Новогодняя звезда.\t" << "Количество - " << stars_count << ".\t\tЦена за шт - " << stars_price << " т." << endl
		<< "3. Игрушки для елке.\t" << "Количество - " << toys_count << ".\tЦена за шт - " << toys_price << " т." << endl
		<< "4. Гирлянды.\t\t" << "Количество - " << lights_count << ".\t\tЦена за шт - " << lights_price << " т." << endl
		<< "\n0. Выход. " << endl
		<< "5. Следующий клиент." << "\n\n";


	while (check)
	{
		int amount = 0;

		cout << "Выберите товар: ";
		cin >> choice;


		switch (choice)
		{
		case 0:
			income += cash;
			check = false;

			break;

		case 1:
			cout << "Введите количество товара: ";
			cin >> amount;

			cout << "Введите размер скидки в %: ";
			cin >> percent;

			if (amount > trees_count)
			{
				cout << "В ассортименте недостаточно товаров. " << endl;
			}
			else
			{
				if (percent != 0)
				{
					percent = percent / 100;
					cash = cash + (amount * (trees_price - (trees_price * percent)));
				}
				else
				{
					cash = cash + (amount * trees_price);
				}

				trees_count = trees_count - amount;
			}

			break;

		case 2:
			cout << "Введите количество товара: ";
			cin >> amount;

			cout << "Введите размер скидки в %: ";
			cin >> percent;

			if (amount > stars_count)
			{
				cout << "В ассортименте недостаточно товаров. " << endl;
			}
			else
			{
				if (percent != 0)
				{
					percent = percent / 100;
					cash = cash + (amount * (stars_price - (stars_price * percent)));
				}
				else
				{
					cash = cash + (amount * stars_price);
				}

				stars_count = stars_count - amount;
			}

			break;

		case 3:
			cout << "Введите количество товара: ";
			cin >> amount;

			cout << "Введите размер скидки в %: ";
			cin >> percent;

			if (amount > toys_count)
			{
				cout << "В ассортименте недостаточно товаров. " << endl;
			}
			else
			{
				if (percent != 0)
				{
					percent = percent / 100;
					cash = cash + (amount * (toys_price - (toys_price * percent)));
				}
				else
				{
					cash = cash + (amount * toys_price);
				}

				toys_count = toys_count - amount;
			}

			break;

		case 4:
			cout << "Введите количество товара: ";
			cin >> amount;

			cout << "Введите размер скидки в %: ";
			cin >> percent;

			if (amount > lights_count)
			{
				cout << "В ассортименте недостаточно товаров. " << endl;
			}
			else
			{
				if (percent != 0)
				{
					percent = percent / 100;
					cash = cash + (amount * (lights_price - (lights_price * percent)));
				}
				else
				{
					cash = cash + (amount * lights_price);
				}

				lights_count = lights_count - amount;
			}
			break;

		case 5:
			income += cash;
			cash = 0;

			break;
		}

		if (choice != 0 && choice != 5)
		{
			cout << "Итоговая стоимость с учетом скидки - " << cash << " т." << endl;
		}


	}


	cout
		<< "\nВыручка - " << income << "\n\n";



	return 0;
}