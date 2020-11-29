#include "Checking.h"
#include <iostream>

Checking::Checking(const std::string& name, float balance, float mBal=50.0f):
	m_MinimumBalance(mBal), Account(name, balance)
{
}

Checking::~Checking()
{
}

void Checking::withdraw(float amount)
{
	if ((m_Balance - amount) > 50) {
		Account::withdraw(amount);
	}
	else {
		std::cout << "Insufficient funds! Current balance=" << m_Balance << ", Withdrawl amount=" << amount << ". Funds must be 50 or greater upon completion of withdrawl." << std::endl;
	}
}

float Checking::getMinimumBalance()
{
	return m_MinimumBalance;
}
