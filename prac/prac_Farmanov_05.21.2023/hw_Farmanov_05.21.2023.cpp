#include <iostream>
#include <string>

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


	void setBirthDate(uint16_t day, uint16_t month, uint16_t year) {
		this->studentBirthDate.day = day;
		this->studentBirthDate.month = month;
		this->studentBirthDate.year = year;
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
	student newStudent{};
	uint16_t dd{}, mm{}, yy{};

	std::cout << "Enter student's name: ";
	std::getline(std::cin, newStudent.name);
	std::cout << "Enter student's surname: ";
	std::getline(std::cin, newStudent.surname);

	std::cout
		<< "You are about to enter students birth date..." << '\n'
		<< "Enter day of birth: ";
	std::cin >> dd;
	std::cout << "Enter month: ";
	std::cin >> mm;
	std::cout << "Enter year: ";
	std::cin >> yy;
	newStudent.setBirthDate(dd, mm, yy);

	std::cin.ignore();

	std::cout << "Enter contact number: ";
	std::getline(std::cin, newStudent.phoneNumber);
	std::cout << "Enter group: ";
	std::getline(std::cin, newStudent.group);
	std::cout << "City: ";
	std::getline(std::cin, newStudent.city);
	std::cout << "Country: ";
	std::getline(std::cin, newStudent.country);

	std::cout << "Enter school name: ";
	std::getline(std::cin, newStudent.school);
	std::cout << "City: ";
	std::getline(std::cin, newStudent.schoolCity);
	std::cout << "Country: ";
	std::getline(std::cin, newStudent.schoolCountry);

	system("cls");
	newStudent.print();

	return 0;
}