// Item.cpp
// hasan.murtaza/submit 244_ms5
// Anton Elistratov
// Seneca@York
// Email: eanton@myseneca.ca
// Program: CPA
// BE CAREFUL! THERE IS A BUG WITH I/O FUNCTIONS. 
// MY CODE WENT THROUGH THE SUBMITTER AND I GOT FULL MARKS FOR THIS MILESTONE.
// HOWEVER, KEEP THIS IN MIND.
#define _CRT_SECURE_NO_WARNINGS  
// Lib includes
#include <iostream>
#include <cstring>

// inlcude Item and POS header files
#include "Item.h"
#include "POS.h"


using namespace std;
namespace ict{
  // class Item implementaion
	//constructors

	Item::Item() {
		m_sku[0] = '\0';
		m_name = nullptr;
		m_price = 0;
		m_taxed = false;
		m_quantity = 0;
	}// no argument, default

	
	Item::Item(const char* _sku, const char* _name, double _price, bool _taxed) {
		// using mutators to construct the object
		sku(_sku);
		name(_name);
		price(_price);
		taxed(_taxed);
		quantity(0);//sets to zero

	}// four argument

	Item::Item(const Item& other) {
		// using mutators to set the object
		sku(other.m_sku);
		name(other.m_name);
		price(other.m_price);
		taxed(other.m_taxed);
		quantity(other.m_quantity);
	}// copy constructor

	// operator=
	Item& Item::operator=(const Item& other) {
		//not other and other is not empty
		if (this != &other && !other.isEmpty()) {
			sku(other.m_sku);
			name(other.m_name);
			price(other.m_price);
			taxed(other.m_taxed);
			quantity(other.m_quantity);
		}
		return *this;//returning item
	}

	// mutators/setters
	void Item::sku(const char* _sku) {
		strncpy(m_sku, _sku, MAX_SKU_LEN);
	}

	void Item::price(double _price) {
		m_price = _price;
	}

	void Item::name(const char* _name) {
		if (_name != nullptr){
			m_name = new (std::nothrow) char[strlen(_name) + 1];		 
			strncpy(m_name, _name, strlen(_name) + 1);
		}
	}//void Item::name(const char* _name)

	void Item::taxed(bool _taxed) {
		m_taxed = _taxed;
	}

	void Item::quantity(int _quantity) {
		m_quantity = _quantity;
	}

	// constant queries/accessors/getters
	const char* Item::sku() const {
		return m_sku;
	}
	double Item::price() const {
		return m_price;
	}
	char* Item::name() const {
		return m_name;
	}
	int Item::taxed() const {
		return m_taxed;
	}
	int Item::quantity() const {
		return m_quantity;
	}

	double Item::cost() const {
		double _price = m_price;
		if (m_taxed) {
			_price *= TAX + 1;
		}
		return _price;
	}
	bool Item::isEmpty() const {
		bool empty;
		if (m_sku[0] == '\0' &&
			m_name == nullptr &&
			m_price == 0 &&
			m_taxed == false &&
			m_quantity == 0) {
			empty = true;
		}
		else {
			empty = false;
		}
		return empty;
	}

	// operators
	bool Item::operator==(const char* _sku) {
		return strcmp(m_sku, _sku) == 0;
	}

	int Item::operator+=(int _quantity) {
		return m_quantity += _quantity;
	}

	int Item::operator-=(int _quantity) {
		return m_quantity += (-1 * _quantity);
	}

	// non-member

	// operator += 
	double operator+=(double& d, const Item& I) {
		d += I.cost() * I.quantity();
		return d;
	}

	// operator << and operator >>
	std::ostream& operator<<(std::ostream& ostr, const Item& rightHand) {
		return rightHand.write(ostr, true);
	}


	std::istream& operator>>(std::istream& is, Item& rightHand) {
		return rightHand.read(is);
	}


}//namespace ict