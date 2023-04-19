#pragma once

#include <iostream>

struct machine {
	int width{};
	int height{};
	int depth{};

	int power{};
	int spinSpeed{};
	int temp{};

	char* name = new char[32];
	char* color = new char[32];

	void print();
	void turnON(bool flag);
	int wash();

};