// w3_in_lab.cpp
// edgardo.arvelaez/submit 244_w3_lab
// Anton Elistratov
// Seneca@York
// Email: eanton@myseneca.ca
// Program: CPA
#include <iostream>
using namespace std;
#include "CreditCard.h"
using namespace sict;

int main() {
	CreditCard myCC;
	char name[41];
	int instCode;
	int expiryYear;
	int expiryMonth;
	unsigned long long cardNumber;
	int backNumber;
	char slash;

	cout << "Credit Card app" << endl <<
		"===================" << endl << endl;
	cout << "Please enter your name: ";
	cin >> name;

	do {
		cout <<
			"Please enter your credit card number, institution code, " <<
			"expiry date, and security number as follows: " <<
			"4000123412341234 999 12/1234 999" << endl << "> ";

		cin >> cardNumber >> instCode >> expiryMonth >> slash >> expiryYear >>
			backNumber;

		cout << endl;
		myCC.name(name);
		myCC.initialize(cardNumber, instCode, expiryYear, expiryMonth, backNumber);
		myCC.write();
	} while (!myCC.isValid() && cout << "Invalid input" << endl);
	cout << endl << "Thank you!" << endl;
	return 0;
}