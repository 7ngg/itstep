#include <iostream>
#include <ctime>

#pragma region Task1

int* allocate(const int length){
	int* range = new int[length];
	return range;
}

 
void initialize(int* arr, const int len){
	for (size_t i = 0; i < len; i++){
		*(arr + i) = rand() % 127;
	}
}


void print(int* arr, const int len){
	for (size_t k = 0; k < len; k++){
		std::cout << *(arr + k) << ' ';
	}
	std::cout << std::endl;
}


void del(int* arr, const int len){
	/*for (size_t i = 0; i < len; i++)
	{
		delete[] (arr + i);
	}*/
	delete[] arr;
}


void add(int *&arr, int &len, int newElement){
	int* tmp = new int[len]{};
	for (size_t i = 0; i < len; ++i) {
		*(tmp + i) = *(arr + i);
	}

	del(arr, len);
	len += 1;
	arr = allocate(len);

	for (size_t i = 0; i < len - 1; i++)
	{
		*(arr + i) = *(tmp + i);
	}
	*(arr + len - 1) = newElement;
}


void insert(int *&arr, int &len) {
	int index{};
	std::cout << "Enter index to insert an element: ";
	std::cin >> index;

	int newElement{};
	std::cout << "Enter element, you want to insert: ";
	std::cin >> newElement;

	int* tmp = new int[len];
	for (size_t i = 0; i < len; ++i) {
		*(tmp + i) = *(arr + i);
	}
	print(tmp, len);

	del(arr, len);
	len += 1;
	arr = allocate(len);

	for (size_t i = 0, j = 0; i < len; ++i) {
		if (i == index)
		{
			*(arr + i) = newElement;
		}
		else
		{
			*(arr + i) = *(tmp + j);
			j += 1;
		}
	}
}


void remove(int *&arr, int &len) {
	int index{};
	std::cout << "Enter index to remove the element: ";
	std::cin >> index;

	int* tmp = new int[len];
	for (size_t i = 0; i < len; i++)
	{
		*(tmp + i) = *(arr + i);
	}

	del(arr, len);
	len -= 1;
	arr = allocate(len);

	for (size_t i = 0, j = 0; i < len + 1; i++)
	{
		if (i != index)
		{
			*(arr + j) = *(tmp + i);
			j += 1;
		}
	}
}

#pragma endregion

#pragma region Task2

bool primeCheck(int num) {
	for (size_t i = 2; i < num / 2 + 1; i++) {
		if (num % i == 0) {
			return true;
		}
	}
	return false;
}


int* task2(int* arr, const int len) {
	int newSize = 0;
	
	for (size_t i = 0; i < len; i++) {
		if (not primeCheck(*(arr + i))) {
			newSize += 1;
		}
	}

	int* result = allocate(newSize);

	for (size_t i = 0, j = 0; i < len; i++) {
		if (not primeCheck(*(arr + i))) {
			*(result + j) = *(arr + i);
			j += 1;
		}
	}

	return result;
}

#pragma endregion

#pragma region Task3

struct task3Pointers
{
	int* positive;
	int* negative;
	int* zeros;
};

task3Pointers task3(int* arr, const int len) {
	task3Pointers result;
	int zerosCount{}, positiveCount{}, negativeCount{};

	for (size_t i = 0; i < len; i++)
	{
		if (*(arr + i) == 0)
		{
			zerosCount += 1;
		}
		else if (*(arr + i) > 0)
		{
			positiveCount += 1;
		}
		else
		{
			negativeCount += 1;
		}
	}

	result.zeros = allocate(zerosCount);
	result.positive = allocate(positiveCount);
	result.negative = allocate(negativeCount);

	int zerosIndex{}, positiveIndex{}, negativeIndex{};
	for (size_t i = 0; i < len; i++)
	{
		if (*(arr + i) == 0)
		{
			result.zeros[zerosIndex] = arr[i];
			zerosIndex += 1;
		}
		else if (*(arr + i) > 0)
		{
			result.positive[positiveIndex] = arr[i];
			positiveIndex += 1;
		}
		else
		{
			result.negative[negativeIndex] = arr[i];
			negativeIndex += 1;
		}
	}

	return result;
}

#pragma endregion

int main(){
	using namespace std;
	srand(time(NULL));

	int32_t length = 0;		
	int32_t task = 0;

	cout << "Choose the task: ";
	cin >> task;

	switch (task)
	{
	case 1:
	{
		cout << "Enter elements count: ";
		cin >> length;

		int* A = allocate(length);				// Задание 1.1
		initialize(A, length);					// Задание 1.2

		cout << "Array - ";
		print(A, length);						// Задание 1.3

		add(A, length, 1337);					// Задание 1.5
		print(A, length);

		insert(A, length);						// Задание 1.6
		print(A, length);

		remove(A, length);						// Задание 1.7
		print(A, length);

		del(A, length);							// Задание 1.4

		break;
	}

	case 2:
	{
		cout << "Enter elements count: ";
		cin >> length;

		int* A = allocate(length);
		initialize(A, length);

		cout << "Array - ";
		print(A, length);
		cout << "New array pointer - " << task2(A, length);

		break;
	}

	case 3:
	{
		int task3Array[] = { 0, 1, -1, 2, -2, 3, -3, 4, -4, 5, -5 };
		cout
			<< "Pointer to zeros array - " << task3(task3Array, 11).zeros << endl
			<< "Pointer to positive numbers array - " << task3(task3Array, 11).positive + 1 << endl
			<< "Pointer to negative numbers array - " << task3(task3Array, 11).negative << endl;

		break;
	}

	default:
		break;
	}



	return 0;
}
