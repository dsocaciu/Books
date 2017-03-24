//Accelerated C++
//Chapter 5 Using sequential containers and analyzing strings
//Question 5-6

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

using namespace std;

//predicate to determine whether a student failed
bool fgrade(const Student_info& s){
	return grade(s) < 60;
}





//updated for 5-6  
vector<Student_info> extract_fails2(vector<Student_info>& students)
{
	cout << "extract_fails2" << endl;
	vector<Student_info>::size_type i = 0, j = 0;


	//invariants: elements [ 0,i) of students represent failing passing grades
	while (i != students.size()){
		if (!fgrade(students[i])){
			
			students.insert(students.begin(),students[i++]);
			j++;

		}
		++i;
			
	}
	students.resize(j);

	vector<Student_info>::iterator iter = students.begin();
	while (iter != students.end())
	{
		cout << iter->name << endl;
		iter++;
	}

	return students;
}





int main()
{



	vector<Student_info> students_vector;

	Student_info record;
	string::size_type maxlen = 0;	//length of the longest name


	//read and store all the students' data.
	//Invariant: students contains all the studnets records read so far
	//			 maxlen contains the length of the longest name in the students
	while (read(cin, record)){
		maxlen = max(maxlen,record.name.size());
		students_vector.push_back(record);
	}

		sort(students_vector.begin(),students_vector.end(),compare);
	//students_list.sort(compare);

	// write the names and grades
	for (vector<Student_info>::size_type i = 0; i != students_vector.size(); ++i)
	{

		//write the name , padded on the right to maxlen+ 1 characters
		cout << students_vector[i].name
			 << string(maxlen + 1 - students_vector[i].name.size(), ' ');

		//compute and write the grade

		try{
			double final_grade = grade(students_vector[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				 << setprecision(prec);

		} catch( domain_error e){
			cout << e.what();
		}	 
		cout << endl;

	}

	vector<Student_info> failsVector;
	failsVector = extract_fails2(students_vector);
	cout << failsVector.size() << endl;





	return 0;
}


//Compile: g++ median.cpp  Student_info.cpp grade.cpp chap56.cpp -o chap56.o

