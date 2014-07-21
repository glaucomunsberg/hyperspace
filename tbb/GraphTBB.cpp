#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <stdlib.h>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoi */
#include <string>
#include "../Graph.hpp"
#include "GraphTBB.hpp"
#include "Check.hpp"
#include "tbb/parallel_for.h"
#include "tbb/blocked_range.h"

using namespace tbb;
using namespace std;

void GraphTBB::insertEdges(int adj1, int adj2, int value){

	matrix[adj1][adj2] = value;
}

void GraphTBB::removeEdges(int adj1, int adj2){

	if(matrix[adj1][adj2] > 0){

		matrix[adj1][adj2]--;
	}
}

void GraphTBB::minimumWeightSpanningTree(){
	
	for(int a =0;a < getSize(); a++){
		
		edges.push_back(Node(a,a));
		for(int b =0; b < getSize(); b++){
			if(matrix[a][b] != 0){
				adjacencies.push_back(Adjacency(a,b,matrix[a][b]));
			}
		}
	}

	std::sort(adjacencies.begin(), adjacencies.end(), lessThanKey());
	Check * checkAdjacencies;
	checkAdjacencies = new Check();
	int cont = 0;
	int i = 0;
	int anterior = 0;	
	while(!adjacencies.empty()){
		
		if(adjacencies.at(i).value == anterior){
			cont++;
		} else {
			parallel_for(blocked_range<size_t>(0, cont), this->checkAdjacencies(* adjacencies, * edges, * minimumAdjacencies, cont));
			adjacencies = checkAdjacencies.getAdjacency();
			edges = checkAdjacencies.getEdges();
			minimumAdjacencies = checkAdjacencies.getMinimumAdjacencies();


			anterior = adjacencies.at(i).value;
			for (j = 0; j <= cont; j++){
				adjacencies.erase(adjacencies.begin());
			}

		}
	i++;
	}
}





int main(int argc, char* argv[]) {

	cout << "Graph->GraphTBB()" << endl;
	
	Graph *graph;
	graph = new GraphTBB();
	std::string file = "";


	graph->setSize(2);
	graph->inicialize();

	if(argc <= 1){

		file = "graphExample.txt";
	}else{

		file = argv[1];
		
	}

	graph->openFile(file);
	graph->printMatrix();
	graph->minimumWeightSpanningTree();
	graph->printMinimumWeightSpanningTree();
	
	return 0;
}