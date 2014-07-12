#ifndef GRAPHOPEN_H
#define	GRAPHOPEN_H
#include <string>
#include </opt/intel/composer_xe_2013_sp1.2.144/compiler/include/omp.h>

using namespace std;

class GraphOpen: public Graph{
public:

	

	GraphOpen(){}
	~GraphOpen(){}
	void insertEdges(int adj1, int adj2, int value);
	void removeEdges(int adj1, int adj2);
	void minimumWeightSpanningTree();
	void checkAdjacencies(int thread);
};
#endif	/* GRAPHOPEN_H */
