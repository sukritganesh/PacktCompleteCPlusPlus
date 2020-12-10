#include <iostream>
#include <string_view>

int main() {
	using namespace std::string_view_literals;

	// initialize
	std::string_view sv1{ "Hello world" };

	std::string str1{ "Hello" };
	std::string_view sv2{ str1 };

	auto sv3 = "Using\0literals"sv;

	// properties
	std::cout << "Size: " << sv3.length() << std::endl;
	std::cout << sv3 << std::endl;

	std::cout << "data() (whole string isn't printed, since there's a null terminating character): " << sv3.data() << std::endl;

	// access
	std::cout << sv3[0] << std::endl;
	std::cout << sv3.at(8) << std::endl;

	// find
	auto f = sv3.find("literals");
	if (f != std::string::npos) {
		std::cout << "Found at index: " << f << std::endl;
	}

	// doesn't modify string; only changes view
	sv3.remove_prefix(3);
	std::cout << sv3 << std::endl;
	sv3.remove_suffix(3);
	std::cout << sv3 << std::endl;

	// substring returns new string_view
	auto sv4 = sv1.substr(0, 5);
	std::cout << sv4 << std::endl;

	return 0;
}