#ifndef GRAPHTBB_H
#define	GRAPHTBB_H
#include <string>
#include <algorithm>
#include "Check.hpp"
using namespace std;

class GraphTBB: public Graph{
public:

	GraphTBB(){}
	~GraphTBB(){}
	
	void insertEdges(int adj1, int adj2, int value);
	void removeEdges(int adj1, int adj2);
	void checkAdjacencies(Adjacency *tmpAdjacency, int thread);
	void minimumWeightSpanningTree();
};
#endif	/* GRAPHORIGINAL_H */
