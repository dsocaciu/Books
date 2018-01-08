#include <iostream>

#include "Core.h"
#include "Student_info.h"

using std::istream;

istream& Student_info::read(istream& is)
{
	delete cp;          // delete previous object, if any

	char ch;
	is >> ch;           // get record type

	if (ch == 'U') {
		cp = new Core(is);
	} 
	/*else if (ch == 'G'){
		cp = new Grad(is);
	}
	else if (ch == 'P')
	{
		cp = new PassFail(is);
	}
	else if (ch == 'A')
	{
		cp = new Audit(is);
	}
	
	else{
		throw std::runtime_error("read invalid student type");
	}*/
	else {
		cp = new Grad(is);
	}


	return is;
}

Student_info::Student_info(const Student_info& s): cp(0)
{
	if (s.cp) cp = s.cp->clone();
}

Student_info& Student_info::operator=(const Student_info& s)
{
	if (&s != this) {
		delete cp;
		if (s.cp)
			cp = s.cp->clone();
		else
			cp = 0;
	}
	return *this;
}

