#include "json.hpp"

using json = nlohmann::json;

enum priority
{
	LOW = 1,
	DEFAULT,
	HIGH,
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