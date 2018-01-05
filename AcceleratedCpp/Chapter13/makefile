CXX = g++
CC = g++
CXXFLAGS = -I. -I../Chapter8

all:		main_core main_grad main_orig main_core_ptrs

Core.o:	Core.cc Core.h

Grad.o:	Grad.cc Core.h

Student_info.o:	Student_info.cc ../Chapter8/median.h Student_info.h Core.h

grade.o:	grade.cc ../Chapter8/median.h Student_info.h

read_hw.o:	read_hw.cc ../Chapter8/median.h Student_info.h

main_core.o:	main_core.cc Core.h ../Chapter8/median.h

main_grad.o:	main_grad.cc Core.h ../Chapter8/median.h

main_orig.o:	main_orig.cc Core.h ../Chapter8/median.h Student_info.h

main_core_ptrs.o:	main_core_ptrs.cc Core.h ../Chapter8/median.h

main_orig:	main_orig.o grade.o Student_info.o read_hw.o Core.o

main_core:	main_core.o grade.o  read_hw.o Core.o

main_grad:	main_grad.o grade.o  read_hw.o Core.o

main_core_ptrs:	main_core_ptrs.o grade.o  read_hw.o Core.o

test:		all
	./main_core <../data/grades_core
	./main_grad <../data/grades_grad
	./main_orig <../data/mixed_grades
	./main_core_ptrs <../data/mixed_grades

clobber:
	rm -f *.o *.exe core main_core main_grad main_orig main_core_ptrs
