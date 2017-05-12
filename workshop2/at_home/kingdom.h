// edgardo.arvelaez/submit 244_w2_home
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
        int m_population; // stores number of ppl who live 
    };

    void display(Kingdom& pKingdom);
    void display(Kingdom pKingdom[], int _count);
    void display(Kingdom pKingdom[], int _count, int _population);
    void display(Kingdom pKingdom[], int _count, const char* kingdom_name);

}
#endif