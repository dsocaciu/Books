#include <algorithm>

#ifdef _MSC_VER
#include "../minmax.h"
#else
using std::min;
#endif

#include "Core.h"
#include "grade.h"

using std::istream;
using std::string;
using std::vector;
std::istream& read_hw(std::istream& in, std::vector<double>& hw);

string Core::name() const { return n; }

bool Core::valid() const{ return !homework.empty(); }


double Core::grade() const
{
	//std::cout << "Core:grade()" << std::endl;
	return ::grade(midterm, final, homework);
}

string Core::letter_grade() const {
// range posts for numeric grades 
	static const double numbers[] = {
	97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0 };
// names for the letter grades

static const char* const letters[] = {
"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F" };
// compute the number of grades given the size of the array
// and the size of a single element
	static const size_t ngrades = sizeof(numbers)/sizeof(*numbers);
// given a numeric grade, find and return the associated letter grade 
	for (size_t i = 0; i < ngrades; ++i) {
		if (::grade(midterm, final, homework) >= numbers[i]) return letters[i];
	}
        return "?\?\?";
}


istream& Core::read_common(istream& in)
{
	// read and store the student's name and exam grades
	in >> n >> midterm >> final;
	return in;
}

istream& Core::read(istream& in)
{
	read_common(in);
	read_hw(in, homework);
	return in;
}

istream& Grad::read(istream& in)
{
	read_common(in);
	in >> thesis;
	read_hw(in, homework);
	return in;
}



bool Grad::valid() const{ return !homework.empty() && thesis != 0; }

double Grad::grade() const
{
	//std::cout << "Grade::grade()" << std::endl;
	return min(Core::grade(), thesis);
}

istream& PassFail::read(istream& in)
{
	read_common(in);
	read_hw(in, homework);
	return in;
}

double PassFail::grade() const
{
	//std::cout << "Grade::grade()" << std::endl;
	//return ::grade(midterm, final, homework);
	if( homework.empty() )
	{
		return (midterm + final )/ 2;
	}
	else
	{
		return Core::grade();
	}
	
}

string PassFail::letter_grade() const {
	if (PassFail::grade() > 60){
		return "Pass";
	}
	else{
		return "Fail";
	}
}


bool compare(const Core& c1, const Core& c2)
{
	return c1.name() < c2.name();
}

bool compare_Core_ptrs(const Core* cp1, const Core* cp2)
{
	return compare(*cp1, *cp2);
}

