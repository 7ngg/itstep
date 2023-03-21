#include <iostream>

int main(){
	using namespace std;
	setlocale(LC_ALL, "Russian");

	const int length = 5;
	string items[length] = {"12700k", "potato bag", "Vans MTE", "ONI-katana", "Dirol X-Fresh"}; 
	double prices[length] = {298, 3.99, 90, 35, 1337};


	for (int i = 0; i < length; ++i)			// Сортировка товаров по алфавиту
	{
		int index = i;

		if (int(items[index][0]) >= 97)
		{
			int letter = int(items[index][0]);
			letter -= 32;
			items[index][0] = char(letter);
		}

		while (index > 0 && int(items[index - 1][0]) > int(items[index][0]))
		{
			string tmp_string = items[index - 1];
			items[index - 1] = items[index];
			items[index] = tmp_string;

			double tmp_num = prices[index - 1];
			prices[index - 1] = prices[index];
			prices[index] = tmp_num;

			index -= 1;
		}
	}

	for (int i = 0; i < length; ++i)
	{
		cout << items[i] << " - " << *(prices + i) << "т." << endl;
	}

	int min = 0;
	int max = 0;

	for (size_t i = 0; i < length; i++)				// Поиск самого дорогого и дешевого товаров
	{
		min = (prices[i] < prices[min]) ? i : min;
		max = (prices[i] > prices[max]) ? i : max;
	}

	cout
		<< "Самый дорогой товар - " << items[max] << ". Цена - " << prices[max] << "т." << endl
		<< "Самый дешевый товар - " << items[min] << ". Цена - " << prices[min] << "т." << endl;



	return 0;
}