#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	int task;

	cout << "�������� �������: ";
	cin >> task;

	switch (task) {
	case 1:
		cout
			<< "\n������ ���������\n"
			<< "������� �����������\n"
			<< "������� ���������\n"
			<< "�������� ��������\n"
			<< "��������� ����\n"
			<< "\t\t�� �����\n"
			<< "\t\t\t\t�.�. ������\n";

		break;
	case 2:
		cout
			<< "������\n"
			<< "\t�������\n"
			<< "\t\t������\n"
			<< "\t\t\t�����\n"
			<< "\t\t\t\t���\n"
			<< "\t\t\t\t\t�����\n"
			<< "\t\t\t\t\t\t�����\n";


		break;
	case 3:
	{
		string name = "����������� '�����'";
		float price = 1337;
		string description = "�������� �����������. ������.";
		string number = "+7(800)555-35-35";

		cout
			<< "\n\t\t\t\t����������\n"
			<< "��������� " << name << endl
			<< "���� - " << price << " ��������" << endl
			<< "��������: " << description << endl
			<< "����� ��������: " << number << endl;

		break;
	}

	default:
		cout << "������ ������ ���." << endl;
	}
}