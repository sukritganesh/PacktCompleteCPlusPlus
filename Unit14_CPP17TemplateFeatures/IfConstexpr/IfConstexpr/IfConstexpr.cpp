#include <iostream>
#include <type_traits>
#include <string>

template<typename T>
void Print(const T& value) {
	if constexpr (std::is_pointer_v<T>) {
		std::cout << *value << std::endl;
	}
	else if constexpr (std::is_array_v<T>) {
		for (const auto& v : value) {
			std::cout << v << ' ';
		}
		std::cout << std::endl;
	}
	else {
		std::cout << value << std::endl;
	}
}

template<typename T>
std::string toString(T value) {
	if constexpr (std::is_arithmetic_v<T>) {
		return std::to_string(value);
	}
	else {
		return std::string{ value };
	}
}

void checkMode() {
	// compiler discards statements which evalaute to false
	if constexpr (sizeof(void*) == 4) {
		std::cout << "32-bit" << std::endl;
	}
	else if constexpr (sizeof(void*) == 8) {
		std::cout << "64-bit" << std::endl;
	}
	else {
		std::cout << "Unknown mode" << std::endl;
	}
}

int main() {
	Print(10);
	int value{ 5 };
	Print(&value);
	int arr[]{ 1, 2, 3, 4, 5 };
	Print(arr);

	int x = 3;
	int y = 4;
	int z = x + y;
	Print(&z);

	auto s = toString(value);
	Print(s);

	checkMode();
}