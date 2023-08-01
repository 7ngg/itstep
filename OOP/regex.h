#pragma once

#include <regex>

std::regex USERNAME (R"([a-zA-Z0-9]{4, 16})");
std::regex PASSWORD (R"([a-zA-Z0-9]{4, 16})([*!.~?<>^@]+)");
