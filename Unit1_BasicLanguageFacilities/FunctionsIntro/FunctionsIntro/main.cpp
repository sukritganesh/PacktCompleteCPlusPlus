#include <iostream>
#include "math.h"

void print(char ch) {
	for (int i = 0; i < 10; i++) {
		std::cout << ch;
	}
	std::cout << std::endl;
}

// main function
int main() {
	int x, y;
	std::cin >> x >> y;
	int res = add(x, y);
	
	// use result
	std::cout << res << std::endl;

	print('#');
}