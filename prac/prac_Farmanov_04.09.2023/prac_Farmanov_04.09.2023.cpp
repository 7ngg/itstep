#include <iostream>

double addition(int x, int y) {
	return x + y;
}

double subtraction(int x, int y) {
	return x - y;
}

double multiplication(int x, int y) {
	return x * y;
}

double division(int x, int y) {
	return (float)x / y;
}


int main() {
	using namespace std;
	
	double (*functions[])(int, int) = {addition, subtraction, multiplication, division};

	int x{}, y{};
	int choice{};

	cout
		<< "Choose operation:\n"
		<< "1. Addition\n"
		<< "2. Subtraction\n"
		<< "3. Multiplication\n"
		<< "4. Division\n"
		<< "> ";
	cin >> choice;

	cout << "Enter x - ";
	cin >> x;
	cout << "Enter y - ";
	cin >> y;

	cout << "Result - " << functions[choice - 1](x, y);

	return 0;
}
