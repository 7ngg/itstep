#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	// Задание 1	
	/*
	int mark = 0, sum = 0;


	for (int i = 1; i < 6; i++)
	{
		cout << "введите " << i << "-ю оценку: ";
		cin >> mark;

		sum = sum + mark;
	}

	if (sum / 5 >= 4)
	{
		cout << "средний балл - " << sum / 5 << endl;
		cout << "студент допущен." << endl;
	}
	else 
	{
		cout << "средний балл - " << sum / 5 << endl;
		cout << "студент не допущен." << endl;
	}
	*/


	// Задание 2
	/*
	int num = 0;

	cout << "Введите число: ";
	cin >> num;


	if (num % 2 == 0)
	{
		num *= 3;
		cout 
			<< "Число - четное.\n"
			<< num << endl;
	}
	else
	{
		float float_num = float(num);
		float_num /= 2;
		cout 
			<< "Число - нечетное.\n"
			<< float_num << endl;
	}
	*/


	// Задание 3
	float num1{}, num2{};
	int sign;

	cout << "Введите первое число: ";
	cin >> num1;

	cout << "Введите второе число: ";
	cin >> num2;

	cout
		<< "\n1. Сложение +" << endl
		<< "2. Вычитание -" << endl
		<< "3. Умножение *" << endl
		<< "4. Деление /" << endl
		<< "\nВыберите операцию: ";

	cin >> sign;

	switch (sign)
	{
	case 1:
		cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;

		break;
	case 2:
		cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;

		break;
	case 3:
		cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;

		break;
	case 4:
		cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;

		break;
	default:
		cout << "Такая операция не определена." << endl;

		break;
	}

	return 0;
}