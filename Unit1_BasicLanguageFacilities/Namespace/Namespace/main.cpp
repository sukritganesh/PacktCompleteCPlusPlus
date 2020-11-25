#include <iostream>
namespace Avg {
	double Calculate(double x, double y) {
		return (x + y) / 2;
	}
	double HaveFun(double x, double y) {
		return x * y * 2 / (x + y);
	}
}

namespace Basic {
	double Calculate(double x, double y) {
		return x + y;
	}
}

// nested namespaces
namespace Sort {
	void mergesort() {

	}
	void quicksort() {

	}

	// Nested Namespace
	namespace Comparison {
		bool less(int x, int y) {
			return x < y;
		}
		bool greater(int x, int y) {
			return x > y;
		}
	}
}

int main() {
	// Method 1 (RECOMMENDED):
	std::cout << "Average: " << Avg::Calculate(2.2, 3.6) << std::endl;
	std::cout << "Sum: " << Basic::Calculate(2.2, 3.6) << std::endl << std::endl;

	// Method 2:
	using Avg::Calculate;
	std::cout << "Average: " << Calculate(2.2, 3.6) << std::endl;
	// Must still use namespace name when accessing other functions in Avg
	std::cout << "Having fun: " << Avg::HaveFun(2.2, 3.6) << std::endl << std::endl;

	// Method 3 (NOT RECOMMENDED):
	using namespace Avg;
	std::cout << "Average: " << Calculate(2.2, 3.6) << std::endl;
	std::cout << "Having fun: " << HaveFun(2.2, 3.6) << std::endl << std::endl;
	using namespace Basic;
	// WILL CAUSE ERROR, SINCE Avg AND Basic BOTH HAVE Calculate function!!!
	// std::cout << "Sum: " << Calculate(2.2, 3.6) << std::endl;

	// Access nested namespace
	std::cout << "Nested namespace: " << Sort::Comparison::less(4, 6) << std::endl;
}