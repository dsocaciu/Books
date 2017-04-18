//Accelerated C++
//Chapter 10 Managing memory and low-level data structures
//Question 10-1

#include "Student_info.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>

using std::cout;	using std::domain_error; 	using std::endl;	using std::cin;
using std::setprecision;						using std::max;		using std::streamsize;
using std::vector;	using std::string;			using std::sort;


string letter_grade(double grade)
{
	//range posts for numeric grades
	static const double numbers[] = {97, 94,90, 87, 84, 80, 77, 74, 70, 60, 0};

	//names for the letters grades
	static const char* const letters[] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"};

	//compute the number of grades given the size of the array
	//and the size of a single elements
	static const size_t ngrades = sizeof(numbers)/sizeof(*numbers);

	//given a numeric grade, find and return the  associated letter grade
	for(size_t i = 0; i < ngrades; ++i)
	{
		if(grade >= numbers[i])
			return letters[i];
	}

	return "?\?\?";
}


int main()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	//read and store the data
	while(record.read(cin)) {						
		maxlen = max(maxlen,record.name().size());	
		students.push_back(record);
	}

	//alphabetize the student records
	sort(students.begin(),students.end(), compare);

	//write the names and grades
	for (vector<Student_info>::size_type i = 0;
			i != students.size(); ++i){

		cout << students[i].name()				
			 << string(maxlen + 1 - students[i].name().size(), ' ');
		try{
			string final_grade = letter_grade(students[i].grade());	
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				 << setprecision(prec) << endl;
		} catch(domain_error e){
			cout << e.what() << endl;
		}	
	}

	return 0;


}

/*

g++ median.cpp grade.cpp Student_info.cpp chap101.cpp -o chap101.o

*/