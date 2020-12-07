#include <iostream>

template<typename T>
struct SumStruct {
	T operator()(T x, T y) const {
		return x + y;
	}
};

int main() {
	auto fn = []() {
		std::cout << "Welcome to Lambda expressions!" << std::endl;
	};
	fn();
	std::cout << typeid(fn).name() << std::endl;

	auto sum = [](auto x, auto y) noexcept(false) -> auto {
		return x + y;
	};
	std::cout << "Sum is " << sum(5.4, 2.2) << std::endl;
	SumStruct<int> s;
	std::cout << "Sum is " << s(5, 2) << std::endl;

	return 0;
}