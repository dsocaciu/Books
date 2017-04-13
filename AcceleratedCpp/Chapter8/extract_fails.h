#ifndef GUARD_extract_fail_h
#define GUARD_extract_fail_h



#include <vector>
#include <list>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::vector; using std::list;

bool fgrade(const Student_info& s);
bool pgrade(const Student_info& s);
vector<Student_info> extract_fails1(vector<Student_info>& students);
vector<Student_info> extract_fails2(vector<Student_info>& students);



#endif 