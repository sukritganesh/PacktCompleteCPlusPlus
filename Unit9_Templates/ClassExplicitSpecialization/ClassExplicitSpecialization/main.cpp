#include <iostream>
#include <vector>

template<typename T>
class PrettyPrinter {
	T* m_pData;
public:
	PrettyPrinter(T* data) :m_pData(data) {
		
	}
	void Print() {
		std::cout << "{" << *m_pData << "}" << std::endl;
	}
	T* GetData() {
		return m_pData;
	}
};

// explicit specialization for std::vector<int> Print() function only!
template<>
void PrettyPrinter<std::vector<int>>::Print() {
	std::cout << "{";
	for (const auto& x : *m_pData) {
		std::cout << x << " ";
	}
	std::cout << "}" << std::endl;
}

// explicit specialization for char*
template<>
class PrettyPrinter<char*> {
	char* m_pData;
public:
	PrettyPrinter(char* data) :m_pData(data) {

	}
	void Print() {
		std::cout << "{" << m_pData << "}" << std::endl;
	}
	char* GetData() {
		return m_pData;
	}
};

int main() {
	int data = 5;
	float f = 8.2f;
	PrettyPrinter<int> p1(&data);
	p1.Print();
	PrettyPrinter<float> p2(&f);
	p2.Print();

	char* p = new char[12]{ "Hello world" };
	PrettyPrinter<char*> p3(p);
	p3.Print();
	char* pData = p3.GetData();
	std::cout << pData << std::endl;

	std::vector<int> v{ 1, 2, 3, 4, 5 };
	PrettyPrinter<std::vector<int>> pv(&v);
	pv.Print();

	return 0;
}