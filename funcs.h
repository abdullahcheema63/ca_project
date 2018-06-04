#include <string>
using namespace std;
bool parseParams(int argc, char *argv[ ], int& cache_capacity,
				int& cache_blocksize, int& cache_associativity);

string decimalToBoolean(int dec);
int booleanToDecimal(string boolean);
string hexToBinary(string input);

string binaryTohex(string str);
