#include <iostream>

class Number {
	int m_Number;
public:
	Number() = default;
	Number(int x) :m_Number{ x } {
	};
};

int main()
{
	static_assert(std::is_default_constructible_v<Number>, "Only objects with default constructor can be deserialized");
}

// type: _t
// value (boolean): _v

