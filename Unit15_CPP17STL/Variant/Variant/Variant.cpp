#include <iostream>
#include <variant>
#include <string>

// std::variant is a type-safe replacement for union
// automatic destruction

struct Visitor {
	void operator()(const std::string& s) const {
		std::cout << "string:" << s << std::endl;
	}
	void operator()(int& x) const {
		std::cout << "int:" << x << std::endl;
	}
};

struct Modifier {
	void operator()(std::string& s) const {
		s = s + "modified string";
	}
	void operator()(int& x) const {
		x += 1000;
	}
};

int main() {
	std::variant<std::string, int> v{ 5 };

	auto val = std::get<int>(v);
	val = std::get<1>(v);
	std::cout << val << std::endl;

	auto activeIndex = v.index();
	std::cout << activeIndex << std::endl;

	// bad_variant_access exception will be thrown if inactive member is accessed
	try {
		std::get<0>(v);
	}
	catch (std::exception & ex) {
		std::cout << ex.what() << std::endl;
	}

	auto p = std::get_if<int>(&v);		// returns nullptr if you access inactive member
	std::cout << *p << std::endl;

	v = 10;		// new value to active member
	std::get<int>(v) = 12;		// can also do this
	v.emplace<int>(14);			// another way (if object is member, pass arguments to constructor)
	std::cout << *std::get_if<int>(&v) << std::endl;

	// visitation
	std::cout << "Visitor demo: " << std::endl;
	std::visit(Visitor{}, v);
	v = "C++";
	std::visit(Visitor{}, v);
	std::visit(Modifier{}, v);
	std::visit(Visitor{}, v);

	v = "using lambda";
	auto visitor = [](auto& x) {
		using T = std::decay_t<decltype(x)>;		// decay from reference
		if constexpr (std::is_same_v<T, int>) {
			std::cout << "int: " << x << std::endl;
		}
		else if constexpr (std::is_same_v<T, std::string>) {
			std::cout << "string: " << x << std::endl;
		}
	};
	std::visit(visitor, v);
	v = -10;
	std::visit(visitor, v);
}