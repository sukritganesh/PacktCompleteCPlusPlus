#pragma once
#include "Account.h"
class Checking :
	public Account
{
	float m_MinimumBalance;
public:
	using Account::Account;
	Checking(const std::string& name, float balance, float mBal);
	~Checking();
	void withdraw(float amount);
	float getMinimumBalance();
};

