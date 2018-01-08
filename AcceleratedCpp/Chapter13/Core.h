#ifndef GUARD_Core_h
#define GUARD_Core_h

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

class Core {
public:
	Core(): midterm(0), final(0) { }
	Core(std::istream& is) { read(is); /*std::cerr << "Core::Core(istream&)" << std::endl;*/}

	std::string name() const;

	// as defined in 13.1.2/230
	virtual std::istream& read(std::istream&);
	virtual double grade() const;

	virtual ~Core() { }

	virtual bool valid() const;
	virtual std::string letter_grade() const;

protected:
	// accessible to derived classes
	std::istream& read_common(std::istream&);
	double midterm, final;
	std::vector<double> homework;

	virtual Core* clone() const { return new Core(*this); }

private:
	// accessible only to `Core'
	std::string n;
	friend class Student_info;
};

class Grad: public Core {
public:
	Grad(): thesis(0) { }
	Grad(std::istream& is) { read(is); /*std::cerr << "Grad::Grad(istream&)" << std::endl;*/ }

	bool valid() const;
	// as defined in 13.1.2/230; Note: `grade' and `read' are `virtual' by inheritance
	double grade() const;
	std::istream& read(std::istream&);
private:
	double thesis;
#ifdef _MSC_VER
	Core* clone() const { return new Grad(*this); }
#else
	Grad* clone() const { return new Grad(*this); }
#endif
};

class PassFail: public Core {
public:
	PassFail(): pass(0){ }
	PassFail(std::istream& is) { read(is); /*std::cerr << "PassFail::PassFail(istream&)" << std::endl;*/ }

	bool valid() const;
	// as defined in 13.1.2/230; Note: `grade' and `read' are `virtual' by inheritance
	double grade() const;
	std::istream& read(std::istream&);
	std::string letter_grade() const;
private:
	double pass;
#ifdef _MSC_VER
	Core* clone() const { return new PassFail(*this); }
#else
	PassFail* clone() const { return new PassFail(*this); }
#endif
};

class Audit: public Core {
public:
	Audit(): audit(0){ }

	std::string letter_grade() const;
private:
	double audit;
#ifdef _MSC_VER
	Core* clone() const { return new Audit(*this); }
#else
	Audit* clone() const { return new Audit(*this); }
#endif
};

bool compare(const Core&, const Core&);
bool compare_Core_ptrs(const Core* cp1, const Core* cp2);

#endif

