#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	int task{};

	cout << "�������� �������: ";
	cin >> task;

	switch (task)
	{
	case 1:
	{
		int a;

		cout << "������� �: ";
		cin >> a;

		cout << "����� ����� �� � �� 500 ����� " << (a + 500) * (500 - a + 1) / 2;

		break;
	}

	case 2:
	{
		int x{}, y{};

		cout << "������� x: ";
		cin >> x;

		cout << "������� y: ";
		cin >> y;

		int result = x;

		for (size_t i = 1; i < y; i++)
		{
			result *= x;
		}

		cout << "�����: " << result << endl;

		break;
	}

	case 3:
	{
		float result;
		result = float(1 + 1000) / float(2);

		cout << "������� �������������� �� 1 �� 1000 ����� " << result << endl;

		break;
	}

	case 4:
	{
		int a{}, result = 1;

		cout << "������� a: ";
		cin >> a;

		for (a; a < 20 + 1; a++)
		{
			result *= a;
		}

		cout << "�����: " << result << endl;

		break;
	}

	case 5:
	{
		int k{};

		cout << "������� k: ";
		cin >> k;

		for (size_t i = 0; i < 11; i++)
		{
			cout << k << " * " << i << " = " << k * i << endl;
		}

		break;
	}

	default:
		cout << "������ ������� ���. " << endl;

		break;
	}

	return 0;
}