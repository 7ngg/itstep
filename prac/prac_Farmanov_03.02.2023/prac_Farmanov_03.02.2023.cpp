#include <iostream>

using namespace std;

void task1(int height, int width){
		for (int i = 0; i < height; ++i)
		{
			cout << "* ";
			for (int j = 0; j < width - 2; ++j)
			{
				if (i == 0 || i == height - 1)
				{
					cout << "* ";
				}
				else
				{
					cout << "  ";
				}
			}
			cout << "* " << endl;
		}

	}


int task2(int x){
	int res = 1;

	for (int i = 1; i < x + 1; ++i)
	{
		res *= i;
	}

	return res;
}


void task3(int x){
	int check = 0;

	for (int i = 2; i < x / 2 + 1; ++i)
	{
		if (x % i == 0)
		{
			check += 1;
		}
	}

	if (check <= 0)
	{
		cout << "Num is prime" << endl;
	}
	else
	{
		cout << "Num is not prime" << endl;
	}
}

int task4(int x){
	int res = x * x * x;

	return res;
}


int task5(int x, int y){
	int res = (x > y) ? x : y;

	return res;
}


void task6(int x){
	bool res;

	if (x > 0)
	{
		cout << "Num is positive" << endl;
	}
	else if (x < 0)
	{
		cout << "Num is negative" << endl;
	}
	else
	{
		cout << "You've entered 0" << endl;
	}
}

int main(){
	int task = 0;

	cout << "Choose task: ";
	cin >> task;

	switch (task){
		case  1:
			{
				int height{}, width{};
			
				cout << "Enter height: ";
				cin >> height;
		
				cout << "Enter width: ";
				cin >> width;
		
				task1(height, width);
		
				break;
			}
		case 2:
			{
				int num = 0;

				cout << "Enter num: ";
				cin >> num;

				cout << task2(num) << endl;

				break;
			}

		case 3:
			{
				int num = 0;

				cout << "Enter num: ";
				cin >> num;

				task3(num);

				break;
			}

		case 4:
			{
				int num = 0;

				cout << "Enter num: ";
				cin >> num;

				cout << "Cubed num - " << task4(num) << endl;

				break;
			}

		case 5:
			{
				int num1{}, num2{};

				cout << "Enter first num: ";
				cin >> num1;

				cout << "Enter second num: ";
				cin >> num2;

				cout << "Bigger num - " << task5(num1, num2);

				break;
			}

		case 6:
			{
				int num = 0;

				cout << "Enter num: ";
				cin >> num;

				task6(num);

				break;
			}
	}

	return 0;
}