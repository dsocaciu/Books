//Accelerated C++
//Chapter 4 Organizing programs and data
//Question 4-6 Student info source file

#include "Student_info46.h"

using std::istream;
using std::vector;

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}

istream& read(istream& is, Student_info& s)
{
	double midterm, final;
	vector<double> homework;
	is >> s.name >> midterm >> final;
	read_hw(is, homework);
	double average = 0;
	for (int i = 0; i < homework.size(); i++)
	{
		average += homework[i];
	}
	average = average/homework.size();

	s.final = 0.2 * midterm + 0.4 * final + 0.4 * average;

	return is;
}

istream& read_hw(istream& in, vector<double>& hw)
{
	if (in){
		// get rid of previous contents
		hw.clear();

		//read homework grades
		double x;
		while (in >> x){
			hw.push_back(x);
		}

		//clear the stream so that the input will work for the next student
		in.clear();
	}
}