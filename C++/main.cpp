#include <iostream>
#include <fstream>

#include "./include/json.hpp"
#include "./include/global_functions.h"

#include "./include/ToDo.h"
#include "./include/sea_battle.h"
#include "./include/arithmetic.h"
#include "./include/lyrics.h"

int main() {
	using namespace std;
	using json = nlohmann::json;

	setlocale(LC_ALL, "Russian");

	uint16_t choice = 0;
	
	char* line = new char[128] {};
	
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
	cin.ignore();

	switch (choice)
	{
	case 1:
		break;

	case 3:


		break;

	case 5:
		cout
			<< "������� �������������� ��������� (�� ����� 127 ��������)" << endl
			<< "> ";
		cin.getline(line, 127);
		cout << line << endl;
		cout << arithmeticMainFunc(line);

		break;

	case 6:
		lyricsMainFunction();
		break;

	default:
		cout << "No such option" << endl;
		break;
	}
	
	return 0;
}