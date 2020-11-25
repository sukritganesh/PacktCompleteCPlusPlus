#include <iostream>

void Print(int count, char ch) {
	for (int i = 0; i < count; i++) {
		std::cout << ch;
	}
	std::cout << std::endl;
}

void EndMessage() {
	std::cout << "END OF PROGRAM!!!" << std::endl;
}
int main() {
	// standard function call
	Print(5, '#');
	
	// function pointer
	void(*pfn) (int, char) = Print;

	// Calling the function using the pointer
	(*pfn) (8, '@');
	// another way to call the function using the pointer
	pfn(5, '+');

	// atexit takes in function pointer as argument
	// and calls that function at the end of the program
	atexit(EndMessage);
	std::cout << "end of main method" << std::endl;
	return 0;
}