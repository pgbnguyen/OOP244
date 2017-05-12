// Fraction.cpp
// edgardo.arvelaez/submit 244_w5_lab
// Anton Elistratov
// Seneca@York
// Email: eanton@myseneca.ca
// Program: CPA
#include "Fraction.h"

using namespace std;

namespace sict{
    Fraction::Fraction(){  
            denom =-1;              // safe empty state
    }
    
    Fraction::Fraction(int n, int d) // n: numerator, d: denominator
    { 
        if(n >= 0 && d > 0){
            num = n;
            denom = d;
            reduce();
        }
        else 
            denom =-1;              // set to safe empty state
    }

    int Fraction::gcd()                                        // returns the greatest common divisor of num and denom 
    {
        int mn = min();                                        // min of num and denom
        int mx = max();                                        // mX of num and denom

        for (int x=mn ; x > 0 ; x--)                           // find the greatest common divisor
            if( mx % x == 0 &&  mn % x == 0)
                return x;
        return 1;

    } 

    void Fraction::reduce()                                         // simplify the Fraction number  
    {
        int tmp = gcd();
        num /= tmp;
        denom /= tmp;
    }

    int Fraction::max ()
    {
        return (num >= denom) ? num : denom; 
    }

    int Fraction::min()
    {
        return (num >= denom) ? denom : num; 
    }

    // in_lab

    // TODO: write the implementation of display function HERE
    void Fraction::display() const{
        if (isEmpty()){
            cout << "Invalid Fraction Object!";
        } else if (denom == 1){
            cout << num;
        } 
        else {
            cout << num << "/" << denom;
        }
    }
    // TODO: write the implementation of isEmpty function HERE
    bool Fraction::isEmpty() const{
        bool state;
        if (denom == -1){
            state = true;
        } else {
            state = false;
        }
        return state;
    }

    // TODO: write the implementation of member operator+= function HERE
    Fraction& Fraction::operator+= (const Fraction& p){
        
        //if either is empty
        if (isEmpty() || p.isEmpty()){
            this->denom = -1;
        }

        //if both aren't empty
        if (!isEmpty() && !p.isEmpty()) {
            this->num = (num * p.denom) + (p.num*denom);
            this->denom = denom * p.denom;
            this->reduce();
        }

        return *this;
    }
    

    // TODO: write the implementation of member operator+ function HERE
    Fraction Fraction::operator+ (const Fraction& p){
        Fraction temp;

        //if either is empty
        if (isEmpty() || p.isEmpty() ){
            temp.denom = -1;
        } 
        
        //if both aren't empty
        if (!isEmpty() && !p.isEmpty()){
            temp.num = (num*p.denom) + (p.num*denom);
            temp.denom = denom * p.denom;
            temp.reduce();
        }
        return temp;
    }
    
    // TODO: write the implementation of member operator* function HERE
    Fraction Fraction::operator* (const Fraction& p){
        Fraction temp;

        if (isEmpty() || p.isEmpty()){
            temp.denom = -1;//safe state
        }

        if (!isEmpty() && !p.isEmpty()){
            temp.num = (num * p.num);
            temp.denom = (denom * p.denom);       
        }
        
        return temp;
    }
}