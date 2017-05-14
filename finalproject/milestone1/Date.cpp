// Date.cpp
// hasan.murtaza/submit 244_ms1
// Anton Elistratov
// Seneca@York
// Email: eanton@myseneca.ca
// Program: CPA
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
using namespace std;
#include "Date.h"
#include "POS.h"


namespace ict{
  void Date::set(){
    time_t t = time(NULL);
    tm lt = *localtime(&t);
    m_day = lt.tm_mday;
    m_mon = lt.tm_mon + 1;
    m_year = lt.tm_year + 1900;
    if (dateOnly()){
      m_hour = m_min = 0;
    }
    else{
      m_hour = lt.tm_hour;
      m_min = lt.tm_min;
    }
  }

  int Date::value()const{
    return m_year * 535680 + m_mon * 44640 + m_day * 1440 + m_hour * 60 + m_min;
  }

  int Date::mdays()const{
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
    int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
    mon--;
    return days[mon] + int((mon == 1)*((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
  }

  //no argument constructor
  Date::Date() {
	  m_dateOnly = false;
	  set();
  }
  //3 argument constructor
  Date::Date(int year, int mon, int day) {
	  m_dateOnly = true;
	  //setting variables;
	  m_year = year;
	  m_mon = mon;
	  m_day = day;
	  //not going to be displayed
	  m_hour = 0;
	  m_min = 0;
	  
	  //error code
	  m_readErrorCode = 0;
  }
  //5 argument constructor added
  Date::Date(int year, int mon, int day, int hour, int min ) {
	  m_dateOnly = false;

	  //setting variables
	  m_year = year;
	  m_mon = mon;
	  m_day = day;
	  m_hour = hour;
	  m_min = min;

	  //error code
	  m_readErrorCode = 0;
  }
  //void @errCode(int errorCode);
  //Sets the m_readErrorCode member variable to one of the possible values listed above.
  void Date::errCode(int errorCode) {
	  m_readErrorCode = errorCode;
  }

  //void @set(int year, int mon, int day, int hour, int min)
  //Sets the member variables to the corresponding arguments and then sets the m_readErrorCode to NO_ERROR.
  void Date::set(int year, int mon, int day, int hour, int min) {
	  
	  //setting variables
	  m_year = year;
	  m_mon = mon;
	  m_day = day; 
	  m_hour = hour;
	  m_min = min;

	  //error code
	  m_readErrorCode = NO_ERROR;
  }
  
  //Public member-functions (methods) and operators
  //
  bool Date::operator==(const Date& D)const {
	  return (this->value() == D.value());
  }
  bool Date::operator!=(const Date& D)const {
	  return (this->value() != D.value());
  }
  bool Date::operator<(const Date& D)const {
	  return (this->value() < D.value());
  }
  bool Date::operator>(const Date& D)const {
	  return (this->value() > D.value());
  }
  bool Date::operator<=(const Date& D)const {
	  return (this->value() <= D.value());
  }
  bool Date::operator>=(const Date& D)const {
	  return (this->value() >= D.value());
  }
  
  //Accessor or getter member functions (methods):
  //Returns the m_readErrorCode value.
  int Date::errCode()const {
	  return m_readErrorCode;
  }
  //Returns true if m_readErrorCode is not equal to zero.
  bool Date::bad()const {
	  bool error;

	  if (m_readErrorCode != 0) {
		  error = true;
	  }
	  else {
		  error = false;
	  }

	  return error;
  }
  //Returns the m_dateOnly attribute.
  bool Date::dateOnly()const {
	  return m_dateOnly;
  }
  //Sets the m_dateOnly attribute to the �value� argument.Also if the �value� is true, then it will set m_hour and m_min to zero.
  void Date::dateOnly(bool value) {
	  m_dateOnly = value;

	  if (m_dateOnly) {
		  m_hour = 0;
		  m_min = 0;
	  }
  }

  //istream  and ostream read and write methods
  //Reads the date in the following format: YYYY/MM/DD (e.g. 2015/03/24) from the console if _date only is true
  std::istream& Date::read(std::istream& is) {
	  if (m_dateOnly) {
		  //date only
		  is >> m_year;//year
		  if (is.get() != '/') {
			  m_readErrorCode = CIN_FAILED;
			  return is;
		  }
		  is >> m_mon;//month
		  if (is.get() != '/') {
			  m_readErrorCode = CIN_FAILED;
			  return is;
		  }
		  is >> m_day; //day
		  //validate();
	  }
	  else {
		  //full date
		  is >> m_year;
		  if (is.get() != '/') {
			  m_readErrorCode = CIN_FAILED;
			  return is;
		  }
		  is >> m_mon;
		  if (is.get() != '/') {
			  m_readErrorCode = CIN_FAILED;
			  return is;
		  }
		  is >> m_day;
		  if (is.get() != ',') {
			  m_readErrorCode = CIN_FAILED;
			  return is;
		  }
		  is >> m_hour;
		  if (is.get() != ':') {
			  m_readErrorCode = CIN_FAILED;
			  return is;
		  }
		  is >> m_min;
	  }
	  
	  if (m_year < MIN_YEAR || m_year > MAX_YEAR) {
		  m_readErrorCode = YEAR_ERROR;
	  }
	  else if (m_mon < 1 || m_mon > 12) {
		  m_readErrorCode = MON_ERROR;
	  }
	  else if (m_day < 1 || m_day > mdays()) {
		  m_readErrorCode = DAY_ERROR;
	  }
	  else if (m_hour < 0 || m_hour > 23) {
		  m_readErrorCode = HOUR_ERROR;
	  }
	  else if (m_min < 0 || m_min > 59) {
		  m_readErrorCode = MIN_ERROR;
	  }
	  else {
		  m_readErrorCode = NO_ERROR;
	  }


	  //validate
	  return is;
  }

  std::ostream& Date::write(std::ostream& ostr)const {
	  if (m_dateOnly) {
		  //ostr << m_year << "/" << m_mon  << "/" << m_day;
		  ostr << m_year << "/";
		  //month format
		  if (m_mon > 0 && m_mon < 10) {
			  ostr << "0" << m_mon << "/";
		  }
		  else {
			  ostr << m_mon << "/";
		  }
		  //day format
		  if (m_day > 0 && m_day < 10) {
			  ostr << "0" << m_day;
		  }
		  else {
			  ostr << m_day;
		  }

		//ostr << m_year << "/" << m_mon  << "/" << m_day;

	  }
	  else {
		  ostr << m_year << "/";
		  //ostr << m_year << "/" << m_mon << "/" << m_day << ", " << m_hour << ":" << m_min;
		  if (m_mon > 0 && m_mon < 10) {
			  ostr << "0" << m_mon << "/";
		  }
		  else {
			  ostr << m_mon << "/";
		  }
		  //day format
		  if (m_day > 0 && m_day < 10) {
			  ostr << "0" << m_day << ", ";
		  }
		  else {
			  ostr << m_day << ", ";
		  }
		  //hour format
		  if (m_hour > 0 && m_hour < 10) {
			  ostr << "0" << m_hour << ":";
		  }
		  else {
			  ostr << m_hour << ":";
		  }
		  //minute format
		  if (m_min > 0 && m_min < 10) {
			  ostr << "0" << m_min;
		  }
		  else {
			  ostr << m_min;
		  }
	  }
	  return ostr;
  }

  //helpers
  std::istream& operator>>(std::istream& is, Date& D) {
	  return D.read(is);
  }
  std::ostream& operator<<(std::ostream& ostr, const Date& D) {
	  return D.write(ostr);
  }


}
