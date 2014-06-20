#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <stdlib.h>
#include "Graph.h"

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
		int numOfNodos;
		ifstream theFile (fileName.c_str());
		
		if(theFile.is_open()){

			theFile >> numOfNodos;
			setSize(numOfNodos);
			inicialize();

			while ( getline (theFile,line) ){

				if(line == "\n"){
					cout << "nova linha\n";
				}else{
					cout << line << '\n';
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
	void existAdj(int adj1, int adj2);
};
void GraphTeste::insertAdj(int adj1, int ajd2){
	
}
void GraphTeste::removeAdj(int adj1, int ajd2){
	
}
void GraphTeste::existAdj(int adj1, int adj2){
	
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
	
	return 0;
}
