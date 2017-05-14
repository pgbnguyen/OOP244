// SavingsAccount.h
// hasan.murtaza/submit 244_w8_lab
// Anton Elistratov
// Seneca@York
// Email: eanton@myseneca.ca
// Program: CPA
#ifndef ICT_SAVINGSACCOUNT_H__
#define ICT_SAVINGSACCOUNT_H__

#include "Account.h"

using namespace std;

namespace ict{
	class SavingsAccount : public Account{
		private:
    		double interestRate; // interest rate (percentage)
		public:

			// TODO: put prototypes here
			SavingsAccount();
			SavingsAccount(double funds, double interest);
			double calculateInterest();
			//shadowing display
			ostream& display(ostream& ostr);
   };
};
#endif
