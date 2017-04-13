#ifndef GUARD_Student_info91
#define GUARD_Student_info91

#include <vector>
#include <string>


class Student_info{
	public:
		Student_info();
		Student_info(std::istream&);
		std::string name() const { return n;}
		bool valid() const { return !homework.empty(); }

		//as defined in 9.2.1/157, and changed to read into n instead of name
		std::istream& read(std::istream&);

		double grade() const; //as defined in 9.2.1/158

	private:
		std::string n;
		double midterm, final;
		std::vector<double> homework;
		double fin_grade;

};

bool compare(const Student_info &, const Student_info&);

#endif