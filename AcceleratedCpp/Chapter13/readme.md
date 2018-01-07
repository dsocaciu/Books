Doing a bit of a different approach with chapter 13

The previous chapters were all typed out. For chapter 13 (and probably going forward) I am using the book code provided online and for each exercise and i'm modifying , commiting and pushing it rather than creating new files as copies. Also I will be detailing the exercises below as appropriate. 

13.1 

output: 

Grad::Grad(istream&)<br />
Core::Core(istream&)<br />
Grad::Grad(istream&)<br />
Core::Core(istream&)<br />
Core::Core(istream&)<br />
Core::Core(istream&)<br />
Grad::Grad(istream&)<br />
Core::Core(istream&)<br />
Core::Core(istream&)<br />
Grad::Grad(istream&)<br />
Grad::Grad(istream&)<br />
Grad::Grad(istream&)<br />
Core::Core(istream&)<br />
Core::Core(istream&)<br />
Grad::Grad(istream&)<br />
Core::Core(istream&)<br />
Core::Core(istream&)<br />
Grad::Grad(istream&)<br />
Baker     67.2<br />
Carpenter 82<br />
Davis     74.8<br />
Edwards   73<br />
Franklin  66.6<br />
Harris    92<br />
Jones     77.2<br />
Moo       100<br />
Moore     79.4<br />
Norman    73<br />
Olson     82.8<br />
Peerson   66.6<br />
Russel    79.4<br />
Smith     87.2<br />
Thomas    95.6<br />
Vaughn    87<br />
Westerly  86.2<br />

13.2

Guess:

Core
Core

Grad
Grad

Core
Core

Grad
Grad

Result:

Core::name()
Core::name()
Core::name()
Core::name()

reason: upon review name isn't virtual whereas grade is. 

13.4 
output 
Baker     67.2 D
Carpenter 82 B-
Davis     74.8 C
Edwards   73 B-
Franklin  66.6 D
Harris    92 A-
Jones     77.2 C+
Moo       100 A+
Moore     79.4 C+
Norman    73 C
Olson     82.8 B-
Peerson   66.6 D
Russel    79.4 C+
Smith     87.2 B+
Thomas    95.6 A
Vaughn    87 B+
Westerly  86.2 B
