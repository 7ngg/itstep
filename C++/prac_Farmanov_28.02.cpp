#include <iostream>
#include <ctime>

using namespace std;

#define columns 5
#define rows 4

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(0));

	int task = 0;

	cout << "Выберите задание: ";
	cin >> task;

	switch (task)
	{
	case 1:
	{

		int sum = 0;
		int count = 0;

		int arr[rows][columns] = {};

		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < columns; j++)
			{
				arr[i][j] = rand() % 10;

				sum += arr[i][j];
				count += 1;
			}
		}

		int min = arr[0][0];
		int max = arr[0][0];

		cout << "Исходный массив" << endl;
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < columns; j++)
			{
				cout << arr[i][j] << ' ';

				min = (arr[i][j] < min) ? arr[i][j] : min;
				max = (arr[i][j] > max) ? arr[i][j] : max;
			}
			cout << endl;
		}

		cout
			<< '\n'
			<< "Сумма всех элементов - " << sum << endl
			<< "Среднее арифметическое - " << (float)sum / count << endl
			<< "Минимум - " << min << endl
			<< "Максимум - " << max << endl;

		break;
	}

	case 2:
	{
		int arr[rows][columns] = {};
		int final_arr[rows + 1][columns + 1] = {};

		int x_sum[rows]{}, y_sum[columns]{};

		for (size_t i = 0; i < rows; i++)
		{
			int x_axis_value{};

			for (size_t j = 0; j < columns; j++)
			{
				arr[i][j] = final_arr[i][j] = rand() % 10;

				x_axis_value += arr[i][j];
			}
			x_sum[i] = x_axis_value;
		}

		for (size_t j = 0; j < columns; j++)
		{
			int y_axis_value{};

			for (size_t i = 0; i < rows; i++)
			{
				y_axis_value += arr[i][j];
			}
			y_sum[j] = y_axis_value;
		}

		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < columns + 1; j++)
			{
				if (j == columns)
				{
					cout.width(2);
					cout << "| " << x_sum[i];
				}
				else
				{
					cout.width(2);
					cout << arr[i][j] << ' ';
				}
			}
			cout << endl;
		}

		int iter{};
		while (iter < columns)
		{
			cout.width(2);
			cout << " - ";
			iter++;
		}

		cout << endl;

		for (size_t i = 0; i < columns; i++)
		{
			cout.width(2);
			cout << y_sum[i] << ' ';
		}

		break;
	}

	case 3:
	{
		int arr[5][10] = {};
		int result[5][5] = {};

		for (size_t i = 0; i < 5; i++)
		{
			for (size_t j = 0; j < 5; j++)
			{
				arr[i][j] = rand() % 50;
				arr[i][j + 5] = rand() % 50;
			}
		}

		for (size_t i = 0; i < 5; i++)
		{
			for (size_t j = 0; j < 5; j++)
			{
				if (j == 0)
				{
					result[i][j] = arr[i][j] + arr[i][j + 1];
				}
				else
				{
					result[i][j] = arr[i][2 * j] + arr[i][2 * j + 1];
				}
			}
		}

		cout << "Исходный массив: " << endl;
		for (size_t i = 0; i < 5; i++)
		{
			for (size_t j = 0; j < 10; j++)
			{
				cout.width(2);
				cout << arr[i][j] << ' ';
			}
			cout << endl;
		}

		cout << endl;

		cout << "Полученный массив: " << endl;
		for (size_t i = 0; i < 5; i++)
		{
			for (size_t j = 0; j < 5; j++)
			{
				cout.width(2);
				cout << result[i][j] << ' ';
			}
			cout << endl;
		}

		break;
	}

	default:
		break;
	}

	

	return 0;
}