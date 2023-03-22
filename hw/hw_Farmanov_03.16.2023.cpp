#include <iostream>
#include <ctime>
using namespace std;

#define length 10

int* createArr(const int len);
void initArr(int* arr, const int len);
void printArray(int* arr, const int len);

void task1(int* arr, const int len, int &sum, int &prod){
	for (int i = 0; i < len; ++i)
	{
		sum += *(arr + i);
		prod *= *(arr + i);
	}
}


void task2(int* arr, const int len, int &pos, int &neg, int &o){
	int i = 0;
	while (i < len)
	{
		if (arr[i] == 0)
		{
			o += 1;
		}
		else if (arr[i] > 0)
		{
			pos += 1;
		}
		else
		{
			neg += 1;
		}
		i++;
	}
}


int* task3(int* arr1, int* arr2, const int arr1_len, const int arr2_len){			// Не совсем ясно как возвращать 0, но таково условие задания
	if (arr2_len > arr1_len)
	{
		return 0;
	}

	for (int i = 0; i <= arr1_len; ++i)
	{
		int check = 0;
		int* value = arr1 + i;

		for (size_t j = 0, k = i; j < arr2_len; j++, k++)
		{
			if (arr1[k] == arr2[j])
			{
				check += 1;
			}
		}

		if (check == arr2_len)
		{
			return value;
		}

	}

	return 0;
}


int* task4(int* arr, const int len, int &newLength) {
	int negativeCount = 0;

	for (size_t i = 0; i < len; i++)
	{
		if (*(arr + i) < 0)
		{
			negativeCount += 1;
		}
	}

	int* result = createArr(len - negativeCount);
	int resultIndex = 0;
	newLength = len - negativeCount;

	for (size_t i = 0; i < len; i++)
	{
		if (*(arr + i) < 0)
		{
			continue;
		}

		*(result + resultIndex) = *(arr + i);
		resultIndex += 1;
	}

	return result;
}


int* task5(int* arr, const int len, int &newLength) {
	int additionalCount = 0;

	cout << "How many elements would you like to add?" << endl;
	cout << "> ";
	cin >> additionalCount;

	int* newElements = createArr(additionalCount);

	cout << "Enter additional elements: " << endl;
	for (size_t i = 0; i < additionalCount; i++)
	{
		int element = 0;

		cout << "> ";
		cin >> element;
		*(newElements + i) = element;
	}

	newLength = len + additionalCount;
	int* result = createArr(newLength);

	for (size_t i = 0; i < len; i++)
	{
		*(result + i) = *(arr + i);
		if (i < additionalCount)
		{
			*(result + i + len) = *(newElements + i);
		}
	}

	delete[] newElements;

	return result;
}


int* task6(int* arr, const int len, int& newLength) {
	int additionalCount = 0;
	int startIndex = 0;

	cout << "How many elements would you like to add?" << endl;
	cout << "> ";
	cin >> additionalCount;

	int* newElements = createArr(additionalCount);

	cout << "Enter additional elements: " << endl;
	for (size_t i = 0; i < additionalCount; i++)
	{
		int element = 0;

		cout << "> ";
		cin >> element;
		*(newElements + i) = element;
	}

	cout << "Starting from which index would you like to add elements?" << endl;
	cout << "> ";
	cin >> startIndex;

	newLength = len + additionalCount;
	int* result = createArr(newLength);

	int i = 0, j = 0, k = 0;			// i - шагаем по конечному массиву, j - по новым элементам, k - по старым
	while (i < newLength)
	{
		if (i >= startIndex && i < startIndex + additionalCount)
		{
			*(result + i) = *(newElements + j);
			i++;
			j++;
		}
		else
		{
			*(result + i) = *(arr + k);
			i++;
			k++;
		}
	}

	delete[] newElements;

	return result;
}


int* task7(int* arr, const int len, int& newLength) {
	int startIndex = 0;

	cout << "Starting from which index would you like to start removing?" << endl;
	cout << "> ";
	cin >> startIndex;

	int* result = createArr(startIndex);
	newLength = startIndex;

	int i = 0;
	while (i < startIndex)
	{
		*(result + i) = *(arr + i);
		i++;
	}

	return result;
}


int main(){
	srand(time(NULL));
	setlocale(LC_ALL, "RU");

	int task;

	cout << "Choose the task: ";
	cin >> task;

	switch (task)
	{
	case 1:
		{
			int sum = 0, prod = 1; 

			int* arr = createArr(length);
			initArr(arr, length);
			cout << "Array - ";
			printArray(arr, length);

			task1(arr, length, sum, prod);
			cout 
				<< "Sum = " << sum << endl
				<< "Product = " << prod << endl;

			break;
		}

	case 2:
		{
			int positive{}, negative{}, zero{};

			int* arr = createArr(length);
			initArr(arr, length);
			cout << "Array - ";
			printArray(arr, length);

			task2(arr, length, positive, negative, zero);
			cout
				<< "Positive elements cout - " << positive << '\n'
				<< "Positive elements cout - " << negative << '\n'
				<< "Zeros cout - " << zero << '\n';

			break;
		}

	case 3:
		{
			 int* A = createArr(length * 2);
			 int* B = createArr(length / 2);

			 initArr(A, length * 2);
			 initArr(B, length / 2);

			 cout << "Array 1 - ";
			 printArray(A, length * 2);

			 cout << "Array 2 - ";
			 printArray(B, length / 2);
			
			/*int A[] = {1, 1, 4, 5, 6, 7, 2, 3, 4, 5};
			int B[] = {4, 5, 6, 7};*/

			cout << task3(A, B, length * 2, length / 2) << endl;
		
			break;
		}

	case 4:
	{
		int* A = createArr(length);
		initArr(A, length);
		cout << "Array - ";
		printArray(A, length);

		int newLength = 0;

		cout << "Result - ";
		printArray(task4(A, length, newLength), newLength);

		break;
	}

	case 5:
	{
		int* A = createArr(length / 2);
		initArr(A, length / 2);
		cout << "Array - ";
		printArray(A, length / 2);

		int newLength = 0;

		printArray(task5(A, length / 2, newLength), newLength);

		break;
	}

	case 6:
	{
		int* A = createArr(length / 2);
		initArr(A, length / 2);
		cout << "Array - ";
		printArray(A, length / 2);

		int newLength = 0;

		printArray(task6(A, length / 2, newLength), newLength);

		break;
	}

	case 7:
	{
		int* A = createArr(length);
		initArr(A, length);
		cout << "Array - ";
		printArray(A, length);

		int newLength = 0;

		/*	Почему-то компилятор g++ отказывается выводить результат, если писать таким образом: 
			
				printArray(task7(A, length, newLength), newLength);

			в Visual Studio все работает
		*/

		int* x = task7(A, length, newLength);
		printArray(x, newLength);

		break;
	}

	}
}


int* createArr(const int len){
	int* arr = new int[len] {};
	return arr;
}


void initArr(int* arr, const int len){
	for (int i = 0; i < len; ++i)
	{
		*(arr + i) = -length + rand() % (2 * length);
//		*(arr + i) = rand() % 10;
	}
}


void printArray(int* arr, const int len){
	for (int i = 0; i < len; ++i)
	{
		cout << *(arr + i) << ' ';
	}
	cout << endl;
}
