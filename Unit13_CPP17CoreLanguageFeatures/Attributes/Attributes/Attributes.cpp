#include <iostream>

[[deprecated("Use the new version instead - CreateArray")]]
int * CreateIntArray(size_t size) {
	return new int[size];
}

template<typename T>
[[nodiscard]]
T* CreateArray(size_t size) {
	return new T[size];
}

class [[nodiscard]] Number{

};

Number getNumber(int x) {
	return Number{};
}

class [[deprecated("This class is replaced by NewTest class")]] Test{

};

namespace [[deprecated("DO NOT USE THIS NAMESPACE!!!")]] A{

}

int main() {
	CreateIntArray(3);
	Test t;
	using namespace A;
	CreateArray<int>(3);		// warning: violating [[nodiscard]]
	getNumber(3);				// warning: violating [[nodiscard]]
}