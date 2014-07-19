#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <stdlib.h>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoi */
#include <string>
#include "../Graph.hpp"
#include "GraphCpp11.hpp"

using namespace std;

void GraphCpp11::insertEdges(int adj1, int adj2, int value){

	matrix[adj1][adj2] = value;
}

void GraphCpp11::removeEdges(int adj1, int adj2){

	if(matrix[adj1][adj2] > 0){

		matrix[adj1][adj2]--;
	}
}

void GraphCpp11::minimumWeightSpanningTree(){
	
	for(int a =0;a < getSize(); a++){
		
		edges.push_back(Node(a,a));
		for(int b =0; b < getSize(); b++){
			if(matrix[a][b] != 0){
				adjacencies.push_back(Adjacency(a,b,matrix[a][b]));
			}
		}
	}

	std::sort(adjacencies.begin(), adjacencies.end(), lessThanKey());
	
	
	int idThread =0;
	Adjacency *tmp1Adjacency;
	Adjacency *tmp2Adjacency;
	


	while(!adjacencies.empty()){

		tmp1Adjacency = new Adjacency(adjacencies.at(0).node1,adjacencies.at(0).node2,adjacencies.at(0).value);
		checkAdjacencies(tmp1Adjacency,idThread);
		idThread++;
		adjacencies.erase(adjacencies.begin());
		
		if(!adjacencies.empty()){
			tmp2Adjacency = new Adjacency(adjacencies.at(0).node1,adjacencies.at(0).node2,adjacencies.at(0).value);
			int valuePivo = tmp1Adjacency->value;
			int valueOuther = tmp2Adjacency->value;
			while(valuePivo == valueOuther){
				
				cout << idThread << tmp2Adjacency << "\n";

				std::thread t (checkAdjacencies(tmp2Adjacency,idThread));
				cout << "aquina thread \n";

				t.join();
				idThread++;
				adjacencies.erase(adjacencies.begin());
				
				if(!adjacencies.empty()){
					tmp2Adjacency = &adjacencies.at(0);
					valueOuther = tmp2Adjacency->value;

				}else{
					valueOuther = valuePivo+1;
				}
			}
		}
	}
	
}
void GraphCpp11::checkAdjacencies(Adjacency *tmpAdjacency, int thread){
	
	
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
}

int main(int argc, char* argv[]) {

	cout << "Graph->GraphCpp11()" << endl;
	
	Graph *graph;
	graph = new GraphCpp11();
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
