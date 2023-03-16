#include <iostream>
#include <time.h>
using namespace std;

int* createArr(const int len);
void initArr(int* arr, const int len);
void printArray(int* arr, const int len);
void print2d(int** arr, const int rows, const int columns);
void sort(int* arr, const int len);


int binary(int* arr, int start, int end, int x){
	if (x == arr[(start + end) / 2])
	{
		return (start + end) / 2;
	}
	else if (x <= arr[(start + end) / 2])
	{
		return binary(arr, start, end / 2, x);
	}
	else
	{
		return binary(arr, start + 1, end, x);
	}
}


void moveRight(int** arr, const int rows, const int columns, int count) {
	if (count == 0) 
		return;

	for (size_t i = 0; i < rows; i++)
	{
		int tmp = arr[i][columns - 1];
		for (size_t j = columns - 1; j > 0; j--)
		{
			arr[i][j] = arr[i][j - 1];
		}
		arr[i][0] = tmp;
	}

	moveRight(arr, rows, columns, count - 1);
}


void moveLeft(int** arr, const int rows, const int columns, int count) {
	if (count == 0)
		return;

	for (size_t i = 0; i < rows; i++)
	{
		int tmp = arr[i][0];
		for (size_t j = 0; j < columns; j++)
		{
			arr[i][j - 1] = arr[i][j];
		}
		arr[i][columns - 1] = tmp;
	}

	moveLeft(arr, rows, columns, count - 1);
}


void moveUp(int** arr, const int rows, const int columns, int count) {
	if (count == 0)
		return;

	for (size_t j = 0; j < columns; j++)
	{
		int tmp = arr[0][j];
		for (size_t i = 0; i < rows - 1; i++)
		{
			arr[i][j] = arr[i + 1][j];
		}
		arr[rows - 1][j] = tmp;
	}

	moveUp(arr, rows, columns, count - 1);
}


void moveDown(int** arr, const int rows, const int columns, int count) {
	if (count == 0)
		return;

	for (size_t j = 0; j < columns; j++)
	{
		int tmp = arr[rows - 1][j];
		for (size_t i = rows - 1; i > 0; i--)
		{
			arr[i][j] = arr[i - 1][j];
		}
		arr[0][j] = tmp;
	}

	moveDown(arr, rows, columns, count - 1);
}


int main(){
	srand(time(NULL));

	int task;
	cout << "Enter task: ";
	cin >> task;

	switch (task)
	{
	case 1:
	{
		int* A = createArr(10);
		initArr(A, 10);

		cout << "Array - ";
		printArray(A, 10);

		sort(A, 10);
		cout << "Sorted array - ";
		printArray(A, 10);

		int x;
		cin >> x;
		cout << "Index - " << binary(A, 0, 9, x);

		break;
	}

	case 2:				// Tasks 2, 3, 4
	{
		int quantity = 0;

		cout << "Enter roll count: ";
		cin >> quantity;

		int** A = new int*[4];
		for (size_t i = 0; i < 4; i++)
		{
			*(A + i) = new int[4];
		}

		for (size_t i = 0; i < 4; i++)
		{
			for (size_t j = 0; j < 4; j++)
			{
				*(*(A + i) + j) = rand() % 10;
			}
		}

		cout << "Array: " << endl;
		print2d(A, 4, 4);

		//moveRight(A, 4, 4, quantity);
		//moveLeft(A, 4, 4, quantity);
		moveUp(A, 4, 4, quantity);
		//moveDown(A, 4, 4, quantity);

		cout << "Result: " << endl;
		print2d(A, 4, 4);

		break;
	}

	default:
		break;
	}


	return 0;
}


int* createArr(const int len){
	int* arr = new int[len];
	return arr;
}


void initArr(int* arr, const int len){
	for (int i = 0; i < len; ++i)
	{
		*(arr + i) = rand() % 10;
	}
}


void printArray(int* arr, const int len){
	for (int i = 0; i < len; ++i)
	{
		cout << *(arr + i) << ' ';
	}
	cout << endl;
}


void print2d(int** arr, const int rows, const int columns) {
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			cout << *(*(arr + i) + j) << ' ';
		}
		cout << endl;
	}
	cout << endl;
}


void sort(int* arr, const int len){
	for (int k = 0; k < len; ++k)
	{
		int index = k;
		while (index > 0 && arr[index - 1] > arr[index])
		{
			int tmp = arr[index - 1];
			arr[index - 1] = arr[index];
			arr[index] = tmp;
			index -= 1;
		}
	}
}
