//Accelerated C++
//Chapter 6 Using library algorithms
//Question 6-5


#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "grade.h"
#include "Student_info.h"
#include "extract_fails.h"

using std::vector;	using std::cin;	using std::cout; 	using std::endl;
using std::domain_error;			using std::ostream;	using std::string;

bool did_all_hw(const Student_info& s)
{
	return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}

/*
//this function doesn't quite work

double median_analysis(const vector<Student_info>& students)
{
	vector<double> grades;

	transform(students.begin(),students.end(), back_inserter(grades), grade);
	return median(grades);
}

// transform doesn't know which version of grade to call sans arguments
// also can't handle expection if student did no homework

*/

double average(const vector<double>& v)
{
	return accumulate(v.begin(),v.end(),0.0) / v.size();
}

double average_grade(const Student_info& s)
{
	return grade(s.midterm,s.final,average(s.homework));
}

double average_analysis(const vector<Student_info>& students)
{
	vector<double> grades;

	transform(students.begin(),students.end(),back_inserter(grades),average_grade);
	return median(grades);
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
double median_analysis(const vector<Student_info>& students)
{
	vector<double> grades;

	transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
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

double optimistic_median_analysis(const vector<Student_info>& students)
{
	vector<double> grades;

	transform(students.begin(),students.end(),back_inserter(grades),optimistic_median);
	return median(grades);
}


void write_analysis(ostream& out, const string& name, 
	double analysis(const std::vector<Student_info>&),
		const vector<Student_info>& did,
		const vector<Student_info>& didnt)
{
	out << name << ": median(did) = " << analysis(did) << 
				   ", median(didnt) = " << analysis(didnt) << endl; 
}


int main()
{
	vector<Student_info> did,didnt;
	Student_info student;

	//read all records, separating them based on whether all homework was done
	while (read(cin,student)){
		if(did_all_hw(student))
			did.push_back(student);
		else
			didnt.push_back(student);
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

	//do the analyses
	write_analysis(cout,"median", median_analysis, did, didnt);
	write_analysis(cout,"average", average_analysis,did, didnt);
	write_analysis(cout,"median of homework turned in",optimistic_median_analysis,did,didnt);


	return 0;
}