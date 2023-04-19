#include <iostream>
#include <ctime>

void printArr(int32_t* arr, int32_t length);
int32_t* merge(int32_t* arr1, int32_t* arr2, int32_t arr1Length, int32_t arr2Length);

double findMin(int32_t* arr, const int length) {
	double min = *arr;
	for (size_t i = 0; i < length; i++)
	{
		min = (*(arr + i) > min) ? min : *(arr + i);
	}

	return min;
}


double findMax(int32_t* arr, const int length) {
	double max = *arr;
	for (size_t i = 0; i < length; i++)
	{
		max = (*(arr + i) < max) ? max : *(arr + i);
	}

	return max;
}


double avg(int32_t* arr, const int length) {
	double sum = 0;
	for (size_t i = 0; i < length; i++)
	{
		sum += *(arr + i);
	}

	return sum / length;
}


double action(int32_t* arr1, int32_t* arr2, int32_t arr1Length, int32_t arr2Length, double (*function)(int32_t*, const int)) {
	int32_t* mergedArray = merge(arr1, arr2, arr1Length, arr2Length);
	return function(mergedArray, arr1Length + arr2Length);
}


int main() {
	using namespace std;
	srand(time(NULL));

	int32_t length = 2;

	int32_t* ARR_1 = new int32_t[length] {};
	int32_t* ARR_2 = new int32_t[length] {};
	int16_t choice = 0;
	bool flag = true;

	for (size_t i = 0; i < length; i++)
	{
		*(ARR_1 + i) = rand() % 10;
		*(ARR_2 + i) = rand() % 10;
	}

	while (flag == true)
	{
		cout << "Array 1 - ";
		printArr(ARR_1, length);
		cout << "Array 2 - ";
		printArr(ARR_2, length);
		cout
			<< "Choose operation: " << endl
			<< "1. Max of two arrays" << endl
			<< "2. Min of two arrays" << endl
			<< "3. Average of two arrays" << endl
			<< "0. Exit" << endl
			<< "> ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Overall max - " << action(ARR_1, ARR_2, length, length, findMax) << endl;

			break;
		
		case 2:
			cout << "Overall min - " << action(ARR_1, ARR_2, length, length, findMin) << endl;

			break;

		case 3:
			cout << "Overall average - " << action(ARR_1, ARR_2, length, length, avg) << endl;

			break;

		case 0:
			flag = false;
			break;

		default:
			break;
		}
		cout << endl;
	}


	return 0;
}


void printArr(int32_t* arr, int32_t length) {
	for (size_t i = 0; i < length; i++)
	{
		std::cout << *(arr + i) << ' ';
	}
	std::cout << std::endl;
}


int32_t* merge(int32_t* arr1, int32_t* arr2, int32_t arr1Length, int32_t arr2Length) {
	int32_t* mergedArr = new int32_t[arr1Length + arr2Length];

	for (size_t i = 0; i < arr1Length; i++)
	{
		*(mergedArr + i) = *(arr1 + i);
	}
	for (size_t i = arr1Length, j = 0; i < arr1Length + arr2Length; i++, j++)
	{
		*(mergedArr + i) = *(arr2 + j);
	}

	return mergedArr;
}
