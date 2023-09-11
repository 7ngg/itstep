#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream>
#include <string>
#include <iomanip>

void SaveException(std::exception& ex)
{
    std::ofstream stream("exceptions.csv", std::ios::app);
    std::time_t currentTime = std::time(nullptr);
    struct tm timeInfo;

    localtime_s(&timeInfo, &currentTime);
    char timeBuffer[20];
    std::strftime(timeBuffer, sizeof(timeBuffer), "%Y-%m-%d %H:%M:%S", &timeInfo);
    std::string timeStr = std::string(timeBuffer);

    //stream << "Time,ExceptionType,ErrorMessage\n";
    stream << timeStr << ',' << typeid(ex).name() << ',' << ex.what() << '\n';
}


class RegexInconsistencyException : public std::exception {
private:
    std::string message;

public:
    RegexInconsistencyException() : std::exception()
    {
        message = "Input doesn't match the template";
    }

    RegexInconsistencyException(const std::string& message) : std::exception()
    {
        this->message = message;
    }

    const char* what() const noexcept
    {
        return message.c_str();
    }
};


class InvalidRangeException : std::exception {
private:
    std::string message;

public:
    InvalidRangeException()
    {
        message = "Input doesn't match the value range";
    }

    InvalidRangeException(const std::string& message)
    {
        this->message = message;
    }

    const char* what() const noexcept
    {
        return this->message.c_str();
    }
};