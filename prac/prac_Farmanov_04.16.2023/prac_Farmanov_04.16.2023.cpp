#include <iostream>
#include "machine.h"

int main() {
	using namespace std;

	machine newMachine;
	char state{};

	cout << "Enter manufacturer: ";
	cin >> newMachine.name;
	cout << "Entrer color: ";
	cin >> newMachine.color;
	cout << "Enter width/height/depth: ";
	cin >> newMachine.width >> newMachine.height >> newMachine.depth;
	cout << "Enter power amount: ";
	cin >> newMachine.power;
	cout << "Enter spin speed: ";
	cin >> newMachine.spinSpeed;
	cout << "Enter temperature: ";
	cin >> newMachine.temp;

	newMachine.print();

	cout << "Turn on the machine? y/n: ";
	cin >> state;
	if (state == 'y')
	{
		newMachine.turnON(true);
	}
	else if (state == 'n')
	{
		newMachine.turnON(false);
	}
	else
	{
		cout << "No such state\n";
		newMachine.turnON(false);
	}

	cout << "Start washing? y/n: ";
	cin >> state;
	if (state == 'y')
	{
		cout << "Washing will last " << newMachine.wash() << " mins" << endl;
	}
	else if (state == 'n')
	{
		newMachine.turnON(false);
	}
	else
	{
		cout << "No such state\n";
		newMachine.turnON(false);
	}

	return 0;
}