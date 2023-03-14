#include <iostream>
#include <time.h>
using namespace std;


template <typename T>
T* lineSort(T* arr, const int length);

int* append(int num);

#pragma region Task1


template <typename T>
T** task1(const int rows, const int columns) {
	T** matrix = new T*[rows];
	for (size_t i = 0; i < rows; i++)
	{
		*(matrix + i) = new T[columns];
	}

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			*(*(matrix + i) + j) = T(rand() % 100);
		}
	}

	return matrix;
}


//template <typename T>
//void task1(T** arr, const int rows, const int columns) {
//	for (size_t i = 0; i < rows; i++)
//	{
//		for (size_t j = 0; j < columns; j++)
//		{
//			cout.width(2);
//			cout << *(*(arr + i) + j) << ' ';
//		}
//		cout << endl;
//	}
//}


template <typename T>
void task1(T** arr, const int columns) {
	T min = **arr;
	T max = **arr;

	for (size_t i = 0; i < columns; i++)
	{
		min = (*(*(arr + i) + i) < min) ? *(*(arr + i) + i) : min;
		max = (*(*(arr + i) + i) > max) ? *(*(arr + i) + i) : max;
	}

	cout
		<< "Main diagonal max = " << max << '\n'
		<< "Main diagonal min = " << min << '\n';
}


template <typename T>
T* task1(T** arr, const int rows, const int rowLength) {
	for (int i = 0; i < rows; i++)
	{
		lineSort(arr[0 + i], rowLength);
	}
	return *arr;
}


#pragma endregion


int task2(int a, int b) {
	if (b == 0)
		return a;
	else
		return task2(b, a % b);
}


int main(){
	srand(time(NULL));

	int task;
	cout << "Choose the task: ";
	cin >> task;

	switch (task)
	{
	case 1:
		{
			int** arr = task1<int>(5, 5);			// def + init
			task1<int>(arr, 5, 5);					// diagonal min/max
			task1<int>(arr, 5);						// sorting rows

			for (size_t i = 0; i < 5; i++)
			{
				for (size_t j = 0; j < 5; j++)
				{
					cout.width(2);
					cout << *(*(arr + i) + j) << ' ';
				}
				cout << endl;
			}

			break;
		}

	case 2:
		{
			int num1{}, num2{};

			cout << "Enter first num: ";
			cin >> num1;
			cout << "Enter second num: ";
			cin >> num2;

			cout << task2(num1, num2);

			break;
		}

	case 3:
		{
			int x = 1000 + rand() % 9000;
			cout << x << endl;

			int num = 0, attempts = 0;
			int a = 0;				// variable to avoid dublication in loop (line 171 - 181)

			while (true)
			{
				int guessed = 0, right_place_guessed = 0;

				cout << "Enter 0 to exit.\n";
				cout << "Enter num: ";
				cin >> num;
				attempts += 1;

				if (num == 0)
				{
					break;
				}

				if (num < 1000 || num >= 10000)
				{
					cout << "Num must contain 4 digits." << endl;
					continue;
				}

				if (num == x)
				{
					cout << "You've guessed right!" << endl;
					cout << "Attempts - " << attempts << endl;
					break;
				}

				for (size_t k = 0; k < 4; k++)
				{
					if (*(append(num) + k) == *(append(x) + k))
					{
						cout << *(append(num) + k) << " is placed right." << endl;
						right_place_guessed += 1;
					}

					for (size_t l = 0; l < 4; l++)
					{
						if (*(append(num) + k) != a)
						{
							if (*(append(num) + k) == *(append(x) + l))
							{
								guessed += 1;
							}
						}
					}
					a = *(append(num) + k);
				}
				cout << "Bulls - " << guessed - right_place_guessed << endl;
				cout << "Cows - " << right_place_guessed << endl;
			}

			break;
		}
	}

	return 0;
}


template <typename T>
T* lineSort(T* arr, const int length) {
	for (size_t i = 1; i < length; i++)
	{
		int index = i;
		while (index > 0 && arr[index - 1] > arr[index])
		{
			T tmp = arr[index - 1];
			arr[index - 1] = arr[index];
			arr[index] = tmp;
			index -= 1;
		}
	}
	return arr;
}


int* append(int num) {
	int* arr = (int*)calloc(4, 4 * sizeof(int));

	for (int i = 0; i < 4; ++i)
	{
		*(arr + 3 - i) = num % 10;
		num /= 10;
	}

	return arr;
}