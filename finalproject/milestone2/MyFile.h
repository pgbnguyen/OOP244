// MyFile.h
// hasan.murtaza/submit 244_ms2
// Anton Elistratov
// Seneca@York
// Email: eanton@myseneca.ca
// Program: CPA
#ifndef ICT_MYFILE_H__
#define ICT_MYFILE_H__
#include "PosIO.h"
namespace ict {
	class MyFile : public PosIO {
		char _fname[256];
		char _text[10000];
	public:
		MyFile(const char* fname);
		std::fstream& save(std::fstream& file)const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear)const;
		std::istream& read(std::istream& is);
		void print();
	};
	std::ostream& operator<<(std::ostream& ostr, const MyFile& mf);
	std::istream& operator>>(std::istream& istr, MyFile& mf);
}
#endif