all:
	@echo You need pass througth the make the parameter \'open\', \'cilk\' or \'graph\'
	
open:
	g++ -g -Wall -o graphOpen GraphOpen.cpp Graph.cpp

cilk:
	g++ -g -Wall -o graphCilk GraphCilk.cpp Graph.cpp

graph:
	g++ -g -Wall -o graph Graph.cpp

clean: 
	$(RM) count *.o *~
