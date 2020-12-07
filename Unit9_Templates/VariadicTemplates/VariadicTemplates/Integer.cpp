#include "Integer.h"

Integer::Integer()
{
	std::cout << "Integer()" << std::endl;
	m_pInt = new int(0);
}

Integer::Integer(int value)
{
	std::cout << "Integer(int value)" << std::endl;
	m_pInt = new int(value);
}

Integer::Integer(const Integer& obj)
{
	std::cout << "Integer(const Integer&)" << std::endl;
	m_pInt = new int{ *obj.m_pInt };
}

Integer& Integer::operator=(const Integer& a)
{
	std::cout << "operator=(const Integer& a)" << std::endl;
	if (this != &a) {
		delete m_pInt;
		m_pInt = new int(*a.m_pInt);
		return *this;
	}
	return *this;
}

Integer::~Integer()
{
	std::cout << "~Integer()" << std::endl;
	delete m_pInt;
}

Integer::Integer(Integer&& obj)
{
	std::cout << "Integer(int&&)" << std::endl;
	m_pInt = obj.m_pInt;
	obj.m_pInt = nullptr;
}

Integer& Integer::operator=(Integer&& a)
{
	std::cout << "operator=(Integer&&)" << std::endl;
	if (this != &a) {
		delete m_pInt;
		m_pInt = a.m_pInt;
		a.m_pInt = nullptr;
	}
	return *this;
}

int Integer::getValue() const
{
	return *m_pInt;
}

void Integer::setValue(int value)
{
	*m_pInt = value;
}

Integer& Integer::operator++()
{
	++(*m_pInt);
	return *this;
}

Integer Integer::operator++(int)
{
	Integer temp(*this);
	++(*m_pInt);
	return temp;
}

bool Integer::operator==(const Integer& other) const
{
	return *m_pInt == *other.m_pInt;
}

Integer Integer::operator+(const Integer& a)
{
	return Integer(*m_pInt + *a.m_pInt);
}

void Integer::operator()()
{
	std::cout << *m_pInt << std::endl;
}

Integer::operator int()
{
	return *m_pInt;
}
