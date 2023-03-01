#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
	srand(time(NULL));

	// Задание 1
	/*int level;

	printf("Choose the level: \n");
	printf("1. Easy\n2. Medium\n3. Hard\nChoice: ");
	scanf_s("%d", &level);

	int first_num = 0, second_num = 0, answer = 0;
	int true_count = 0, t_count = 0;
	float score = 0;

	switch (level)
	{
	case 1:
		t_count = 2;

		for (int i = 0; i < t_count; i++)
		{
			first_num = rand() % 5;
			second_num = rand() % 5;

			printf("%d * %d = ", first_num, second_num);

			scanf_s("%d", &answer);

			if (first_num * second_num == answer)
			{
				true_count += 1;
			}

			score = true_count / float(t_count) * 10;
		}

		break;
	case 2:
		t_count = 3;

		for (int i = 0; i < t_count; i++)
		{
			first_num = (rand() % 5) + 5;
			second_num = (rand() % 5) + 5;

			printf("%d * %d = ", first_num, second_num);

			scanf_s("%d", &answer);

			if (first_num * second_num == answer)
			{
				true_count += 1;
			}

			score = true_count / float(t_count) * 10;
		}
	
		break;

	case 3:
		t_count = 5;

		for (int i = 0; i < t_count; i++)
		{
			first_num = (rand() % 5) + 10;
			second_num = (rand() % 5) + 10;

			printf("%d * %d = ", first_num, second_num);

			scanf_s("%d", &answer);

			if (first_num * second_num == answer)
			{
				true_count += 1;
			}

			score = true_count / float(t_count) * 10;
		}

	default:
		break;
	}

	printf("Your score is %f out of 10.\n", score);*/

	// Задание 2
	/*
	int line = 9;
	int centre = line / 2;

	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < line; j++)
		{
			if (i <= centre)
			{
				if (j >= centre - i && j <= centre + i)
					printf("*");
				else
					printf(" ");
			}
			else
			{
				if (j >= centre + i - line + 1 && j <= centre - i + line - 1)
					printf("*");
				else
					printf(" ");
			}
		}
		printf("\n");
	}
	*/
	


	return 0;
}