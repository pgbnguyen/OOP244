// CheckingAccount.cpp
// hasan.murtaza/submit 244_w8_home
// Anton Elistratov
// Seneca@York
// Email: eanton@myseneca.ca
// Program: CPA
#include "CheckingAccount.h"
#include <iomanip>

using namespace std;

namespace ict {

	// TODO: define CheckingAccount class member functions here  
	//two argument constructor
	CheckingAccount::CheckingAccount(double funds, double tf) : Account(funds) {
		transactionFee = 0;

		if (tf >= 0) {
			transactionFee = tf;
		}
	}

	//chargeFee
	void CheckingAccount::chargeFee() {
		double funds;
		//deducting fees
		funds = getBalance();
		funds -= transactionFee;

		//setting the balance
		setBalance(funds);
	}

	//debit
	bool CheckingAccount::debit(double funds) {
		//charging fee
		chargeFee();

		return Account::debit(funds);//returning base class function debit.
	}

	//credit
	void CheckingAccount::credit(double funds) {
		//charging fee
		chargeFee();

		//calling base class function credit.
		Account::credit(funds);
	}

	//display
	ostream& CheckingAccount::display(ostream& ostr) {
		ostr << fixed;
		ostr << std::setprecision(2) << "Account type: Checking" << "\n";
		ostr << std::setprecision(2) << "Balance: $ " << getBalance() << "\n";
		ostr << std::setprecision(2) << "Transaction Fee: " << transactionFee << "\n";
		return ostr;
	}
}//namespace ict