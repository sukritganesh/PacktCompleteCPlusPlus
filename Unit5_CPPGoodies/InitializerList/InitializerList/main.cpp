#include <iostream>
#include <initializer_list>

class Bag {
	int arr[10];
	int m_Size{};
public:
	Bag(std::initializer_list<int> values) {
		if (values.size() < 10) {
			auto it = values.begin();
			while (it != values.end()) {
				Add(*it);
				++it;
			}
		}
	}
	void Add(int value) {
		if(m_Size < 10)
			arr[m_Size++] = value;
	}
	void Remove() {
		--m_Size;
	}
	int operator [] (int index) {
		return arr[index];
	}
	int getSize() const {
		return m_Size;
	}
};

void Print(std::initializer_list<int> values) {
	for (auto x : values) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
}

int main() {
	int x{ 0 };
	float y{ 3.1f };
	int arr[5]{ 3, 2, 1, 0, -1 };
	std::string s{ "Hello C++" };
	std::initializer_list<int> data = { 1, 2, 3, 4 };
	auto values = { 1, 2, 3, 4 };

	Bag b{ 3, 1, 8 };
	//b.Add(3);
	//b.Add(1);
	//b.Add(8);
	for (int i = 0; i < b.getSize(); ++i) {
		std::cout << b[i] << " ";
	}
	std::cout << std::endl;

	Print({ 8, 2, 6, 3 });

	return 0;
}