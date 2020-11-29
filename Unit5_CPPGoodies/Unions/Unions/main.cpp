#include <iostream>

union Test {
	// only one member is active at a time
	// cannot store value in x, ch, and d at the same time
	// because x, ch, and d are stored in the same memory spot
	int x;
	char ch;
	double d;
	
	Test() : ch{ 'a' } {
		std::cout << __FUNCSIG__ << std::endl;
	}
	~Test() {
		std::cout << __FUNCSIG__ << std::endl;
	}
};

union Test2 {
	std::string s;
	int p;

	Test2() {
		std::cout << __FUNCSIG__ << std::endl;
	}
	~Test2() {
		std::cout << __FUNCSIG__ << std::endl;
	}
};

int main() {
	Test t;
	std::cout << "Size of Test: " << sizeof(Test) << std::endl;
	std::cout << t.ch << std::endl;

	t.x = 1000;

	// ch will no longer hold 'a', because int x is written in its memory space
	std::cout << t.ch << std::endl;

	Test2 t2;
	std::cout << "Size of Test2: " << sizeof(Test2) << std::endl;
	new(&t2.s) std::string{"shdgashjdgashjgdahjdgbahjsgdahjdgbahjd"};
	std::cout << t2.s << std::endl;
	t2.s.~basic_string();
}