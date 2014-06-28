##########################################################################
#                       Hyperspace - Trabalho de IPPD
##########################################################################
#
# 1.Introdution
# 2. How was implemented
# 3. How to run
# 4. Results
# 5. Conclusion
#
# @autor   Glauco Roberto Munsberg dos Santos
# @github  git@github.com:glaucomunsberg/hyperspace.git
# @version 0.8
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
#		}
#
#		GraphCilk: public Graph{}
#
#		GraphOpen: public Graph{}
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
#		Cilk Library
#		OpenMP Library
#		
#	3.2 Compilation
#		The compilation is simple, you need use make command with one the
#		libraries or using the default graph without parallel mode.
#
#		$ make <cilk|open>
#
#	3.3 Executation
#
#		Look at the compilation way to see the out file and pass through
#		parameter the file whit graph. Look an example to Cilk Graph and 
#		the file GraphData.txt whit an example graph:
#
#		$ ./graphCilk GraphData.txt
#
#		Atention: if none file is passed by parameter is used the default
#		example.
#
#	3.4 Building a Graph
#		The construction of the graph file is this way:
#		~<Number of Nodes>
#		~
#		~<Node Number>
#		~<Nodo whit have adjacency>
#		~
#		~<Node Number>
#		~<Nodo whit have adjacency>
#		~<Nodo whit have adjacency>
#		~<IOF>
#		
#		Atention: Note that if in a node have two lines adjacency to the
# 		same other node, means that they  have the weight 2.
##########################################################################
# 4. Results
##########################################################################
#
#   Abaixo temos alguns dos resultados obtidos pelas simulações, todos
#   foram realizados a partir da versão 0.9.1 na Trie e 0.9.6 da sufixo
#   onde não se dectou mais problemas de lógica na inserção, remoção e 
#   busca com arquivos médianos.
#
# 	4.1 Simulation Cilk
#   4.2 Simulation OpenMP
#
##########################################################################
# 5. Conclusion
##########################################################################
#
#   
#
##########################################################################