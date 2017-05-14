// Error.cpp
// hasan.murtaza/submit 244_ms1
// Anton Elistratov
// Seneca@York
// Email: eanton@myseneca.ca
// Program: CPA
		#define _CRT_SECURE_NO_WARNINGS 

		#include "Error.h"
		#include <iostream>
		#include <cstring>

		namespace ict{
			Error::Error() {
				m_message = nullptr;
			}

			Error::Error(const char* errorMessage) {
				m_message = nullptr;
				message(errorMessage);
			}

			//have a look
			void Error::operator=(const char* errorMessage) {
				//clear();//dealloc m_message
				//message(errorMessage);
				delete[] m_message;
				m_message = nullptr;
				m_message = new char[strlen(errorMessage) + 1];
				strcpy(m_message, errorMessage);
			}

			void Error::clear() {
				delete[] m_message;
				m_message = nullptr;

			}


			bool Error::isClear()const {
				bool clear = false;
				if (m_message == nullptr) {
					clear = true;
				}
				return clear;
				//return !m_message;
			}

			void Error::message(const char* value) {
				clear();//dealloc m_message
				//delete[] m_message;
				m_message = new char[strlen(value) + 1];
				strcpy(m_message, value);
			}

			Error::operator const char*() const {
				return m_message;
			}

			Error::operator bool()const {
				return isClear();
			}

			std::ostream& operator<<(std::ostream& ostr, const Error& em) {
				if (em.isClear()) {
					//nothing
				}
				else {
					ostr << em.m_message;
				}

				return ostr;
			}

		}//namespace ict