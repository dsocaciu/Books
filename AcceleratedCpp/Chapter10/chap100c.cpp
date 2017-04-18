//Accelerated C++
//Chapter 10 Managing memory and low-level data structures
//Question 10-0

#include <fstream>
#include <iostream>
#include <string>

using std::ifstream;	using std::cout;	using std::endl;	using std::cerr;	
using std::string;


int main(int argc, char** argv)
{
	int fail_count = 0;
	//for each file in the input list

	for(int i = 1; i < argc; ++i)
	{
		ifstream in(argv[i]);

		//if it exists, write its contents, otherwise generate an errir nessage
		if(in){
			string s;
			while (getline(in,s))
				cout << s << endl;
		} else {
			cerr << "cannot open file " << argv[i] << endl;
			++fail_count;
		}
	}

	return fail_count;
}

/*

$ cat test.txt 
this is a line
this is a second line

$ ./chap100c.o test.txt 
this is a line
this is a second line
$ ./chap100c.o test.txt test2.txt
this is a line
this is a second line
cannot open file test2.txt





*/