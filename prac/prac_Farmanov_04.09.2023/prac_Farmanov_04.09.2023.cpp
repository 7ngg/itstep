#include <iostream>

int addition(int x, int y) {
	return x + y;
}

int subtraction(int x, int y) {
	return x - y;
}

int multiplication(int x, int y) {
	return x * y;
}

int division(int x, int y) {
	return x / y;
}


int main() {
	using namespace std;

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

	cout << result(x, y, choice);

	return 0;
}