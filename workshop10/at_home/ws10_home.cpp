// ws10_home.cpp
// hasan.murtaza/submit 244_w10_home
// Anton Elistratov
// Seneca@York
// Email: eanton@myseneca.ca
// Program: CPA
// Same as in_lab part but we only had to submit reflect.txt with it.
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include "data.h"


using namespace std;


//////////////////
// File format is simple. file reproduced below
//
// first line is number of columns
//
// 
// each row is Name, data1, data2, data3 ,...

// file crimedata.csv
/* 
5
Year,2000,2001,2002,2003,2004
Population,281421906,285317559,287973924,290788976,293656842
ViolentCrime,1425486,1439480,1423677,1383676,1360088
ViolentCrime_Rate,506.5,504.5,494.4,475.8,463.2
GrandTheftAuto,1160002,1228391,1246646,1261226,1237851
GrandTheftAuto_Rate,412.2,430.5,432.9,433.7,421.5

*/



////////////////////////////////
// readRow
//
// first you read the first line with the number. It tells you how much memory to allocate
// for your arrays.
// then you can call readRow once for each line of the file
// for extra error checking, you pass the name of the row you want and it checks to make sure it's valid.
// read a single line of data from the datafile and put it in the array
//
// it is the job of main() to ensure that you read the correct row. If the name
// does not match the row, the function will return false.
template<typename T>
bool readRow(istream& input, const char* name, T* pData, int N)
{
    char rowname[2000];
    //char comma;
    
    bool ok = true;
    
    // robust error handling
    if (input.bad())
    {
        ok = false;
    }
    
    if (ok)
    {
        // read the name of the row first

        input.get(rowname, 2000, ',');
        // note: get will read a string upto the , character
        // it will leave the , character in the input buffer 
        
        // if the user is trying to read the wrong row, return an error
        if (strcmp(rowname, name) != 0)
        {
            // wrong row
            cout << "Cannot parse row for " << name << endl;
            input.ignore(2000, '\n');
            ok = false;
        }
    }
    
    if (ok)
    {
        
        // read in the data array
        ok  = read(input, pData, N);
    }
    
    // finish the line
    input.ignore(2000, '\n');
    return ok;
}





/////////////////////////////
// main
//
// returns the max item in the array
//
int main()
{
    
    ifstream finput ("crimedata.csv");
    if (!finput)
    {
        cerr << "Cannot open file" << endl;
        return 1;
    }
    
    // file format
    // -------------
    // 5
    // year,2000,2001, 2002 2003, 2004
    // 
    int N = 0;
    finput >> N;
    finput.ignore(2000, '\n');  // read the rest of the line
    
    
    // for inlab, assume N is a large enough number.
    const int ArraySize = 10;
    // for athome, implement this as dynamic memory
    int year [ArraySize];
	int population [ArraySize];
	int violentCrime[ArraySize];
	double violentCrimeRate[ArraySize];
	int grandTheftAuto[ArraySize];
	double grandTheftAutoRate[ArraySize];
    
    
    
    ////////////////////
    // Note: this is a simple file reader
    // we MUST read each row in the same order it is found in the file
    //
    if (!readRow(finput, "Year", year, N))                              { return 1; }
	if (!readRow(finput, "Population", population, N))                  { return 1; }
	if (!readRow(finput, "ViolentCrime", violentCrime, N))              { return 1; }
	if (!readRow(finput, "ViolentCrime_Rate", violentCrimeRate, N))     { return 1; }
	if (!readRow(finput, "GrandTheftAuto", grandTheftAuto, N))          { return 1; }
	if (!readRow(finput, "GrandTheftAuto_Rate", grandTheftAutoRate, N)) { return 1; } 
	
    // print the data
    display("Year", year, N);
	display("Population", population, N);
	display("ViolentCrime", violentCrime, N);
	display("ViolentCrimeRate", violentCrimeRate, N);
	display("GrandTheftAuto", grandTheftAuto, N);
	display("GrandTheftAutoRate", grandTheftAutoRate, N);    
    
    cout << endl;
    
    // Answer the following questions
    
    
    // print the population change in millions of people
    // print answer correct to 2 decimal places.
    // e..g "6.31 million";
    // note that population is an integer, so dividing by 1000000 would yield "6"
    int population_change = population[N-1] - population[0]; 
    cout << "Population change from " << year[0]<<" to " << year[N-1] << " is ";
	std::cout << std::fixed;
	cout.precision(2);
    cout << static_cast<double>(population_change / 1.0E6) << " million" << endl;
    
    
    
    // Q2. print whether violent crime rate is going up or down between the years 2000 and 2005
    auto violentCrimeStart  = violentCrime[0];
    auto violentCrimeEnd    = violentCrime[N-1];
    const char *trend = "";
	
	if (violentCrimeEnd - violentCrimeStart > 0) {
		trend = "up";
	}
	else {
		trend = "down";
	}
	//const strings
	

    cout << "Violent Crime trend is " << trend << endl;
    
    
    // Q3 print the GTA rate in millions accurate to 2 decimal places
    double gtaMillions = average(grandTheftAuto, 5); // tyour code goes here
	//format output
	gtaMillions = gtaMillions / 1000000;


    cout << "There are ";
	std::cout << std::fixed;
	cout.precision(2);
    cout <<	gtaMillions 
        << " million Grand Theft Auto incidents on average a year"  <<  endl;
    
    // Q4. Print the min and max violentCrime rates
	int maxCrime = max(violentCrimeRate, 5);
	int minCrime = min(violentCrimeRate, 5);
    // your code goes here
	cout << "The Minimum Violent Crime rate was " << minCrime << endl;
	cout << "The Maximum Violent Crime rate was " << maxCrime << endl;
  
	return 0;
}