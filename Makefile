all:
	@echo You need pass througth the make the parameter \'open\' or \'cilk\'
	
open: Open.cpp
	g++ -g -Wall -o openmp -fopenmp Open.cpp
cilk:
	@echo Not implemented yet
clean: 
	$(RM) count *.o *~
