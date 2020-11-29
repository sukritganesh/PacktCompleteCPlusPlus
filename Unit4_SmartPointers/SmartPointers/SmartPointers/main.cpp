#include <iostream>
#include "Integer.h"
#include <memory>

// UNIQUE POINTER DEMO:

void display(Integer* p) {
	if (!p) {
		return;
	}
	std::cout << p->getValue() << std::endl;
}

Integer * getPointer(int value) {
	Integer* p = new Integer(value);
	return p;
}

void store(const std::unique_ptr<Integer> & p) {
	std::cout << "Storing data into a file:" << p->getValue() << std::endl;
}

void uniquePointerDemo() {
	int value = 5;
	std::unique_ptr<Integer> p(getPointer(value));
	if (p == nullptr) {
		//p = new Integer(value);
		p.reset(new Integer(value));
	}
	p->setValue(100);
	display(p.get());
	//delete p;
	//p = nullptr;
	//p = new Integer();
	p.reset(new Integer);
	*p = __LINE__;
	display(p.get());
	store(p);
	*p = 200;
	display(p.get());
	//delete p;
}

// SHARED POINTER DEMO

class Project {
public:
	~Project() {
		std::cout << "~Project()" << std::endl;
	}
};
class Employee {
	std::shared_ptr<Project> m_pProject;
public:
	void setProject(std::shared_ptr<Project> p) {
		m_pProject = p;
	}
	std::shared_ptr<Project> getProject() const {
		return m_pProject;
	}
	~Employee() {
		std::cout << "~Employee()" << std::endl;
	}
};

std::shared_ptr<Employee> assignProject() {
	std::shared_ptr<Project> p{ new Project };
	Employee* e1 = new Employee{};
	e1->setProject(p);
	return std::shared_ptr<Employee>{e1};
}

void sharedPointerDemo() {
	auto sp = assignProject();
}

// WEAK POINTER DEMO 1
class Printer {
	std::weak_ptr<int> m_pValue;
public:
	void setValue(std::weak_ptr<int> p) {
		m_pValue = p;
	}
	void Print() {
		if (m_pValue.expired()) {
			std::cout << "Resource is no longer available" << std::endl;
			return;
		}
		auto sp = m_pValue.lock();
		std::cout << "Value is:" << *sp << std::endl;
		std::cout << "Ref count:" << sp.use_count() << std::endl;
	}
};

void weakPointerDemo() {
	Printer prn;
	int num{};
	std::cout << "Enter an integer: " << std::endl;
	std::cin >> num;
	std::shared_ptr<int> p{ new int{ num } };
	prn.setValue(p);

	// we want to release underlying memory
	// but using shared pointer and setting it to nullptr will only decrement count by 1
	// and using "dumb pointer" makes it difficult to know if underlying memory has been released
	if (*p > 10) {
		p = nullptr;
	}

	prn.Print();
}

// WEAK POINTER DEMO 2
class Employee1;
class Project1 {
public:
	std::weak_ptr<Employee1> m_emp;
	Project1() {
		std::cout << "Project()" << std::endl;
	}
	~Project1() {
		std::cout << "~Project()" << std::endl;
	}
};
class Employee1 {
public:
	std::weak_ptr<Project1> m_prj;
	Employee1() {
		std::cout << "Employee()" << std::endl;
	}
	~Employee1() {
		std::cout << "~Employee()" << std::endl;
	}
};

void weakPointerDemo2() {
	std::shared_ptr<Employee1> emp{ new Employee1{} };
	std::shared_ptr<Project1> prj{ new Project1{} };

	emp->m_prj = prj;
	prj->m_emp = emp;
}

int main() {
	//uniquePointerDemo();
	//sharedPointerDemo();
	//weakPointerDemo();
	weakPointerDemo2();
}