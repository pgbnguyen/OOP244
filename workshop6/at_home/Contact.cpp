// Contact.cpp
// hasan.murtaza/submit 244_w6_home
// Anton Elistratov
// Seneca@York
// Email: eanton@myseneca.ca
// Program: CPA
#include <iostream>
#include "Contact.h"
#include <cstring>

using namespace std;
namespace communication {
	Contact::Contact() {
		//safe state 
		m_name[0] = '\0';
		m_phoneNumbers = nullptr;
		m_noOfPhoneNumbers = 0;
	}



	Contact::Contact(const char* cName, long long* pNumbers, int num) {
		//safe state 
		m_name[0] = '\0';
		m_phoneNumbers = nullptr;
		m_noOfPhoneNumbers = 0;

		//Allocate mem
		if (pNumbers != nullptr && pNumbers[0] != '\0') {
			m_phoneNumbers = new long long[num];
		}
		//string areaCode;
		int countryCode;
		int areaCode;
		int phoneNumber;
		//another loop
		int x = 0;
		
		//name validation
		if (cName != nullptr && cName[0] != '\0') {
			strncpy(m_name, cName, 20);//0-19
			m_name[20] = '\0'; //20-null

							   // for (int i = 0; i < 20; i++){
							   //     m_name[i] = cName[i];
							   // }

		}
		//phone number validation
		for (int i = 0; i < num; i++) {
			//Designed to validate 11&12 digit numbers as well numbers validation
			if (pNumbers[i] > 10000000000 && pNumbers[i] < 999999999999) {
				//phone number validation
				countryCode = (pNumbers[i] / 10000000000);
				//cout << "Country Code " << countryCode << endl; //text 
				areaCode = ((pNumbers[i] % 10000000000) / 10000000);
				//cout << "Area Code " << areaCode << endl;  //text
				phoneNumber = pNumbers[i] % 10000000;
				//cout << "Phone Number " << phoneNumber << endl; //text

				if (countryCode > 0 && countryCode <= 19 &&
					areaCode > 0 && areaCode < 999 &&
					phoneNumber >= 1000000 && phoneNumber <= 99999999) {
					m_phoneNumbers[x] = pNumbers[i];
					x++;
				}//if (countryCode =< 0 && countryCode >= 9 ...)
			}//if(pNumbers[i] > 10000000000 && pNumbers[i] < 99999999999)

			 //for the display function
			m_noOfPhoneNumbers = x;
		}
	}
	void Contact::display() {
		int countryCode;
		int areaCode;
		int phoneNumber;
		//too lazy to do math with big array numbers!!!
		//so, I just format phoneNumber itself.
		int firstPartOfPhoneNumber;
		int secondPartOfPhoneNumber;

		if (isEmpty()) {
			cout << "Empty contact!" << endl;
		}
		else {
			//name
			cout << m_name << endl;
			//formated phone number
			if (m_phoneNumbers != nullptr && m_phoneNumbers[0] != '\0') {
				for (int ii = 0; ii < m_noOfPhoneNumbers; ii++) {

					countryCode = (m_phoneNumbers[ii] / 10000000000);
					areaCode = ((m_phoneNumbers[ii] % 10000000000) / 10000000);
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
	Contact::~Contact() {
		//dealoc
		delete [] m_phoneNumbers;
		m_phoneNumbers = nullptr;
	}

	bool Contact::isEmpty() const {
		bool empty;//mutator
		if (m_name[0] == '\0' && m_phoneNumbers == nullptr && m_noOfPhoneNumbers == 0) {
			empty = true;
		}
		else {
			empty = false;
		}

		return empty;
	}
	//at_home
	// TODO: copy constructor here
	Contact::Contact(const Contact& other) {
			m_phoneNumbers = nullptr;//safe state
			strncpy(m_name, other.m_name, 20);//0-19
			m_name[20] = '\0'; //20-null
			m_noOfPhoneNumbers = other.m_noOfPhoneNumbers;
		
			if (other.m_phoneNumbers != nullptr && other.m_phoneNumbers[0] != '\0') {
				//m_phoneNumbers = nullptr;
				m_phoneNumbers = new long long[other.m_noOfPhoneNumbers];
				//copy
				for (int i = 0; i < other.m_noOfPhoneNumbers; i += 1) {
					if (other.m_phoneNumbers[i] >= 10000000000 && other.m_phoneNumbers[i] <= 999999999999)
					m_phoneNumbers[i] = other.m_phoneNumbers[i];
				}
			}//if (other.m_phoneNumbers != nullptr && other.m_phoneNumbers[0] != '\0')
	}

	Contact& Contact::operator=(const Contact& other) {
		if (this != &other) {
			strncpy(m_name, other.m_name, 20);//0-19
			m_name[20] = '\0'; //20-null
			m_noOfPhoneNumbers = other.m_noOfPhoneNumbers;
			delete[] m_phoneNumbers;// deallocate dynamic memory
			m_phoneNumbers = nullptr;//safe state
			//allocate new dynamic memory
			if (other.m_phoneNumbers != nullptr) {
				m_phoneNumbers = new long long[m_noOfPhoneNumbers];
	
				for (int i = 0; i < m_noOfPhoneNumbers; i++)
					m_phoneNumbers[i] = other.m_phoneNumbers[i];
			}//if (other.m_phoneNumbers != nullptr)
		}//(this != &other)
		return *this;
	}

	//deallocates dynamic array, allocates it again with +1 space;
	void Contact::addPhoneNumber(long long phoneNumber) {
		//validation

		if (phoneNumber > 10000000000 && phoneNumber < 999999999999) {

			//phone number validation
			int countryCode = (phoneNumber / 10000000000);
			//cout << "Country Code " << countryCode << endl; //text 
			int areaCode = ((phoneNumber % 10000000000) / 10000000);
			//cout << "Area Code " << areaCode << endl;  //text
			int number = phoneNumber % 10000000;
			//cout << "Phone Number " << phoneNumber << endl; //text

			if (countryCode > 0 && countryCode <= 19 &&
				areaCode > 0 && areaCode < 999 &&
				number >= 1000000 && number <= 99999999) {

				//increasing the number of phone numbers by 1(adding a number)
				m_noOfPhoneNumbers += 1;
				long long* temp = new long long[m_noOfPhoneNumbers];//temp array to hold backed up data

				//backing up the original array
				for (int i = 0; i < m_noOfPhoneNumbers - 1; i++) {
					temp[i] = m_phoneNumbers[i];
				}

				//temp[m_noOfPhoneNumbers] = '\0';
				//adding the number
				temp[m_noOfPhoneNumbers - 1] = phoneNumber;

				//deallocating array and allocating it with +1 phone number
				delete[] m_phoneNumbers;
				m_phoneNumbers = nullptr;

				//allocating array again
				m_phoneNumbers = new long long[m_noOfPhoneNumbers];

				//restoring the original data from backup with the new phonenumber
				for (int i = 0; i < m_noOfPhoneNumbers; i += 1) {
					m_phoneNumbers[i] = temp[i];
				}
				delete[] temp;//clearing memory, removing array.
				temp = nullptr;
			}//if (countryCode > 0 && countryCode <= 19 && etc.)
		}//if (phoneNumber > 10000000000 && phoneNumber < 999999999999)
	}
}//communication