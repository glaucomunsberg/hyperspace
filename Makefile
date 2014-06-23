all:
	@echo You need pass througth the make the parameter \'open\', \'cilk\' or \'graph\'
	
open: Open.cpp

	g++ -g -Wall -o openmp -fopenmp Open.cpp
cilk:
	g++ -g -Wall -o cilkplus cilkPlus.cpp
graph:
	g++ -g -Wall -o graph Graph.cpp
clean: 
	$(RM) count *.o *~
