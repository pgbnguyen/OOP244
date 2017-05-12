// edgardo.arvelaez/submit 244_w3_lab
// Anton Elistratov
// Seneca@York
// Email: eanton@myseneca.ca
// Program: CPA
#include "CreditCard.h"
#include <iostream>
#include <cstring>

using namespace std;

namespace sict {

    void CreditCard::name(const char cardHolderName[])
    {
            strcpy(m_cardHolderName, cardHolderName);
    }

    void CreditCard::initialize(unsigned long long creditCardNumber, 
    int instCode, int expiryYear, int expiryMonth,  int numberInTheBack)
    {       
        m_CardNumber = creditCardNumber;
        m_intitutionCode = instCode;
        m_expiryYear = expiryYear;
        m_expiryMonth = expiryMonth;
        m_numberInTheBack = numberInTheBack;
    }
    void CreditCard::write() const{
        if(isValid()){
            cout << "Cardholder: " << m_cardHolderName <<endl;
            cout << "Card Number: "<< m_CardNumber<< endl;
            cout << "Institution: "<< m_intitutionCode<< endl;
            cout << "Expires: "<< m_expiryMonth <<"/"<<m_expiryYear<< endl;
            cout << "Number at the back: "<< m_numberInTheBack;
        }

    }
    // edgardo.arvelaez/submit 244_w3_lab

    bool CreditCard::isValid() const{
        bool valid;
            
            if (m_cardHolderName[0] != 0 && 
            m_CardNumber >= MIN_CARD_NUMBER && m_CardNumber <= MAX_CARD_NUMBER &&
            m_intitutionCode >= MIN_INST_NUMBER && m_intitutionCode <= MAX_INST_NUMBER &&
            m_expiryYear >= MIN_EXP_YEAR && m_expiryYear <= MAX_EXP_YEAR &&
            m_expiryMonth >= 1 && m_expiryMonth <= 12 && 
            m_numberInTheBack > 0 && m_numberInTheBack <= 999){
                valid = true;
            } else {
                valid = false;
            }
            return valid;
    }

}
