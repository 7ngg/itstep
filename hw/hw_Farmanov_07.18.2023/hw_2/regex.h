#pragma once
#include <iostream>
#include <regex>

namespace Regular
{
    std::regex model("[a-zA-Z0-9.-/]+");
    std::regex make("[a-zA-Z0-9]+");
    std::regex year("\\b\\d{2}\\.\\d{2}\\.\\d{4}\\b");
    std::regex color("[a-zA-Z]+");

}