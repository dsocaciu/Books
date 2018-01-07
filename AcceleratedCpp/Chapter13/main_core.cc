#include <algorithm>

#ifndef __GNUC__
#include <ios>
#endif

#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

#include "Core.h"

using std::cout;           using std::cin;
using std::endl;           using std::domain_error;
using std::setprecision;   using std::setw;
using std::sort;           using std::streamsize;
using std::string;         using std::vector;

#ifdef _MSC_VER
#include "../minmax.h"
#else
using std::max;
#endif

int main()
{




	vector<Core> students;          // read and process `Core' records
	Core record;
	string::size_type maxlen = 0;

	// read and store the data
	while (record.read(cin)) {
		maxlen = max(maxlen, record.name().size());
		students.push_back(record);
	}

	// alphabetize the student records
	sort(students.begin(), students.end(), compare);

	// write the names and grades
#ifdef _MSC_VER
	for (std::vector<Core>::size_type i = 0; i != students.size(); ++i) {
#else
	for (vector<Core>::size_type i = 0; i != students.size(); ++i) {
#endif
		cout << students[i].name()
		     << string(maxlen + 1 - students[i].name().size(), ' ');
		try {
			double final_grade = students[i].grade(); // `Core::grade'
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
			     << setprecision(prec) << endl;
		} catch (domain_error e) {
			cout << e.what() << endl;
		}
	}

	Core* p1 = new Core; Core* p2 = new Grad; Core s1;
	Grad s2;
	//p1->grade();
	 p1->name();
	//p2->grade(); 
	 p2->name();
	//s1.grade(); 
	 s1.name();
	s2.name(); 
	//s2.grade();

	return 0;
}

