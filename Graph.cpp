#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <stdlib.h>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoi */
#include "Graph.hpp"

using namespace std;

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
						insertAdj(nodo1,nodo2);	
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

void Graph::setSize(int size){
		sizeGraph = size;
	}
int Graph::getSize(){
	return sizeGraph;
}
Graph::Graph(){}
Graph::~Graph(){
		delete[] matrix;
		delete &sizeGraph;
	};

class GraphTeste: public Graph{
public:
	GraphTeste()
	{

	}
	~GraphTeste(){
		
	}
	void insertAdj(int adj1, int adj2);
	void removeAdj(int adj1, int adj2);
	bool existAdj(int adj1, int adj2);
	void printMatrix();
};
void GraphTeste::insertAdj(int adj1, int adj2){
	matrix[adj1][adj2]++;
}
void GraphTeste::removeAdj(int adj1, int adj2){

	if(matrix[adj1,adj2] > 0){
		matrix[adj1][adj2]--;
	}
}
bool GraphTeste::existAdj(int adj1, int adj2){
	if(matrix[adj1,adj2] > 0){
		return true;
	}else{
		return false;
	}
}
void GraphTeste::printMatrix(){

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

int main(int argc, char* argv[]) {
	Graph *graph;
	graph = new GraphTeste();
	graph->setSize(2);
	graph->inicialize();
	if(argc < 1){
		graph->openFile("GraphData.txt");
	}else{
		std::string file = argv[1];
		graph->openFile(file);
	}
	graph->printMatrix();
	if(graph->existAdj(0,1)){
		cout << "existe 0,1" << endl;
	}
	if(graph->existAdj(1,0)){
		cout << "não existe 1,0" << endl;
	}
	return 0;
}
