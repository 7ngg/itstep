#include <iostream>

class InsufficientPermissions : public std::exception {
	const char* message = "Insufficient permissions";
public:
	InsufficientPermissions() = default;
	InsufficientPermissions(const char* message) {
		this->message = message;
	}

	const char* what() const throw() override {
		return this->message;
	}
};


class AlreadySignedIn : public std::exception {
	const char* message = "You are already signed in";
public:
	AlreadySignedIn() = default;
	AlreadySignedIn(const char* message) {
		this->message = message;
	}

	const char* what() const throw() override {
		return this->message;
	}
};