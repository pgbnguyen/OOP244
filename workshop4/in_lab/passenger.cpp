// passenger.cpp
// edgardo.arvelaez/submit 244_w4_lab
// Anton Elistratov
// Seneca@York
// Email: eanton@myseneca.ca
// Program: CPA
// TODO: add your headers here
#include "passenger.h"
#include <iostream>
#include <cstring>
// TODO: add the namespaces that you will be using here
using namespace std;
// TODO: holiday namespace here
namespace holiday{
    // TODO: add the default constructor here
	Passenger::Passenger(){
		m_name[0] = '\0';
        m_destination[0] = '\0';
        m_departureYear = 0;
        m_departureMonth = 0;
        m_departureDay = 0;
	}
    // TODO: add the constructor with 2 parameters here
	Passenger::Passenger(const char* pName,const char* pDestination){
		//safe state
		m_name[0] = '\0';
        m_destination[0]= '\0';
        m_departureYear = 0;
        m_departureMonth = 0;
        m_departureDay = 0;
		//validation
		if ( pDestination != nullptr && pName != nullptr && 
			 pDestination[0] != 0 && pName[0] != 0){
				strcpy(m_name,pName);
				strcpy(m_destination,pDestination);
				m_departureYear = 2017;								
				m_departureMonth = 7;
				m_departureDay = 1;
		}
	}
    // TODO: add the canTravelWith(...) function here
	bool Passenger::canTravelWith(const Passenger& pPassenger) const{
		bool _together;
		if( m_departureYear == pPassenger.m_departureYear && 
		    m_departureMonth == pPassenger.m_departureMonth &&
			m_departureDay == pPassenger.m_departureDay &&
			strcmp(m_destination, pPassenger.m_destination) == 0) {		
				_together = true;			
			} else {
				_together = false;
			}
			return _together;
	}
    // TODO: add the isEmpty() function here
	bool Passenger::isEmpty() const{
		bool _empty;
		if (m_name[0] == '\0' &&
        m_destination[0] == '\0' &&
        m_departureYear == 0 &&
        m_departureMonth == 0 &&
        m_departureDay == 0){
			_empty = true;
		} else {
			_empty = false;
		}
		return _empty;
	}
    // below is the member function already provided
    // TODO: read it and understand how it accomplishes its task
	void Passenger::display(bool nameOnly) const
	{
		if (false == this->isEmpty())
		{
			cout << this->m_name;
			if (false == nameOnly)
			{
				cout << " will travel to " << this->m_destination << ". "
				     << "The journey will start on "
				     << this->m_departureYear << "-"
					 << this->m_departureMonth << "-"
					 << this->m_departureDay
				     << "." << endl;
			}
		}
		else
		{
			cout << "Invalid passenger!" << endl;
		}
	}

}//holiday