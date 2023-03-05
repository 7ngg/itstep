#include <iostream>

using namespace std;

int main(){
	setlocale(LC_ALL, "Russian");

	int task;

	cout << "Выберите задание: ";
	cin >> task;

	switch (task) {
		case 1:
		{
			float time;

			cout << "Введите время в секундах: ";
			cin >> time;

			cout << "Время в секундах - " << time << endl;
			cout << "Время в минутах - " << time / 60 << endl;
			cout << "Время в часах - " << time / 3600 << endl;

			break;
		}

		case 2:
		{
			float amount;

			cout << "Введите значение: ";
			cin >> amount;

			cout << int(amount) << " долларов и " << (amount - int(amount)) * 100 << " центов" << endl;

			break;
		}

		case 3:
		{
			int days;

			cout << "Введите значение: ";
			cin >> days;

			cout
				<< "Недель - " << days / 7 << endl
				<< "Дней - " << days - (days / 7 * 7) << endl
				<< endl;

			break;
		}

		case 4:
		{
			float distance = 0, time = 0, overall_seconds = 0;

			cout << "Выисление скорости бега." << endl;

			cout << "Введите длину дистанции (метров) = ";
			cin >> distance;

			cout << "Введите время (мин.сек) = ";
			cin >> time;

			overall_seconds = 60 * int(time) + (time - int(time)) * 100;

			cout << "Дистанция: " << distance << " м" << endl;
			cout << "Время: " << int(time) << " мин " << (time - int(time)) * 100 << " сек = " << overall_seconds << " сек " << endl;

			cout << "Вы бежали со скоростью " << (distance / 1000) / (overall_seconds / 3600) << " км/ч" << endl;


			break;
		}

		case 5:
		{
			float paper = 0, percent = 0;
			
			cout << "Введите размер вклада (евро): ";
			cin >> paper;

			cout << "Введите процент годовых: ";
			cin >> percent;

			percent = percent / 100;

			cout << "В месяц будет выплачено: " << (paper * percent) / 12 << endl;


			break;
		}



		default:
			cout << "Такого задания нет." << endl;
	}
}