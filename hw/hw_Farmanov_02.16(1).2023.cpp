#include <iostream>
#include <time.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(0));

	int task{};

	cout << "�������� �������: ";
	cin >> task;

	switch (task)
	{
	case 1:
	{
		int input_num{}, guessed_num{};
		cout << "������ �����." << '\n';

		guessed_num = rand() % 10;

		while (true)
		{
			cout << "������� �����: ";
			cin >> input_num;

			if (input_num == guessed_num)
			{
				cout << "�� ������� �����." << endl;
				break;
			}
			else if (input_num < guessed_num)
			{
				cout << "���������� ����� ������ ����������." << endl;
			}
			else
			{
				cout << "���������� ����� ������ ����������." << endl;
			}
		}
	}

	case 2:
	{
		bool stop = true;
		int amount{};

		cout 
			<< "��������� �����.\n"
			<< "�������� ���� �����.\n\n"
			<< "1. ������� - ��������\n"
			<< "2. ������� - �������\n"
			<< "3. �������� - �������\n\n"
			<< "0. �����." << endl;

		cout << "������� ���������� ������: ";
		cin >> amount;

		switch (stop)
		{
		case 0:
			stop = false;
			break;

		case 1:
			cout << "�� �������� " << amount * 1.7 << " ���������." << endl;

			break;

		case 2:
			cout << "�� �������� " << amount / 40 << " ��������." << endl;

			break;

		case 3:
			cout << "�� �������� " << amount * 75 << " ��������." << endl;

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