#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <stdlib.h>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoi */
#include "Graph.hpp"

using namespace std;


Graph::Graph(){}
Graph::~Graph(){
	delete[] matrix;
	delete &sizeGraph;
};
void Graph::inicialize(){
		
	matrix = new int *[sizeGraph];
	//create a matrix
	for (int count = 0; count < sizeGraph; count++){
	    matrix[count] = new int[sizeGraph];
	}

	// Make the matrix with unabled adj.
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
	cout << "Nodos:" << endl;
	cout << "\t";
	for(int a=0; a < getSize(); a++){
		cout <<a<<"\t";
	}
	cout << endl;
	for(int a=0; a < getSize(); a++){
		cout << a << "\t";
		for(int b=0; b < getSize();b++){
			if(matrix[a][b] != 0){
				cout << "●\t";
			}else{
				cout << "\t";
			}
		}
		cout << endl;
	}
} 
void Graph::openFile(string fileName){	
	string line;
	int numOfNodos, nodo1, nodo2;
	bool inseriuNodo1 = false;
	bool nextNodo1 = false;
	bool nextNodo2 = false;
	ifstream theFile (fileName.c_str());
	
	if(theFile.is_open()){

		theFile >> numOfNodos;
		setSize(numOfNodos);
		inicialize();

		while ( getline (theFile,line) ){
			
			if(line == ""){
				
				nextNodo1 = true;
				nextNodo2 = false;
				inseriuNodo1 = false;
			}

			if(nextNodo1 == true && line != "" ){
				
				nodo1 = atoi(line.c_str());
				nextNodo1 = false;
				nextNodo2 = true;
				inseriuNodo1 = true;
			}

			if(nextNodo2 == true && line != "" && inseriuNodo1 == false  ){
				
				nodo2 = atoi(line.c_str());
				nextNodo1 = false;
				inseriuNodo1 = false;
				if(nodo1 <= getSize() && nodo2 <= getSize()){
					insertEdges(nodo1,nodo2);	
				}
				
				
			}else{

				if(inseriuNodo1){

					inseriuNodo1 = false;
				}
			}
			
		}

		theFile.close();
	}else{
		cout << "It's not possible open the file.\n";
	}
}
