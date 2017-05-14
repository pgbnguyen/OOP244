// Error.h
// hasan.murtaza/submit 244_ms4
// Anton Elistratov
// Seneca@York
// Email: eanton@myseneca.ca
// Program: CPA
// compilation safegaurds
#ifndef ICT_ERROR_H_
#define	ICT_ERROR_H_

#include <iostream>
namespace ict {
   class Error {
      char* m_message;
   public:
   // constructors
	   //Sets the m_message member variable to nullptr.
	   Error();
	   //Sets the m_message member variable to nullptr and then uses the message() setter member function to set the error message to the errorMessage argument.
	   Error(const char* errorMessage);
	   //A deleted copy constructor to prevent an Error object to be copied.
	   Error(const Error& em) = delete; //no implementation needed
   // destructor

   // deleted constructor and operator=
	   //A deleted assignment operator overload to prevent an Error object to be assigned to another.
	   Error& operator=(const Error& em) = delete;//no implementation needed
   // operator= for c-style strings
	   void operator=(const char* errorMessage);
   // methods
	   virtual ~Error(){ delete [] m_message;};
	   void clear();
	   bool isClear()const;
	   void message(const char* value);
	   operator const char*() const;
	   operator bool()const;
   // cast overloads
	   friend std::ostream& operator<<(std::ostream& ostr, const Error& em);
	   char* getError() const { return m_message; }
   };
   // operator << overload prototype for cout
 
   std::ostream& operator<<(std::ostream& ostr, const Error& em);
}
#endif //ICT_ERROR_H_


