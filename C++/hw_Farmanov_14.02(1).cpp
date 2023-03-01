#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	int task;

	cout << "�������� �������: ";
	cin >> task;

	switch (task)
	{
	case 1:
	{
		char sym{};

		cout << "������� ������: ";
		cin >> sym;

		int i = sym;
		cout << "ASCII - " << i << endl;

		if (48 <= i && i <= 57)
		{
			cout << "�� ����� �����." << endl;
		}
		else if ((65 <= i && i <= 90) || (97 <= i && i <= 122))
		{
			cout << "�� ����� �����." << endl;
		}
		else
		{
			cout << "�� ����� ������." << endl;
		}

		break;
	}

	case 2:
	{
		int duration{}, choice{};

		cout << "������� ����������������� ��������� (���): ";
		cin >> duration;

		cout
			<< "�������� ���� ����������: " << endl
			<< "1. First - Second" << endl
			<< "2. First - Third" << endl
			<< "3. Second - Third" << endl
			<< "��� �����: ";
		
		cin >> choice;

		if (choice == 1)
		{
			cout << "�� " << duration << " ����� ��������� �� ��������� " << duration * 0.05 << " �." << endl;
		}
		else if (choice == 2)
		{
			cout << "�� " << duration << " ����� ��������� �� ��������� " << duration * 0.07 << " �." << endl;
		}
		else if (choice == 3)
		{
			cout << "�� " << duration << " ����� ��������� �� ��������� " << duration * 0.03 << " �." << endl;
		}
		else
		{
			cout << "����� �� ���������." << endl;
		}

		break;
	}

	case 3:
	{
		int choice{};

		cout << "�������� ������, �������� ������� �������: ";
		cin >> choice;

		int d_income{}, lateness{}, code_lines{};

		if (choice == 1)
		{
			cout << "������� �������� �����: ";
			cin >> d_income;

			cout << "������� ���������� ���������: ";
			cin >> lateness;

			if (lateness == 0)
			{
				cout << "���� ����� �������� " << (d_income + ((lateness / 3) * 20)) / 50 * 100 << " ����� ����." << endl;
			}
			else
			{
				cout << "���� ����� �������� " << (d_income + ((lateness / 3) * 20)) / 50 * 100 + 100 << " ����� ����." << endl;
			}
			
		}
		else if (choice == 2)
		{
			cout << "������� ���������� �����: ";
			cin >> code_lines;

			cout << "������� �������� ����� ��������: ";
			cin >> d_income;

			cout << "���� ����� �������� " << ((code_lines / 2) - d_income) / 20 * 3 << " ���";
		}
		else if (choice == 3)
		{
			cout << "������� ���������� �����: ";
			cin >> code_lines;

			cout << "������� ���������� ���������: ";
			cin >> lateness;

			d_income = code_lines / 2 - (lateness / 3 * 20);

			if (d_income <= 0)
			{
				cout << "���� �� ��������. " << endl;
			}
			else
			{
				cout << "���� �������� " << d_income << endl;
			}
		}

		break;
	}

	default:
		break;
	}


	return 0;
}