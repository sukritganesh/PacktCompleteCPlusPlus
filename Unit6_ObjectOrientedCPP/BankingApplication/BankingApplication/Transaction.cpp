#include "Transaction.h"
#include "Checking.h"
#include "Savings.h"
#include <iostream>

void Transact(Account* pAccount)
{
	std::cout << "Transaction started" << std::endl;
	std::cout << "Initial balance:" << pAccount->getBalance() << std::endl;
	pAccount->deposit(100);
	pAccount->accumulateInterest();

	if (typeid(*pAccount) == typeid(Checking)) {
		Checking* pChecking = static_cast<Checking*>(pAccount);
		std::cout << "Min bal. checking: " << pChecking->getMinimumBalance() << std::endl;
	}
	Savings* pSavings = dynamic_cast<Savings*>(pAccount);
	if (pSavings != nullptr) {
		std::cout << "Savings account. Can invoke any methods proprietary to savings." << std::endl;
	}

	pAccount->withdraw(170);
	std::cout << "Interest rate:" << pAccount->getInterestRate() << std::endl;
	std::cout << "Final balance:" << pAccount->getBalance() << std::endl;
}
