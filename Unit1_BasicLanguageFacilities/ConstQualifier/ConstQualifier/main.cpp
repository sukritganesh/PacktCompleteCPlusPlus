#include <iostream>

void demoConst(const int* ptr) {
	// this function can only take const pointers as inputs

	std::cout << *ptr << std::endl;
	// *ptr = 10; (cannot do this, as ptr is const)
}

// takes pointer input
// cannot modify value held by *ptr
void Print(const int* ptr) {
	std::cout << *ptr << std::endl;
}

// takes reference input
// cannot modify ref
void Print(const int& ref) {
	std::cout << ref << std::endl;
}


int main() {
	float radius = 0;
	std::cout << "Enter Radius: " << std::endl;
	std::cin >> radius;
	const float PI = 3.14159f;
	float area = PI * radius * radius;
	float circumference = PI * 2 * radius;
	// PI = 5 (compiler will give error, cannot modify const PI)
	std::cout << "Area: " << area << std::endl;
	std::cout << "Circumference" << circumference << std::endl;

	const int CHUNK_SIZE = 512;
	const int* ptr = &CHUNK_SIZE;	// MUST use const ptr, means that I can't modify value at address ptr
	int x = 10;
	ptr = &x;
	// *ptr = 1 (CANNOT do this, since I cannot modify value of const pointer)

	const int HEIGHT = 60;
	const int *const ptr2 = &HEIGHT;  // now, the value stored in pointer's address AS WELL AS pointer itself can't be changed.

	std::cout << "Const Function Demo:" << std::endl;
	Print(&x);
	std::cout << "main->x " << x << std::endl;
	Print(ptr);
	demoConst(ptr);

	std::cout << "Const Reference Demo: " << std::endl;
	int p = 5;
	const int& ref = p;
	const int& ref2 = 5;		// const reference can have literal initialization
	Print(ref);					// references preferred as function argument
	Print(4);					// can pass in literal argument if parameter is const reference!

	return 0;
}