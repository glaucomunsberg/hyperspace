#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <stdlib.h>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoi */
#include <string>
#include "Graph.hpp"
#include "GraphCilk.hpp"

using namespace std;

void GraphCilk::insertEdges(int adj1, int adj2){
	matrix[adj1][adj2]++;
}

void GraphCilk::removeEdges(int adj1, int adj2){

	if(matrix[adj1][adj2] > 0){

		matrix[adj1][adj2]--;
	}
}

void GraphCilk::minimumWeightSpanningTree(){
	
	for(int a =0;a < getSize(); a++){
		
		edges.push_back(Node(a,a));
		for(int b =0; b < getSize(); b++){
			
			if(matrix[a][b] != 0){
				
				adjacencies.push_back(Adjacency(a,b,matrix[a][b]));
			}
		}
	}

	std::sort(adjacencies.begin(), adjacencies.end(), lessThanKey());
	Adjacency *tmpAdjacency;
	
	
	while(!adjacencies.empty()){
		
		tmpAdjacency = &adjacencies.at(0);
		
		if(edges[tmpAdjacency->node1].tree != edges[tmpAdjacency->node2].tree){
			
			minimumAdjacencies.push_back(Adjacency(tmpAdjacency->node1,tmpAdjacency->node2,tmpAdjacency->value));
		
			for(int a=0; a < edges.size(); a++){
				
				if(edges[a].tree == edges[tmpAdjacency->node2].tree){
					edges[a].tree = edges[tmpAdjacency->node1].tree;
				}
			}
		}

		adjacencies.erase(adjacencies.begin());
	}
}


int main(int argc, char* argv[]) {
	Graph *graph;
	graph = new GraphCilk();
	graph->setSize(2);
	graph->inicialize();
	if(argc < 1){
		graph->openFile("GraphData.txt");
	}else{
		std::string file = argv[1];
		graph->openFile(file);
	}
	graph->printMatrix();
	graph->minimumWeightSpanningTree();
	graph->printMinimumWeightSpanningTree();
	return 0;
}