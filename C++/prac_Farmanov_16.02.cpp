#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	// ������� 1
	/*
	int start, end, check_num;

	cout << "������� ������ ����������: ";
	cin >> start;

	cout << "������ ����� ����������: ";
	cin >> end;

	while (true)
	{
		cout << "������� ����� ��� ��������: ";
		cin >> check_num;

		if (check_num < start || check_num > end)
		{
			continue;
		}
		else
		{
			cout << "����� ����������� ����������." << endl;
			break;
		}
	}
	*/


	// ������� 2
	int trees_count = 3, stars_count = 5, toys_count = 10, lights_count = 5;
	float trees_price = 250, stars_price = 30, toys_price = 10, lights_price = 15;

	int choice = 0, next_client_choice = 0;
	float income = 0, cash = 0, percent = 0;
	bool check = true;

	cout
		<< "�����������:" << endl
		<< "1. ���������� ����.\t" << "���������� - " << trees_count << ".\t\t���� �� �� - " << trees_price << " �." << endl
		<< "2. ���������� ������.\t" << "���������� - " << stars_count << ".\t\t���� �� �� - " << stars_price << " �." << endl
		<< "3. ������� ��� ����.\t" << "���������� - " << toys_count << ".\t���� �� �� - " << toys_price << " �." << endl
		<< "4. ��������.\t\t" << "���������� - " << lights_count << ".\t\t���� �� �� - " << lights_price << " �." << endl
		<< "\n0. �����. " << endl
		<< "5. ��������� ������." << "\n\n";


	while (check)
	{
		int amount = 0;

		cout << "�������� �����: ";
		cin >> choice;


		switch (choice)
		{
		case 0:
			income += cash;
			check = false;

			break;

		case 1:
			cout << "������� ���������� ������: ";
			cin >> amount;

			cout << "������� ������ ������ � %: ";
			cin >> percent;

			if (amount > trees_count)
			{
				cout << "� ������������ ������������ �������. " << endl;
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
			cout << "������� ���������� ������: ";
			cin >> amount;

			cout << "������� ������ ������ � %: ";
			cin >> percent;

			if (amount > stars_count)
			{
				cout << "� ������������ ������������ �������. " << endl;
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
			cout << "������� ���������� ������: ";
			cin >> amount;

			cout << "������� ������ ������ � %: ";
			cin >> percent;

			if (amount > toys_count)
			{
				cout << "� ������������ ������������ �������. " << endl;
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
			cout << "������� ���������� ������: ";
			cin >> amount;

			cout << "������� ������ ������ � %: ";
			cin >> percent;

			if (amount > lights_count)
			{
				cout << "� ������������ ������������ �������. " << endl;
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
			cout << "�������� ��������� � ������ ������ - " << cash << " �." << endl;
		}


	}


	cout
		<< "\n������� - " << income << "\n\n";



	return 0;
}