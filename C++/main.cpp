#include <iostream>

int main() {
	using namespace std;
	setlocale(LC_ALL, "Russian");

	uint16_t choice = 0;
	cout
		<< "�������� �������:" << endl
		<< "1. ������� ���" << endl
		<< "2. ��������" << endl
		<< "3. C����� ���" << endl
		<< "4. ���� \'������\'" << endl
		<< "5. ������� ��������������� ���������" << endl
		<< "6. ���������� \'������� ������� �����\'" << endl
		<< "> ";
	cin >> choice;

	switch (choice)
	{
	case 1:


		break;

	default:
		cout << "No such option" << endl;
		break;
	}
	
	return 0;
}