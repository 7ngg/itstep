#include <iostream>
#include <cstdint>
#include <fstream>

#include "../include/json.hpp"
#include "../include/global_functions.h"
#include "../include/lyrics.h"


void song::showSong() {
	std::cout
		<< "\tAuthor - " << author << '\n'
		<< "\tName - " << name << '\n'
		<< "\tYear - " << year 
		<< std::endl;
}


void song::showLyrics() {
	if (lyrics[0] == '\0')
	{
		std::cout << "No lyrics for this song" << std::endl;
	}
	else
	{
		std::cout << lyrics << std::endl;
	}
}


void song::removeLyrics() {
	delete[] lyrics;
	lyrics = new char[2048] {};
}


void song::editLyrics() {
	delete[] lyrics;
	lyrics = new char[2048] {};

	std::cout << "Enter new lyrics (2048 characters max): " << '\n';
	std::cin.ignore();
	std::cin.getline(lyrics, 2048);
}


song addSong() {
	song newSong{};
	uint16_t choice = 0;

	std::cout << "Enter author (32 characters max): ";
	std::cin.ignore();
	std::cin.getline(newSong.author, 32);
	std::cout << "Enter song's name (32 characters max): ";
	std::cin.getline(newSong.name, 32);
	std::cout << "Enter year: ";
	std::cin >> newSong.year;

	std::cout
		<< "Choose lyrics input method: " << '\n'
		<< "1. Keyboard input" << '\n'
		<< "2. Read from file" << '\n'
		<< "> ";
	std::cin >> choice;

	switch (choice)
	{
	case 1:
		std::cout << "Enter lyrics (2048 characters max): " << '\n';
		std::cin.ignore();
		std::cin.getline(newSong.lyrics, 2048);

		break;

	case 2:
		std::cout << "Searching for lyrics.txt..." << std::endl;

		if (!fileExists("lyrics.txt"))
		{
			std::cout << "No lyrics file in working directory" << std::endl;
		}
		else
		{
			FILE* file{};
			fopen_s(&file, "lyrics.txt", "r");

			while (!feof(file))
			{
				fgets(newSong.lyrics, 2048, file);
			}
			
		}

		break;

	default:
		std::cout << "No such case" << std::endl;
		break;
	}

	return newSong;
}


void showAllSongs(song* playlist, uint16_t songsCount) {
	for (size_t i = 0; i < songsCount; i++)
	{
		std::cout << i + 1 << ". ";
		playlist[i].showSong();
	}
}


void lyricsMainFunction() {
	uint16_t songsCount = 0;
	uint16_t choice = 0;

	song* playlist{};

	bool flag = true;



	while (flag)
	{
		std::cout
			<< "Choose operation:" << '\n'
			<< "1. Add lyrics" << '\n'
			<< "2. Remove lyrics" << '\n'
			<< "3. Edit lyrics" << '\n'
			<< "4. Show lyrics" << '\n'
			<< "5. Save lyrics to file" << '\n'
			<< "6. Show all lyrics of specific author" << '\n'
			<< "7. Search by keyword" << '\n'
			<< "0. Exit" << '\n'
			<< "> ";
		std::cin >> choice;
		system("cls");

		switch (choice)
		{
		case 0:
		{
			flag = false;
			break;
		}

		case 1:
		{
			if (songsCount <= 0)
			{
				songsCount += 1;
				playlist = new song[songsCount]{};
				playlist[songsCount - 1] = addSong();
			}
			else
			{
				songsCount += 1;
				song* tmp = new song[songsCount - 1];

				for (size_t i = 0; i < songsCount - 1; i++)
				{
					tmp[i] = playlist[i];
				}

				delete[] playlist;
				playlist = new song[songsCount];

				for (size_t i = 0; i < songsCount - 1; i++)
				{
					playlist[i] = tmp[i];
				}
				playlist[songsCount - 1] = addSong();
				
				delete[] tmp;
			}

			break;
		}

		case 2:
		{
			uint16_t case2Choice = 0;

			std::cout << "Choose lyrics to remove: " << '\n';
			showAllSongs(playlist, songsCount);
			std::cout << "> ";
			std::cin >> case2Choice;

			playlist[case2Choice - 1].removeLyrics();

			break;
		}

		case 3:
		{
			uint16_t case3Choice = 0;

			std::cout << "Choose lyrics to edit: " << '\n';
			showAllSongs(playlist, songsCount);
			std::cout << "> ";
			std::cin >> case3Choice;
			
			playlist[case3Choice - 1].editLyrics();

			break;
		}

		case 4:
		{
			uint16_t case4Choice = 0;

			std::cout << "Choose lyrics to show: " << '\n';
			showAllSongs(playlist, songsCount);
			std::cout << "> ";
			std::cin >> case4Choice;

			std::cout << "Lyrics: " << '\n';
			playlist[case4Choice - 1].showLyrics();
			
			break;
		}

		case 5:
		{
			uint16_t case5Choice = 0;

			std::cout << "Choose lyrics to be written to file: " << '\n';
			showAllSongs(playlist, songsCount);
			std::cout << "> ";
			std::cin >> case5Choice;

			uint16_t newLength = len(playlist[case5Choice - 1].name) + 5;

			char* fileName = new char[newLength] {};
			sprintf_s(fileName, newLength, "%s.txt", playlist[case5Choice - 1].name);

			std::ofstream stream(fileName);
			stream << playlist[case5Choice - 1].lyrics << std::endl;

			break;
		}

		case 6:
		{
			uint16_t case6Choice = 0;
			
			std::cout << "Choose an author: " << '\n';
			std::cout << "1. " << playlist[0].author << '\n';
			for (size_t i = 1, j = 2; i < songsCount; i++)
			{
				if (!compare(playlist[i].author, playlist[i - 1].author))
				{
					std::cout << j << ". " << playlist[i].author << '\n';
					j += 1;
				}
			}
			std::cout << "> ";
			std::cin >> case6Choice;

			for (size_t i = 0; i < songsCount; i++)
			{
				if (compare(playlist[i].author, playlist[case6Choice].author))
				{
					std::cout << playlist[i].name << ": " << '\n' << '\t';
					playlist[i].showLyrics();
				}
			}

			break;
		}

		case 7:
		{
			char* keyword = new char[32] {};
			
			std::cout << "Enter keyword (32 characters max): ";
			std::cin.ignore();
			std::cin.getline(keyword, 32);

			std::cout << "Keyword was found in: " << '\n';
			for (size_t i = 0, j = 1; i < songsCount; i++)
			{
				if (search(playlist[i].lyrics, keyword))
				{
					std::cout << j << ". " << playlist[i].name << '\n';
					j += 1;
				}
			}

			break;
		}

		default:
			std::cout << "No such case" << std::endl;
			system("pause");
			break;
		}

	}
}