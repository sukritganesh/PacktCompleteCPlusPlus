#include <iostream>
#include <type_traits>

template<typename T>
T Divide(T a, T b) {
	static_assert(std::is_floating_point<T>::value, "Use floating point types only!\n");
	return a / b;
}

template<typename T>
void Check(T&& x) {
	std::cout << std::boolalpha;
	std::cout << x << " is reference?" << std::is_reference<T>::value << std::endl;

	std::cout << "After removing:" << 
		std::is_reference<std::remove_reference<T>::type>::value << std::endl;
}

int main() {
	// check if code is compiled in 32-bit mode (compile time)
	static_assert(sizeof(void*) == 4, "Compile in 32-bit mode only!");

	std::cout
	<< std::boolalpha
	<< "Is integer?" << std::is_integral<int>::value << std::endl;

	//std::cout << Divide(5, 2) << std::endl;
	std::cout << Divide(5.3, 2.1) << std::endl;

	Check(-11);
	int value{23};
	Check(value);
}