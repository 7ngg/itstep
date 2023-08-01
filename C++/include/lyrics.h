#pragma once
<<<<<<< HEAD
#include <cstdint>

struct song
{
	char* author{};
	char* name{};
	char* lyrics{};
	uint16_t year{};

	song() {
		author = new char[32] {};
		name = new char[32] {};
		lyrics = new char[2048] {};
		year = 0;
	}

	void showSong();
	void showLyrics();
	void removeLyrics();
	void editLyrics();
};


void lyricsMainFunction();
song addSong();
=======
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
>>>>>>> f3913e17fd32d1211c71ec2b132bacccfe050e7f
