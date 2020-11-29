#include <iostream>
#include <vector>

int main() {
	std::vector<int> data2{10, 1, 9, 2, 8};
	std::vector<double> data3{ 2, 3.3, -10.2, 22, 4.f, 34.4f };

	data2.push_back(4);

	std::vector<int> data;
	for (int i = 0; i < 10; i++) {
		data.push_back(i);
	}

	// Access
	data[0] = 100;
	for (auto x : data) {
		std::cout << x << " ";
	}
	std::cout << std::endl;

	// Delete
	data.erase(data.begin() + 3);	// erases element at index 3
	for (auto x : data) {
		std::cout << x << " ";
	}
	std::cout << std::endl;

	// Insert
	data.insert(data.begin() + 5, -15);	// inserts -15 at index 5
	for (auto x : data) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
}