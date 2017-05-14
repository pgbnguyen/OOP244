// Contact.h
// hasan.murtaza/submit 244_w6_home
// Anton Elistratov
// Seneca@York
// Email: eanton@myseneca.ca
// Program: CPA
// TODO: add header guard
#ifndef CONTACT_H_244_
#define CONTACT_H_244_
// TODO: add namespace here
namespace communication {
	class Contact
	{
		char m_name[21];
		long long* m_phoneNumbers;
		int m_noOfPhoneNumbers; //holds the number of phone numbers
	public:
		//in_lab
		Contact();
		Contact(const char*, long long*, int);
		~Contact();
		void display();
		bool isEmpty() const;
		void addPhoneNumber(long long phoneNumber);
	public:
		Contact(const Contact& other);
		Contact& operator=(const Contact& other);
	};
}
#endif //244_CONTACT_H

