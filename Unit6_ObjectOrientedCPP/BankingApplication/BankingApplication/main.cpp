#include <iostream>
#include "Account.h"
#include "Savings.h"
#include "Checking.h"
#include "Transaction.h"
#include <typeinfo>

int main()
{
	Checking acc("Bob", 100, 0.05f);
	Transact(&acc);

	Savings s3("David", 200, 0.06f);
	Transact(&s3);

	// Casting
	std::cout << std::endl;
	Checking ch("Adam", 100, 50);
	Account* pAccount = &ch;

	Checking* pChecking = static_cast<Checking*>(pAccount);		// downcast

	// RTTI
	std::cout << std::endl;
	Savings ss("Charlie", 100, 0.05f);
	Transact(&ss);

	int i{};
	float f{};
	const std::type_info& ti = typeid(i);
	std::cout << ti.name() << std::endl;

	const std::type_info &ti2 = typeid(*pAccount);
	if (ti2 == typeid(Checking)) {
		std::cout << "pChecking points to Checking" << std::endl;
	}


	return 0;
}