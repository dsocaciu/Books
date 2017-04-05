//Accelerated C++
//Chapter 7 Using associative containers
//Question 7-2




#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <map>
#include "grade.h"
#include "Student_info.h"

using namespace std;

string getLetterGrade(double grade)
{
	if (grade > 90 && grade <=100)
		return "A";
	else if (grade >= 80 && grade <90)
		return "B";
	else if (grade >= 70 && grade <80)
		return "C";
	else if (grade >= 60 && grade <70)
		return "D";
	else 
		return "F";
}

int main()
{
	map<string, int > student_grades;
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;	//length of the longest name

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
			cout << setprecision(3) << final_grade  << setprecision(prec);
			++student_grades[getLetterGrade(final_grade)];

		} catch( domain_error e){
			cout << e.what();
		}	 
		cout << endl;

	}

	for (map<string,int>::iterator it = student_grades.begin();it!=student_grades.end();it++)
	{
		cout << it->first << " " << it->second << endl;
 	}

	return 0;
}

//Answer:
//g++ median.cpp  Student_info.cpp grade.cpp chap40.cpp -o chap40.o