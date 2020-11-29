#include <iostream>
#include <memory>
#include <vector>
#include <random>

// BASIC EXCEPTION DEMO

class Test {
public:
	Test() { std::cout << "Test()" << std::endl; }
	~Test() { std::cout << "~Test()" << std::endl; }
};


int ProcessRecords(int count) {
	std::unique_ptr<Test> t{ new Test };
	if (count < 10) {
		throw std::out_of_range("Count should be greater than 10!");
	}

	std::vector<int> p;
	p.reserve(count);
	std::vector<int> pArray;
	pArray.reserve(count);

	//int* p = new int[count];
	//int* pArray = (int*)malloc(count * sizeof(int));
	//if (pArray == nullptr) {
	//	throw std::runtime_error("Failed to allocate memory!");
	//}

	// Dummy processing
	for (int i = 0; i < count; i++) {
		pArray[i] = i;
	}
	// no need to free p or pArray
	return 0;
}

void basicExceptionDemo() {
	try {
		ProcessRecords(5);
		//ProcessRecords(std::numeric_limits<int>::max());
	}
	catch (std::runtime_error & ex) {
		std::cout << ex.what() << std::endl;
	}
	catch (std::out_of_range & ex) {
		std::cout << ex.what() << std::endl;
	}
	catch (std::bad_alloc & ex) {
		std::cout << ex.what() << std::endl;
	}

	try {
		ProcessRecords(std::numeric_limits<int>::max());
	}
	catch (std::exception & ex) {
		std::cout << ex.what() << std::endl;
	}

	try {
		ProcessRecords(5);
	}
	catch (...) {
		std::cout << "Caught an exception, avoid ..." << std::endl;
	}
}

// STACK UNWINDING

void stackUnwindingDemo() {
	try {
		ProcessRecords(std::numeric_limits<int>::max());
	}
	catch (std::exception & ex) {
		std::cout << ex.what() << std::endl;
	}
}

// NESTED EXCEPTION HANDLING

int ProcessRecords2(int count) {
	// Dummy processing
	// Some pass, some fail, but we do not want to exit function and stop processing
	// if one record fails
	std::default_random_engine eng;
	std::bernoulli_distribution dist;
	int errors{};
	for (int i = 0; i < count; i++) {
		try {
			std::cout << "Processing record # : " << i << " ";
			if (!dist(eng)) {
				++errors;
				throw std::runtime_error("Could not process the record");
			}
			std::cout << std::endl;
		}
		catch (std::runtime_error & ex) {
			std::cout << "[ERROR " << ex.what() << "]" << std::endl;
			if (errors > 4) {
				std::runtime_error err("Too many errors. Abandoning operation.");
				ex = err;
				throw;		// throw original exception ex out to caller
			}
		}
	}
	return 0;
}

void nestedExceptionHandling() {
	try {
		ProcessRecords2(10);
	}
	catch (std::exception & ex) {
		std::cout << ex.what() << std::endl;
	}
}

// CONSTRUCTOR AND DESTRUCTOR EXCEPTION HANDLING
class A {
public:
	A() { std::cout << "A()" << std::endl; }
	~A() { std::cout << "~A()" << std::endl; }
};

class B {
public:
	B() { std::cout << "B()" << std::endl; }
	~B() { std::cout << "~B()" << std::endl; }
};

class Test2 {
	// use smart pointers, strings, vectors instead of dumb pointers and arrays
	// so that they will be deleted if constructor throws exception
	std::unique_ptr<A> pA{};
	B b{};
	std::unique_ptr<int> pInt{};
	std::string pStr{};
	std::vector<int> pArr{};
public:
	Test2() { 
		std::cout << "Test2()" << std::endl; 
		pA.reset(new A);
		throw std::runtime_error("Dummy exception!");

		//pA = new A;
		//pInt = new int;
		//pStr = new char[1000];
		//pArr = new int[50000];
	}
	~Test2() { 
		// try to avoid throwing exceptions from destructor
		//throw std::runtime_error("Destructor exception");

		std::cout << "~Test2()" << std::endl; 
		//delete pA;
		//delete pInt;
		//delete[] pStr;
		//delete[] pArr;
	}
};


void cdExceptionHandling() {
	try {
		Test2 t;
	}
	catch (std::runtime_error & ex) {
		std::cout << ex.what() << std::endl;
	}
}

// NOEXCEPT DEMO

void Tester(int x) noexcept(false) {
	throw x;
}

void Tester2(int x) {		// implicitly noexcept(false)
	std::cout << x << std::endl;
}

int Sum(int x, int y) noexcept(true) {
	//Tester(x);		DO NOT DO
	return x + y;
}

int Sum2(int x, int y) noexcept(noexcept(Tester(x))) {
	//Tester(x);		DO NOT DO
	return x + y;
}

void noexceptDemo() {
	std::cout << "Tester is noexcept(false) " << std::boolalpha << noexcept(Tester(5)) << std::endl;
	A a;
	std::cout << "Destructor is noexcept(true) " << std::boolalpha << noexcept(a.~A()) << std::endl;
	try {
		Sum(3, 5);
	}
	catch (int x) {
		std::cout << x << std::endl;
	}
}

// move constructors, destructors, etc. should be noexcept
// destructor is implicitly noexcept(true)
// move operations should have noexcept(true)


int main() {
	//basicExceptionDemo();
	//stackUnwindingDemo();
	//nestedExceptionHandling();
	//cdExceptionHandling();
	noexceptDemo();

	return 0;
}