//Accelerated C++
//Chapter 6 Using library algorithms
//Question 6-8


#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "grade.h"
#include "Student_info.h"
#include "extract_as.h"

using std::vector;	using std::cin;	using std::cout; 	using std::endl;
using std::domain_error;			using std::ostream;	using std::string;

bool did_all_hw(const Student_info& s)
{
	return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}


double average(const vector<double>& v)
{
	return accumulate(v.begin(),v.end(),0.0) / v.size();
}

double average_grade(const Student_info& s)
{
	return grade(s.midterm,s.final,average(s.homework));
}



double grade_aux(const Student_info& s)
{
	try{
		return grade(s);
	}catch (domain_error)
	{ 	//catch the case where students did no homework
		return grade(s.midterm,s.final, 0);
	}
}

//this version works fine
double analysis(const vector<Student_info>& students, double grade_determine(const Student_info& s))
{
	vector<double> grades;

	transform(students.begin(), students.end(), back_inserter(grades), grade_determine);
	return median(grades);
}

//median of the nonzero elements of s.homework or 0 if no such elements exist
double optimistic_median(const Student_info& s)
{
	vector<double> nonzero;
	remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);

	if(nonzero.empty())
		return grade(s.midterm,s.final,0);

	else
		return grade(s.midterm,s.final,median(nonzero));
}


void write_analysis(ostream& out, const string& name, 
	double grade_determine(const Student_info& s),
		const vector<Student_info>& did,
		const vector<Student_info>& didnt)
{
	out << name << ": median(did) = " << analysis(did,grade_determine) << 
				   ", median(didnt) = " << analysis(didnt,grade_determine) << endl; 
}


int main()
{
	vector<Student_info> did;
	Student_info student;

	//read all records, separating them based on whether all homework was done
	while (read(cin,student)){
				did.push_back(student);
	}

	vector<Student_info>::iterator iter = stable_partition(did.begin(),did.end(),did_all_hw);
	vector<Student_info> didnt(iter,did.end());
	did.erase(iter,did.end());

	vector<Student_info> asVector = extract_as(did);
	//cout << asVector.size() << endl;

	vector<Student_info>::iterator a_iter = asVector.begin();

	//print the A students
	while (a_iter != asVector.end())
	{
		cout << a_iter->name << endl;
		a_iter++;
	}


	//check that both groups contain data
	if(did.empty()) {
		cout << "No student did all the homework!" << endl;
		return 1;
	}

	if(didnt.empty()){
		cout << "Every student did all the homwork!" << endl;
		return 1;
	}


	



	return 0;
}	


	//vector<Student_info> failsVector;
	//failsVector = extract_fails3(students_vector);
	//cout << failsVector.size() << endl;
