// Item.h
// hasan.murtaza/submit 244_ms5
// Anton Elistratov
// Seneca@York
// Email: eanton@myseneca.ca
// Program: CPA
// BE CAREFUL! THERE IS A BUG WITH I/O FUNCTIONS. 
// MY CODE WENT THROUGH THE SUBMITTER AND I GOT FULL MARKS FOR THIS MILESTONE.
// HOWEVER, KEEP THIS IN MIND.
#ifndef ICT_ITEM_H__
#define ICT_ITEM_H__
// inlcude PosIO and POS header files
#include "POS.h"
#include "PosIO.h"

namespace ict{
  // class Item
	class Item: public PosIO { // inherited from PosIO
		char m_sku[MAX_SKU_LEN + 1];// the SKU barcode
		char* m_name;// Item�s name
		double m_price;// Item�s Price
		bool m_taxed;// this variable is true if this item is taxed, false otherwise
		int m_quantity;// current quantity
	public:
		// constructors
		Item();// no argument, default
		Item(const char*, const char*, double, bool = true);// four argument
		Item(const Item& other);// copy

		// virtual destructor
		virtual ~Item() { delete[] m_name; }

		// operator=
		Item& operator=(const Item& other);

		// mutators/setters
		void sku(const char*);
		void price(double);
		void name(const char*);
		void taxed(bool);
		void quantity(int);

		// constant queries/accessors/getters
		const char* sku() const; //returns the address of an unmodifiable character string
		double price() const;// returns a double
		char* name() const; //returns the address of an unmodifiable character string
		int taxed() const; // returns a bool
		int quantity() const;// returns an integer

		double cost() const; // return (m_price = (m_taxed) ? m_price *= TAX + 1 : m_price);
		bool isEmpty() const; // return true if the Item is in a safe empty state.

		// operators
		bool operator==(const char*);
		int operator+=(int);
		int operator-=(int);

	};// class Item
	  
  // non-member
  // operator += 
  double operator+=(double& d, const Item& I);
  // operator << and operator >>
  std::ostream& operator<<(std::ostream& ostr, const Item& rightHand);// posIO.h
  std::istream& operator>>(std::istream& is, Item& rightHand);// posIO.h
}
#endif