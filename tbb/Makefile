all:
	icpc -ltbb GraphTBB.cpp -o tbb ../Graph.cpp
	#g++ GraphTBB.cpp ../Graph.cpp -std=c++11 -lpthread -o graphpt

clean:
	$(RM) count *.o *~
