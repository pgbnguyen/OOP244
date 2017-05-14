// Contact.h
// hasan.murtaza/submit 244_w6_lab
// Anton Elistratov
// Seneca@York
// Email: eanton@myseneca.ca
// Program: CPA
// TODO: add header guard
#ifndef CONTACT_H_244_
#define CONTACT_H_244_
// TODO: add namespace here
namespace communication{	
	class Contact
	{
		char m_name[21];
		long long* m_phoneNumbers;
		int m_noOfPhoneNumbers;
		int outputNum; //for void display function
	public:
		// TODO: add the default constructor here
		Contact();
		// TODO: add the constructor with parameters here
		Contact(const char*, long long*, int );
		// TODO: add the destructor here
		~Contact();
		// TODO: add the display function here
		void display();
		// TODO: add the isEmpty function here
		bool isEmpty() const;
	public:
		Contact(const Contact& other) = delete;
		Contact& operator=(const Contact& other) = delete;
	};
}
#endif //244_CONTACT_H

