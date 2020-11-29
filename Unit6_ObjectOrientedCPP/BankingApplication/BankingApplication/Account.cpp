#include "Account.h"
#include <iostream>

int Account::s_ANGenerator = 1000;

Account::Account(const std::string& name, float balance):
m_Name(name), m_Balance(balance) {
	m_AccNo = ++s_ANGenerator;
}

Account::~Account()
{
}

const std::string Account::getName() const
{
	return m_Name;
}

float Account::getBalance() const
{
	return m_Balance;
}

int Account::getAccountNo() const
{
	return m_AccNo;
}

void Account::accumulateInterest()
{
}

void Account::withdraw(float amount)
{
	if (m_Balance > amount) {
		m_Balance = m_Balance - amount;
	}
	else {
		std::cout << "Insufficient funds! Current balance=" << m_Balance << ", Withdrawl amount=" << amount << "." << std::endl;
	}
}

void Account::deposit(float amount)
{
	m_Balance += amount;
}

float Account::getInterestRate() const
{
	return 0.0f;
}
