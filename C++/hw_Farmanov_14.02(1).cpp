#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	int task;

	cout << "Выберите задание: ";
	cin >> task;

	switch (task)
	{
	case 1:
	{
		char sym{};

		cout << "Введите символ: ";
		cin >> sym;

		int i = sym;
		cout << "ASCII - " << i << endl;

		if (48 <= i && i <= 57)
		{
			cout << "Вы ввели цифру." << endl;
		}
		else if ((65 <= i && i <= 90) || (97 <= i && i <= 122))
		{
			cout << "Вы ввели букву." << endl;
		}
		else
		{
			cout << "Вы ввели символ." << endl;
		}

		break;
	}

	case 2:
	{
		int duration{}, choice{};

		cout << "Введите продолжительность разговора (мин): ";
		cin >> duration;

		cout
			<< "Выберите пару операторов: " << endl
			<< "1. First - Second" << endl
			<< "2. First - Third" << endl
			<< "3. Second - Third" << endl
			<< "Ваш выбор: ";
		
		cin >> choice;

		if (choice == 1)
		{
			cout << "За " << duration << " минут разговора Вы заплатите " << duration * 0.05 << " т." << endl;
		}
		else if (choice == 2)
		{
			cout << "За " << duration << " минут разговора Вы заплатите " << duration * 0.07 << " т." << endl;
		}
		else if (choice == 3)
		{
			cout << "За " << duration << " минут разговора Вы заплатите " << duration * 0.03 << " т." << endl;
		}
		else
		{
			cout << "Выбор не определен." << endl;
		}

		break;
	}

	case 3:
	{
		int choice{};

		cout << "Выберите задачу, согласно условию задания: ";
		cin >> choice;

		int d_income{}, lateness{}, code_lines{};

		if (choice == 1)
		{
			cout << "Введите желаемый доход: ";
			cin >> d_income;

			cout << "Введите количество опозданий: ";
			cin >> lateness;

			if (lateness == 0)
			{
				cout << "Васе нужно написать " << (d_income + ((lateness / 3) * 20)) / 50 * 100 << " строк кода." << endl;
			}
			else
			{
				cout << "Васе нужно написать " << (d_income + ((lateness / 3) * 20)) / 50 * 100 + 100 << " строк кода." << endl;
			}
			
		}
		else if (choice == 2)
		{
			cout << "Введите количество строк: ";
			cin >> code_lines;

			cout << "Введите желаемый объем зарплаты: ";
			cin >> d_income;

			cout << "Вася может опоздать " << ((code_lines / 2) - d_income) / 20 * 3 << " раз";
		}
		else if (choice == 3)
		{
			cout << "Введите количество строк: ";
			cin >> code_lines;

			cout << "Введите количество опозданий: ";
			cin >> lateness;

			d_income = code_lines / 2 - (lateness / 3 * 20);

			if (d_income <= 0)
			{
				cout << "Васе не заплатят. " << endl;
			}
			else
			{
				cout << "Васе заплатят " << d_income << endl;
			}
		}

		break;
	}

	default:
		break;
	}


	return 0;
}