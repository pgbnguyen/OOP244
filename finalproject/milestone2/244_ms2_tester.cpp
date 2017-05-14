// 244_ms2_tester.cpp
// hasan.murtaza/submit 244_ms2
// Anton Elistratov
// Seneca@York
// Email: eanton@myseneca.ca
// Program: CPA
#include <iostream>
#include "MyFile.h"
using namespace std;
using namespace ict;
int main() {
	fstream file;
	MyFile F("PosIO.txt");
	cout << "Run this program few times and keep adding to" << endl << "the content of the file created." << endl;
	F.load(file);
	cout << "Linear content of file streamable.txt: " << endl << endl << F << endl;
	cout << "Press <ENTER> to continue...";
	cin.ignore();
	cout << endl << "streamble.txt as is: " << endl;
	F.print();
	cout << " ---------------- " << endl << "Enter a text and then"
		<< endl << "On windows end it with in a new line with Ctrl-Z <ENTER>"
		<< endl << "On Linux or mac end it with a new line with Ctrl-D"
		<< endl << "to append to the end of streamable.txt:" << endl;
	cin >> F;
	F.save(file);
	cout << "Re-run the program to see the appended lines." << endl;
	return 0;
}