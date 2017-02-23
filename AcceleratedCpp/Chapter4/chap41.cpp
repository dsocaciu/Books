//Accelerated C++
//Chapter 4 Organizing programs and data
//Question 4-1 

#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"

using namespace std;

int main()
{
	vector<Student_info> students;
	Student_info record;
	int maxlen;	
	/*
		results in compliation error
		chap41.cpp:27:12: error: no matching function for call to 'max'
                maxlen = max(maxlen,record.name.size());
                         ^~~
		/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/algorithm:2654:1: note: 
      candidate template ignored: deduced conflicting types for parameter '_Tp'
      ('int' vs. 'unsigned long')
		max(const _Tp& __a, const _Tp& __b)

	*/

	//read and store all the students' data.
	//Invariant: students contains all the studnets records read so far
	//			 maxlen contains the length of the longest name in the students
	while (read(cin, record)){
		maxlen = max(maxlen,record.name.size());
		students.push_back(record);
	}

	//alphabetize the student records
	sort(students.begin(),students.end(),compare);

	// write the names and grades
	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i)
	{

		//write the name , padded on the right to maxlen+ 1 characters
		cout << students[i].name
			 << string(maxlen + 1 - students[i].name.size(), ' ');

		//compute and write the grade

		try{
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				 << setprecision(prec);

		} catch( domain_error e){
			cout << e.what();
		}	 
		cout << endl;

	}

	return 0;
}