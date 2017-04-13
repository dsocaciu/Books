#include <iostream>
#include <vector>

#include "Student_info95.h"

using std::vector;	using std::istream;	using std::string;

string Student_info::grade() const
{
	return (midterm+final)/2 > 60 ? "P" : "F";
}

string Student_info::final_grade() const
{
	return fin_grade;
}


bool compare(const Student_info& x, const Student_info& y)
{
	return x.name() < y.name();
}


Student_info::Student_info(): midterm(0), final(0) { }

Student_info::Student_info(istream& is) { read(is); }


istream& Student_info::read(istream& in)
{
	in >> n >> midterm >> final;
	fin_grade = grade();
	return in;
}



