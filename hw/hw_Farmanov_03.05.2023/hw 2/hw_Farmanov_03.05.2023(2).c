#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iso646.h>

int* createArray(const int length);
void initArray(int *arr, const int length);
void printArray(int *arr, const int len);


bool leapCheck(int year) {
	if (year % 400 == 0)
	{
		return true;
	}
	else if (year % 4 == 0 && year % 100 != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
_overall variables meant to show days count for the current year
tmp - variable to show difference between completed years
*/
void task1(int start_dd, int start_mm, int start_yy, int end_dd, int end_mm, int end_yy) {
	int result = 0;
	int start_overall = 0, start_months2days = 0;
	int end_overall = 0, end_months2days = 0;

#pragma region Start date

	if (start_mm - 1 <= 7)
	{
		for (int i = 1; i <= 7; i++)
		{
			if (start_mm - 1 == 2 && leapCheck(start_yy))
			{
				start_months2days += 29;
			}
			else if (start_mm - 1 == 2 && not leapCheck(start_yy))
			{
				start_months2days += 28;
			}
			else if ((start_mm - 1) % 2 == 1)
			{
				start_months2days += 31;
			}
			else if ((start_mm - 1) % 2 == 0)
			{
				start_months2days += 30;
			}
		}
	}
	else if (7 < start_mm <= 12)
	{
		for (int i = 0; i <= 5; i++)
		{
			if ((start_mm - 1) % 2 == 1)
			{
				start_months2days += 31;
			}
			else if ((start_mm - 1) % 2 == 0)
			{
				start_months2days += 30;
			}
		}
	}

	start_overall = start_dd + start_months2days;

#pragma endregion

#pragma region End date

	if (end_mm - 1 <= 7)
	{
		for (int i = 1; i <= 7; i++)
		{
			if (end_mm - 1 == 2 && leapCheck(end_yy))
			{
				end_months2days += 29;
			}
			else if (end_mm - 1 == 2 && not leapCheck(end_yy))
			{
				end_months2days += 28;
			}
			else if ((end_mm - 1) % 2 == 1)
			{
				end_months2days += 31;
			}
			else if ((end_mm - 1) % 2 == 0)
			{
				end_months2days += 30;
			}
		}
	}
	else if (7 < end_mm <= 12)
	{
		for (int i = 0; i <= 5; i++)
		{
			if ((end_mm - 1) % 2 == 1)
			{
				end_months2days += 31;
			}
			else if ((end_mm - 1) % 2 == 0)
			{
				end_months2days += 30;
			}
		}
	}

	end_overall = end_dd + end_months2days;

#pragma endregion

	int tmp = 0;
	for (int i = 0; i < end_yy - start_yy; i++)
	{
		if (leapCheck(i))
		{
			tmp += 366;
		}
		else
		{
			tmp += 365;
		}
	}

	result = (end_overall - start_overall) + tmp;

	printf("%d\n", result);

}


void task2(int* arr, const int len) {
	float sum = 0;

	for (int i = 0; i < len; i++)
	{
		sum += *(arr + i);
	}

	printf("Array average - %f\n", (float)sum / len);
}


void task3(int* arr, const int len) {
	int positive = 0;
	int negative = 0;
	int zero = 0;

	for (int i = 0; i < len; i++)
	{
		if (*(arr + i) > 0)
		{
			positive += 1;
		}
		else if (*(arr + i) < 0)
		{
			negative += 1;
		}
		else
		{
			zero += 1;
		}
	}

	printf(
		"Positive numbers count - %d\n"
		"Negative numbers count - %d\n"
		"Zeros count - %d\n",
		positive, negative, zero
		);
}


int main() {
	srand(time(NULL));

	int task;

	printf("Choose the task: ");
	scanf_s("%d", &task);

	switch (task)
	{
	case 1:
	{
		int start_day = 0, start_month = 0, start_year = 0;
		int end_day = 0, end_month = 0, end_year = 0;

		printf("Enter start day: ");
		scanf_s("%d", &start_day);
		printf("Enter start month: ");
		scanf_s("%d", &start_month);
		printf("Enter start year: ");
		scanf_s("%d", &start_year);

		printf("Enter end day: ");
		scanf_s("%d", &end_day);
		printf("Enter end month: ");
		scanf_s("%d", &end_month);
		printf("Enter end year: ");
		scanf_s("%d", &end_year);

		task1(start_day, start_month, start_year, end_day, end_month, end_year);

		break;
	}

	case 2:
	{
		int length;

		printf("Enter array length: ");
		scanf_s("%d", &length);

		int* A = createArray(length);
		initArray(A, length);
		printArray(A, length);

		task2(A, length);

		break;
	}

	case 3:
	{
		int length;

		printf("Enter array length: ");
		scanf_s("%d", &length);

		int* A = createArray(length);
		initArray(A, length);
		printArray(A, length);

		task3(A, length);

		break;
	}

	default:
		break;
	}

	return 0;
}


int* createArray(const int len) {
	int* arr = (int*)calloc(len, len * sizeof(int));

	return arr;
}


void initArray(int *arr, const int len) {
	for (int i = 0; i < len; i++)
	{
		*(arr + i) = -10 + rand() % 20;
	}
}


void printArray(int *arr, const int len) {
	printf("Array - ");
	for (int i = 0; i < len; i++)
	{
		printf("%d ", *(arr + i));
	}
	printf("\n");
}