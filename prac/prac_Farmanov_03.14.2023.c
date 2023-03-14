#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(0));

	int task;

	printf("Choose the task: ");
	scanf("%d", &task);

	switch (task){
	case 1:
		{
			int* num1 = (int*)calloc(1, sizeof(int));
			int* num2 = (int*)calloc(1, sizeof(int));

			printf("Enter first num: ");
			scanf("%d", num1);
			printf("Enter second num: ");
			scanf("%d", num2);

			int result = (*num1 > *num2) ? *num1 : *num2;
			printf("Bigger num - %d", result);

			break;
		}

	case 2:
		{
			int* num = (int*)calloc(1, sizeof(int));

			printf("Enter num: ");
			scanf("%d", num);

			if (*num > 0)
			{
				printf("Num is positive.\n");
			}
			else if (*num == 0)
			{
				printf("Num is equal to 0.\n");
			}
			else
			{
				printf("Num is negative.\n");
			}

			break;
		}

	case 3:
		{
			int* num1 = (int*)calloc(1, sizeof(int));
			int* num2 = (int*)calloc(1, sizeof(int));

			printf("Enter first num: ");
			scanf("%d", num1);
			printf("Enter second num: ");
			scanf("%d", num2);

			printf(
				"First num - %d\n"
				"Second num - %d\n"
				"Changing...\n",
				*num1, *num2);

			int tmp = *num1;
			*num1 = *num2;
			*num2 = tmp;

			printf(
				"First num - %d\n"
				"Second num - %d\n",
				*num1, *num2);

			break;
		}

	case 4:
		{
			int num1, num2;
			int choice;
			float result;

			int* ptrNum1 = &num1;
			int* ptrNum2 = &num2;

			printf("Enter first num: ");
			scanf("%d", &num1);
			printf("Enter second num: ");
			scanf("%d", &num2);

			printf(
				"1. +\n"
				"2. -\n"
				"3. *\n"
				"4. /\n"
				"Choose operation: ");
			scanf("%d", &choice);

			if (choice == 1)
			{
				result = *ptrNum1 + *ptrNum2;
			}
			else if (choice == 2)
			{
				result = *ptrNum1 - *ptrNum2;
			}
			else if (choice == 3)
			{
				result = *ptrNum1 * *ptrNum2;
			}
			else if (choice == 4)
			{
				result = (float)*ptrNum1 / *ptrNum2;
			}

			printf("Result = %f", result);

			break;
		}
	case 5:
		{
			int length = 0, sum = 0;

			printf("Enter array length: ");
			scanf("%d", &length);

			int* arr = (int*)calloc(length, length * sizeof(int));

			printf("Array - ");
			for (int i = 0; i < length; ++i)
			{
				*(arr + i) = rand() % 10;
				printf("%d ", *(arr + i));
				sum = sum + *(arr + i);
			}

			printf("\nSum = %d", sum);

			break;
		}
	}

	return 0;
}