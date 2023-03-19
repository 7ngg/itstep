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

	int arr1_length{}, arr2_length{};
	int A_not_B_count{}, A_and_B_count{};
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

	int* tmp = createTmpArr(arr2, arr2_length);					// Копия второго массива. Нужна, т.к isElement "портит" получаемый массив, чтобы избежать повторений
	for (int i = 0; i < arr1_length; ++i)
	{
		if (not isElement(arr1[i], tmp, arr2_length))			// Вычисляем минимальный размер массива для обоих заданий
		{
			A_not_B_count += 1;
		}
		else
		{
			A_and_B_count += 1;
		}
	}


	tmp = createTmpArr(arr2, arr2_length);

	int* A_not_B = createArr(A_not_B_count);
	int A_not_B_index = 0;

	int* A_and_B = createArr(A_and_B_count);
	int A_and_B_index = 0;

	for (int i = 0; i < arr1_length; ++i)
	{
		if (not isElement(arr1[i], tmp, arr2_length))			// Если элемент из А, но не из Б, то добавляем его в ответ для первого задания
		{
			*(A_not_B + A_not_B_index) = *(arr1 + i);
			A_not_B_index += 1;
		}
		else													// Если элемент лежит и в А, и а Б, то добавляем его в ответ для второго задания 
		{
			*(A_and_B + A_and_B_index) = *(arr1 + i);
			A_and_B_index += 1;
		}
	}
	
	cout << "Elements, those are in Array 1, but not in Array 2 - ";			// Задание 1 ответ
	printArray(A_not_B, A_not_B_count);

	cout << "Elements, those are in both Array 1 and Array 2 - ";				// Задание 2 ответ
	printArray(A_and_B, A_and_B_count);

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
