#include <stdio.h>
#include <unistd.h> //for the getopt function
#include <stdlib.h> //for atoi
#include <iostream>
#include <math.h>
using namespace std;

bool parseParams(int argc, char *argv[ ], int& cache_capacity,
				int& cache_blocksize, int& cache_associativity)
{
  //needed for the parsing of command line options
  int c;
  bool c_flag, b_flag, a_flag;
  bool errflg = false;

  c_flag = b_flag = a_flag = errflg = false;

  //the following variables are used by getopt and
  //are defined elsewhere so we just make them
  //extern here
  extern char *optarg;
  extern int optind, optopt;

  //start the parsing of the command line options.
  //end is indicated by getopt returning -1
  //each option has a case statement
  //the corresponding flags are set if the option exists on
  //the command line
  //the : int he getopt indicates that the option preceeding the
  //: requires a argument to be specified
  while ((c = getopt(argc, argv, "c:b:a:")) != -1) {
	switch (c) {
	  case 'c':
		cache_capacity = atoi(optarg);
		c_flag = true;
		break;
	  case 'b':
		cache_blocksize = atoi(optarg);
		b_flag = true;
		break;
	  case 'a':
		cache_associativity = atoi(optarg);
		a_flag = true;
		break;
	  case ':':       /* -c without operand */
		fprintf(stderr,
			"Option -%c requires an operand\n", optopt);
		errflg++;
		break;
	  case '?':
		fprintf(stderr, "Unrecognised option: -%c\n", optopt);
		errflg=true;
	}
  }

  //check if we have all the options and have no illegal options
  if(errflg || !c_flag || !b_flag || !a_flag) {
	fprintf(stderr, "usage: %s -c<capacity> -b<blocksize> -a<associativity>\n", argv[0]);
	return false;
  }

  return true;

}

string decimalToBoolean(int dec){
	string returnValue="00000000000000000000000000000001";
	// cout<<returnValue[31]<<endl;
	int i=31;
	int temp=dec;
	while((temp)>0){
		
		returnValue[i]=char((temp%2)+48);
		i--;
		temp=temp/2;
	}
	return returnValue;
}
int booleanToDecimal(string boolean){
	int returnValue=0;
	for (int i=0;i<boolean.length();i++){
		if (boolean[i]=='1'){
			returnValue+=pow(2,boolean.length()-1-i);
		}
	}
	return returnValue;
}
string hexToBoolean(string hex){
	string returnValue="00000000000000000000000000000000";
	if (hex.length()>8){
		cout<<"large number given cant convert"<<endl;
		return "";
	}
}
string hexToBinary(string input)
{
	string str = "00000000000000000000000000000000";
	int i = 31, j = input.length() - 1;
	char c = input[j];
	while (j >= 0)
	{
		if (c == '0')
		{
			str[i] = '0';
			str[i - 1] = '0';
			str[i - 2] = '0';
			str[i - 3] = '0';
		}
		else if (c == '1')
		{
			str[i] = '1';
			str[i - 1] = '0';
			str[i - 2] = '0';
			str[i - 3] = '0';
		}
		else if (c == '2')
		{
			str[i] = '0';
			str[i - 1] = '1';
			str[i - 2] = '0';
			str[i - 3] = '0';
		}
		else if (c == '3')
		{
			str[i] = '1';
			str[i - 1] = '1';
			str[i - 2] = '0';
			str[i - 3] = '0';
		}
		else if (c == '4')
		{
			str[i] = '0';
			str[i - 1] = '0';
			str[i - 2] = '1';
			str[i - 3] = '0';
		}
		else if (c == '5')
		{
			str[i] = '1';
			str[i - 1] = '0';
			str[i - 2] = '1';
			str[i - 3] = '0';
		}
		else if (c == '6')
		{
			str[i] = '0';
			str[i - 1] = '1';
			str[i - 2] = '1';
			str[i - 3] = '0';
		}
		else if (c == '7')
		{
			str[i] = '1';
			str[i - 1] = '1';
			str[i - 2] = '1';
			str[i - 3] = '0';
		}
		else if (c == '8')
		{
			str[i] = '0';
			str[i - 1] = '0';
			str[i - 2] = '0';
			str[i - 3] = '1';
		}
		else if (c == '9')
		{
			str[i] = '1';
			str[i - 1] = '0';
			str[i - 2] = '0';
			str[i - 3] = '1';
		}
		else if (c == 'a' || c == 'A')
		{
			str[i] = '0';
			str[i - 1] = '1';
			str[i - 2] = '0';
			str[i - 3] = '1';
		}
		else if (c == 'b' || c == 'B')
		{
			str[i] = '1';
			str[i - 1] = '1';
			str[i - 2] = '0';
			str[i - 3] = '1';
		}
		else if (c == 'c' || c == 'C')
		{
			str[i] = '0';
			str[i - 1] = '0';
			str[i - 2] = '1';
			str[i - 3] = '1';
		}
		else if (c == 'd' || c == 'D')
		{
			str[i] = '1';
			str[i - 1] = '0';
			str[i - 2] = '1';
			str[i - 3] = '1';
		}
		else if (c == 'e' || c == 'E')
		{
			str[i] = '0';
			str[i - 1] = '1';
			str[i - 2] = '1';
			str[i - 3] = '1';
		}
		else if (c == 'f' || c == 'F')
		{
			str[i] = '1';
			str[i - 1] = '1';
			str[i - 2] = '1';
			str[i - 3] = '1';
		}
		i -= 4;
		j--;
		if (j >= 0)
			c = input[j];
	}
	return str;
}


string binaryTohex(string str)
{
	string output = "00000000";
	int j = 7, i = str.length() - 1;
	if (str.length() % 4 != 0)
	{
		cout << "incorrect binary" << endl;
		return output = "";
	}
	while (i >= 3)
	{
		if (str[i] == '0'&&
		str[i - 1] == '0'&&
		str[i - 2] == '0'&&
		str[i - 3] == '0')
		{
			output[j]= '0';
		}
		else if (str[i] == '1'&&
			str[i - 1] == '0'&&
			str[i - 2] == '0'&&
			str[i - 3] == '0')
		{
			output[j] = '1';
		}
		else if (str[i] == '0'&&
			str[i - 1] == '1'&&
			str[i - 2] == '0'&&
			str[i - 3] == '0')
		{
			output[j] = '2';
		}
		else if (str[i] == '1'&&
			str[i - 1] == '1'&&
			str[i - 2] == '0'&&
			str[i - 3] == '0')
		{
			output[j] = '3';
		}
		else if (str[i] == '0'&&
			str[i - 1] == '0'&&
			str[i - 2] == '1'&&
			str[i - 3] == '0')
		{
			output[j] = '4';
		}
		else if (str[i] == '1'&&
			str[i - 1] == '0'&&
			str[i - 2] == '1'&&
			str[i - 3] == '0')
		{
			output[j] = '5';
		}
		else if (str[i] == '0'&&
			str[i - 1] == '1'&&
			str[i - 2] == '1'&&
			str[i - 3] == '0')
		{
			output[j] = '6';
		}
		else if (str[i] == '1'&&
			str[i - 1] == '1'&&
			str[i - 2] == '1'&&
			str[i - 3] == '0')
		{
			output[j] = '7';
		}
		else if (str[i] == '0'&&
			str[i - 1] == '0'&&
			str[i - 2] == '0'&&
			str[i - 3] == '1')
		{
			output[j] = '8';
		}
		else if (str[i] == '1'&&
			str[i - 1] == '0'&&
			str[i - 2] == '0'&&
			str[i - 3] == '1')
		{
			output[j] = '9';
		}
		else if (str[i] == '0'&&
			str[i - 1] == '1'&&
			str[i - 2] == '0'&&
			str[i - 3] == '1')
		{
			output[j] = 'A';
		}
		else if (str[i] == '1'&&
			str[i - 1] == '1'&&
			str[i - 2] == '0'&&
			str[i - 3] == '1')
		{
			output[j] = 'B';
		}
		else if (str[i] == '0'&&
			str[i - 1] == '0'&&
			str[i - 2] == '1'&&
			str[i - 3] == '1')
		{
			output[j] = 'C';
		}
		else if (str[i] == '1'&&
			str[i - 1] == '0'&&
			str[i - 2] == '1'&&
			str[i - 3] == '1')
		{
			output[j] = 'D';
		}
		else if (str[i] == '0'&&
			str[i - 1] == '1'&&
			str[i - 2] == '1'&&
			str[i - 3] == '1')
		{
			output[j] = 'E';
		}
		else if (str[i] == '1'&&
			str[i - 1] == '1'&&
			str[i - 2] == '1'&&
			str[i - 3] == '1')
		{
			output[j] = 'F';
		}
		j--;
		if (i > 3)
			i -= 4;
		else
			break;
	}
	return output;
}
