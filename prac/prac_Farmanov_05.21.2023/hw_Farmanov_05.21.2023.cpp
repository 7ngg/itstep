#include <iostream>

class student
{
	struct birthDate
	{
		uint16_t day = 0;
		uint16_t month = 0;
		uint16_t year = 0;
	};

	birthDate studentBirthDate{};

public:
	std::string name{}, surname{};
	std::string phoneNumber{};
	std::string city{}, country{};
	std::string school{};
	std::string schoolCity{}, schoolCountry{};
	std::string group{};

	birthDate getBirthDate() {
		return studentBirthDate;
	}

	void print() {
		std::cout
			<< "Student - " << name << ' ' << surname << '\n'
			<< "Birth day - " << studentBirthDate.day << '.' << studentBirthDate.month << '.' << studentBirthDate.year << '\n'
			<< "Contact phone - " << phoneNumber << '\n'
			<< "Group - " << group << '\n'
			<< "Adress: " << city << ", " << country << '\n'
			<< "School name - " << school << '\n'
			<< "School adress: " << schoolCity << ", " << schoolCountry << std::endl;

	}
};


int main() {
	


	return 0;
}