// CreditCard.h
// edgardo.arvelaez/submit 244_w3_home
// Anton Elistratov
// Seneca@York
// Email: eanton@myseneca.ca
// Program: CPA
#ifndef CREDITCARD_H
#define CREDITCARD_H

namespace sict {
#define MAX_NAME_LENGTH 40
#define MIN_INST_NUMBER 100
#define MAX_INST_NUMBER 999
#define MIN_EXP_YEAR 2017
#define MAX_EXP_YEAR 2037
#define MIN_CARD_NUMBER 4000000000000000
#define MAX_CARD_NUMBER 4000999999999999

	class CreditCard {
		char m_cardHolderName[MAX_NAME_LENGTH];
		unsigned long long m_CardNumber;
		int m_intitutionCode;
		int m_expiryYear;
		int m_expiryMonth;
		int m_numberInTheBack;
		public:
		void name(const char cardHolderName[]);
		void initialize(unsigned long long creditCardNumber, 
    int instCode, int expiryYear, int expiryMonth,  int numberInTheBack);
		//write 
		void write() const;
		void write(bool displayName) const;
		void write(bool displayName, bool displayCardInfo) const;
		
		bool isValid() const;
		//at_Home
		void writeName() const;
		void writeCardInfo() const;
	};
	
}

#endif
