#include "Graph.h"

class CilkGraph: public Graph{
public:
	CilkGraph()
	{

	}
	~CilkGraph(){}
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
	Graph *graph;
	graph = new Graph();

	return 0;
}