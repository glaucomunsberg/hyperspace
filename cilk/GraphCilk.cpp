#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <stdlib.h>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoi */
#include <string>
#include "../Graph.hpp"
#include "GraphCilk.hpp"
#include </opt/intel/composer_xe_2013_sp1.2.144/compiler/include/cilk/cilk_stub.h>
#include </opt/intel/composer_xe_2013_sp1.2.144/compiler/include/cilk/cilk_api.h>
#include </opt/intel/composer_xe_2013_sp1.2.144/compiler/include/cilk/cilk.h>

using namespace std;

void GraphCilk::insertEdges(int adj1, int adj2, int value){

	matrix[adj1][adj2] = value;
}

void GraphCilk::removeEdges(int adj1, int adj2){

	if(matrix[adj1][adj2] > 0){

		matrix[adj1][adj2]--;
	}
}

void GraphCilk::minimumWeightSpanningTree(){
	
	cilk_for(int a =0;a < getSize(); a++){
		
		edges.push_back(Node(a,a));
		cilk_for(int b =0; b < getSize(); b++){
			if(matrix[a][b] != 0){
				adjacencies.push_back(Adjacency(a,b,matrix[a][b]));
			}
		}
	}

	std::sort(adjacencies.begin(), adjacencies.end(), lessThanKey());
	
	
	int idThread =0;
	Adjacency *tmpAdjacency, tmpAdjacency1;
	while(!adjacencies.empty()){
		
		tmpAdjacency = &adjacencies.at(0);
		cilk_spawn checkAdjacencies(&tmpAdjacency,idThread);
		idThread++;
		adjacencies.erase(adjacencies.begin());

		tmpAdjacenc1 = &adjacencies.at(0);

		while(tmpAdjacency->value == tmpAdjacenc1->value){

			cilk_spawn checkAdjacencies(&tmpAdjacency1,idThread);
			idThread++;
			adjacencies.erase(adjacencies.begin());
		}

		cilk_sync;
	}
	
}
void GraphCilk::checkAdjacencies(Adjacency tmpAdjacency, int thread){
	
	GraphCilk::mtx.lock();

	int change;
	int removePosition;

	if(edges[tmpAdjacency->node1].tree != edges[tmpAdjacency->node2].tree){
		
		minimumAdjacencies.push_back(Adjacency(tmpAdjacency->node1,tmpAdjacency->node2,tmpAdjacency->value));
		change = edges[tmpAdjacency->node2].tree;
		for(int a=0; a < (int) edges.size(); a++){
			
			if(edges[a].tree == change){
				edges[a].tree = edges[tmpAdjacency->node1].tree;
			}
		}
	}

	for(int a=0; a < adjacencies.size();a++){
		if(tmpAdjacency == &adjacencies.at(a) ){
			removePosition = a;
		}
	}

	delete tmpAdjacency;
	
	GraphCilk::mtx.unlock();
}

int main(int argc, char* argv[]) {

	cout << "Graph->GraphCilk()" << endl;
	if(argc > 2){

		__cilkrts_end_cilk();  
		__cilkrts_set_param("nworkers", argv[2]);
		cout << "\tThreads:" << argv[2] << endl;
	}else{

		cout << "\tThreads:" <<  __cilkrts_get_nworkers() << endl;
	}

	Graph *graph;
	graph = new GraphCilk();
	std::string file = "";


	graph->setSize(2);
	graph->inicialize();

	if(argc <= 1){

		file = "graphExample1Data.txt";
	}else{

		file = argv[1];
		
	}

	graph->openFile(file);
	graph->printMatrix();
	graph->minimumWeightSpanningTree();
	graph->printMinimumWeightSpanningTree();
	
	return 0;
}
