#include <iostream>
#include "Integer.h"

void Print(Integer a) {
	std::cout << a.getValue() << std::endl;
}

int main() {
	int a = 5, b = 2;
	float f = static_cast<float>(a) / b;
	// char* p = static_cast<char*>(&a); (not allowed)
	char* p = reinterpret_cast<char*>(&a);
	const int x = 1;
	int* q = const_cast<int*>(&x);
	std::cout << f << std::endl;

	std::cout << "Primitive to User Type Conversions" << std::endl;

	Integer a1{ 5 };
	Integer a2 = 5;
	Print(150);
	Integer a3;
	a3 = 20;

	//int x = static_cast<int>(a1);
	
	return 0;
}