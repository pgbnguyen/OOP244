// w5_in_lab.cpp
// edgardo.arvelaez/submit 244_w5_lab
// Anton Elistratov
// Seneca@York
// Email: eanton@myseneca.ca
// Program: CPA
#include <iostream>
#include "Fraction.h"

using namespace sict;
using namespace std;


int main(){

   cout << "------------------------------" << endl;

    cout << "Fraction Class Operators Test:" << endl;
    cout << "------------------------------" << endl;
    
    Fraction A;
    cout << "Fraction A; // ";
    cout << "A = ";
    A.display();
    cout << endl;

    Fraction B(1, 3);
    cout << "Fraction B(1, 3); // ";
    cout << "B = ";
    B.display();
    cout << endl;

    
    Fraction C(-5, 15);
    cout << "Fraction C(-5, 15); //";
    cout << " C = " ;
    C.display();
    cout << endl;

    Fraction D(2, 4);
    cout << "Fraction D(2, 4); //";
    cout << " D = ";
    D.display();
    cout << endl;

    Fraction E(8, 4);
    cout << "Fraction E(8, 4); //"; // corrected the ouput here V1.1
    cout << " E = " ;
    E.display();
    cout << endl;

    cout << endl;

    cout << "A+B equals ";
    (A+B).display();
    cout << endl;

    cout << "B+3 equals ";
    (B+3).display();
    cout << endl;
     
    cout << "B+D equals ";
    (B+D).display();
    cout << endl;

    cout << "(A = D = (B+=E)) equals " ;
    (A = D = (B+=E)).display();
    cout << endl;
    cout << "Now A, D, B, and E equal " ;
    A.display();
    cout << ", " ;
    D.display();
    cout << ", ";
    B.display();
    cout << ", ";  
    E.display();
    cout << endl;
   
    return 0;
}
