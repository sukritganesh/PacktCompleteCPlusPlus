#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

//using Comparator = bool(*)(int, int);
template<typename T, int size, typename Comparator>
void Sort(T(&arr)[size], Comparator comp) {
	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - 1; ++j) {
			if (comp(arr[j], arr[j + 1])) {
				T temp = std::move(arr[j]);
				arr[j] = std::move(arr[j + 1]);
				arr[j + 1] = std::move(temp);
			}
		}
	}
}

bool Comp(int x, int y) {
	return x > y;
}

bool Comp1(int x, int y) {
	return x < y;
}

struct Comp2 {
	bool operator()(int x, int y) {
		return x > y;
	}
};

template<typename T, int size, typename Callback>
void ForEach(T(&arr)[size], Callback operation) {
	for (int i = 0; i < size; i++) {
		operation(arr[i]);
	}
}

template<typename T>
struct __Unnamed {
	int offset;
	__Unnamed(int off) : offset(off) {

	}
	void operator()(T &x) {
		x += offset;
		++offset;
	}
};

class Product {
	std::string name;
	float price;
public:
	Product(const std::string& n, float p) : name(n), price(p) {

	}
	void AssignFinalPrice() {
		float taxes[]{ 12, 5, 5 };
		float basePrice{ price };
		ForEach(taxes, [basePrice, this](const float & tax) {
			float taxedPrice = basePrice * tax / 100;
			price += taxedPrice;
		});
	}
	float GetPrice() const {
		return price;
	}
	auto GetDescription() {
		return [*this](const std::string& header) {
			std::ostringstream ost;
			ost << header << std::endl;
			ost << "Name: " << name << std::endl;
			ost << "Price: " << price << std::endl;
			return ost.str();
		};
	}
};

int main() {
	//__Unnamed<int> n(3);
	//int x = 5;
	//n(5);

	int arr[]{ 1, 6, 8, 4, 0 };
	ForEach(arr, [](auto x) {
		std::cout << x << " ";
	});
	std::cout << std::endl;

	// [=] captures all by value
	int offset = 0;
	ForEach(arr, [=](auto & x) mutable {
		x += offset;
		++offset;
	});
	ForEach(arr, [](auto x) {
		std::cout << x << " ";
	});
	std::cout << std::endl;

	// [&] captures all by reference
	std::cout << std::endl;
	int sum = 0;
	offset = 1;
	ForEach(arr, [&, offset](auto& x) {
		x += offset;
		sum += x;
	});
	std::cout << "Sum:" << sum << std::endl;
	ForEach(arr, [](auto x) {
		std::cout << x << " ";
		});
	std::cout << std::endl;

	// [this] captures member variables of class
	Product p{ "Watch", 500 };
	p.AssignFinalPrice();
	std::cout << std::endl << "Final Price: " << p.GetPrice() << std::endl;

	// lambda within lambda
	int s = 5;
	[](int x) {
		x *= 2;
		[](int x) {
			std::cout << std::endl << "Lambda within lambda: " << x << std::endl << std::endl;
		}(x);
	}(s);

	// generalized capture
	// create variables in capture clause
	int z{ 5 };
	auto f = [x = z](int arg) {
		std::cout << "Created in lambda capture clause: " << x << std::endl;
		return x + arg;
	};
	std::cout << "Sum: " << f(7) << std::endl;

	std::ofstream out{ "file.txt" };
	auto write = [out = std::move(out)](int x) mutable {
		int k = 4;
		std::cout << k << std::endl;
		out << x;
	};
	write(300);

	// GetDescription
	// capture product by copy so that it can be accessed even after product is deleted
	Product* q = new Product("BMW", 50000);
	std::cout << std::endl;
	auto desc = q->GetDescription();
	delete q;
	std::cout << desc("#############") << std::endl;

	// automatically constexpr function
	auto fff = [](int x, int y) {
		return x + y;
	};
	constexpr auto sumfff = fff(3, 5);
	std::cout << "Sum calculated at compile time: " << sumfff << std::endl;

	// NOTE: lambda function without capture clause decmposes to function pointer
	atexit([]() {
		std::cout << "Lambda expression convered to function pointer. Program is exiting ..." << std::endl;
	});
	
	std::cout << std::endl;
}