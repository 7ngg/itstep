#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	// ������� 1	
	/*
	int mark = 0, sum = 0;


	for (int i = 1; i < 6; i++)
	{
		cout << "������� " << i << "-� ������: ";
		cin >> mark;

		sum = sum + mark;
	}

	if (sum / 5 >= 4)
	{
		cout << "������� ���� - " << sum / 5 << endl;
		cout << "������� �������." << endl;
	}
	else 
	{
		cout << "������� ���� - " << sum / 5 << endl;
		cout << "������� �� �������." << endl;
	}
	*/


	// ������� 2
	/*
	int num = 0;

	cout << "������� �����: ";
	cin >> num;


	if (num % 2 == 0)
	{
		num *= 3;
		cout 
			<< "����� - ������.\n"
			<< num << endl;
	}
	else
	{
		float float_num = float(num);
		float_num /= 2;
		cout 
			<< "����� - ��������.\n"
			<< float_num << endl;
	}
	*/


	// ������� 3
	float num1{}, num2{};
	int sign;

	cout << "������� ������ �����: ";
	cin >> num1;

	cout << "������� ������ �����: ";
	cin >> num2;

	cout
		<< "\n1. �������� +" << endl
		<< "2. ��������� -" << endl
		<< "3. ��������� *" << endl
		<< "4. ������� /" << endl
		<< "\n�������� ��������: ";

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
		cout << "����� �������� �� ����������." << endl;

		break;
	}

	return 0;
}