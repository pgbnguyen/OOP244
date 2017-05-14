// Perishable.cpp
// hasan.murtaza/submit 244_ms5
// Anton Elistratov
// Seneca@York
// Email: eanton@myseneca.ca
// Program: CPA
// BE CAREFUL! THERE IS A BUG WITH I/O FUNCTIONS. 
// MY CODE WENT THROUGH THE SUBMITTER AND I GOT FULL MARKS FOR THIS MILESTONE.
// HOWEVER, KEEP THIS IN MIND.
#define _CRT_SECURE_NO_WARNINGS
// lib includes
#include <iostream>
#include <cstring>
#include <iomanip>
#include "NonPerishable.h"
#include "Error.h"
#include "Date.h"

#include "Perishable.h"

using namespace std;

namespace ict {
	Perishable::Perishable() {
		m_expiry.dateOnly(true);
	}

	char Perishable::signature()const {
		char sig = 'P';
		return sig; //returns P tag
	}

	// I/O
	std::fstream& Perishable::save(std::fstream& file)const {
		Date _date; // create a Date object

		//NonPerishable::save(file);
		file << signature() << ','
			<< sku() << ','
			<< name() << ','
			<< price() << ','
			<< taxed() << ','
			<< quantity() << ','
		    << m_expiry << endl;

		return file;
	}

	std::fstream& Perishable::load(std::fstream& file) {
		NonPerishable::load(file);

		Date _date;
		_date.dateOnly(true);

		file.ignore();
		file >> _date;
		file.ignore();
		
		m_expiry = _date;
		return file;
	}

	std::ostream& Perishable::write(std::ostream& os, bool linear)const {

		NonPerishable::write(os, linear);

		if (ok() && !linear) {

			os << "Expiry date: ";
			m_expiry.write(os);

			os << endl;
		}

		return os;
	}

	std::istream& Perishable::read(std::istream& istr) {
		
		NonPerishable::read(istr);

		//if there was no mistakes in product description then we can go to the product date
		if (!istr.fail()) {

			std::cout << "Expiry date (YYYY/MM/DD): ";

			m_expiry.read(istr);
			//another validation layer

			int errorType = m_expiry.errCode();
			if (m_expiry.bad()) {
				if (errorType == 1) {
					error("Invalid Date Entry");
					istr.setstate(ios::failbit);
					//input correct here month, day, year validation						
				}//if (!errorType == 1)

				if (errorType == 2) {
					error("Invalid Year in Date Entry");
					istr.setstate(ios::failbit);
				}

				if (errorType == 3) {
					error("Invalid Month in Date Entry");
					istr.setstate(ios::failbit);
				}

				if (errorType == 4) {
					error("Invalid Day in Date Entry");
					istr.setstate(ios::failbit);
				}
			}//end of validation
			//m_err.message("Invalid Taxed Entry, (y)es or (n)o");
		}//if (!istr.fail()) {
		return istr;
	}
}//namespace ict
