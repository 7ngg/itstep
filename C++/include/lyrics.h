#pragma once
#include <iostream>

struct song {
	char* author{};
	char* name{};
	char* text{};

	song()
	{
		author = new char[32] {};
		name = new char[32] {};
		text = new char[4096] {};
	}

	song(char* auhtor, char* name, char* text) {
		this->author = auhtor;
		this->name = name;
		this->text = text;
	}
};

void lyricsMainFunction();
