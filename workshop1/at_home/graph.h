// graph.h
// edgardo.arvelaez/submit 244_w1_home
// Anton Elistratov
// Seneca@York
// Email: eanton@myseneca.ca
// Program: CPA
#ifndef SICT_GRAPH_H_
#define SICT_GRAPH_H_


namespace sict {

// Maximum number of samples in an graph
#define MAX_NO_OF_SAMPLES 20

// Finds the largest sample in the samples array, if it is larger than 70,
// therwise it will return 70.
int findMax(int samples[], int noOfSamples);
// Prints a scaled bar relevant to the maximum value in samples array
void printBar(int val, int max);
// Prints a graph comparing the sample values visually
void printGraph(int samples[], int noOfSamples);
// Fills the samples array with the statistic samples
void getSamples(int samples[], int noOfSamples);
}
#endif