#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>     /* atoi */
#include </opt/intel/composer_xe_2013_sp1.2.144/compiler/include/cilk/cilk.h>
#include </opt/intel/composer_xe_2013_sp1.2.144/compiler/include/cilk/cilk_stub.h>
#include </opt/intel/composer_xe_2013_sp1.2.144/compiler/include/cilk/cilk_api.h>
using namespace std;

class GraphGenerator{

private:
	int 	numNodes;
	int 	numAdjacencies;
	string 	nameFile;

public:
	GraphGenerator(string file, int nodes, int adjacencies){

		numNodes 		= nodes;
		numAdjacencies 	= adjacencies;
		nameFile		= file;
	}

	void createGraph(){

		int randomMinimumNode 	= 0;
		int randomMaximumNode 	= numNodes-1;
		int randomMinimumValue	= 0;
		int randomMaximumValue 	= 30;
		int nodeLeft, nodeRight, value;

		if(numNodes*numNodes < numAdjacencies){

			cout << "\tAtention: You will generate a number of adjacencies more than number of adjacencies possibilities." << endl;
		}

		if(numNodes < 1){

			cout << "\tError: Num of nodes need be higher that 0." << endl;

		}else{

			ofstream theFile (nameFile.c_str(), std::ofstream::trunc);
			theFile << numNodes << endl;
			srand( time(NULL));

			for(int a = 0; a < numAdjacencies; a++){

				nodeLeft = randomMinimumNode + (rand() % (int) (randomMaximumNode - randomMinimumNode + 1) );
				nodeRight = randomMinimumNode + (rand() % (int) (randomMaximumNode - randomMinimumNode + 1) );
				value = randomMinimumValue + (rand() % (int) (randomMaximumValue - randomMinimumValue + 1) );
				if(a +1 == numAdjacencies){

					theFile << nodeLeft << " " << nodeRight << " " << value;
				}else{

					theFile << nodeLeft << " " << nodeRight << " " << value << endl;
				}
			}

			theFile.close();
			cout << "Done!" << endl;
		}
		

	}

};
void oie(int a){
	cout << "oi:" << a << endl;
}
int main(int argc, char* argv[]) {
	
	cilk_for( int a=0; a < argv[1] ;a++){
		oie(a);
	}

	GraphGenerator *graph;
	cout << "Generator Graph" << endl;

	if(argc > 2){
		
		if(argc > 3){

			string file = "";
			file = argv[3];
			graph = new GraphGenerator(file,atoi(argv[1]),atoi(argv[2]));
		}else{

			graph = new GraphGenerator("graphExample.txt",atoi(argv[1]),atoi(argv[2]));
		}

		graph->createGraph();
	}else{

		cout << "\tError: To create a Graph you need pass through parameter <num_nodes>, <num_adjacencies> and <name_file>" << endl;
	}

	delete graph;
}