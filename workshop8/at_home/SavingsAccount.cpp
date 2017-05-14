// SavingsAccount.cpp
// hasan.murtaza/submit 244_w8_home
// Anton Elistratov
// Seneca@York
// Email: eanton@myseneca.ca
// Program: CPA
#include "SavingsAccount.h"
#include <iomanip>

using namespace std;

namespace ict{ 
	
	// TODO: Implement SavingsAccount member functions here
	//default constructor
	SavingsAccount::SavingsAccount() : Account() {
		//default constructor
	}
	//one argument
	SavingsAccount::SavingsAccount(double funds, double interest) : Account (funds) {
		if (interest > 0) {
			interestRate = interest;
		}
		else {
			interestRate = 0;//safe state 
		}
	}
	//interest rate calcultor
	double SavingsAccount::calculateInterest(){
		double interest = 0;
		double funds;
		funds = getBalance();
		if (interestRate > 0) {
			interest = interestRate;
		}
		if (interest > 0) {
			funds *= interest;
		}
		else {
			funds = 0;
		}
		return funds;
	}
	//shadowing display
	ostream& SavingsAccount::display(ostream& ostr) {
		ostr << fixed;
		ostr << std::setprecision(2) <<"Account type: Saving" << "\n";
		ostr << std::setprecision(2) << "Balance: $ " << getBalance() << "\n";
		ostr << std::setprecision(2) << "Interest Rate (%): " << interestRate * 100 <<"\n";
		return ostr;
	}


}//namespace ict