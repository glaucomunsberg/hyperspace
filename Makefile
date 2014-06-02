all:
	@echo You need pass througth the make the parameter \'open\' or \'cilk\'
	
open: Open.cpp
	g++ -g -Wall -o openmp -fopenmp Open.cpp
cilk:
	g++ -g -Wall -o cilkplus cilkPlus.cpp
clean: 
	$(RM) count *.o *~
