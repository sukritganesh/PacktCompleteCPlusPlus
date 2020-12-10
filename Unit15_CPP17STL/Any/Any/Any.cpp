#include <iostream>
#include <any>
#include <string>

int main() {
	std::any v = 5;

	try {
		std::cout << std::any_cast<std::string>(v) << std::endl;
	}
	catch (std::exception & ex) {
		std::cout << "Exception: " << ex.what() << std::endl;
	}

	std::any v1 = 300;
	if (v1.has_value()) {
		if (v1.type() == typeid(int)) {
			std::cout << std::any_cast<int>(v1) << std::endl;
		}
	}
	v1.reset();

	std::any v2 = 1;
	int &st = std::any_cast<int&>(v2);
	std::cout << st << std::endl;
	st = 2;
	std::cout << std::any_cast<int>(v2) << std::endl;

	auto p = std::any_cast<int>(&v2);
	*p = 5;
	std::cout << std::any_cast<int>(v2) << std::endl;

	return 0;
}