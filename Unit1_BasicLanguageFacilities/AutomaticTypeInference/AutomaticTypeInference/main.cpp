#include <iostream>

inline int add(int x, int y, int z=0) {
	return x + y + z;
}

int main() {
	auto i{ 10 };
	auto j{ 5 };
	auto sum{ i + j };

	auto float1{ 3.14f };
	auto float2{ i + 3.14f };
	auto char1{ 'f' };
	auto str1{ "I like C++" };

	// infer type from return value
	auto result = add(i, j);

	// can have const auto
	const auto var = 5;
	// const reference (TRY TO AVOID THIS - CAN CAUSE CONFUSION)
	auto& var1 = var;
	// const pointer (TRY TO AVOID THIS)
	auto ptr = &var;

	// must put list on right-hand side of assignment operator for initializer list
	auto list = { 1, 2, 3, 4 };
	// auto list{ 1, 2, 3 }; (CANNOT DO THIS)
	std::cout << list.begin()[0] << std::endl;

	return 0;
}