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
	return 0;
}