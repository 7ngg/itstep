#pragma once
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
