// ws10_lab.cpp
// hasan.murtaza/submit 244_w10_lab
// Anton Elistratov
// Seneca@York
// Email: eanton@myseneca.ca
// Program: CPA
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include "data.h"

using namespace std;

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