#ifndef GUARD_Student_info91
#define GUARD_Student_info91

#include <vector>
#include <string>


class Student_info{
	public:
		Student_info();
		Student_info(std::istream&);
		std::string name() const { return n;}

		
		std::istream& read(std::istream&);

		std::string grade() const;
		std::string final_grade() const;


	private:
		std::string n;
		double midterm, final;
		std::string fin_grade;

};

bool compare(const Student_info &, const Student_info&);

#endif