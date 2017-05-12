// edgardo.arvelaez/submit 244_w2_lab
// Anton Elistratov
// Seneca@York
// Email: eanton@myseneca.ca
// Program: CPA
#include <iostream>
#include "kingdom.h"

using namespace std;

namespace westeros{
    void display(Kingdom& pKingdom){
        cout << pKingdom.m_name << ", population " << pKingdom.m_population << endl;
    }
}