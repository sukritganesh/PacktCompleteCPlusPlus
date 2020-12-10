#include <iostream>

// for copy elision, MUST provide copy and move constructors in c++14
// but in c++ 17, copy elision can still work without those constructors implemented
class Number {
public:
	Number(const Number& n) = delete;
	Number(Number&& n) = delete;
	Number(int value) {
		std::cout << "Parametrized ctor\n";
	}
	//Number(const Number& n) {
	//	std::cout << "Copy ctor\n";
	//}
	//Number(Number&& n) {
	//	std::cout << "Move ctor\n";
	//}
};

void Foo(Number n) {

}

// returns temporary object
Number Create() {
	//Number n(0);
	//return n;

	return Number(0);
}

template<typename T, typename...Args>
T Create(Args&&...args) {
	return T{ args... };
}

// copy elision: no need to make copy, elided
int main() {
	std::cout << "Case 1" << std::endl;
	Number n1 = 3;		// copy elision applied: Number n1 = Number(3)

	std::cout << "Case 2" << std::endl;
	Foo(Number(3));		

	std::cout << "Case 3" << std::endl;
	auto n2 = Create();

	std::cout << "Case 4" << std::endl;
	auto n3 = Create<Number>(10);		// copy elision performed, no copy constructors used
}