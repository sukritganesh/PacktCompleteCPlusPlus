#include <iostream>

// BASIC TEMPLATE DEMO

template <typename T>
T Max(T x, T y) {
	std::cout << typeid(T).name() << std::endl;
	return x > y ? x : y;
}

void basicTemplateDemo() {
	auto num = Max(2.5, 5.1);
	auto num2 = Max(2, -5);
	auto num3 = Max<double>(2, 5.1);
	std::cout << num << " " << num2 << " " << num3 << std::endl;
}

// EXPLICIT INSTANTIATION AND EXPLICIT SPECIALIZATION

// explicit instantiation, will be instantiated even if not used
// template return_type function_name(args ...)
template char Max(char x, char y);

// explicit specialization
// template<> return_type function_name(args ...)
template<> const char* Max(const char* x, const char* y) {
	std::cout << "Max<const char*>()" << std::endl;
	return strcmp(x, y) > 0 ? x : y;
}

void explicitDemo() {
	const char* b{ "B" };
	const char* a{ "A" };
	auto s = Max(a, b);
	std::cout << s << std::endl;
}

// NON TYPE TEMPLATE ARGUMENTS

template<int size>
void Print() {
	std::cout << size << std::endl;
	//size++;		// cannot modify!!!
	const int s = 4;
}

//template<typename T>
//T Sum(T* parr, int size) {
//	T sum{};
//	for (int i = 0; i < size; ++i) {
//		sum += parr[i];
//	}
//	return sum;
//}

template<typename T, int size>
T Sum(T (&parr)[size]) {
	T sum{};
	for (int i = 0; i < size; ++i) {
		sum += parr[i];
	}
	return sum;
}

void nonTypeDemo() {
	Print<3>();
	int i = 3;
	//Print<i>();
	Print<sizeof(3)>();

	int arr[]{ 3, 1, 9, 7 };
	auto b = std::begin(arr);
	//int(&ref)[4] = arr;
	int sum = Sum(arr);
	std::cout << sum << std::endl;
}

int main() {
	//basicTemplateDemo();
	//explicitDemo();
	nonTypeDemo();
	
	return 0;
}