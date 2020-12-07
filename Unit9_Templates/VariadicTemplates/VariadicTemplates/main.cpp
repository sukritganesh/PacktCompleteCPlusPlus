#include <iostream>
#include "Integer.h"

std::ostream& operator<<(std::ostream& os, Integer& a)
{
	os << a.getValue();
	return os;
}

//template<typename T>
//void Print(std::initializer_list<T> args) {
//	for (const auto& x : args) {
//		std::cout << x << " ";
//	}
//}

// base case function, accepts no arguments
void Print() {
	std::cout << std::endl;
}

// template parameter pack
template<typename T, typename ... Params>
// function parameter pack
void Print(T &&a, Params&& ... args) {
	std::cout << a;
	if (sizeof...(args) != 0) {
		std::cout << ", ";
	}
	Print(std::forward<Params>(args)...);
}

int main() {
	Print(1, 2.5, 3.0f, '4', "50");
	std::cout << std::endl;
	Integer val{ 4 };
	Print(2, 5.5, Integer{ 3 }, val);
	return 0;
}

/*
1. Print(1, 2.5, 3.0f, '4', "50");
T a = 1
args ... = 2.5, 3.0f, '4', "50"

2. Print(2.5, 3.0f, '4', "50");
T a = 2.5
args ... = 3.0f, '4', "50"

3. Print(3.0f, '4', "50");
T a = 3.0f
args ... = '4', "50"

4. Print('4', "50");
T a = '4'
args ... = "50"

5. Print("50")
T a = "50"
args ... = <empty>

6. Print();
*/