//Accelerated C++
//Chapter 10 Managing memory and low-level data structures
//Question 10-0


#include <iostream>
#include <string>

using std::cout;	using std::endl;	using std::string;

int next(int n)
{
	return n + 1;
}

//Example implmentation of standard-library function 
size_t strlen(const char* p)
{
	size_t size = 0;
	while(*p++ != '\0')
		++size;
	return size;
}

string letter_grade(double grade)
{
	//range posts for numeric grades
	static const double numbers[] = {97, 94,90, 87, 84, 80, 77, 74, 70, 60, 0};

	//names for the letters grades
	static const char* const letters[] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"};

	//compute the number of grades given the size of the array
	//and the size of a single elements
	static const size_t ngrades = sizeof(numbers)/sizeof(*numbers);

	//given a numeric grade, find and return the  associated letter grade
	for(size_t i = 0; i < ngrades; ++i)
	{
		if(grade >= numbers[i])
			return letters[i];
	}

	return "?\?\?";
}

int main()
{
	
	int *p1; 		//*p1 has type int

	int* p2;		//*p2 has type int*


	int* p3, q3; //What does this definition mean?
	//Defines p3 as an object of type 'pointer to int' and q3 as an object of type int

	//Easier to define
	int *p4, q4;	// *p4 and q4 have type int

	int (*p5),q5;	// (*p5) and q5 have type int


	//Make intentions crystal clear by writing
	int *p6;	//*p6 has type int
	int q6;		//q6 has type int

	int x = 5;

	// p points to x
	int*p = &x;
	cout << "x = " << x << endl;

	//change the value of x through p
	*p = 6;
	cout << "x = " << x << endl;


	int (*fp)(int);

	fp = next;

	int i = fp(x);

	cout << "i = " << i << endl;

	const char hello[] = { 'H', 'e', 'l', 'l', 'o', '\0'};

	cout << "strlen(hello) " << strlen(hello) << endl;

	cout << "strlen('hello') " << strlen("hello") << endl; 

	cout << "letter_grade(96.5)" << letter_grade(96.5) << endl;
 

	return 0;
}