#include "Integer.h"
#include <iostream>
#include <memory>

//class IntPtr {
//	Integer* m_p;
//public:
//	IntPtr(Integer* p) : m_p(p) {
//
//	}
//	~IntPtr() {
//		delete m_p;
//	}
//	Integer* operator ->() {
//		return m_p;
//	}
//	Integer& operator *() {
//		return *m_p;
//	}
//};

Integer operator +(int x, const Integer& y) {
	Integer temp;
	temp.setValue(x + y.getValue());
	return temp;
}

std::ostream & operator <<(std::ostream& out, const Integer& a) {
	out << a.getValue();
	return out;
}

std::istream& operator >>(std::istream& input, Integer& a) {
	input >> *a.m_pInt;
	return input;
}

void Process(std::shared_ptr<Integer> ptr) {
	std::cout << ptr->getValue() << std::endl;
}

void CreateInteger() {
	std::shared_ptr<Integer> p(new Integer);
	Process(p);
	p->setValue(3);
	std::cout << p->getValue() << std::endl;
	(*p).setValue(10);
	(*p)();
}

int main() {
	Integer a{ 1 }, b(3);
	Integer c;
	c = a;
	std::cout << c.getValue() << std::endl;
	a.setValue(5);
	std::cout << c.getValue() << " " << a.getValue() << std::endl;
	a = a;
	std::cout << a.getValue() << std::endl;

	std::cout << "Global overload: " << std::endl;
	Integer d(4);
	Integer sum1 = d + 10;
	Integer sum2 = 10 + d;
	std::cout << "sum1: " << sum1 << " sum2: " << sum2 << std::endl;

	std::cout << "Input an int: ";
	Integer e;
	std::cin >> e;
	std::cout << std::endl << "Your int: " << e << std::endl;

	std::cout << "Function call operator: ";
	e();
	std::cout << std::endl;

	std::cout << "Smart Pointer: " << std::endl;
	CreateInteger();
	std::cout << "Smart pointer successfully destroyed" << std::endl;

	return 0;
}
