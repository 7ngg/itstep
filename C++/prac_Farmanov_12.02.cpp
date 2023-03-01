#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	// Задание 1
	/*
	int year;
	cout << "Введите год: ";
	cin >> year;

	cout 
		<< "В " << year << " году "
		<< 365 + (int)((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		<< " дней"
		<< endl;
	*/


	// Задание 2
	/*
	int paper, metal;

	cout << "Введите гривны: ";
	cin >> paper;

	cout << "Введите копейки: ";
	cin >> metal;

	cout
		<< paper + (metal / 100) << " грн. "
		<< metal % 100 << " коп."
		<< endl;
	*/


	// Задание 3
	/*
	float length, width, height;

	cout << "Вычисление объема параллелепипеда." << endl;
	cout << "Введите исходные данные:" << endl;

	cout << "Длина (см) -> ";
	cin >> length;

	cout << "Ширина (см) -> ";
	cin >> width;

	cout << "Высота (см) -> ";
	cin >> height;

	cout << "Объем равен " << length * width * height << " куб. см." << endl;
	*/


	// Задание 4
	/*
	int scale;
	float distance;

	cout
		<< "Вычисление расстояния между населенными пунктами.\n"
		<< "Введите исходные данные: \n";

	cout << "\tМасштаб карты (количество километров в одном сантиметре) -> ";
	cin >> scale;

	cout << "\tРасстояние между точками, изображающими населенные пункты(см) -> ";
	cin >> distance;

	cout << "\tРасстояние между населенными пунктами " << scale * distance << " км." << endl;
	*/


	// Задание 5
	/*
	float radius;
	cout << "Введите радиус сферы: ";
	cin >> radius;

	cout << "Радиус сферы равен " << 4 * (radius * radius * radius) / 3 << "п" << endl;
	*/




	return 0;
}