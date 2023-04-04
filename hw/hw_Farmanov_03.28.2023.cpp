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
	delete[] arr;
}


void add(int* arr, int &len, int newElement){
	int* tmp = new int[len]{};
	for (size_t i = 0; i < len; ++i) {
		*(tmp + i) = *(arr + i);
	}

	del(arr, len);
	len += 1;
	arr = new int[len]{};

	std::cout << "tmp - ";
	print(tmp, len - 1);
	std::cout << "init - ";
	print(arr, len);

	for (size_t i = 0; i < len - 1; i++)
	{
		*(arr + i) = *(tmp + i);
	}
}


void insert(int* arr, const int len) {
	int index{};
	std::cout << "Enter index to insert an element: ";
	std::cin >> index;

	int element{};
	std::cout << "Enter element, you want to insert: ";
	std::cin >> element;

	int* tmp = new int[len];
	for (size_t i = 0; i < len; ++i) {
		*(tmp + i) = *(arr + i);
	}
	print(tmp, len);

	delete[] arr;
	arr = new int[len + 1] {};

	std::cout << "Norm" << std::endl;

	for (size_t i = 0, j = 0; i < len + 1; ++i) {
		if (i != index) {
			*(arr + i) = *(tmp + j);
			j += 1;
		} else {
			*(arr + i) = element;
		}
	}
}

#pragma endregion


bool primeCheck


int main(){
	using namespace std;
	srand(time(NULL));

	int32_t task = 0;
	cout << "Choose the task: ";
	cin >> task;

	int32_t length = 0;
	cout << "Enter elements count: ";
	cin >> length;

	switch (task)
	{
	case 1:
	{
		int* A = allocate(length);			// Задание 1

		initialize(A, length);				// Задание 2

		cout << "Array - ";
		print(A, length);					// Задание 3

		//cout << "new Arr - ";
		insert(A, length);
		cout << "Res - ";
		print(A, length);

		break;
	}

	case 2:
	{


		break;
	}

	default:
		break;
	}



	return 0;
}
