#pragma once

enum gender
{
	MALE = 1,
	FEMALE
};

struct animal
{
	char* name{};
	uint16_t age{};
	gender gender{};
	bool aviaryCheck = false;

	void remove();
};

struct zoo
{
	char* name = new char[32] {};
	uint16_t maxCount{};
	uint16_t currentCount{};
	animal* animals{};

	void showAllAnimals();
	void edit(uint16_t aviaryNum);
};
