#include <stdio.h>

int main(int argc, const char* argv[]) {
	// Task 1
	/*int num = 0;
	int choice = 0;

	int d_count = 0, d_sum = 0;
	int o_count = 0;

	printf("Enter num: ");
	scanf_s("%d", &num);

	printf(
		"Choose the option:\n"
		"1. Digits count, sum of digits and average value of digits\n"
		"2. Zeros count\n"
		"Choice: "
	);

	scanf_s("%d", &choice);

	switch (choice)
	{
	case 1:
		while (num > 0)
		{
			d_sum += num % 10;
			d_count += 1;

			num /= 10;
		}
		
		printf(
			"Digits count - %d\n"
			"Digits sum - %d\n"
			"Average - %f\n",
			d_count, d_sum, (float)d_sum / d_count
		);

		break;

	case 2:
		while (num > 0)
		{
			if (num % 10 == 0)
			{
				o_count += 1;
			}

			num /= 10;
		}

		printf("Zeros count - %d", o_count);

		break;

	default:
		printf("No such option.\n");

		break;
	}*/

	// Task 2
	/*int num = 0;

	printf("Enter num: ");
	scanf_s("%d", &num);

	while (num > 0)
	{
		int last_digit = num % 10;
		int factorial = last_digit;

		for (int i = last_digit; i > 2; i--)
		{
			factorial *= (i - 1);
		}

		printf("%d! = %d\n", last_digit, factorial);

		num /= 10;
	}*/

	return 0;
}