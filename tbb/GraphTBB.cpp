#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <stdlib.h>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoi */
#include <string>
#include "GraphTBB.hpp"
#include "tbb/parallel_for.h"
#include "tbb/blocked_range.h"
#include "tbb/task_scheduler_init.h"
#include <tbb/mutex.h>

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

struct check {
	vector<Adjacency> * adjacencies;
	vector<Adjacency> * minimumAdjacencies;
	vector<Node> * edges;
 
	void operator() ( const tbb::blocked_range<size_t> &r) const {
		tbb::mutex countMutex;
		for ( size_t i = r.begin(); i < r.end(); ++i ) {
			countMutex.lock();
			int change;
			int removePosition;
			Adjacency *tmpAdjacency = &adjacencies->at(i);
			Node *edges1 = &edges->at(tmpAdjacency->node1);
			Node *edges2 = &edges->at(tmpAdjacency->node2);
			if(edges1->tree != edges2->tree){
			
				minimumAdjacencies->push_back(Adjacency(tmpAdjacency->node1,tmpAdjacency->node2,tmpAdjacency->value));
				change = edges2->tree;
				for(int a=0; a < (int) edges->size(); a++){
					Node *tmpEdge = &edges->at(a);
					if(tmpEdge->tree == change){
						tmpEdge->tree = edges1->tree;
					}
				}
			}
			countMutex.unlock();
		}

	}

};


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

	struct check checkAdjacencies;
	checkAdjacencies.adjacencies = &adjacencies;
	checkAdjacencies.minimumAdjacencies = &minimumAdjacencies;
	checkAdjacencies.edges = &edges;

	int cont = 0;
	int i = 0;
	int anterior = adjacencies.at(0).value;
	int valueNow;
	int flag;
	while(!adjacencies.empty()){
		flag = 0;
		valueNow = adjacencies.at(i).value;
		if(valueNow == anterior){
			cont++;
		} else {

				if(cont != 0){
					tbb::parallel_for(tbb::blocked_range<size_t>(0, cont), checkAdjacencies);	
				}
				
				anterior = adjacencies.at(i).value;
				flag = 1;
				for (int j = 0; j < cont; j++){
					adjacencies.erase(adjacencies.begin());
				}
				cont = 0;		
				i = 0;

		}
		if(i < adjacencies.size()-1){
			if(flag == 0){
				i++;	
			}
		} else {
			tbb::parallel_for(tbb::blocked_range<size_t>(0, cont), checkAdjacencies);
			for (int j = 0; j < cont; j++){
					adjacencies.erase(adjacencies.begin());
			}
		}
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