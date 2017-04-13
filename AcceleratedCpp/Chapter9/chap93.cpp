//Accelerated C++
//Chapter 9 Defining new types
//Question 9-3


#include "Student_info.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>

using std::cout;	using std::domain_error; 	using std::endl;	using std::cin;
using std::setprecision;						using std::max;		using std::streamsize;
using std::vector;	using std::string;			using std::sort;


int main()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	//read and store the data
	while(record.read(cin)) {						//changed
		maxlen = max(maxlen,record.name().size());	//changed
		students.push_back(record);
	}

	//alphabetize the student records
	sort(students.begin(),students.end(), compare);

	//write the names and grades
	for (vector<Student_info>::size_type i = 0;
			i != students.size(); ++i){

		cout << students[i].name()					//changed
			 << string(maxlen + 1 - students[i].name().size(), ' ');
			double final_grade = students[i].grade();	//changed
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				 << setprecision(prec) << endl;
	}

	return 0;


}

/*

g++ median.cpp grade.cpp Student_info.cpp chap93.cpp -o chap93.o

pass in
Dan 100 100

Results in 
libc++abi.dylib: terminating with uncaught exception of type std::domain_error: student has done no homework
Dan Abort trap: 6





*/