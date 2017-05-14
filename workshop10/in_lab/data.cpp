// data.cpp
// hasan.murtaza/submit 244_w10_lab
// Anton Elistratov
// Seneca@York
// Email: eanton@myseneca.ca
// Program: CPA
#include <iostream>
#include <cmath>
#include "data.h"


using namespace std;

// min
int min(const int* data, int N) 
{
    int ret = LARGEST_NUMBER;
    for (int i=0; i < N; i++)
    {
        if (data[i] < ret)
        {
            ret = data[i];
        }
    }
    return ret;
}