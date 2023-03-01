#include <iostream>

using namespace std;

int main(){
	setlocale(LC_ALL, "Russian");

	int task;

	cout << "�������� �������: ";
	cin >> task;

	switch (task) {
		case 1:
		{
			float time;

			cout << "������� ����� � ��������: ";
			cin >> time;

			cout << "����� � �������� - " << time << endl;
			cout << "����� � ������� - " << time / 60 << endl;
			cout << "����� � ����� - " << time / 3600 << endl;

			break;
		}

		case 2:
		{
			float amount;

			cout << "������� ��������: ";
			cin >> amount;

			cout << int(amount) << " �������� � " << (amount - int(amount)) * 100 << " ������" << endl;

			break;
		}

		case 3:
		{
			int days;

			cout << "������� ��������: ";
			cin >> days;

			cout
				<< "������ - " << days / 7 << endl
				<< "���� - " << days - (days / 7 * 7) << endl
				<< endl;

			break;
		}

		case 4:
		{
			float distance = 0, time = 0, overall_seconds = 0;

			cout << "��������� �������� ����." << endl;

			cout << "������� ����� ��������� (������) = ";
			cin >> distance;

			cout << "������� ����� (���.���) = ";
			cin >> time;

			overall_seconds = 60 * int(time) + (time - int(time)) * 100;

			cout << "���������: " << distance << " �" << endl;
			cout << "�����: " << int(time) << " ��� " << (time - int(time)) * 100 << " ��� = " << overall_seconds << " ��� " << endl;

			cout << "�� ������ �� ��������� " << (distance / 1000) / (overall_seconds / 3600) << " ��/�" << endl;


			break;
		}

		case 5:
		{
			float paper = 0, percent = 0;
			
			cout << "������� ������ ������ (����): ";
			cin >> paper;

			cout << "������� ������� �������: ";
			cin >> percent;

			percent = percent / 100;

			cout << "� ����� ����� ���������: " << (paper * percent) / 12 << endl;


			break;
		}



		default:
			cout << "������ ������� ���." << endl;
	}
}