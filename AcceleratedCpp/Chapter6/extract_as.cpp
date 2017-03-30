#include <vector>
#include <list>
#include <algorithm>
#include "grade.h"
#include "median.h"
#include "Student_info.h"
#include "extract_as.h"


using std::vector; using std::list;

//predicate to determine whether a student failed
bool agrade(const Student_info& s){
	return grade(s) > 90;
}

bool notagrade(const Student_info& s)
{
	return !agrade(s);
}




//single pass solution
vector<Student_info> extract_as(vector<Student_info> & students)
{
	vector<Student_info>::iterator iter = stable_partition(students.begin(),students.end(), notagrade);
	vector<Student_info> a(iter,students.end());
	students.erase(iter,students.end());

	return a;

}