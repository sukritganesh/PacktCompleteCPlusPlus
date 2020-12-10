#include <iostream>
#include <optional>

const char* getErrorString(int errorNo) {
	switch (errorNo) {
	case 0:
		return "Invalid input";
	case 1:
		return "Connection not established yet";
	default:
		return "";
	}
}

std::optional<const char *> getErrorStringOpt(int errorNo) {
	switch (errorNo) {
	case 0:
		return "Invalid input";
	case 1:
		return "Connection not established yet";
	default:
		return std::nullopt;
	}
}

struct ContactName {
	std::string first;
	std::optional<std::string> middle;
	std::string last;
	void Print() {
		std::cout << first << " " << middle.value_or("") << " " << last << std::endl;
	}
};


int main() {

	// check if std::optional contains a value or not
	std::optional<int> value{ 5 };
	if (value.has_value()) {
		std::cout << value.value() << std::endl;
	}
	// another way to check (note that we can reuse the same std::optional object)
	value.reset();
	value = { std::make_optional(6) };
	if (value) {
		std::cout << *value << std::endl;
	}

	// non optional
	auto message = getErrorString(1);
	if (strlen(message) != 0) {
		std::cout << message << std::endl;
	}
	else {
		std::cout << "Unknown error number" << std::endl;
	}

	// optional
	auto errorMessage = getErrorStringOpt(4);
	if (errorMessage) {
		std::cout << errorMessage.value() << std::endl;
	}
	else {
		std::cout << "Unknown error number" << std::endl;
	}

	std::cout << getErrorStringOpt(4).value_or("Unknown error number") << std::endl;

	// can use optional with classes
	ContactName c;
	c.first = "Hello";
	c.last = "World";
	c.Print();

	c.middle = "I";
	c.Print();

	return 0;
}