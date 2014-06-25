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

	if(matrix[adj1,adj2] > 0){
		matrix[adj1][adj2]--;
	}
}

void GraphCilk::sortedEdges(){
	for(int a =0;a < getSize(); a++){
		for(int b =0; b < getSize(); b++){
			if(matrix[a][b] != 0){
				Adjacency adjacencyCurrent = {a, b, matrix[a][b]};
				adjacencies.push_back(adjacencyCurrent);
			}
		}
	}
	std::sort(adjacencies.begin(), adjacencies.end(), lessThanKey());
	//cout << "ordem" << endl;
	//for(int a=0;a < edges.size(); a++){
	//	 cout << "[" << edges[a].nodo1 << "," << edges[a].nodo2 << "]=" << edges[a].value << endl;
	//}
}

bool GraphCilk::existEdges(int adj1, int adj2){
	if(matrix[adj1,adj2] > 0){
		return true;
	}else{
		return false;
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
	if(graph->existEdges(0,1)){
		cout << "existe 0,1" << endl;
	}
	if(graph->existEdges(1,0)){
		cout << "não existe 1,0" << endl;
	}
	graph->sortedEdges();
	return 0;
}