#include <iostream>
#include <chrono>
#include <string_view>
#include <vector>
#include <random>
#include <execution>

class Timer {
	std::chrono::steady_clock::time_point m_start;
public:
	Timer() : m_start{ std::chrono::steady_clock::now() } {

	}
	void ShowResult(std::string_view message = "") {
		auto end = std::chrono::steady_clock::now();
		auto difference = end - m_start;
		std::cout << message 
			<< ':' 
			<< std::chrono::duration_cast<std::chrono::nanoseconds>(difference).count() 
			<< std::endl;
	}
	void reset() {
		m_start = std::chrono::steady_clock::now();
	}
};

//constexpr unsigned VEC_SIZE{ 100000 };
std::vector<long> createVector(const int& vecSize) {
	std::vector<long> vec;
	vec.reserve(vecSize);
	std::default_random_engine engine{ std::random_device{}() };
	std::uniform_int_distribution<long> dist{ 0, vecSize };
	for (unsigned i = 0; i < vecSize; ++i) {
		vec.push_back(dist(engine));
	}
	return vec;
}

int main() {
	// SORT
	auto dataset = createVector(10000000);
	auto dataset2{ dataset };

	Timer t;
	std::sort(dataset.begin(), dataset.end());
	t.ShowResult("Sorting time (sequential)");

	t.reset();
	std::sort(std::execution::par, dataset2.begin(), dataset2.end());
	t.ShowResult("Sorting time (parallel)");

	std::cout << std::endl;

	// SUM
	auto dataset3 = createVector(1000000);

	t.reset();
	auto sum = std::accumulate(dataset3.begin(), dataset3.end(), 0L);
	t.ShowResult("Sum time (sequential)");

	t.reset();
	auto sum2 = std::reduce(dataset3.begin(), dataset3.end(), 0L);
	t.ShowResult("Sum time (parallel)");

	std::cout << std::endl;

	// Parallel is not perfect! There's an overhead to using multiple threads ...
	// synchronization is expensive
	// on small datasets, it's cheaper to use sequential algorithms
	auto dataset4 = createVector(100);

	t.reset();
	std::sort(dataset4.begin(), dataset4.end());
	t.ShowResult("Sorting time small dataset (sequential)");

	t.reset();
	std::sort(std::execution::par, dataset4.begin(), dataset4.end());
	t.ShowResult("Sorting time small dataset (parallel)");
	std::cout << "In this case, sequential takes less time!" << std::endl;

	return 0;
}