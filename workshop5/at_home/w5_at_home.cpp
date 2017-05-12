// Fraction.h
// edgardo.arvelaez/submit 244_w5_home
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
    cout << "Fraction E(8, 4); //";  // corrected the ouput here V1.1
    cout << " E = " ;
    E.display();
    cout << endl;

    cout << endl;

    cout << "(B*Fraction(6) == E) equals ";  // corrected the ouput here V1.1
    cout << (B*Fraction(6) == E);
    cout << endl;

    cout << "(A == C) equals ";
    cout << (A == C);
    cout << endl;

    cout << "(double) B equals ";
    cout.precision(3);
    cout << (double) B;
    cout << endl;


    cout << "(int) B equals ";
    cout << (int) B;
    cout << endl;

    cout << "S := ";

    Fraction s = 0;
    for(Fraction r = Fraction(1,2) ; r != Fraction(3,1);r +=Fraction(1,4)){
        r.display();
        cout  << ", " ;
        s += r;
    }

    cout << endl << "The sum of elements in S equals " ;
    s.display();
    cout << endl ;
   
    return 0;
}