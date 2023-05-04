#include <iostream>

#include "json.hpp"

#include "global_functions.h"
#include "sea_battle.h"
#include "arithmetic.h"

int main() {
	using namespace std;
	using json = nlohmann::json;

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

	case 3:


		break;

	case 5:
	{
		char* line = new char[128] {};
		cout
			<< "������� �������������� ��������� (�� ����� 127 ��������)" << endl
			<< "> ";
		cin.ignore();
		cin.getline(line, 127);
		cout << line << endl;
		cout << arithmeticMainFunc(line);

	}
		break;

	case 10:
	{
		json j;
		cin >> j["age"];
		cout << j;
		break;
	}

	default:
		cout << "No such option" << endl;
		break;
	}
	
	return 0;
}