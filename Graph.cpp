#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <stdlib.h>
#include <stdio.h> 
#include <stdlib.h>
#include "Graph.hpp"

using namespace std;

Graph::Graph(){}
Graph::~Graph(){
	delete[] matrix;
	delete &sizeGraph;
};

void Graph::inicialize(){
		
	matrix = new int *[sizeGraph];
	//Create a matrix
	for (int count = 0; count < sizeGraph; count++){

	    matrix[count] = new int[sizeGraph];
	}

	//Make the matrix with unabled adj.
	for(int count=0; count < sizeGraph; count++){

		for(int count2=0;count2 < sizeGraph; count2++){

			matrix[count][count] = 0;
		}
	}
}

void Graph::setSize(int size){
	sizeGraph = size;
}

int Graph::getSize(){
	return sizeGraph;
}

void Graph::printMatrix(){
	cout << "Nodes:" << endl;
	cout << "\t";
	for(int a=0; a < getSize(); a++){
		cout <<a<<"\t";
	}
	cout << endl;
	for(int a=0; a < getSize(); a++){
		cout << a << "\t";
		for(int b=0; b < getSize();b++){
			if(matrix[a][b] != 0){
				cout << "●->" << matrix[a][b] << "\t" ;
			}else{
				cout << "\t";
			}
		}
		cout << endl << endl;
	}
} 

void Graph::printMinimumWeightSpanningTree(){


	if(minimumAdjacencies.empty()){

		cout << "Minimum Spanning Tree not implemented yeat." << endl;
	}else{

		cout << "Minimum Spanning Tree" << endl;
		
		for(int a=0; a < (int)minimumAdjacencies.size(); a++){

			cout << "[" <<minimumAdjacencies[a].node1 << "," << minimumAdjacencies[a].node2 << "]=" << minimumAdjacencies[a].value << endl;
		}
	}
}

void Graph::openFile(string fileName){	
	
	string line;
	int numOfNodes;
	int node1;
	int node2;
	bool inseriuNode1 = false;
	bool nextNode1 = false;
	bool nextNode2 = false;

	ifstream theFile (fileName.c_str());
	
	if(theFile.is_open()){

		theFile >> numOfNodes;
		setSize(numOfNodes);
		inicialize();

		while ( getline (theFile,line) ){
			
			if(line == ""){
				
				nextNode1 = true;
				nextNode2 = false;
				inseriuNode1 = false;
			}

			if(nextNode1 == true && line != "" ){
				
				node1 = atoi(line.c_str());
				nextNode1 = false;
				nextNode2 = true;
				inseriuNode1 = true;
			}

			if(nextNode2 == true && line != "" && inseriuNode1 == false  ){
				
				node2 = atoi(line.c_str());
				nextNode1 = false;
				inseriuNode1 = false;
				if(node1 <= getSize() && node2 <= getSize()){
					insertEdges(node1,node2);	
				}
			}else{

				if(inseriuNode1){

					inseriuNode1 = false;
				}
			}
			
		}
		theFile.close();
	}else{

		cout << "It's not possible open the file.\n";
		
	}
}