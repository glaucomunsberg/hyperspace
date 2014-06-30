all:
	@echo You need pass througth the make the parameter \'open\', \'cilk\' or \'graph\'
	
open:
	cd openmp/; make

cilk:
	cd cilk; -C make

graph:
	g++ -g -Wall -o graph Graph.cpp

clean: 
	$(RM) count *.o *~
