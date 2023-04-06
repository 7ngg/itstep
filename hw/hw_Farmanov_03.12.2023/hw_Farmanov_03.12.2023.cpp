#include <iostream>
#include <ctime>

// Границы генерации случайных чисел
#define left 0
#define right 10

int* createArr(const int len);
void initArr(int* arr, const int len, int start, int end);
void printArray(int* arr, const int len);
int* createTmpArr(int* arr, const int len);

bool isElement(int element, int* arr, const int arrLen){
	for (int i = 0; i < arrLen; ++i)
	{
		if (*(arr + i) == element)
		{
			*(arr + i) = left - 1;
			return true;
		}
	}
	return false;
}

int main(){
	using namespace std;
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int task{};
	cout << "Choose the task: ";
	cin >> task;
	if (task > 2 or task <= 0)
		return 0;

	int arr1_length{}, arr2_length{};
	int count{};
	int *arr1, *arr2;

	cout << "Enter first array's length: ";
	cin >> arr1_length;
	cout << "Enter second array's length: ";
	cin >> arr2_length;

	arr1 = createArr(arr1_length);
	arr2 = createArr(arr2_length);

	initArr(arr1, arr1_length, left, right);
	initArr(arr2, arr2_length, left, right);

	cout << "Array 1 - ";
	printArray(arr1, arr1_length);
	cout << "Array 2 - ";
	printArray(arr2, arr2_length);

	switch (task){
	case 1:
		{
			int* tmp = createTmpArr(arr2, arr2_length);					// Копия массива нужна, т.к isElement "портит" получаемый массив, чтобы избежать повторений
			for (int i = 0; i < arr1_length; ++i)
			{
				if (not isElement(arr1[i], tmp, arr2_length))			// Вычисляем минимальный размер массива для обоих заданий
				{
					count += 1;
				}
			}

			int* A_not_B = createArr(count);
			int A_not_B_index = 0;

			tmp = createTmpArr(arr2, arr2_length);
			for (int i = 0; i < arr1_length; ++i)
			{
				if (not isElement(arr1[i], tmp, arr2_length))			// Если элемент из А, но не из Б, то добавляем его в ответ для первого задания
				{
					*(A_not_B + A_not_B_index) = *(arr1 + i);
					A_not_B_index += 1;
				}
			}
			
			cout << "Elements, those are in Array 1, but not in Array 2 - ";			// Задание 1 ответ
			printArray(A_not_B, count);
		
			break;
		}

	case 2:
		{
			count = 0;

			int* tmp = createTmpArr(arr2, arr2_length);				// Строки 93-122 - вычисляем минимальный размер массива для задания 2 
			for (int i = 0; i < arr1_length; ++i)
			{
				if (not isElement(*(arr1 + i), tmp, arr2_length))
				{
					count += 1;
				}
			}

			tmp = createTmpArr(arr1, arr1_length);
			for (int i = 0; i < arr2_length; ++i)
			{
				if (not isElement(*(arr2 + i), tmp, arr1_length))
				{
					count += 1;
				}
			}

			int* symmetricDiff = createArr(count);
			int symmetricDiff_index = 0;

			tmp = createTmpArr(arr2, arr2_length);					// Вычисляем симметрическую разность
			for (int i = 0; i < arr1_length; ++i)
			{
				if (not isElement(*(arr1 + i), tmp, arr2_length))
				{
					*(symmetricDiff + symmetricDiff_index) = *(arr1 + i);
					symmetricDiff_index += 1;
				}
			}

			tmp = createTmpArr(arr1, arr1_length);
			for (int i = 0; i < arr2_length; ++i)
			{
				if (not isElement(*(arr2 + i), tmp, arr1_length))
				{
					*(symmetricDiff + symmetricDiff_index) = *(arr2 + i);
					symmetricDiff_index += 1;
				}
			}

			cout << "Symmetric difference between A and B - ";
			printArray(symmetricDiff, count);

			break;
		}
	}

	


	return 0;
}


int* createArr(const int len){
	int* arr = new int[len];
	return arr;
}


void initArr(int* arr, const int len, int start, int end){
	for (int i = 0; i < len; ++i)
	{
		*(arr + i) = start + rand() % (end - start);
	}
}


void printArray(int* arr, const int len){
	if (len == 0)
	{
		std::cout << "None" << std::endl;
		return;
	}

	for (int i = 0; i < len; ++i)
	{
		std::cout << *(arr + i) << ' ';
	}
	std::cout << std::endl;
}


int* createTmpArr(int* arr, const int len){
	int* tmp = new int[len];

	for (int i = 0; i < len; ++i)
	{
		*(tmp + i) = *(arr + i);
	}

	return tmp;
}
