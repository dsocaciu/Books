//Accelerated C++
//Chapter 5 Using sequential containers and analyzing strings
//Question 5-4 

#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <list>
#include "grade.h"
#include "Student_info.h"
#include "extract_fails.h"

using namespace std;





int main()
{
	//comment out vector
	//typedef vector<Student_info> students_v;


	Student_info record;
	string::size_type maxlen = 0;	//length of the longest name

	//typedef vector<Student_info> students_container;
	typedef list<Student_info> students_container;

	students_container students_list;

	//read and store all the students' data.
	//Invariant: students contains all the studnets records read so far
	//			 maxlen contains the length of the longest name in the students
	while (read(cin, record)){
		maxlen = max(maxlen,record.name.size());
		//students_vector.push_back(record);
		students_list.push_back(record);
	}


	//remove the sort since they're different as per the book
	//vector uses std sort
	//list has its own sort function, due to non random access



	//vector<Student_info> failsVector;
	//failsVector = extract_fails3(students_vector);
	//cout << failsVector.size() << endl;

	list<Student_info> failsList;
	failsList = extract_fails4(students_list);
	cout << failsList.size() << endl;

	return 0;


//Answer:
//Compile: g++ median.cpp  Student_info.cpp grade.cpp extract_fails.cpp chap54.cpp -o chap54.o
//Can comment out the different typedefs which are named the same and use the same functions to add
//Will need to differentiate the different extract_fails functions as well
