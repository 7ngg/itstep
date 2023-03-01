#include <iostream>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	int task{};

	cout << "Выберите задание: ";
	cin >> task;

	switch (task) {
	case 1:
	{
		int result = 0;

		for (size_t i = 100; i < 1000; i++)
		{
			if (i / 100 == i / 10 % 10 || i / 100 == i % 10 || i / 10 % 10 == i % 10)
			{
				result += 1;
			}
		}

		cout << "Ответ: " << result << endl;

		break;
	}

	case 2:
	{
		int result = 0;

		for (size_t i = 100; i < 1000; i++)
		{
			if (i / 100 != i / 10 % 10 && i / 100 != i % 10 && i / 10 % 10 != i % 10)
			{
				result += 1;
			}
		}

		cout << "Ответ: " << result << endl;

		break;
	}

	case 3:
	{
		int num = 1337;
		int result = 0;

		cout << "Введите число: ";
		cin >> num;

		while (num > 0)
		{
			if (num % 10 != 3 && num % 10 != 6)
			{
				result *= 10;
				result += num % 10;
			}

			num /= 10;
		}

		cout << "Ответ: ";
		while (result > 0)
		{
			cout << result % 10;
			result /= 10;
		}

		break;
	}

	case 4:
	{
		int num = 666;

		cout << "Введите число: ";
		cin >> num;

		for (size_t i = 2; i < (num / 2 + 1); i++)
		{
			if (num % (i * i) == 0 && num % (i * i * i) != 0)
			{
				cout << i << endl;
			}
		}

		break;
	}

	case 5:
	{
		int num = 0;
		int sum = 0;

		cout << "Введите число: ";
		cin >> num;

		int num_backup = num;

		while (num > 0)
		{
			sum = sum + (num % 10);
			num /= 10;
		}

		if (num_backup * num_backup == sum * sum * sum)
		{
			cout << "Квадрат числа равен кубу суммы цифр." << '\n';
		}
		else
		{
			cout << "Квадрат числа не равен кубу суммы цифр." << '\n';
		}

		break;
	}

	case 6:
	{
		int num = 322;
		
		cout << "Введите число: ";
		cin >> num;

		for (size_t i = 1; i < num / 2 + 1; i++)
		{
			if (num % i == 0)
			{
				cout << num << " делится без остатка на " << i << endl;
			}
		}

		break;
	}

	case 7:
	{
		int num1{}, num2{}, limit{};

		cout << "Введите первое число: ";
		cin >> num1;

		cout << "Введите второе число: ";
		cin >> num2;

		limit = (num1 >= num2) ? num1 : num2;

		for (size_t i = 1; i < limit; i++)
		{
			if (num1 % i == 0 && num2 % i == 0)
			{
				cout << num1 << " и " << num2 << " делятся на " << i << " без остатка." << endl;
			}
		}

		break;
	}
	}

	return 0;
}