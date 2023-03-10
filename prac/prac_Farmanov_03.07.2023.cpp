#include <iostream>
#include <time.h>

using namespace std;

void initArray(int* arr, const int length);
void printArray(int* arr, const int length);


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
		return task1(x * x,  y / 2);
	}
}


void task2(int len) {
	if (len == 1)
	{
		cout << "*";
	}
	else
	{
		cout << "*";
		task2(len - 1);
	}
}


int task3(int start, int end) {
	if (start == end)
	{
		return start;
	}
	else
	{
		return start + task3(start + 1, end);
	}
}


int task4(int* arr, int start, int &pos) {
	int sum = 0;
	
	for (int i = start; i < start + 10; i++)
	{
		sum += arr[i];
	}
	
	if (100 - start == 10)
	{
		pos = start;
		return sum;
	}
	else
	{
		int nextSum = task4(arr, start + 1, pos);
		if (sum <= nextSum)
		{
			pos = start;
			return sum;
		}
		else
		{
			return nextSum;
		}
	}
}


#pragma region Task 5

int task5(int* arr, int length) {
	cout << "One dimensional array:\n";

	for (size_t i = 0; i < length; i++)
	{
		*(arr + i) = rand() % 10;
		cout << *(arr + i) << ' ';
	}

	int max = *(arr);

	for (size_t i = 0; i < length; i++)
	{
		max = (*(arr + i) > max) ? *(arr + i) : max;
	}

	cout << "\nMax equals to - ";
	return max;
}


int task5(int** arr, const int rows, const int columns) {
	cout << "Two dimensional array:\n";

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			*(*(arr + i) + j) = rand() % 10;
			cout << *(*(arr + i) + j) << ' ';
		}
		cout << endl;
	}

	int max = **arr;

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			max = (*(*(arr + i) + j)) > max ? *(*(arr + i) + j) : max;
		}
	}

	cout << "Max equals to - ";
	return max;
}


int task5(int*** arr, const int x, const int y, const int z) {
	cout << "Three dimensional array:\n";
	for (size_t i = 0; i < x; i++)
	{
		for (size_t j = 0; j < y; j++)
		{
			for (size_t k = 0; k < z; k++)
			{
				arr[i][j][k] = rand() % 30;
				cout << arr[i][j][k] << ' ';
				if (k == 2)
				{
					cout << endl;
				}
			}
		}
		cout << endl;
	}

	int max = arr[0][0][0];
	for (size_t i = 0; i < x; i++)
	{
		for (size_t j = 0; j < y; j++)
		{
			for (size_t k = 0; k < z; k++)
			{
				max = (arr[i][j][k] > max) ? arr[i][j][k] : max;
			}
		}
	}

	cout << "Max equals to - ";
	return max;
}

void task5(int x, int y) {
	if (x > y)
	{
		cout << x << " is bigger";
	}
	else if (y > x)
	{
		cout << y << " is bigger";
	}
	else
	{
		cout << "Numbers are equal";
	}
}


void task5(int x, int y, int z) {
	if (x > y && x > z)
	{
		cout << x << " is bigger\n";
	}
	else if (y > x && y > z)
	{
		cout << y << " is bigger\n";
	}
	else if (z > x && z > y)
	{
		cout << z << " is bigger\n";
	}
	else
	{
		cout << "Numbers are equal";
	}
}

#pragma endregion


int main() {
	srand(time(0));

	int task = 0;

	cout << "Choose the task: ";
	cin >> task;

	switch (task)
	{
	case 1:
	{
		int num{}, power{};

		cout << "Enter num: ";
		cin >> num;

		cout << "Enter power: ";
		cin >> power;

		cout << "Result - " << task1(num, power);

		break;
	}

	case 2:
	{
		int length = 0;

		cout << "Enter length: ";
		cin >> length;

		task2(length);

		break;
	}

	case 3:
	{
		int start = 0, end = 0;

		cout << "Enter segment start: ";
		cin >> start;

		cout << "Enter segment end: ";
		cin >> end;

		cout << "Result - " << task3(start, end);

		break;
	}

	case 4:
	{
		int index;
		int* A = (int*)calloc(100, 100 * sizeof(int));
		initArray(A, 100);

		cout << "Array: " << endl;
		printArray(A, 100);

		task4(A, 0, index);
		cout << "Min sum begins from index " << index << endl;

		break;
	}

	case 5:
	{
		int num1{}, num2{}, num3{};

		int* oneD = new int[10];

		int** twoD = new int*[5];
		for (size_t i = 0; i < 5; i++)
		{
			*(twoD + i) = new int[4];
		}

		int*** threeD = new int**[3];
		for (size_t i = 0; i < 3; i++)
		{
			threeD[i] = new int* [3];
			for (size_t j = 0; j < 3; j++)
			{
				threeD[i][j] = new int[3];
			}
		}
		
		cout << "Enter first num: ";
		cin >> num1;
		cout << "Enter second num: ";
		cin >> num2;
		cout << "Enter third num: ";
		cin >> num3;

		cout << task5(oneD, 10) << endl;
		cout << task5(twoD, 4, 5) << endl;
		cout << task5(threeD, 3, 3, 3) << endl;

		cout << endl;

		cout << "Comparing num1 && num2...\n";
		task5(num1, num2);

		cout << endl;

		cout << "Comparing num1 && num2 && num3...\n";
		task5(num1, num2, num3);

		delete[] oneD;
		delete[] twoD;
		delete[] threeD;

		break;
	}

	default:
		break;
	}

	return 0;
}


void initArray(int* arr, const int length) {
	for (size_t i = 0; i < length; i++)
	{
		arr[i] = rand() % 10;
	}
}


void printArray(int* arr, const int length) {
	for (size_t i = 0; i < length; i++)
	{
		if (i % 10 == 0)
		{
			cout << '\n' << arr[i] << ' ';
		}
		else
		{
			cout << arr[i] << ' ';
		}
	}
	cout << endl;
}
