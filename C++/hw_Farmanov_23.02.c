#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define rows 3
#define columns 6

int main(int argc, const char* argv[]) {
	srand(time(0));

	int task = 0;

	printf("Choose the task: ");
	scanf_s("%d", &task);

	switch (task)
	{
	case 1:
	{
		int arr[rows][columns] = { 0 };
		int blob = 0;

		printf("Enter num to fill the array: ");
		scanf_s("%d", &blob);

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				arr[i][j] = blob;
				blob *= 2;

				printf("%d\t", arr[i][j]);
			}
			printf("\n");
		}

		break;
	}

	case 2:
	{
		int arr[rows][columns] = { 0 };
		int blob = 0;

		printf("Enter num to fill the array: ");
		scanf_s("%d", &blob);

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				arr[i][j] = blob;
				blob += 1;

				printf("%3d", arr[i][j]);
			}
			printf("\n");
		}

		break;
	}

	case 3:
	{
		int arr[rows][columns] = { 0 };
		/*
		{
			1, 2, 0, 4, 5, 3,
			4, 5, 3, 9, 0, 1
		};
		*/
		int quantity = 0, direction = 0;

		printf("Original matrix: \n");
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				arr[i][j] = rand() % 10;

				printf("%2d", arr[i][j]);
			}
			printf("\n");
		}

		printf(
			"\n"
			"1. Right\n"
			"2. Left\n"
			"3. Up\n"
			"4. Down\n"
			"Choose directory: "
		);

		scanf_s("%d", &direction);

		printf("Enter shift count: ");
		scanf_s("%d", &quantity);

		/*
			Для всех последующих циклов в этом задании:
				i - строки
				j - количество сдвигов, заданное пользователем
				k - столбцы (элементы i-ой строки, если быть до конца честным)
		*/

		if (direction == 1)
		{
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < quantity; j++)
				{
					int tmp = arr[i][columns - 1];
					for (int k = columns - 1; k > 0; k--)
					{
						arr[i][k] = arr[i][k - 1];
					}
					arr[i][0] = tmp;
				}
			}
		}
		else if (direction == 2)
		{
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < quantity; j++)
				{
					int tmp = arr[i][0];
					for (int k = 0; k < columns - 1; k++)
					{
						arr[i][k] = arr[i][k + 1];
					}
					arr[i][columns - 1] = tmp;
				}
			}
		}
		else if (direction == 3)
		{
			for (int k = 0; k < columns; k++)
			{
				for (int j = 0; j < quantity; j++)
				{
					int tmp = arr[0][k];
					for (int i = 0; i < rows - 1; i++)
					{
						arr[i][k] = arr[i + 1][k];
					}
					arr[rows - 1][k] = tmp;
				}
			}
		}
		else if (direction == 4)
		{
			for (int k = 0; k < columns; k++)
			{
				for (int j = 0; j < quantity; j++)
				{
					int tmp = arr[rows - 1][k];
					for (int i = rows - 1; i > 0; i--)
					{
						arr[i][k] = arr[i - 1][k];
					}
					arr[0][k] = tmp;
				}
			}
		}

		printf("\n");

		printf("Result: \n");
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				printf("%2d", arr[i][j]);
			}
			printf("\n");
		}

		break;
	}

	default:
		printf("zochem?");
		break;
	}
	


	return 0;
}