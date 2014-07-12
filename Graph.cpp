#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <stdlib.h>
#include <stdio.h> 
#include <stdlib.h>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include "Graph.hpp"

using namespace std;

Graph::Graph(){}
Graph::~Graph(){
	delete[] matrix;
	delete &sizeGraph;
};

void Graph::inicialize(){
		
	matrix = new int *[sizeGraph];
	for (int count = 0; count < sizeGraph; count++){

	    matrix[count] = new int[sizeGraph];
	}

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

		cout << "\t Error: Minimum Spanning Tree not implemented yeat." << endl;
	}else{

		cout << "\tMinimum Spanning Tree" << endl;
		for(int a=0; a < (int)minimumAdjacencies.size(); a++){

			cout << "[" <<minimumAdjacencies[a].node1 << "," << minimumAdjacencies[a].node2 << "]=" << minimumAdjacencies[a].value << endl;
		}
	}
}

void Graph::openFile(string fileName){	
	
	int numOfNodes;
	int node1;
	int node2;
	int value;
	bool inseriuNode1 = false;
	bool nextNode1 = false;
	bool nextNode2 = false;

	ifstream theFile (fileName.c_str());
	string line;

	if(theFile.is_open()){

		theFile >> numOfNodes;
		setSize(numOfNodes);
		inicialize();

		while ( getline (theFile,line) ){
			
			while (! theFile.eof() ){

				getline (theFile,line); 
				vector<string> str_split;
				boost::split(str_split,line,boost::is_any_of(" ")); 
				node1 = atoi(str_split[0].c_str());
				node2= atoi(str_split[1].c_str());
				value = atoi(str_split[2].c_str());
				insertEdges(node1,node2, value); 
			}
		}
		
		theFile.close();
	}else{

		cout << "\t Error: It's not possible open the file \"" << fileName << "\".\n";
	}
}