// data.h
// hasan.murtaza/submit 244_w10_home
// Anton Elistratov
// Seneca@York
// Email: eanton@myseneca.ca
// Program: CPA
// Same as in_lab part but we only had to submit reflect.txt with it.

// These numbers define the range of data we expect to see in this lab
// 0 to 1 billion
// use them in the min and max function.

#define LARGEST_NUMBER      1000000000      // 1,000,000,000
#define SMALLEST_NUMBER     0
#define COLUMN_WIDTH        15

// an integer only version of min
int min(const int* data, int N);

// max
template <typename T>
T max(const T* data, int N)
{
	int largest = SMALLEST_NUMBER;
	for (int i = 0; i < N; i++) {
		if (largest <= data[i]) {
			largest = data[i];
		}
	}
	return largest;
}

// min
template <typename T>
T min(const T* data, int N) 
{
	int min = LARGEST_NUMBER;
	for (int i = 0; i < N; i++) {
		if (min > data[i]) {
			min = data[i];
		}
	}
	return min;
}

// sum
template <typename T>
T sum(T *data[], int N)
{
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += data[i];
	}
	return sum;
}

// average
template <typename T>
// template declaration goes here
double average(T data[], int N)
{
	int sum = 0;
	int ave = 0;
	for (int i = 0; i < N; i++) {
		sum += data[i];
	}
	ave = sum / N;
	return ave;
}

// read
template<class T>
bool read(std::istream& input, T* pData, int N)
{
    char comma;
    
    // read N  numbers separated by commas
    for (int i=0; i< N; i++)
    {
        T number;

        input >> comma;
        if (comma != ',') return false;
        if (input >> number) 
        {
            pData[i] = number;
        }
        else
        {
            return false;
        }
        
    }
    return true;
}

// display
template<class T>
void display(const char* rowName, T *pData, int N)
{
    std::cout.width(20);
    std::cout << rowName;
    for (int i=0; i < N; i++)
    {
        std::cout.width(COLUMN_WIDTH);
        std::cout << pData[i];
    }
    std::cout << std::endl;
}