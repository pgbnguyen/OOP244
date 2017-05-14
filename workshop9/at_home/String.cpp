// String.cpp
// hasan.murtaza/submit 244_w9_home
// Anton Elistratov
// Seneca@York
// Email: eanton@myseneca.ca
// Program: CPA
#include <cstring>
#include <iostream>
#include "String.h"


using namespace std;

namespace sict {


	//////////////////////////////////////////////////////
	//
	// Default Constructor
	// String::String(int capacity);
	//
	// initialize the string with an internal buffer capacity of 
	// "capacity." 
	// default capacity is 1 (minimum needed for an empty string)
	//
	// 
	String::String(int capacity) {
		m_capacity = capacity;
		m_pString = new char[m_capacity];
		m_pString[0] = '\0'; //clear the string
	}

	//////////////////////////////////////////////////////
	//
	// String::String(const char* p, int capacity);
	//
	// Construct a String from a char array
	// Should initialize the internal buffer to at least 
	// the length of the string need to hold pSource, 
	// or capacity, whichever is greater.
	//
	//								a         b
	String::String(const char* pSource, int capacity) {

		//unsigned warning
		int capacity2 = capacity;
		int pSourceLen = strlen(pSource) + 1;

		/*//init m_capacity
		if (capacity >= strlen(pSource) + 1) { m_capacity = capacity; }
		else { m_capacity = strlen(pSource) + 1; }*/

		//init m_capacity
		if (capacity2 >= pSourceLen + 1) { m_capacity = capacity2; }
		else { m_capacity = pSourceLen + 1; }

		//init the internal buffer
		m_pString = new char[m_capacity];

		//copy pSource to m_pString
		strcpy(m_pString, pSource);

	}

	//////////////////////////////////////////////////////
	//
	// String::String(const String &s, int capacity);
	//
	// Copy constructor
	//
	// Construct a String from another String
	//
	// 
	String::String(const String& other, int capacity)
	{
		//init m_capacity
		if (capacity >= other.length() + 1) { m_capacity = capacity; }
		else { m_capacity = other.length() + 1; }

		//init the internal buffer
		m_pString = new char[m_capacity];

		//copy pSource to m_pString
		strcpy(m_pString, other.m_pString);


	}



	//////////////////////////////////////////////////////
	//
	// String::resize(int newsize)
	//
	// resize the internal buffer to the value given
	// do NOT shrink the string buffer smaller than 
	// that needed to hold the existing string!
	// (length + 1);
	//    
	void String::resize(int newsize)
	{
		//init m_capacity
		if (newsize >= length() + 1) { m_capacity = newsize; }
		else { m_capacity = length() + 1; }

		//creating temp array && back up data
		char* temp = new char[m_capacity];
		strcpy(temp, m_pString);

		//dealloc m_pString
		delete[] m_pString;
		m_pString = nullptr;

		//alloc m_pString with new capacity
		m_pString = new char[m_capacity];

		//restore data
		strcpy(m_pString, temp);
	}


	//////////////////////////////////////////////////////
	//
	// String::operator=(const String& other)
	// 
	// Assignment operator
	// copy string "other" to this object
	//   
	// 
	String& String::operator=(const String& other)
	{
		
		if (this != &other)
		{
			//dealloc
			delete[] m_pString;
			m_pString = nullptr;
			m_capacity = 0;

			//alloc m_capacity
			if (other.m_capacity >= other.length() + 1) { m_capacity = other.m_capacity; }
			else {
				m_capacity = other.length() + 1;
			}

			//alloc m_pString with new capacity
			m_pString = new char[m_capacity];

			//copy
			strcpy(m_pString, other.m_pString);
		}

		return *this;
	}


	//////////////////////////////////////////////////////
	//
	// String::~String
	// 
	// destructor
	// 
	// clean up the internal string buffer  
	// 
	String::~String()
	{
		delete[] m_pString; //dealloc dynamic memmory
	}

	//////////////////////////////////////////////////////
	//
	// String::length()
	// 
	// return the length of the string
	// 
	// 
	int String::length() const
	{
		return strlen(m_pString);
	}


	//////////////////////////////////////////////////////
	//
	// String::operator const char*() const
	// 
	// convert the String to a char*
	// 
	// 
	String::operator const char *() const
	{
		return m_pString;
	}


	//////////////////////////////////////////////////////
	//
	// String::empty()
	// 
	// 
	// returns true if the string is empty
	// i.e. either the first char is \0, or 
	// length is 0.
	bool String::empty() const
	{
		return (length() == 0 || m_pString[0] == '\0');
	}

	//////////////////////////////////////////////////////
	//
	// String::operator bool()
	// 
	// same as empty(), just wrapped in an operator
	// 
	//     
	String::operator bool() const
	{
		return !empty(); //bool operator
	}


	//////////////////////////////////////////////////////
	//
	// String::operator==(const String& s2) const
	// 
	// returns true if *this == s2.
	// You can use the strcmp function to check if 
	// two strings are equal, or write your own
	// treating the string as a char-array
	//      
	bool String::operator==(const String& s2) const
	{
		return (std::strcmp(m_pString, s2) == 0);
	}


	//////////////////////////////////////////////////////
	//
	// String::operator+=(const String& s2)
	// 
	// Concatenates s2 to the end of *this
	//
	// implements *this = (*this + s2)
	// return *this
	// 
	// 
	String& String::operator+=(const String& s2)
	{
		*this = (*this + s2);
		return *this;
	}



	//////////////////////////////////////////////////////
	//
	// String::operator+(const String& s2) const
	// 
	// implements the operator (*this + s2)
	// returns the expression
	// DOES NOT MODIFY *this
	// 
	// 
	String String::operator+(const String& s2) const
	{
		//allocatin string size for temp
		int tempStringSize = length() + s2.length() + 1;

		//allocating temp string
		char* temp = new char[tempStringSize];

		//copying strings to temp
		strcpy(temp, m_pString);
		strcat(temp, s2.m_pString);

		return temp;
	}

	//////////////////////////////////////////////////////
	//
	// String::operator+=(char c)
	// 
	// Adds a single char c to the end of the string in *this
	// Grows the string buffer if necessary.
	//  
	String& String::operator+= (char c)
	{
		//alloc m_capacity
		if (m_capacity >= length() + 2) {  }
		else { m_capacity = length() + 2; }
	
		//create static string with c variable
		char single_String[2];
		single_String[0] = c;
		single_String[1] = '\0';

		//resizing the array
		resize(m_capacity);		

		//adding c character to the main string
		std::strcat(m_pString, single_String);

		return *this;
	}



	//////////////////////////////////////////////////////
	//
	// String::substr
	// 
	// Returns a substring of the current string. In case of error
	// return an empty String() object instead.
	// 
	// return the string slice starting at index, at most len characters
	// 
	// both index and len have to lie inside the string. If they do not, then 
	// that is an error
	// 
	/*String String::substr(int index, int len) const
	{
		//LMAO AOY
	}
	*/
	//////////////////////////////////////////////////////
	//
	// operator<<
	// 
	// Print the string to the output stream
	// 
	// clean up the internal string buffer  
	// 
	std::ostream& operator<<(std::ostream& ostream, const String &s)
	{
		ostream << s.getString();
		ostream.clear();
		return ostream;
	}

	//////////////////////////////////////////////////////
	//
	// operator>>
	// 
	// Input a string from an input stream into the String s
	// 
	// Note: the input can be ANY length in character. You will need to 
	// read it one char at a time. 
	// 
	std::istream& operator>>(std::istream& istream, String &s)
	{
		s = "";
		char tempC = 0;
		do
		{
			tempC = istream.get();
			if (tempC != '\n')
			{
				s += tempC;
			}
			else
				break;
		} while (1);
		return istream;
	}


}