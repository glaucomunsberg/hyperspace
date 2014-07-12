all:
	@echo You need pass througth the make the parameter \'open\', \'cilk\', \'graph\' or 'generator'
	
open:
	cd openmp/; make

cilk:
	cd cilk; -C make

graph:
	g++ -g -Wall -o graph Graph.cpp

generator:
	cd graphGenerator/; g++ -g -Wall -o generator GraphGenerator.cpp

clean: 
	$(RM) count *.o *~
