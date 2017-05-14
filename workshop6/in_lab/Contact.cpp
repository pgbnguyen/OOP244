// Contact.cpp
// hasan.murtaza/submit 244_w6_lab
// Anton Elistratov
// Seneca@York
// Email: eanton@myseneca.ca
// Program: CPA
#include <iostream>
#include "Contact.h"
#include <cstring>

using namespace std;
namespace communication {
    Contact::Contact(){
        //safe state 
        m_name[0] = '\0';
        m_phoneNumbers = nullptr;
        m_noOfPhoneNumbers = 0;
    }



    Contact::Contact(const char* cName, long long* pNumbers, int num){
        //safe state 
        m_name[0] = '\0';
        m_phoneNumbers = nullptr;
        m_noOfPhoneNumbers = 0;

        //Allocate mem
        if (pNumbers != nullptr && pNumbers[0] != '\0'){
            m_phoneNumbers = new long long[num];
        }
        //string areaCode;
        int countryCode;
        int areaCode;
        int phoneNumber;
        //another loop
        int x = 0;

        //name validation
        if (cName != nullptr && cName[0] != '\0'){
            strncpy(m_name, cName, 20);//0-19
            m_name[20] = '\0'; //20-null

            // for (int i = 0; i < 20; i++){
            //     m_name[i] = cName[i];
            // }
      
        }
        //phone number validation
        for (int i = 0; i < num; i++){
            //Designed to validate 11&12 digit numbers as well numbers validation
            if (pNumbers[i] > 10000000000 && pNumbers[i] < 999999999999){
                //phone number validation
                countryCode = (pNumbers[i] / 10000000000);
                //cout << "Country Code " << countryCode << endl; //text 
                areaCode = ( (pNumbers[i]%10000000000) / 10000000);
                //cout << "Area Code " << areaCode << endl;  //text
                phoneNumber = pNumbers[i] % 10000000;
                //cout << "Phone Number " << phoneNumber << endl; //text

                if (countryCode > 0 && countryCode <= 19 &&
                    areaCode > 0 && areaCode < 999 &&
                    phoneNumber >= 1000000 && phoneNumber <= 99999999){
                        m_phoneNumbers[x] = pNumbers[i];     
                        x++;
                    }//if (countryCode =< 0 && countryCode >= 9 ...)
                }//if(pNumbers[i] > 10000000000 && pNumbers[i] < 99999999999)

                //for the display function
                outputNum = x;
            }
    }
    void Contact::display(){
            int countryCode;
            int areaCode;
            int phoneNumber;
            //too lazy to do math with big array numbers!!!
            //so, I just format phoneNumber itself.
            int firstPartOfPhoneNumber;
            int secondPartOfPhoneNumber;

            if (isEmpty()){
                cout << "Empty contact!" << endl;
            } else {
                //name
                 cout << m_name << endl;
                //formated phone number
                if (m_phoneNumbers != nullptr && m_phoneNumbers[0] != '\0'){
                    for (int ii = 0; ii < outputNum; ii++){

                        countryCode = (m_phoneNumbers[ii] / 10000000000);
                        areaCode = ( (m_phoneNumbers[ii]%10000000000) / 10000000);
                        phoneNumber = m_phoneNumbers[ii] % 10000000;

                        //styling @phoneNumber
                        firstPartOfPhoneNumber = phoneNumber / 10000;
                        secondPartOfPhoneNumber = phoneNumber % 10000;

                        cout << "(+" << countryCode << ") " << areaCode << " " << firstPartOfPhoneNumber << "-" << secondPartOfPhoneNumber << endl;
                    }
                }
            } //if (isEmpty())        
    }

    //destructor
    Contact::~Contact(){
        //dealoc
        delete [] m_phoneNumbers;
    }

    bool Contact::isEmpty() const{
        bool empty;//mutator
        if ( m_name[0] == '\0' && m_phoneNumbers == nullptr && m_noOfPhoneNumbers == 0){
            empty = true;
        } else {
            empty = false;
        }

        return empty;
    }



// s = to_string(12412412412);
// cout << s << endl; 
// cout << s.substr(3,3);
// cout << s.length() <<endl;

// strcpy(m_name, name, 20);
// m_name[21] = '\0';

}//communication