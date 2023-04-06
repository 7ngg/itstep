#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char* argv[]) {
	srand(time(0));

	// Task 1
	/*int main_arr[10] = { 0 };
	int arr1[5] = { 0 }, arr2[5] = { 0 };


	for (int i = 0; i < 10; i++)
	{
		main_arr[i] = rand() % 1337;
	}

	for (int i = 0; i < 5; i++)
	{
		arr1[i] = main_arr[i];
		arr2[i] = main_arr[i + 5];
	}

	printf("Original array - ");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", main_arr[i]);
	}

	printf("\n");

	printf("First array - ");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr1[i]);
	}

	printf("\n");

	printf("Second array - ");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr2[i]);
	}*/

	// Task 2
	/*int arr1[5] = { 0 }, arr2[5] = { 0 }, sum[5] = { 0 };

	for (int i = 0; i < 5; i++)
	{
		arr1[i] = rand() % 10;
		arr2[i] = rand() % 10;
		sum[i] = arr1[i] + arr2[i];
	}

	printf("First array - ");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr1[i]);
	}

	printf("\n");

	printf("Second array - ");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr2[i]);
	}

	printf("\n");

	printf("Sum - ");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", sum[i]);
	}*/

	// Task 3
	/*
	char days[7][10] =
	{
		"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
	};
	
	int d_index[7] = { 0 };
	int overallS = 0, over100 = 0;


	for (int i = 0; i < 7; i++)
	{
		int cash = 0;

		printf("Day %d spending: ", i + 1);
		scanf_s("%d", &cash);

		if (cash > 100)
		{
			d_index[i] = i + 1;
			over100 += 1;
		}
		
		overallS += cash;
	}

	printf("Averagely spent - %f\n", (float)overallS / 7);
	printf("Overall spent - %d\n", overallS);
	printf("Days, when spent more than 100 (%d days): \n", over100);

	for (int i = 0; i < 7; i++)
	{
		if (d_index[i] != 0)
		{
			printf("%s\n", days[i]);
		}
	}
	*/

	// Task 4
	int month_index = 0;
	float deposit = 0;

	printf("Enter deposit amount: ");
	scanf_s("%f", &deposit);
	
	char months[12][10] = 
	{
		"January", "February", "March", "April",
		"May", "June", "July", "August",
		"September", "October", "November", "December"
	};

	int percents[12] = { 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 100 };
	float exc_rate[12] = { 1.2, 1.15, 1.1, 1.05, 1, 0.95, 0.9, 0.85, 0.8, 0.85, 0.9, 1 };

	/*for (int i = 0; i < 12; i++)				// Если хочется ввести курс вручную (доллар к евро)
	{
		float rate = 0;
		printf("Exchange rate in %s: ", months[i]);
		scanf_s("%f", &rate);
		exc_rate[i] = rate;
	}*/

	/*for (int i = 0; i < 12; i++)				// Если хочется ввести начисленные проценты вручную
	{
		int percent = 0;
		printf("Accrued interest in %s: ", months[i]);
		scanf_s("%d", &percent);
		percents[i] = percent;
	}*/

	printf("Enter month: ");
	scanf_s("%d", &month_index);

	for (int i = 0; i < month_index - 1; i++)			// Считается депозит до нужного месяца (не включительно)
	{
		deposit += (deposit * ((float)percents[i] / 100));
	}

	if (deposit / exc_rate[month_index - 1] * percents[month_index - 1] / 100 >= 500)			// VS ругается т.к боится, что индекс окажется -1, но нулевого месяца не существуюет
	{
		printf("Withdraw amount is no more than %f$", (float)deposit / exc_rate[month_index] * percents[month_index] / 100 * 0.5);
	}
	else
	{
		printf("Withdraw option is not available for this account.\n");
		printf("Accrued interest for %s is %f$", months[month_index - 1], (float)deposit / exc_rate[month_index - 1] * percents[month_index - 1] / 100);			// И тут по той же причине
	}

	return 0;
}