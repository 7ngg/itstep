#include <iostream>

#include "../include/lyrics.h"
#include "../include/global_functions.h"
#include "../include/json.hpp"

using json = nlohmann::json;

void lyricsMainFunction() {
	song newSong{};

	std::cout << "Enter author: ";
	std::cin >> newSong.author;
	std::cin.ignore();
	std::cout << "Enter song's name: ";
	std::cin >> newSong.name;
	std::cin.ignore();
	std::cout << "Enter lyrics: " << '\n';
	std::cin >> newSong.text;
	std::cin.ignore();

	json _newSong{};
	_newSong["Author"] = newSong.author;
	_newSong["Name"] = newSong.name;
	_newSong["Text"] = newSong.text;

	std::cout << _newSong << '\n';

}