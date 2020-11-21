#include <iostream>
int factorial(int x) {
	std::cout << "Before first Breakpoint" << std::endl;
	int result = 1;
	std::cout << "After first Breakpoint" << std::endl;
	for (int i = 1; i <= x; ++i) {
		result *= i;
	}
	return result;
}

int main() {
	int i = 5;
	int result = factorial(i);
		std::cout << "Factorial of " << i << " is " << result << std::endl;
	return 0;
}