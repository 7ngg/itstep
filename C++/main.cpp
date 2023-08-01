#include <iostream>
#include <fstream>

#include "./include/json.hpp"
#include "./include/global_functions.h"

#include "./include/ToDo.h"
#include "./include/sea_battle.h"
#include "./include/arithmetic.h"
#include "./include/lyrics.h"
<<<<<<< HEAD
#include "./include/memory.h"
=======
>>>>>>> f3913e17fd32d1211c71ec2b132bacccfe050e7f

int main() {
	using namespace std;
	using json = nlohmann::json;

	setlocale(LC_ALL, "Russian");

	uint16_t choice = 0;
	
	char* line = new char[128] {};
	
	cout
		<< "Choose a task:" << endl
		<< "1. Sea battle" << endl
		<< "2. Pyatnashki" << endl
		<< "3. To do list" << endl
		<< "4. Memory game" << endl
		<< "5. Arithmetics" << endl
		<< "6. Lyrics app" << endl
		<< "> ";
	cin >> choice;
	cin.ignore();

	switch (choice)
	{
	case 1:
		break;

	case 3:


		break;

	case 4:
		memoryMainFunction();
		break;

	case 5:
		cout
			<< "¬ведите арифметическое выражение (не более 127 символов)" << endl
			<< "> ";
		cin.getline(line, 127);
		cout << line << endl;
		cout << arithmeticMainFunc(line);

		break;

	case 6:
		lyricsMainFunction();
<<<<<<< HEAD
		break;

	case 10:
	{
		int* arr = new int[5]{ 1, 2, 3, 4 ,5 };
		cout << isMember(arr, 5, 1) << endl;
	}
=======

		break;
>>>>>>> f3913e17fd32d1211c71ec2b132bacccfe050e7f

	default:
		cout << "No such option" << endl;
		break;
	}
	
	return 0;
}