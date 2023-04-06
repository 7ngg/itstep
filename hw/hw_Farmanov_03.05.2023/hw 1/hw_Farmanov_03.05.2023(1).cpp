#include <iostream>
#include <time.h>

using namespace std;


double task1(double x, int y) {
	if (y == 0)
	{
		return 1;
	}

	if (y % 2 == 1)
	{
		return x * task1(x, y - 1);
	}
	else
	{
		return task1(x * x, y / 2);
	}
}


int task2(int start, int end) {
	int sum = 0;

	for (size_t i = start; i < end + 1; i++)
	{
		sum += i;
	}

	return sum;
}


void task3(int x) {
	int sum = 0;

	for (size_t i = 1; i < x / 2 + 1; i++)
	{
		if (x % i == 0)
		{
			sum += i;
		}
	}

	if (x == sum)
	{
		cout << x << " is a perfect number";
	}
	else
	{
		cout << x << " is not a perfect number";
	}
}

//template <typename T>
void task4(int x, int y) {
	// Задание 4 про колоду карт
}


void task5(int x) {
	int firstH{}, secondH{};

	if (x >= 1000000 || x < 99999)
	{
		cout << "Number must contain 6 digits" << endl;
		exit(666);
	}

	while (x > 0)
	{
		if (x > 1000)
		{
			secondH += x % 10;
			x /= 10;
			continue;
		}

		firstH += x % 10;
		x /= 10;
	}

	cout << "First half sum = " << firstH << endl;
	cout << "Second half sum = " << secondH << endl;

	if (firstH == secondH)
	{
		cout << "You've entered a lucky number";
	}
	else
	{
		cout << "The entered number is not lucky";
	}
}


int main() {
	int task = 0;

	cout << "Choose the task: ";
	cin >> task;

	switch (task)
	{
	case 1:
	{
		double x = 0, y = 0;

		cout << "Enter num: ";
		cin >> x;

		cout << "Enter power: ";
		cin >> y;

		cout << "Result - " << task1(x, y);

		break;
	}

	case 2:
	{
		int start{}, end{};

		cout << "Enter segment star: ";
		cin >> start;

		cout << "Enter segment end: ";
		cin >> end;

		cout << "Result - " << task2(start, end);

		break;
	}

	case 3:
	{
		int num{};

		cout << "Enter num: ";
		cin >> num;

		task3(num);

		break;
	}

	case 4:
	{
		task4(5, 5);

		break;
	}

	case 5:
	{
		int num{};

		cout << "Emter num: ";
		cin >> num;

		task5(num);

		break;
	}

	default:
		break;
	}

	return 0;
}