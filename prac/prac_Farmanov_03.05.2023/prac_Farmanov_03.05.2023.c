#include <stdio.h>
#include <iso646.h>
#include <stdlib.h>
#include <time.h>


void initializeArray(int* arr, const int length);
void printArray(int* arr, const int length);

void findMin(int* arr, const int length);
void findMax(int* arr, const int length);

void reverseArr(int* arr, const int length);

void primeCount(int* arr, const int length);


int main() {
	srand(time(0));

	int length = 0;

	printf("Enter array length: ");
	scanf_s("%d", &length);

	int* A = (int*)calloc(length, length * sizeof(int));
	initializeArray(A, length);
	printArray(A, length);

	// Task 1
	findMin(A, length);
	findMax(A, length);

	// Task 2
	reverseArr(A, length);

	// Task 3
	primeCount(A, length);

	return 0;
}


void initializeArray(int* arr, const int length) {
	for (int i = 0; i < length; i++)
	{
		*(arr + i) = rand() % 10;
	}
}


void printArray(int* arr, const int length) {
	printf("Array - ");

	for (int i = 0; i < length; i++)
	{
		printf("%d ", *(arr + i));
	}

	printf("\n");
}


void findMin(int* arr, const int length) {
	int min = *arr;
	int minIndex = 0;

	for (int i = 0; i < length; i++)
	{
		if (*(arr + i) < min)
		{
			min = *(arr + i);
			minIndex = i;
		}
	}

	printf(
		"Min of the array - %d\n"
		"Index of min element - %d\n",
		min, minIndex + 1);
}


void findMax(int* arr, const int length) {
	int max = *arr;
	int maxIndex = 0;

	for (int i = 0; i < length; i++)
	{
		if (*(arr + i) > max)
		{
			max = *(arr + i);
			maxIndex = i;
		}
	}

	printf(
		"Max of the array - %d\n"
		"Index of max element - %d\n",
		max, maxIndex + 1);
}


void reverseArr(int* arr, const int length) {
	printf("Reversed array - ");

	for (int i = 0; i < length; i++)
	{
		printf("%d ", *(arr + length - 1 - i));
	}
	printf("\n");
}


void primeCount(int* arr, const int length) {
	int result = 0;

	for (int i = 0; i < length; i++)
	{
		if (*(arr + i) >= 2)
		{
			int check = 0;

			for (int j = 2; j < *(arr + i) / 2 + 1; j++)
			{
				if (*(arr + i) % j == 0)
				{
					check += 1;
				}
			}

			if (check <= 0)
			{
				result += 1;
			}
		}
	}

	printf("Prime numbers count - %d\n", result);
}