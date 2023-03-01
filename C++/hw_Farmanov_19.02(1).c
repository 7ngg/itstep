#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define length 10

int main(int argc, const char* argv[]) {
	srand(time(0));

	// Task 1
	/*int arr[length] = {0};

	for (int i = 0; i < length; ++i)
	{
		arr[i] = rand() % 10 - 5;
	}

	int min = arr[0];
	int max = arr[0];

	for (int i = 0; i < length; ++i)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
		else if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	printf("Initialized array - ");
	for (int i = 0; i < length; ++i)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");
	printf("Maximum - %d\n", max);
	printf("Minimum - %d\n", min);*/

	// Task 2
	/*int arr[length] = {0};
	int start = 0, end = 0;
	int sum = 0, limit = 0;

	printf("Enter interval-start: ");
	scanf_s("%d", &start);

	printf("Enter interval-end: ");
	scanf_s("%d", &end);

	for (int i = 0; i < length; ++i)
	{
		arr[i] = start + rand() % (end - start + 1);
	}

	printf("Enter the limit, above which sum won't be calculated: ");
	scanf_s("%d", &limit);

	for (int i = 0; i < length; ++i)
	{
		if (arr[i] <= limit)
		{
			sum += arr[i];
		}
	}

	printf("Original array: ");
	for (int i = 0; i < length; ++i)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");
	printf("Final sum - %d", sum);*/

	// Task 3
	/*
	int a_income[12] = {0};
	int m_income = 0;
	int start = 0, end = 0;

	for (int i = 0; i < 12; i++)
	{
		if (i + 1 == 1)
		{
			printf("Enter income for %dst month: ", i + 1);
		}
		else if (i + 1== 2)
		{
			printf("Enter income for %dnd month: ", i + 1);
		}
		else if (i + 1 == 3)
		{
			printf("Enter income for %drd month: ", i + 1);
		}
		else
		{
			printf("Enter income for %dth month: ", i + 1);
		}

		scanf_s("%d", &m_income);
		a_income[i] = m_income;
	}

	printf("Enter interval-start: ");
	scanf_s("%d", &start);

	printf("Enter interval-end: ");
	scanf_s("%d", &end);

	int min = (start == 0) ? a_income[start] : a_income[start - 1];			// Нулевого месяца нет, но все же
	int max = (start == 0) ? a_income[start] : a_income[start - 1];

	for (int i = start; i < end; i++)
	{
		if (a_income[i] < min)
		{
			min = a_income[i];
		}

		if (a_income[i] > max)
		{
			max = a_income[i];
		}
	}

	printf("Original array - ");
	for (int i = 0; i < 12; i++)
	{
		printf("%d ", a_income[i]);
	}

	printf("\n");
	printf("Maximum income for given period - %d\n", max);
	printf("Minimum income for given period - %d\n", min);
	*/

	// Task 4
	/*
	float arr[length] = {0};
	float negative_sum = 0, minmax_prod = 1, even_prod = 1, pErEmEnNaYa = 0;

	printf("Original array - ");
	for (int i = 0; i < length; i++)
	{
		arr[i] = ((float)-100 + rand() % (200 + 1)) / 10;			// Псевдо-генерация псевдо-случайный вещественных чисел
		printf("%f ", arr[i]);
	}

	float min = arr[0];
	float max = arr[0];

	int min_index = 0;
	int max_index = 0;

	int firstN_index = 0;
	int lastN_index = 0;

	for (int i = 0; i < length; i++)
	{
		if (arr[i] < 0) firstN_index = i; break;			// Первое отрицательное число
	}

	for (int i = 0; i < length; i++)
	{
		if (arr[i] < 0)				
		{
			negative_sum += arr[i];			// Сумма отрицательных
			lastN_index = i;				// Последнее отрицательное число
		}

		if (i % 2 == 0)				// Произведение элементов с четным индексом
		{
			even_prod *= arr[i];
		}

		if (arr[i] < min)			// Находим минимальный элемент и его индекс
		{
			min = arr[i];
			min_index = i;
		}

		if (arr[i] > max)			// Находим максимальный элемент и его индекс
		{
			max = arr[i];
			max_index = i;
		}
	}

	for (int i = firstN_index; i < lastN_index; i++)
	{
		pErEmEnNaYa += arr[i];
	}

	for (int i = min_index; i < max_index; i++)
	{
		minmax_prod *= arr[i];			// Произведение элементов между минимальным и максимальным элементами
	}

	printf("\n");
	printf("Negative numbers sum - %f\n", negative_sum);
	printf("Product of elements between min and max - %f\n", minmax_prod);
	printf("Product of elements with even indexes - %f\n", even_prod);
	printf("Sum between first negative element and last negative element - %f\n", pErEmEnNaYa);
	*/

	return 0;
}