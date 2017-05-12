// kingdom.h
// edgardo.arvelaez/submit 244_w2_lab
// Anton Elistratov
// Seneca@York
// Email: eanton@myseneca.ca
// Program: CPA
#ifndef _KINGDOM_H_
#define _KINGDON_H_
//difs should be here

namespace westeros {

    class Kingdom{
    public:
        char m_name[32];// a static array;
        int m_population; //stores number of ppl who live 
    };

    void display(Kingdom& pKingdom);

}
#endif