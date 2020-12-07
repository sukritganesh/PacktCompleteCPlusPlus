#include <iostream>
#include <string>
#include "Integer.h"

class Employee {
	std::string m_Name;
	Integer m_Id;
public:
	//Employee(const std::string& name, const Integer& id) :
	//	m_Name{ name },
	//	m_Id{ id } {
	//	std::cout << "Employee(const std::string& name, const Integer& id)" << std::endl;
	//}

	template<typename T1, typename T2>
	Employee(T1 && name, T2 && id) :
		m_Name{ std::forward<T1>(name) },
		m_Id{ std::forward<T2>(id) } {
		std::cout << "Employee(std::string&& name, Integer&& id)" << std::endl;
	}
};

Integer * returnInt(Integer* me) {
	return me;
}

int main() {
	Employee emp{ "Washington", 100 };
	Integer i{ 200 };
	Employee emp2{ "Nixon", i };		// "Nixon" is rvalue, i is lvalue
	Employee emp3{ "Bush", Integer{250} };

	//std::cout << "experiment" << std::endl;

	//Integer* k{ new Integer{ 200 } };
	//Employee emp4{ "Kennedy", *returnInt(k) };
	//std::cout << k->getValue() << std::endl;

	return 0;
}