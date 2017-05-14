// NonPerishable.cpp
// hasan.murtaza/submit 244_ms4
// Anton Elistratov
// Seneca@York
// Email: eanton@myseneca.ca
// Program: CPA
#define _CRT_SECURE_NO_WARNINGS
// lib includes
#include <iostream>
#include <cstring>
#include <iomanip>
#include "NonPerishable.h"
#include "Error.h"

using namespace std;

namespace ict {
	bool NonPerishable::ok() const {
		return m_err;
	}

	void NonPerishable::error(const char* message) {
		m_err.message(message);
	}

	char NonPerishable::signature()const {
		char sig = 'N';
		return sig; //returns N tag
	}

	std::fstream& NonPerishable::save(std::fstream& file)const {
		//writing to file
		file << signature() << ','
			<< sku() << ','
			<< name() << ','
			<< price() << ','
			<< taxed() << ','
			<< quantity();

		return file;
	}

	std::fstream& NonPerishable::load(std::fstream& file) {
		char _sku[100];   //stores sku
		char _name[100];  //stores name
		double _price;    //stores price
		bool _taxed;      //stores tax
		int _quantity;    //stores quantity

		//first tag either 'N' or 'P' with a comma is ignored in main function. Thus, I don't read it!
		//reading into variables
		file.getline(_sku, 100, ',');
		file.getline(_name, 100, ',');
		file >> _price;
		file.ignore();
		file >> _taxed;
		file.ignore();
		file >> _quantity;
		file.ignore();

		// Using setters, to set variables
		// defined in Item.h
		sku(_sku);            //sets barcode
		name(_name);          //sets name
		price(_price);        //sets price
		taxed(_taxed);        //sets taxed flag
		quantity(_quantity);  //sets quantity

		return file;
	}


	ostream& NonPerishable::write(ostream& ostr, bool linear)const {
		//MAX_SKU_LEN
		if (ok()) {
			//checking linear bool
			// (linear == true)  - outputs everything in one line
			// (linear == false) - outputs everything in a column 

			// one line output (linear == 0)
			if (linear) {
					 // creating & styling one line output

				
				ostr //adding to output stream
				// barcode
				<< std::setfill(' ') << std::left << std::setw(MAX_SKU_LEN) << Item::sku() << '|'
				// name
				<< std::setw(20) << Item::name() << '|'
				// price
				<< std::right << std::setw(7) << std::fixed << std::showpoint << std::setprecision(2) << Item::price() << '|';

				// taxed
				// using signature() to identify the type of item
				if (Item::taxed()) {
					ostr << " T";
					ostr << signature();
					ostr << "|";
				}
				else {
					ostr << "  " << signature();
					ostr << "|";
				}

				
				ostr 
				// quantity
				<< std::setw(4) << Item::quantity() << '|'
				// total cost
				<< std::right << std::setw(9) << std::fixed << std::showpoint << std::setprecision(2) << Item::cost() * Item::quantity() << '|';

			}//if (linear)

	
			// outputs everyting in a column
			else {
				ostr << "Name:" << std::endl << Item::name() << std::endl
					<< "Sku: " << Item::sku() << std::endl
					<< "Price: " << Item::price() << std::endl;

				// taxed
				if (taxed()) {
					ostr << "Price after tax: " << (TAX * Item::price()) + Item::price() << std::endl;
				}
				else {
					ostr << "Price after tax: N/A" << std::endl;
				}


				ostr << "Quantity: " << Item::quantity() << std::endl
					 << "Total Cost: " << Item::cost() * Item::quantity() << std::endl;
			}//else (!linear)
		}// if (ok())

		else {
			ostr << m_err.getError(); // send error message to output stream
		}// else (!ok())

		return ostr;
	}

	std::istream& NonPerishable::read(std::istream& is) {
		char _sku[100];   //stores sku
		char _name[100];  //stores name
		double _price;    //stores price
		char _taxed;      //stores tax
		int _quantity;    //stores quantity
		
		m_err.clear();//to clean previous errors

		// istream == true
		if (!is.fail()) {
			// styling istream for user input

			// we only have two case scenarios so I don't implement validation
			// item entry
			if (signature() == 'N') {
				std::cout << "Item Entry:" << endl; // NonPerishable
			}
			else {
				std::cout << "Perishable Item Entry:" << endl; // Perishable
			}

			// barcode
			std::cout << "Sku: ";
			is >> _sku;

			// barcode validation
			if (!is.fail()) {
				sku(_sku);
			}//if (!is.fail()) for barcode


			// name
			std::cout << "Name:" << endl;
			is >> _name;

			// name validation
			if (!is.fail()) {
				Item::name(_name);
			}//if (!is.fail()) for name


			// price input & validation
			if (m_err.isClear()) {
				std::cout << "Price: ";
				is >> _price;
				//price
				if (!is.fail()) {
					price(_price);
				}// if (!is.fail()) for price
				else {
					error("Invalid Price Entry");
					is.setstate(ios::failbit);
				}//else (is.fail()) for price
			}//if (m_err.isClear())

			
			// taxed input & validation
			if (m_err.isClear()) {
				std::cout << "Taxed: ";
				is >> _taxed;
				//taxed
				if (!is.fail()) {
					if (_taxed == 'y') {
						taxed(true);
					}
					else if (_taxed == 'n') {
						taxed(false);
					}
					else {
						error("Invalid Taxed Entry, (y)es or (n)o");
						is.setstate(ios::failbit);
					}//wrong letter or else
				}
				else {
					error("Invalid Taxed Entry, (y)es or (n)o");
					is.setstate(ios::failbit);
				}//wrong input
			}//if (m_err.isClear()) for taxed


			 // quantity input & validation
			if (m_err.isClear()) {
				std::cout << "Quantity: ";
				is >> _quantity;
				//quantity
				if (!is.fail()) {
					quantity(_quantity);
				}
				else {
					error("Invalid Quantity Entry");
					is.setstate(ios::failbit);
				}
			}//if (!is.fail()) for quantity
		}//if (m_err.isClear())

		return is;
	}
}// ict namespace