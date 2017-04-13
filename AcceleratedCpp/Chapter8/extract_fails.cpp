#include <vector>
#include <list>
#include <algorithm>
#include "grade.h"
#include "median.h"
#include "Student_info.h"
#include "extract_fails.h"


using std::vector; using std::list;

//predicate to determine whether a student failed
bool fgrade(const Student_info& s){
	return grade(s) < 60;
}

bool pgrade(const Student_info& s){
	return !fgrade(s);
}


//double pass solution
vector<Student_info> extract_fails1(vector<Student_info> & students)
{
	vector<Student_info> fail;

	remove_copy_if(students.begin(),students.end(),back_inserter(fail),pgrade);

	students.erase(remove_if(students.begin(),students.end(),fgrade),students.end());
	

	return fail;
}



//single pass solution
vector<Student_info> extract_fails2(vector<Student_info> & students)
{
	vector<Student_info>::iterator iter = stable_partition(students.begin(),students.end(), pgrade);
	vector<Student_info> fail(iter,students.end());
	students.erase(iter,students.end());

	return fail;

}