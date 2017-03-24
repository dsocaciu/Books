#include <vector>
#include <list>
#include "grade.h"
#include "median.h"
#include "Student_info.h"
#include "extract_fails.h"


using std::vector; using std::list;

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