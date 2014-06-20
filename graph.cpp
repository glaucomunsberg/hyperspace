#include <iostream>
#include <string>
#include <fstream>
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

void Graph::openFile(string const &fileName){
		
		string line;
		ifstream theFile (fileName);
		if(theFile.is_open()){
			while ( getline (theFile,line) )
			    {
			      cout << line << '\n';
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
	}



class GraphTeste: public Graph{
public:
	GraphTeste()
	{

	}
	~GraphTeste(){}
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

int main(int argc, char** argv) {
	GraphTeste *graph;
	graph = new GraphTeste();

	return 0;
}
