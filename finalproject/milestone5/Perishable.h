// Perishable.h
// hasan.murtaza/submit 244_ms5
// Anton Elistratov
// Seneca@York
// Email: eanton@myseneca.ca
// Program: CPA
// BE CAREFUL! THERE IS A BUG WITH I/O FUNCTIONS. 
// MY CODE WENT THROUGH THE SUBMITTER AND I GOT FULL MARKS FOR THIS MILESTONE.
// HOWEVER, KEEP THIS IN MIND.
#ifndef ICT_PERISHABLE_H__
#define ICT_PERISHABLE_H__
//includes
#include "NonPerishable.h"
#include "Date.h"


namespace ict {
	class Perishable : public NonPerishable {
		//private
		Date m_expiry;

	protected:
		char signature()const; //returns 'P'

	public:
		Perishable();//set the m_expiry attribute to date only mode.

		// I/O
		std::fstream& save(std::fstream& file)const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear)const;
		std::istream& read(std::istream& istr);
	};//class Perishable

}//namespace ict


#endif
