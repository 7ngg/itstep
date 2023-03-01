#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define len 5

int main(int argc, const char* argv[]){
	srand(time(0));

	int arr[len][len] = { 0 };

	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; i < len; ++j)
		{
			printf("%d ", arr[i][j]);
		}
	}

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; i < len; j++)
		{
			arr[i][j] = rand() % 10;
		}
	}

	/*for (int i = 0; i < len; ++i)
	{
		for (int j = 0; i < len; ++j)
		{
			printf("%d ", arr[i][j]);
		}
	}*/

	return 0;
}