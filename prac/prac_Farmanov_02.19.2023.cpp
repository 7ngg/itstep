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
		const int length = 6;
		int arr[length];

		int sum = 0;

		for (size_t i = 0; i < length; i++)
		{
			cout << "������� ������� �� " << i + 1 << " �����: ";
			cin >> arr[i];
			sum = sum + arr[i];
		}

		cout << "������� �� 6 ������� - " << sum << endl;

		break;
	}

	case 2:
	{
		int arr[]{ 1, 2, 3, 4, 5 };

		for (size_t i = 0; i < 5; i++)
		{
			cout << arr[4 - i] << ' ';
		}

		break;
	}

	case 3:
	{
		const int length = 5;
		int arr[length];

		int perimeter = 0;

		for (size_t i = 0; i < length; i++)
		{
			cout << "������� ����� �������: ";
			cin >> arr[i];

			perimeter += arr[i];
		}

		cout << "�������� ����� " << perimeter << endl;

		break;
	}

	case 4:
	{
		const int length = 12;
		int arr[length];

		for (size_t i = 0; i < length; i++)
		{
			cout << "������� ������� �� " << i + 1 << " �����: ";
			cin >> arr[i];
		}

		int min = arr[0];
		int max = arr[0];

		int min_index = 0, max_index = 0;

		for (size_t i = 0; i < length; i++)
		{
			if (arr[i] <= min)
			{
				min = arr[i];
				min_index = i;
			}

			if (arr[i] >= max)
			{
				max = arr[i];
				max_index = i;
			}
		}

		cout
			<< "����������� ������� ���� � " << min_index + 1 << " ������." << endl
			<< "������������ ������� ���� � " << max_index + 1<< " ������.";

		break;
	}

	default:
		cout << "������ ������� ���. " << endl;

		break;
	}


	return 0;
}