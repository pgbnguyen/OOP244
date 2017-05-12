// edgardo.arvelaez/submit 244_w2_home
// Anton Elistratov
// Seneca@York
// Email: eanton@myseneca.ca
// Program: CPA
#include <iostream>
#include "kingdom.h"
#include <cstring>

using namespace std;

namespace westeros{
    void display(Kingdom& pKingdom){
        cout << pKingdom.m_name << ", population " << pKingdom.m_population << endl;
    }
    void display(Kingdom pKingdom[], int _count){
        int total = 0;
        cout << "------------------------------" << endl;
        cout << "Kingdoms of Westeros" << endl;
        cout << "------------------------------" << endl;
            for (int i = 0; i < _count; i++){
                cout << i+1 <<". "<< pKingdom[i].m_name << 
                ", population " << pKingdom[i].m_population << endl;
                //total number of ppl
                total = total + pKingdom[i].m_population;
            }
        cout << "------------------------------" << endl;
        cout << "Total population of Westeros: " << total <<endl;
        cout << "------------------------------" << endl;
    }
    void display(Kingdom pKingdom[], int _count, int _population){
        cout << "------------------------------" << endl;
        cout << "Kingdoms of Westeros with more than "<< _population <<" people" << endl;
        cout << "------------------------------" << endl;
            for (int i = 0; i < _count; i++){
                
                if (pKingdom[i].m_population >= _population){                   
                    cout << pKingdom[i].m_name << ", population " << pKingdom[i].m_population << endl;
                }
            }
        cout << "------------------------------" << endl;
    }
    void display(Kingdom pKingdom[], int _count, const char* kingdom_name){
        cout << "------------------------------" << endl;
        cout << "Searching for kingdom " << kingdom_name <<" in Westeros" << endl;
        cout << "------------------------------" << endl;
        //tokken for output
        bool _result = true;
        for (int i = 0; i < _count; i++){
            if (strcmp(pKingdom[i].m_name, kingdom_name) == 0){
                _result = false;
                cout << pKingdom[i].m_name << ", population " << pKingdom[i].m_population << endl;
            }
        }
        if (_result){
            cout << kingdom_name <<" is not part of Westeros." <<endl;
            cout << "------------------------------" << endl;
        }
    }
}


