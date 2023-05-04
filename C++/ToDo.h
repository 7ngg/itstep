#include "json.hpp"

using json = nlohmann::json;

enum priority
{

};

struct task
{
	char* name{};
	char* description{};
	priority priority;
	json date;
};

struct toDoList
{

};