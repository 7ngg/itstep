#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	int task{};

	cout << "Выберите задание: ";
	cin >> task;

	switch (task)
	{
	case 1:
	{
		int a;

		cout << "Введите а: ";
		cin >> a;

		cout << "Сумма чисел от а до 500 равна " << (a + 500) * (500 - a + 1) / 2;

		break;
	}

	case 2:
	{
		int x{}, y{};

		cout << "Введите x: ";
		cin >> x;

		cout << "Введите y: ";
		cin >> y;

		int result = x;

		for (size_t i = 1; i < y; i++)
		{
			result *= x;
		}

		cout << "Ответ: " << result << endl;

		break;
	}

	case 3:
	{
		float result;
		result = float(1 + 1000) / float(2);

		cout << "Среднее арифметическое от 1 до 1000 равно " << result << endl;

		break;
	}

	case 4:
	{
		int a{}, result = 1;

		cout << "Введите a: ";
		cin >> a;

		for (a; a < 20 + 1; a++)
		{
			result *= a;
		}

		cout << "Ответ: " << result << endl;

		break;
	}

	case 5:
	{
		int k{};

		cout << "Введите k: ";
		cin >> k;

		for (size_t i = 0; i < 11; i++)
		{
			cout << k << " * " << i << " = " << k * i << endl;
		}

		break;
	}

	default:
		cout << "Такого задания нет. " << endl;

		break;
	}

	return 0;
}