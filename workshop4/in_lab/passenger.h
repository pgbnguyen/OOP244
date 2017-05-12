// passenger.h
// edgardo.arvelaez/submit 244_w4_lab
// Anton Elistratov
// Seneca@York
// Email: eanton@myseneca.ca
// Program: CPA
//TODO: add header guards here
#ifndef _PASSENGER_H_
#define _PASSENGER_H_
// TODO: holiday namespace here
namespace holiday{
    // TODO: declare the class Passenger here
    class Passenger {
        // TODO: add the class the attributes,
        char m_name[32];
        char m_destination[32];
        int m_departureYear;
        int m_departureMonth;
        int m_departureDay;
    public:       
        //       the member function already provided,
        void display(bool onlyNames = false) const;
        //       and the member functions that you must implement
        Passenger();
        Passenger(const char* pName,const char* pDestination);
        bool isEmpty() const;
        bool canTravelWith(const Passenger&) const;
    };
}  
#endif