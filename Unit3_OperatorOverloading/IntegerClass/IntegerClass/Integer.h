#pragma once
#include <iostream>

class Integer {
	int* m_pInt;
public:
	Integer();
	Integer(int value);

	Integer(const Integer& obj);
	Integer& operator=(const Integer& a);
	~Integer();
	Integer(Integer&& obj);
	Integer& operator=(Integer&& a);

	int getValue() const;
	void setValue(int value);

	Integer & operator ++();
	Integer operator ++(int);
	bool operator ==(const Integer& other) const;
	Integer operator +(const Integer& a);

	void operator ()();
	explicit operator int();

	// friend classes NOT RECOMMENDED - use get, set methods instead
	friend std::istream& operator >>(std::istream& input, Integer& a);

};