// Account.cpp
// hasan.murtaza/submit 244_w8_lab
// Anton Elistratov
// Seneca@York
// Email: eanton@myseneca.ca
// Program: CPA
#include "Account.h"

using namespace std;

namespace ict{ 
	
	// constructor   
	//no argument, default
	Account::Account() {
		setBalance(0);
	}
	//one argument, overloaded
	Account::Account( double funds ) {
		setBalance(funds);
	}
	// credit (add) an amount to the account balance
	void Account::credit( double funds ) {
		balance += funds; 
	}
	
	// debit (subtract) an amount from the account balance return bool 
	bool Account::debit( double funds ) {
		bool withdraw;
		if ((balance - funds) > 0) {
			balance -= funds;
			withdraw = true;
		}
		else {
			withdraw = false;
		}

		return withdraw;
	}

	double Account::getBalance() const
	{
		return balance;
	} 

	void Account::setBalance( double newBalance )
	{
		balance = newBalance;
	} 
}