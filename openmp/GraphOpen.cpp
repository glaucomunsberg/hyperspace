#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <exception>
#include <stdlib.h>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoi */
#include <string>
#include "../Graph.hpp"
#include "GraphOpen.hpp"
#include </opt/intel/composer_xe_2013_sp1.2.144/compiler/include/omp.h>
using namespace std;

void GraphOpen::insertEdges(int adj1, int adj2){
	matrix[adj1][adj2]++;
}

void GraphOpen::removeEdges(int adj1, int adj2){

	if(matrix[adj1][adj2] > 0){

		matrix[adj1][adj2]--;
	}
}

void GraphOpen::minimumWeightSpanningTree(){
	
	for(int a =0;a < getSize(); a++){
		edges.push_back(Node(a,a));
		for(int b =0; b < getSize(); b++){
			
			if(matrix[a][b] != 0){
				
				adjacencies.push_back(Adjacency(a,b,matrix[a][b]));
			}
		}
	}

	std::sort(adjacencies.begin(), adjacencies.end(), lessThanKey());

	while(!adjacencies.empty()){
		checkAdjacencies();
	}
}
void GraphOpen::checkAdjacencies(){
	Adjacency *tmpAdjacency;
	int change;
	tmpAdjacency = &adjacencies.at(0);	
	if(edges[tmpAdjacency->node1].tree != edges[tmpAdjacency->node2].tree){
		
		minimumAdjacencies.push_back(Adjacency(tmpAdjacency->node1,tmpAdjacency->node2,tmpAdjacency->value));
		change = edges[tmpAdjacency->node2].tree;
		#pragma opm parallel
		{
			#pragma opm for schedule(dynamic,2)
			for(int a=0; a < (int)edges.size(); a++){
				cout << a << endl;
				if(edges[a].tree == change){
					edges[a].tree = edges[tmpAdjacency->node1].tree;
				}
			}
		}
		
	}

	adjacencies.erase(adjacencies.begin());
}

int main(int argc, char* argv[]) {
	
	if(argc > 2){
		omp_set_num_threads(atoi(argv[2]));
		cout << "Graph->GraphOpen()" << endl << "Threads:" << argv[2] << endl;
	}else{
		cout << "Graph->GraphOpen()" << endl << "Threads:" <<  omp_get_num_threads() << endl;
	}

	Graph *graph;
	graph = new GraphOpen();
	graph->setSize(2);
	graph->inicialize();
	
	string file = "";
	if(argc <= 1){
		file = "GraphData.txt";
	}else{
		file = argv[1];
		
	}
	graph->openFile(file);

	graph->printMatrix();
	
	graph->minimumWeightSpanningTree();
	graph->printMinimumWeightSpanningTree();
	return 0;
}
