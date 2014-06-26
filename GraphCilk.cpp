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
		edges.push_back(Nodo(a,a));
		for(int b =0; b < getSize(); b++){
			if(matrix[a][b] != 0){
				adjacencies.push_back(Adjacency(a,b,matrix[a][b]));
			}
		}
	}
	std::sort(adjacencies.begin(), adjacencies.end(), lessThanKey());
	//cout << "ordem" << endl;
	//for(int a=0;a < adjacencies.size(); a++){
	//	 cout << "[" << adjacencies[a].nodo1 << "," << adjacencies[a].nodo2 << "]=" << adjacencies[a].value << endl;
	//}
	

	//cout << "ordem 2" << endl;

	Adjacency *tmpAdjacency;
	vector<Adjacency> minimun;
	int lastTree;
	while(!adjacencies.empty()){
		
		tmpAdjacency = &adjacencies.at(0);
		//cout << " Aresta: [" << tmpAdjacency->nodo1 << "," << tmpAdjacency->nodo2 << "]=" << tmpAdjacency->value << endl;
		
		if(edges[tmpAdjacency->nodo1].tree != edges[tmpAdjacency->nodo2].tree){
			minimun.push_back(*tmpAdjacency);
			lastTree = tmpAdjacency->nodo1;
			//cout << "Difere. Arvore: [" << edges[tmpAdjacency->nodo1].tree <<"," << edges[tmpAdjacency->nodo2].tree << "]" << endl;
			
			for(int a=0; a < edges.size(); a++){
				if(edges[a].tree == edges[tmpAdjacency->nodo2].tree){
					edges[a].tree = edges[tmpAdjacency->nodo1].tree;
				}
			}

		}

		adjacencies.erase(adjacencies.begin());

	}
	cout << "ativos" << endl;

	for(int a=0; a < minimun.size();a++ ){
		cout << "Aresta: [" << minimun[a].nodo1 <<"," << minimun[a].nodo2 << "]" << endl;
	}
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