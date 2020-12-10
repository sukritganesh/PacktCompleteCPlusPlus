#include <iostream>

auto Sum() {
	return 0;
}

template<typename T, typename ...Args>
auto Sum(T a, Args...args) {
	return a + Sum(args...);
}

// 1 + (2 + (3 + (4 + (5 + 0))))
// 1 + (2 + (3 + (4 + (5))))
// 1 + (2 + (3 + (9)))
// ...
// 15

template<typename...Args>
auto Sum2(Args...args) {
	return (args + ...);		// unary right fold
	// return (... + args);		// unary left fold
}

// Unary right fold expansion: (1 + (2 + (3 + (4 + (5))))
// Unary left fold expansion: ((((1 + 2) + 3) + 4) + 5)

template<typename...Args>
auto Sum3(Args...args) {
	return (args + ... + 0);		// binary right fold
	// return (0 + ... + args);		// binary left fold
}

// Binary right fold expansion: (1 + (2 + (3 + (4 + (5 + 0)))))
// Binary left fold expansion: (((((0 + 1) + 2) + 3) + 4) + 5)

template<typename...Args>
bool AnyOf(Args...args) {
	return (... || (args % 2 == 0));
}

template<typename...Args, typename Predicate>
bool AllOf(Predicate p, Args...args) {
	return (... || p(args));
}


int main() {
	
	auto result = Sum(1, 2, 3, 4, 5);
	std::cout << result << std::endl;

	auto result2 = Sum2(1, 2, 3, 4, 5);
	std::cout << result2 << std::endl;

	auto result3 = Sum3();		// binary folds allow for no arguments
	std::cout << result3 << std::endl;

	std::cout << std::boolalpha << "Any even? " << AnyOf(10, 3, 5) << std::endl;
	std::cout << std::boolalpha << "Any even? " << AnyOf(9, 3, 5) << std::endl;
	std::cout << std::boolalpha << "All even? " << AllOf([](int x) {return x % 2 == 0;}, 2, -2, 16) << std::endl;


}

// && - default true
// || - default false
// ,  - default void()
// others - default ill-formed