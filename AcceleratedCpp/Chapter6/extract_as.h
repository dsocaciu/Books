#ifndef GUARD_extract_a_h
#define GUARD_extract_a_h



#include <vector>
#include <list>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::vector; using std::list;

bool agrade(const Student_info& s);
bool notagrade(const Student_info& s);
vector<Student_info> extract_as(vector<Student_info>& students);



#endif 