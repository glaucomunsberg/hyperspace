##########################################################################
#                       Hyperspace - Trabalho de IPPD
##########################################################################
#
# 1.Introdution
# 2. How was implemented
# 3. How to run
# 4. Generator
# 5. Results
#
# @autor   Glauco Roberto Munsberg dos Santos
# @github  git@github.com:glaucomunsberg/hyperspace.git
# @version 1.0
#
##########################################################################
# 1. Introdution
##########################################################################
#
#   That's the job of the Introduction of Parallel and Distributed 
#	Processing. Implement one of the applications described in 
#	http://iss.ices.utexas.edu/?p=projects/galois (item Benchmarks) by at 
#	least two of the software tools listed. Developing a methodology to 
#	assess the performance of the program implemented in one (or different)
#	architecture (s) parallel (s). Conduct performance analysis.
#
#	Software Tools: Multiprocessor architecture, cluster e GPU
#	Hardware Tools: Pthreads, Threads C++11, Cilk, TBB, OpenMP,  MPI, CUDA,
#	OpenCL.
#
#	Software and Hardware chosen:
#		Multiprocessor Architecture as a Hardware Tool
#		Cilk and OpenMP as a  Software Tools
#
##########################################################################
# 2. How was implemented
##########################################################################
#
#   Was programed by Glauco Roberto Munsberg dos Santos and developed 
#	between de May 9 at Jule 30 of 2014 with C++98 linguage. Using 
#	Orientation Object Method to construct a powerful and cleaned code.
#	Each of classes of library(Cilk and OpenMP) is derivative of Graph
#	Class, that implement the virtual methods.
#	
#	2.1 Class Structure:
#
#		Adjacency{
#			int node1;
#			int node2;
#			int value;
#		}
#
#		Nodo{
#			int value;
#			int tree;
#		}
#
#		Graph{
#			vector<Adjacency> adjacencies;
#			vector<Adjacency> minimumAdjacencies;
#			vector<Node> edges;
#			int **matrix;
#			int sizeGraph;
#			int getSize();
#
#			void printMatrix();
#			void printMinimumWeightSpanningTree();
#			void inicialize();
#			void openFile(string fileName);
#			void setSize(int size);
#
#			virtual void minimumWeightSpanningTree()=0;
#			virtual void insertEdges(int adj1, int adj2)=0;	
#			virtual void removeEdges(int adj1, int adj2)=0;
#		}
#
#		GraphCilk: public Graph{
#			GraphCilk(){}
#			~GraphCilk(){}
#			std::mutex mtx;
#
#			void insertEdges(int adj1, int adj2);
#			void removeEdges(int adj1, int adj2);
#			void checkAdjacencies();
#			void minimumWeightSpanningTree();
#		}
#
#		GraphOpen: public Graph{
#			GraphOpen(){}
#			~GraphOpen(){}
#
#			void insertEdges(int adj1, int adj2);
#			void removeEdges(int adj1, int adj2);
#			void minimumWeightSpanningTree();
#			void checkAdjacencies();
#		}
#
#	2.2 Archives Structure:
#		Graph.cpp
#		Graph.hpp
#		GraphCilk.cpp
#		GraphCilk.hpp
#		GraphOpen.hpp
#		GraphOpen.cpp
#
##########################################################################
# 3. How to run
##########################################################################
#
#   Trought of GitHub is possible get all files individual to run this
#	project. Might inclusive see and look other versions of this projetct.
#
#	3.1 Minimum Requests Install
#		C++98
#		Cilk Library 	(Intel Composer XE 2013 SP1)
#		OpenMP Library
#		Boost Library
#		
#	3.2 Compilation
#		The compilation is simple, you need use make command with one the
#		libraries or using the default graph without parallel mode.
#
#		$ make <graph|cilk|open|generator*>
#
#	3.3 Executation
#
#		Look at the compilation way to see the out file and pass through
#		parameter the file whit graph. Look an example to Cilk Graph and 
#		the file GraphData.txt whit an example graph and 5 threads:	
#
#		$ cd cilk
#		$ make
#		$ ./graphCilk ../GraphData.txt 5
#
#		Atention: if none file is passed by parameter is used the default
#		example.
#
#	3.4 Building a Graph
#		The construction of the graph file is this way:
#		~<Number of Nodes> 
#		~<Number of Node> <Number of Node> <Weight>
#		~<IOF>
#		
#		An example of Graph:
#		~2
#		~0 1 8
#		~1 0 2
#
#		Atention: Note that if in a node have a weight do adjacency and 
#		that weight is not synchronous.
#
#		* To understant better the generator look at quarter topic.
#
##########################################################################
# 4. Results
##########################################################################
#
#	GraphGenerator is a generator of graphs tool that can assist you to
#	you get a random graph to and help you to test is implementation. If
#	you need compile, do like is described on 3.2 topic (using generator
#	parameter) and you might use pass through three parameter (you have 
#	an obrigation to pass two only), look below how:
#
#	$ make generator
#	$ cd graphGenerator
#	$ ./generator <num_nodos> <num_adjacencies> <file_out>
#
#	<num_nodos> and <num_adjacencies> need be more than 0
#
##########################################################################
# 5. Results
##########################################################################
#
#	Below we have som results obtained trough simluations using a 
#	graph with 7 edges and 11 adjacencys.
#		
#	5.1 Simulation Cilk
#		real	0m0.005s
#		user	0m0.002s
#		sys	0m0.002s
#	5.2 Simulation OpenMP
#		real	0m0.005s
#		user	0m0.001s
#		sys	0m0.003s
#
##########################################################################
