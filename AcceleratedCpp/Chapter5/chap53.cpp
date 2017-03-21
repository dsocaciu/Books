//Accelerated C++
//Chapter 5 Using sequential containers and analyzing strings
//Question 5-0 

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

//separate passing and failing student records; first try
vector<Student_info> extract_fails1(vector<Student_info> & students)
{
	vector<Student_info> pass, fail;

	for (vector<Student_info>::size_type i =0; i != students.size(); ++i)
		if(fgrade(students[i]))
			fail.push_back(students[i]);
		else
			pass.push_back(students[i]);
	students = pass;
	return fail;
}

//second try: correct but potentially slow
vector<Student_info> extract_fails2(vector<Student_info>& students)
{
	vector<Student_info> fail;
	vector<Student_info>::size_type i = 0;

	//invariants: elements [ 0,i) of students represent failing passing grades
	while (i != students.size()){
		if (fgrade(students[i])){
			fail.push_back(students[i]);
			students.erase(students.begin() + i);
		}
		else
			++i;
			
	}
	return fail;
}

//version three: iterators but no indexing; still potentially slow
vector<Student_info> extract_fails3(vector<Student_info>& students)
{
	vector<Student_info> fail;
	vector<Student_info>::iterator iter = students.begin();

	while(iter != students.end()){
		if (fgrade(*iter)){
			fail.push_back(*iter);
			iter = students.erase(iter);
		}
		else
			++iter;
	}

	return fail;
}

//version four: use list instead of vector
list<Student_info> extract_fails4(list<Student_info>& students){
	list<Student_info> fail;
	list<Student_info>::iterator iter = students.begin();

	while(iter != students.end())
	{
		if(fgrade(*iter)){
			fail.push_back(*iter);
			iter = students.erase(iter);
		}
		else
			++iter;
	}

	return fail;
}


int main()
{
	typedef vector<Student_info> students_v;

	students_v students_vector;

	Student_info record;
	string::size_type maxlen = 0;	//length of the longest name

	typedef list<Student_info> students_l;

	students_l students_list;

	//read and store all the students' data.
	//Invariant: students contains all the studnets records read so far
	//			 maxlen contains the length of the longest name in the students
	while (read(cin, record)){
		maxlen = max(maxlen,record.name.size());
		students_vector.push_back(record);
		students_list.push_back(record);
	}


	//alphabetize the student records
	sort(students_vector.begin(),students_vector.end(),compare);
	students_list.sort(compare);

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
	failsVector = extract_fails3(students_vector);
	cout << failsVector.size() << endl;

	list<Student_info> failsList;
	failsList = extract_fails4(students_list);
	cout << failsList.size() << endl;

	return 0;
}

