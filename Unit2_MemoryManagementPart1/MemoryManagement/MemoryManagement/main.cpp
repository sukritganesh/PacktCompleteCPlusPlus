#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void mallocMethod() {
	// allocates enough space for one int
	int* p = (int*)malloc(sizeof(int));
	if (p == nullptr) {
		std::cout << "Failed to allocate memory!\n" << std::endl;
	}
	std::cout << "MALLOC garbage value: " << *p << std::endl;
	*p = 5;
	std::cout << "Assigned value: " << *p << std::endl;
	free(p);
	p = nullptr;

	// allocates enough space for one int, initialized to 0
	int* q = (int*)calloc(1, sizeof(int));
	if (q == nullptr) {
		std::cout << "Failed to allocate memory!\n" << std::endl;
	}
	std::cout << "Calloc: " << std::endl;
	std::cout << "Initialized to 0: " << *q << std::endl;
	*q = 15;
	std::cout << "New value: " << *q << std::endl;
	free(q);
	q = nullptr;

	// allocate enough memory for 5 integers
	int* r = (int*)malloc(sizeof(int) * 5);
	int* s = (int*)calloc(5, sizeof(int));
	free(r);
	free(s);
}

void newOperator() {
	// NEW OPERATOR (COMMONLY USED FOR HEAP ALLOCATION)!
	std::cout << "New Operator: " << std::endl;

	int* p = new int;
	std::cout << "Garbage Value: " << *p << std::endl;
	*p = 6;
	std::cout << "Initialized Value: " << *p << std::endl;
	delete p;	// must delete in order to prevent memory leak
	p = nullptr;

	// Initialize upon allocation
	int* q = new int(100);
	std::cout << "Initialized upon allocation: " << *q << std::endl;
	delete q;
	q = nullptr;

	// Can allocate arrays as well
	// Allocate array with space for 5 doubles
	double* arr = new double[5];
	std::cout << "New double array: ";
	for (int i = 0; i < 5; i++) {
		arr[i] = i * 5.0;
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	delete[] arr;

	// Uniform initialization also works!
	double* arr2 = new double[3]{ 1.0, 3.0, 5.0 };
	delete[] arr2;

	// Allocate memory for strings
	// Need one more byte than number of characters (for null terminating character)
	char* st = new char[5];
	strcpy_s(st, 5, "BOOM");
	std::cout << "String on heap: " << st << std::endl;
	delete[] st;

}

void TwoDArrayNew() {
	// 2D array initialization
	std::cout << "2x3 Array: " << std::endl;
	int* row1 = new int[3];
	int* row2 = new int[3];

	// We create pointers to pointers
	// Each pointer points to a row of the 2D array
	// There are 2 rows, each containing 3 elements
	int** data = new int* [2];
	data[0] = row1;
	data[1] = row2;

	// Standard Access
	data[1][0] = 10;
	data[0][2] = -6;

	std::cout << "data[1][0] = " << data[1][0] << std::endl;

	// Free Memory
	// Must free rows first, then outer array (containing rows)
	// Number of delete calls must match number of new calls
	delete[] data[0];
	delete[] row2;
	delete[] data;
}

int main() {
	mallocMethod();
	std::cout << std::endl;
	newOperator();
	std::cout << std::endl;
	TwoDArrayNew();
	return 0;
}