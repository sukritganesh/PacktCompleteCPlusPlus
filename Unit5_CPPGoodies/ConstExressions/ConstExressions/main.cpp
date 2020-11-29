#include <iostream>

int getNumber() {
	return 42;
}

constexpr int getNumberConstExpr() {
	return 42;
}

constexpr int Add(int x, int y) {
	return x + y;
}

constexpr int Max(int x, int y) {
	if (x > y) {
		return x;
	}
	return y;
	//return x > y ? x : y;	// must be one line
}

int main() {
	constexpr int i = 10;		// evaluated at compile time
	int arr[i];

	const int j = 5;
	int arr1[j];

	const int k = getNumber();		// evaluated at runtime
	//const int arr2[k];			// doesn't work

	constexpr int l = getNumberConstExpr();			// evaluated at compile time
	int arr3[l];

	int x = getNumberConstExpr();			// evaluated at runtime

	constexpr int sum = Add(3, 5);			// evaluated at compile time

	return 0;
}

// Literal types (allowed for constexpr)
// void, scalar types(int, float, char), references, etc....
// constexpr functions should contan only single line statement that should be a return statement
// all constexpr functions are implicitly inline